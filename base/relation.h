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
#include <iostream>
#include <algorithm>
#include <boost/any.hpp>


using namespace std;

class Relation {
public:
	enum ColType { INT, FLOAT, STRING };
	
	Relation& addColumn(string, string);
	Relation& addColumn(string);
	Relation& addColumn();

	void addColumns(vector<string>, vector<ColType>);

	void addTupla(vector<float>);
	void addTuple(vector<string>);
	void addTuple(vector<boost::any>);

	vector<boost::any> getTuple(int);
	vector< vector<float> > getTuplas();
	vector<float> getTupla(int);

	void removeTupla(int);

	void removeTupleById(int);

	int nOfColumns();
	void setHeaders(vector<string>);
	void setTuplas(vector< vector<float> >);
	
	int size();
	vector<string> getHeaders();
	vector<ColType> getColTypes();
	int getColumnIndexByName(string);
	
	string getColumnName(int);
	string getName();

	static int compareColumns(boost::any a, boost::any b);

	Relation();
	Relation(string);
	~Relation();
private:
	vector<string> colNames;
	vector<ColType> colTypes;
	vector< vector<float> > tuplas;
	vector< vector<boost::any> > tuples;
	string name;

	void build(string);

};

#endif
