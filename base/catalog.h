/*
 * =====================================================================================
 *
 *       Filename:  catalogo.h
 *
 *    Description:  Arquivo de definicao do catalogo, que contem os dados dos arquivos
 *
 *        Version:  1.0
 *        Created:  05/25/16 09:14:42
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Victor Silva
 *
 * =====================================================================================
 */
#ifndef CATALOGO_H
#define CATALOGO_H

#include <string>
#include <vector>
#include <iostream>
#include <stdlib.h>
#include "relation.h"
#include "readers.h"

using namespace std;

Relation prepararITBI();

class Catalogo {
private:
	Relation itbi;
public:
	
	Relation getIBTIRelation();
	
	Catalogo();
	~Catalogo();

};


#endif
