/*
 * =====================================================================================
 *
 *       Filename:  projection.cu
 *
 *    Description:  Este arquivo contem a implementacao do operador projection em CUDA/GPU
 *
 *        Version:  1.0
 *        Created:  06/02/16 08:55:22
 *       Revision:  none
 *       Compiler:  nvcc
 *
 *         Author:  Victor Silva
 *
 * =====================================================================================
 */
#include "projection.h"

__global__ void projectColumns ( float		*oldRelation,
								 float		*newRelation,
								 int		*columns,
								 int 		sizeAllTuplas,
								 int 		columnsSize,
								 int 		tuplaSize )
{
	int i = blockIdx.x * blockDim.x + threadIdx.x;
	if ( i < sizeAllTuplas ) {
		int iTupla = i/tuplaSize;
		for (int it = 0; it < columnsSize; it++) {
			newRelation[it + iTupla] = oldRelation[ columns[it] + iTupla ];
		}
	}
}

Relation project( Relation inputRelation, vector<int> columns ) {
	
	cudaEvent_t start, stop;
	cudaEventCreate(&start);
	cudaEventCreate(&stop);
	float totalMillis = 0;

	Relation outputRelation;
	vector<float> h_outputRelationHeaders;

	// Copia os headers para a nova relação
	for(int i = 0; i < columns.size(); i++){
		int colIndex = columns[i];
		outputRelation.addColumn( inputRelation.getColumnName(colIndex));
	}
	
	const unsigned int sizeAllTuplas = inputRelation.size() * inputRelation.getHeaders().size();
	const unsigned int relationSize = inputRelation.size();
	const unsigned int tuplaSize = inputRelation.getHeaders().size();

	thrust::host_vector<float> h_oldRelation(sizeAllTuplas, 0);
	thrust::device_vector<int> d_columns(columns);	
	thrust::device_vector<float> d_oldRelation( sizeAllTuplas );
	thrust::device_vector<float> d_newRelation( inputRelation.size() * columns.size(), 0 );
	
	for (int i = 0; i < sizeAllTuplas; i++) {
		int tuplaIndex = i/tuplaSize;
		int col = i%tuplaSize;
		h_oldRelation[i] = inputRelation.getTupla(tuplaIndex)[col];
	}
	thrust::copy( h_oldRelation.begin(), h_oldRelation.end(), d_oldRelation.begin() );

	int *ptr_columns = thrust::raw_pointer_cast( d_columns.data() );
	float *ptr_oldRelation = thrust::raw_pointer_cast( d_oldRelation.data() );
	float *ptr_newRelation = thrust::raw_pointer_cast( d_newRelation.data() );

	const unsigned int numThreadsPerClusterBlock = 256;
	const unsigned int numClusterBlocks = (sizeAllTuplas + numThreadsPerClusterBlock - 1) / numThreadsPerClusterBlock;
	
	cout << "Chegou no Kernel" << endl;
	checkCuda(cudaEventRecord(start));
	projectColumns
		<<< numClusterBlocks, numThreadsPerClusterBlock >>>
		( ptr_oldRelation, ptr_newRelation, ptr_columns, sizeAllTuplas, columns.size(), tuplaSize );
	checkCuda(cudaEventRecord(stop));
	checkCuda(cudaEventSynchronize(stop));

	thrust::host_vector<float> h_newRelation( d_newRelation );
	vector< vector<float> > newTuplas(relationSize);
	for (int i = 0; i < sizeAllTuplas; i++)
	{
		int tuplaIndex = i/tuplaSize;
		newTuplas[tuplaIndex].push_back(h_newRelation[i]);
	}

	outputRelation.setTuplas(newTuplas);

	checkCuda(cudaEventElapsedTime(&totalMillis, start, stop));
	checkCuda( cudaEventDestroy( start ) );
	checkCuda( cudaEventDestroy( stop ) );
	double seconds = totalMillis/1000;
	printf("GPU Time =\t%f\n", seconds);

	return outputRelation;

}