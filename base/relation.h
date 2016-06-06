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
	vector< vector<string> > tuplas;

public:
	Relation& addColumn(string);
	void addTupla(vector<string>);
	int nOfColumns();
	void setHeaders(vector<string>);

	int size();
	vector<string> getHeaders();
	vector< vector<string> > getTuplas();
	string getColumnName(int);
	vector<string> getTupla(int);

	Relation();
	~Relation();

};

#endif
