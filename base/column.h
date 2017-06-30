/*
 * =====================================================================================
 *
 *       Filename:  column.h
 *
 *    Description:  Column with template type
 *
 *        Version:  0.0
 *        Created:  06/20/17 23:36:23
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  @vpcsilva
 *
 * =====================================================================================
 */
#ifndef COLUMN_H
#define COLUMN_H

#include <string>
// #include <map>
#include <vector>
// #include <algorithm>

using namespace std;

template<class T>
class Column {
private:
	T value;

public:
	T getValue() {
		return this->value;
	}
	void setValue(T newValue) {
		this->value = newValue;
	}

	Column(T value) {
		this->value = value;
	}

	Column() { this->value = NULL; }
	~Column() {}
};

#endif
