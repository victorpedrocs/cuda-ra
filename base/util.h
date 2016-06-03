/*
 * =====================================================================================
 *
 *       Filename:  headers.h
 *
 *    Description:  Imports e cabeçalhos de função
 *
 *        Version:  1.0
 *        Created:  05/22/16 13:02:05
 *       Revision:  none
 *       Compiler:  g++ C98
 *
 *         Author:  Victor Pedro
 *
 * =====================================================================================
 */

#ifndef UTIL_H
#define UTIL_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*-------- METHODS --------*/
vector<string> splitString(string, char);

/*-------- CONSTANTS --------*/
struct Constants {
	static const int ALUNOS_COLS;
	static const int CURSOS_COLS;
	static const int DISCIPLINAS_COLS;
	static const int ELEMENTOS_COLS;
	static const int DISCIPLINA_HIST_COLS;
};

#endif