/*
 * =====================================================================================
 *
 *       Filename:  join.cpp
 *
 *    Description:  Implementation of the join operator
 *
 *        Version:  1.0
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  @vpcsilva
 *
 * =====================================================================================
 */
#include "join.h"

Relation  natural(	Relation relA, 
					Relation relB, 
					string relAColumnName, 
					string relBColumnName)
{
	Relation result(relA.getName() + relB.getName());
	result.addColumns(relA.getHeaders(), relA.getColTypes());
	result.addColumns(relB.getHeaders(), relB.getColTypes());


	for(int i = 0; i < relA.size(); i++){
		vector<boost::any> tuple(relA.getHeaders().size() 
								+ relB.getHeaders().size());
		int keyIndexA = relA.getColumnIndexByName(relAColumnName);
		boost::any key = relA.getTuple(i)[keyIndexA];
		for(int j = 0; j < relB.size(); j++) {
			int keyIndexB = relB.getColumnIndexByName(relBColumnName);
			if(Relation::compareColumns(key, relB.getTuple(j)[keyIndexB]) == 0 ) {
				set_union(relA.getTuple(i).begin(), relA.getTuple(i).end(), relB.getTuple(j).begin(), relB.getTuple(j).end(), tuple.begin());
				result.addTuple(tuple);
			}
		}
	}

	return result;

}