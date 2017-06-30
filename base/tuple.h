/*
 * =====================================================================================
 *
 *       Filename:  tupla.h
 *
 *    Description:  Implementacao do tipo tupla, que permitirá a utilização de tuplas na gpu
 *
 *        Version:  1.0
 *        Created:  06/06/16 10:13:54
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Victor Silva
 *
 * =====================================================================================
 */
#ifndef TUPLA_H
#define TUPLA_H

#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include "column.h"
#include <boost/any.hpp>
using namespace std;

class Tuple {
private:
	vector<boost::any> columns;
public:
	// Tupla& addColumn(string);
	// void addTupla(vector<float>);
	// void removeTupla(int);
	// int nOfColumns();
	// void setHeaders(vector<string>);
	// void setTuplas(vector< vector<float> >);
	
	// int size();
	// vector<string> getHeaders();
	// vector< vector<float> > getTuplas();
	// string getColumnName(int);
	// vector<float> getTupla(int);

	Tuple(vector<boost::any>);
	Tuple();
	~Tuple();

};

#endif
