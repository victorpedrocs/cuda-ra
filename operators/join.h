/*
 * =====================================================================================
 *
 *       Filename:  join.h
 *
 *    Description:  Header file for the join operator
 *
 *        Version:  1.0
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  @vpcsilva
 *
 * =====================================================================================
 */

#ifndef JOIN_H
#define JOIN_H

#include <string>
#include <vector>
#include <iostream>
#include <boost/any.hpp>
#include <algorithm>
#include "../base/relation.h"

using namespace std;

Relation natural(Relation, Relation, string, string);

#endif
