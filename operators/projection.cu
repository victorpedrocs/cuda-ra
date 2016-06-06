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

__global__ void copyHeaders (	string	inputRelationHeaders, 
								int 	*columns,
							  	string 	*newHeader,
							  	int 	size )
{
	int index = blockIdx.x * blockDim.x + threadIdx.x;
	if (index < size ) {
		newHeader[index] = inputRelationHeaders[columns[index]];
	}
}

__global__ void projectColumns ( string		*tupla,
								 int		tSize,
								 int		*columns,
								 int		cSize,
								 string 	*novaTupla)
{
	int index = blockIdx.x * blockDim.x + threadIdx.x;
	if (index < tSize) {
		for (int i = 0; i < cSize; i++) {
			novaTupla[i] = tupla[columns[i]];
		}
	}
}

Relation project( Relation inputRelation, vector<int> columns ) {
	Relation outputRelation;
	vector<string> h_outputRelationHeaders;

	const unsigned int numObjs = inputRelation.size();
	const unsigned int numThreadsPerClusterBlock = 128;
    const unsigned int numClusterBlocks =
        (numObjs + numThreadsPerClusterBlock - 1) / numThreadsPerClusterBlock;
    const unsigned int clusterBlockSharedDataSize =
        numThreadsPerClusterBlock * sizeof(unsigned char);

	thrust::device_vector<string> d_inputRelationHeaders(inputRelation.getHeaders());
	thrust::device_vector<int> d_columns(columns);
	thrust::device_vector<string> d_newHeader(columns.size());

	string *ptr_inputRelationHeaders = thrust::raw_pointer_cast( d_inputRelationHeaders.data() );
	int *ptr_columns = thrust::raw_pointer_cast( d_columns.data() );
	string *ptr_newHeader = thrust::raw_pointer_cast( d_newHeader.data() );

	copyHeaders<<< 1, columns.size() >>>( ptr_inputRelationHeaders, ptr_columns, ptr_newHeader, columns.size() );

	thrust::copy( d_newHeader.begin(), d_newHeader.end(), h_outputRelationHeaders.begin() );
	outputRelation.setHeaders( h_outputRelationHeaders );

	for(int i = 0; i < inputRelation.size(); i++){
		thrust::device_vector<string> d_tupla( inputRelation.getTupla(i) );
		thrust::device_vector<string> d_newTupla;
		vector<string> h_newTupla;

		string *ptr_tupla = thrust::raw_pointer_cast( d_tupla.data() );
		string *ptr_newTupla = thrust::raw_pointer_cast( d_newTupla.data() );

		projectColumns
			<<< numClusterBlocks, numThreadsPerClusterBlock >>> 
			( ptr_tupla, inputRelation.size(), ptr_columns, columns.size(), ptr_newTupla );

		thrust::copy( d_newTupla.begin(), d_newTupla.end(), h_newTupla.begin() );

		outputRelation.addTupla( h_newTupla );
	}

	return outputRelation;


}