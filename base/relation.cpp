/*
 * =====================================================================================
 *
 *       Filename:  relation.cpp
 *
 *    Description:  Implementacao da relacao
 *
 *        Version:  1.0
 *        Created:  06/02/16 15:55:56
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Victor Silva
 *
 * =====================================================================================
 */
#include "relation.h"

void Relation::build(string name) {
	this->name = name;
	this->colNames.clear();
	this->tuplas.clear();
}

Relation::Relation() {
	this->build("");
}

Relation::Relation(string name) {
	this->build(name);
}

Relation::~Relation() {
	this->colNames.clear();
	this->tuplas.clear();
}


Relation& Relation::addColumn(string name, string type) {
	this->colNames.push_back(name);
	if(type == "int" || type == "integer") {
		this->colTypes.push_back(Relation::INT);
	}
	else if( type == "float") {
		this->colTypes.push_back(Relation::FLOAT);
	}
	else if(type == "string") {
		this->colTypes.push_back(Relation::STRING);
	}
	else {
		cout << "Column Type Unknown" << endl;
	}
	return *this;
}

Relation& Relation::addColumn(string colName) {
	this->colNames.push_back(colName);
	return *this;
}

void Relation::setTuplas( vector<vector<float> > tuplas ) {
	this->tuplas.clear();
	this->tuplas.resize(tuplas.size());
	copy(tuplas.begin(), tuplas.end(), this->tuplas.begin());
}

void Relation::addTupla(vector<float> tupla) {
	this->tuplas.push_back(tupla);
}

void Relation::addTuple(vector<string> tuple) {
	vector<boost::any> newTuple;
	for(int i = 0; i < tuple.size(); i++) {
		if(this->colTypes[i] == Relation::INT) {
			newTuple.push_back(stoi(tuple[i]));
		}
		else if (this->colTypes[i] == Relation::FLOAT) {
			newTuple.push_back(stof(tuple[i]));
		}
		else {
			newTuple.push_back(tuple[i]);
		}
	}
	this->tuples.push_back(newTuple);
}

void Relation::removeTupla(int index) {
	this->tuplas.erase(this->tuplas.begin()+index);
}

int Relation::nOfColumns() {
	return this->colNames.size();
}

int Relation::size() {
	return this->tuplas.size();
}

vector< vector<float> > Relation::getTuplas() {
	return this->tuplas;
}

string Relation::getColumnName(int index) {
	return this->colNames[index];
}

vector<float> Relation::getTupla(int index) {
	return this->tuplas[index];
}

void Relation::setHeaders( vector<string> headers ) {
	this->colNames.clear();
	copy(headers.begin(), headers.end(), this->colNames.end());
}

vector<string> Relation::getHeaders() {
	return this->colNames;
}

vector<Relation::ColType> Relation::getColTypes() {
	return this->colTypes;
}