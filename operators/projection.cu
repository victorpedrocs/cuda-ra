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

__global__ void projectColumns ( float		*tupla,
								 float		*novaTupla,
								 int		*colunas,
								 int 		size )
{
	int i = blockIdx.x * blockDim.x + threadIdx.x;
	if (i < size)
	{
		novaTupla[i] = tupla[ colunas[i] ];
	}
}

Relation project( Relation inputRelation, vector<int> columns ) {
	Relation outputRelation;
	vector<float> h_outputRelationHeaders;

	for(int i = 0; i < columns.size(); i++){
		int colIndex = columns[i];
		outputRelation.addColumn( inputRelation.getColumnName(colIndex));
	}

	thrust::device_vector<int> d_columns(columns);
	int *ptr_columns = thrust::raw_pointer_cast( d_columns.data() );

	for(int i = 0; i < inputRelation.size(); i++){
		thrust::device_vector<float> d_tupla( inputRelation.getTupla(i) );
		thrust::device_vector<float> d_newTupla(columns.size(), 0);
		vector<float> h_newTupla(columns.size(), 0);

		float *ptr_tupla = thrust::raw_pointer_cast( d_tupla.data() );
		float *ptr_newTupla = thrust::raw_pointer_cast( d_newTupla.data() );

		projectColumns<<< 1, columns.size() >>>( ptr_tupla, ptr_newTupla, ptr_columns, columns.size() );

		thrust::copy( d_newTupla.begin(), d_newTupla.end(), h_newTupla.begin() );


		outputRelation.addTupla( h_newTupla );
	}

	return outputRelation;

}