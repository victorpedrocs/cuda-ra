/**
 * =====================================================================================
 *
 *       Filename:  projection.cpp
 *
 *    Description:  Este arquivo contem a implementacao do operador projection em CPU
 *
 *        @version  1.0
 *        Created:  06/02/16 08:53:12
 *       Revision:  none
 *       Compiler:  g++
 *
 *         @author  Victor Silva
 *
 * =====================================================================================
 */
#include "projection.h"

Relation project(Relation inputRelation, vector<int> columns) {
	Relation outputRelation;
	double start, stop, elapsed;
	for(int i = 0; i < columns.size(); i++){
		int colIndex = columns[i];
		outputRelation.addColumn( inputRelation.getColumnName(colIndex));
	}

	
	start = wtime();

	for(int i = 0; i < inputRelation.size(); i++){
		vector<float> tupla = inputRelation.getTupla(i);
		vector<float> newTupla;

		for(int j = 0; j < columns.size(); j++){
			int columnIndex = columns[j];
			newTupla.push_back(tupla[columnIndex]);
		}
		outputRelation.addTupla(newTupla);
	}

	stop = wtime();
	elapsed = stop - start;
	
	cout << setprecision(5) << "CPU Time =\t" << elapsed << endl;

	return outputRelation;
}