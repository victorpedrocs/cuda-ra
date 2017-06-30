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

void Catalogo::initializeFields() {
	cout << "Novo catalogo" << endl;
	this->isItbiInitialized = false;
	this->isFacialInitialized = false;
	this->relations.clear();
}

Catalogo::Catalogo() {
	this->relationSize = -1;
	this->initializeFields();
}

Catalogo::Catalogo(int relationSize) {
	this->relationSize = relationSize;
	this->initializeFields();
}

Catalogo::~Catalogo() {}

Relation Catalogo::getIBTIRelation() {
	if(!this->isItbiInitialized){
		this->itbi = prepararITBI(this->relationSize);
		this->isItbiInitialized = true;
	}
	return this->itbi;
}

Relation Catalogo::getFacialRelation() {
	if(!this->isFacialInitialized){
		this->facialAffirmative = prepararFacialAffirmative(this->relationSize);
		this->isFacialInitialized = true;
	}
	return this->facialAffirmative;
}

Relation prepararITBI(int size) {
	Relation itbiRelation;
	vector< vector<string> > dadosITBI = lerDadosITBI();

	if( size < 1 || size > dadosITBI.size() ) {
		size = dadosITBI.size();
	}

	itbiRelation.addColumn(dadosITBI[0][0])
		.addColumn(dadosITBI[0][1])
		.addColumn(dadosITBI[0][5])
		.addColumn(dadosITBI[0][6]);

	for(int i = 1; i < size; i++) {
		vector<float> newTupla;

		newTupla.push_back( atof(dadosITBI[i][0].c_str()) );
		newTupla.push_back( atof(dadosITBI[i][1].c_str()) );
		newTupla.push_back( atof(dadosITBI[i][5].c_str()) );
		newTupla.push_back( atof(dadosITBI[i][6].c_str()) );

		itbiRelation.addTupla(newTupla);
	}

	return itbiRelation;
}

Relation prepararFacialAffirmative(int size) {
	cout << "Preparar facial affirmative" << endl;
	Relation facial;
	vector< vector<string> > dadosFacial = lerFacialAffirmative();

	if( size < 1 || size > 1000 ) {
		size = 1000;
	}

	cout << "Inicializa headers" << endl;
	cout << "Header" << endl;
	for(int i = 0; i < dadosFacial[0].size(); i++) {
		cout << dadosFacial[0][i] << " ";
		facial.addColumn(dadosFacial[0][i]);
	}
	cout << endl;

	cout << "le arquivo, " << size << " instancias" << endl;
	for(int i = 1; i < size; i++) {
		vector<float> tupla;
		cout << "Linha " << i << endl;
		cout << "dadosfacial[i].size = " << dadosFacial[i].size() << endl;
		cout << "dadosfacial[i][0] = " << dadosFacial[i][0] << endl;
		for(int j = 0; dadosFacial[i].size(); j++) {
			cout << dadosFacial[i][j] << " ";
			tupla.push_back( atof( dadosFacial[i][j].c_str() ) );
		}
		cout << endl;
		facial.addTupla(tupla);
	}

	cout << "Retorna relacao pronta" << endl;
	return facial;
}

void Catalogo::createRelation(string name, string pathToCsv) {
	Relation newRelation(name);
	vector< vector<string> > rows = readCsv(pathToCsv);
	
	// Add columns
	for(int i = 0; i < rows[0].size(); i++) {
		vector<string> colNameType = splitString(rows[0][i], ':');
		newRelation.addColumn(colNameType[0], colNameType[1]);
	}

	// Add tuples
	for(int i = 1; i < rows.size(); i++) {
		newRelation.addTuple(rows[i]);
	}

}



