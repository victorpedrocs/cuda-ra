/*
 * =====================================================================================
 *
 *       Filename:  catalog.cpp
 *
 *    Description:  Arquivo com a implementacao do catalogo
 *
 *        Version:  1.0
 *        Created:  05/26/16 12:20:04
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Victor Silva
 *
 * =====================================================================================
 */
#include "catalog.h"

Catalogo::Catalogo() {
	this->itbi = prepararITBI();
}

Catalogo::~Catalogo() {}

Relation Catalogo::getIBTIRelation() {
	return this->itbi;
}

Relation prepararITBI() {
	Relation itbiRelation;
	vector< vector<string> > dadosITBI = lerDadosITBI();
	
	/*for(int i = 0; i < dadosITBI[0].size(); i++) {
		itbiRelation.addColumn(dadosITBI[0][i]);
	}*/

	itbiRelation.addColumn(dadosITBI[0][0])
		.addColumn(dadosITBI[0][1])
		.addColumn(dadosITBI[0][5])
		.addColumn(dadosITBI[0][6]);

	for(int i = 1; i < dadosITBI.size(); i++) {
		vector<float> newTupla;

		newTupla.push_back( atof(dadosITBI[i][0].c_str()) );
		newTupla.push_back( atof(dadosITBI[i][1].c_str()) );
		newTupla.push_back( atof(dadosITBI[i][5].c_str()) );
		newTupla.push_back( atof(dadosITBI[i][6].c_str()) );

		itbiRelation.addTupla(newTupla);
	}

	return itbiRelation;
}
