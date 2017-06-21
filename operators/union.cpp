/*
 * =====================================================================================
 *
 *       Filename:  union.cpp
 *
 *    Description:  Implementation of the Uion relational operator
 *
 *        Version:  1.0
 *        Created:  06/14/17 19:50:14
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  @vpcsilva
 *
 * =====================================================================================
 */
#include "union.h"


Relation unionOp(Relation relationA, Relation relationB) {
	vector<float> dest;
	Relation result;

	set_union(relationA.getTuplas().begin(),
				relationA.getTuplas().end(),
				relationB.getTuplas().begin(),
				relationB.getTuplas().end(),
				back_inserter(dist) );

	result.set
}