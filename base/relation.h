/*
 * =====================================================================================
 *
 *       Filename:  relation.h
 *
 *    Description:  Headers do arquivo de relacoes
 *
 *        Version:  1.0
 *        Created:  05/25/16 09:05:02
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Victor Silva
 *
 * =====================================================================================
 */
#ifndef RELATION_H
#define RELATION_H

#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

class Relation {
private:
	vector<string> colNames;
	vector< vector<float> > tuplas;

public:
	Relation& addColumn(string);
	void addTupla(vector<float>);
	void removeTupla(int);
	int nOfColumns();
	void setHeaders(vector<string>);
	void setTuplas(vector< vector<float> >);
	
	int size();
	vector<string> getHeaders();
	vector< vector<float> > getTuplas();
	string getColumnName(int);
	vector<float> getTupla(int);

	Relation();
	~Relation();

};

#endif
