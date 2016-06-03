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
#include "base/readers.h"
#include "base/relation.h"
#include "base/catalog.h"
#include "operators/projection.h"

int main(int argc, char const *argv[])
{
	Catalogo catalog;
	Relation ITBI = catalog.getIBTIRelation();

	int cols[3] = {3,4,6};
	vector<int> colunas(cols, cols + sizeof(cols) / sizeof(int) );
	Relation projection = project(ITBI, colunas);

	for(int linha = 0; linha < projection.size() ; linha++) {
		vector<string> colunas = projection.getTupla(linha);
		for(int col = 0; col < colunas.size(); col++) {
			cout << colunas[col] << endl;
		}
		cout << endl;
	}
	
	return 0;
}