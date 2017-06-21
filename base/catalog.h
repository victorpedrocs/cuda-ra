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
#include <stdlib.h>
#include "relation.h"
#include "readers.h"

using namespace std;

Relation prepararITBI();
Relation prepararITBI(int);
Relation prepararFacialAffirmative();
Relation prepararFacialAffirmative(int);

class Catalogo {
private:
	Relation itbi;
	Relation facialAffirmative;
	bool isFacialInitialized;
	bool isItbiInitialized;
	int relationSize;

	void initializeFields();
public:
	
	Relation getIBTIRelation();
	Relation getFacialRelation();
	
	Catalogo();
	Catalogo(int);
	~Catalogo();

};


#endif
