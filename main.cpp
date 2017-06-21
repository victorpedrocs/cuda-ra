/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  Main File
 *
 *        Version:  1.0
 *        Created:  05/26/16 12:30:39
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Victor Silva
 *
 * =====================================================================================
 */
#include <iomanip>
#include <iostream>
#include "base/readers.h"
#include "base/relation.h"
#include "base/catalog.h"
#include "operators/projection.h"

int main(int argc, char const *argv[])
{

	int size;
	double time, stop;

	if(argc > 1){
		size = atoi(argv[1]);
	}
	else {
		size = -1;
	}

	Catalogo catalog(size);
	Relation relation = catalog.getFacialRelation();

	time = wtime();
	int cols[4] = {1,2,5,6};
	vector<int> colunas(cols, cols + sizeof(cols) / sizeof(int) );
	Relation projection = project(relation, colunas);

	for(int i = 0; i < projection.size(); i++){
		for(int j = 0; j < projection.getTupla(i).size() ; j++){
			cout << projection.getTupla(i)[j] << ", ";
		}
		cout << endl;
	}

	stop = wtime();
	time = stop - time;

	cout << "TOTAL time =\t" << time << endl;
	return 0;
}