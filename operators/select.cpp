/**
 * =====================================================================================
 *
 *       Filename:  select.cpp
 *
 *    Description:  Implementação do operador select
 *
 *        @version  1.0
 *        Created:  06/04/16 00:10:08
 *       Revision:  none
 *       Compiler:  g++
 *
 *         @author  Victor Silva
 *
 * =====================================================================================
 */
#include "select.h"

bool checkCondition(float a, float b, string op) {
	if (op == "<") {
		return a < b;
	}
	else if (op == "<=") {
		return a <= b;
	}
	else if (op == "==") {
		return a == b;
	}
	else if (op == ">=") {
		return a >= b;
	}
	else if (op == ">") {
		return a > b;
	}
	else {
		return a != b;
	}
}

/**
 * Returns the relation with only the selected tuples following the selection operator
 * operator.op: logic operator (<, <=, ==, >=, >)
 * operator.column: the index of the column to be evaluated
 * operator.value: the value to be compared with the column using the logic operator
 * 
 * @param  relation Relation object
 * @param  op       Operator struct
 * @return          Relation
 */
Relation select(Relation relation, Operator op) {

	for (int i = 0; i < relation.size(); i++) {
		vector<float> tupla = relation.getTupla(i);

		if ( !checkCondition(op.value, tupla[op.column], op.op) ) {
			relation.removeTupla(i);
		}
	}

	return relation;
}

