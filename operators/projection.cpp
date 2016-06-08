/*
 * =====================================================================================
 *
 *       Filename:  projection.cpp
 *
 *    Description:  Este arquivo contem a implementacao do operador projection em CPU
 *
 *        Version:  1.0
 *        Created:  06/02/16 08:53:12
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Victor Silva
 *
 * =====================================================================================
 */
#include "projection.h"

Relation project(Relation inputRelation, vector<int> columns) {
	Relation outputRelation;

	for(int i = 0; i < columns.size(); i++){
		int colIndex = columns[i];
		outputRelation.addColumn( inputRelation.getColumnName(colIndex));
	}

	double timing;
	double projection_time = wtime();

	for(int i = 0; i < inputRelation.size(); i++){
		vector<float> tupla = inputRelation.getTupla(i);
		vector<float> newTupla;

		for(int j = 0; j < columns.size(); j++){
			int columnIndex = columns[j];
			newTupla.push_back(tupla[columnIndex]);
		}
		outputRelation.addTupla(newTupla);
	}

	timing = wtime();
	projection_time = timing - projection_time;
	
	cout << setprecision(5) << projection_time << endl;

	return outputRelation;
}