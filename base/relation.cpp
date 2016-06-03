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

void Relation::addTupla(vector<string> tupla) {
	this->tuplas.push_back(tupla);
}

int Relation::nOfColumns() {
	return this->colNames.size();
}

int Relation::size() {
	return this->tuplas.size();
}

vector< vector<string> > Relation::getTuplas() {
	return this->tuplas;
}

string Relation::getColumnName(int index) {
	return this->colNames[index];
}

vector<string> Relation::getTupla(int index) {
	return this->tuplas[index];
}

