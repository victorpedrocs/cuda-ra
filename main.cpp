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
#include "base/readers.h"
#include "base/relation.h"
#include "base/catalog.h"
#include "operators/projection.h"
#include "wtime.h"

int main(int argc, char const *argv[])
{
	Catalogo catalog;
	Relation ITBI = catalog.getIBTIRelation();

	int cols[2] = {1,2};
	vector<int> colunas(cols, cols + sizeof(cols) / sizeof(int) );

	double timing;
	double projection_time = wtime();

	Relation projection = project(ITBI, colunas);

	timing = wtime();
	projection_time = timing - projection_time;
	
	cout << "Projection time: " << setprecision(5) << projection_time << endl;
	return 0;
}