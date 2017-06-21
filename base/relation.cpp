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

Relation::Relation() {
	colNames.clear();
	tuplas.clear();
}

Relation::~Relation() {
	colNames.clear();
	tuplas.clear();
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