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
#include "readers.h"

Catalogo::Catalogo() {
	this->itbi = prepararITBI();
}

Catalogo::~Catalogo() {
	
}

Relation Catalogo::getIBTIRelation() {
	return this->itbi;
}

Relation prepararITBI() {
	Relation itbiRelation;
	vector< vector<string> > dadosITBI = lerDadosITBI();
	
	for(int i = 0; i < dadosITBI[0].size(); i++) {
		itbiRelation.addColumn(dadosITBI[0][i]);
	}

	for(int i = 1; i < dadosITBI.size(); i++) {
		itbiRelation.addTupla(dadosITBI[i]);
	}

	return itbiRelation;
}
