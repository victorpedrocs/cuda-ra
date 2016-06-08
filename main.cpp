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

	if(argc > 1){
		size = atoi(argv[1]);
	}
	else {
		size = -1;
	}

	Catalogo catalog(size);
	Relation ITBI = catalog.getIBTIRelation();

	int cols[2] = {1,2};
	vector<int> colunas(cols, cols + sizeof(cols) / sizeof(int) );

	Relation projection = project(ITBI, colunas);

	return 0;
}