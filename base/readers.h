/*
 * =====================================================================================
 *
 *       Filename:  readers.h
 *
 *    Description:  Este arquivo contem os cabeçalhos de classes e funcoes dos leitores
 *
 *        Version:  1.0
 *        Created:  05/26/16 12:09:02
 *       Revision:  none
 *       Compiler:  g++ C98
 *
 *         Author:  Victor Silva
 *
 * =====================================================================================
 */
#ifndef READERS_H
#define READERS_H

#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include "util.h"
// #include <stdio>

using namespace std;

/*-------- Methods --------*/
vector< vector<string> > lerAlunos();
vector< vector<string> > lerCursos();
vector< vector<string> > lerDisciplinas();
vector< vector<string> > lerDisciplinaHistorico();
vector< vector<string> > lerDadosITBI();
vector< vector<string> > lerFacialAffirmative();
vector< vector<string> > readCsv(string);

#endif
