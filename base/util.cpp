/*
 * =====================================================================================
 *
 *       Filename:  util.cpp
 *
 *    Description:  Arquivo com os imports e funções auxiliares
 *
 *        Version:  1.0
 *        Created:  05/22/16 12:43:04
 *       Revision:  none
 *       Compiler:  g++ C98
 *
 *         Author:  Victor Pedro
 *
 * =====================================================================================
 */
#include "util.h"

/*-------- CONSTANTS --------*/
 const int Constants::ALUNOS_COLS = 4;
 const int Constants::CURSOS_COLS = 2;
 const int Constants::DISCIPLINA_HIST_COLS = 7;
 const int Constants::DISCIPLINAS_COLS = 3;


vector<string> splitString( string text, char delim ) {
	string buf = "";
	vector<string> array;

	for(int i = 0; i < text.length(); i++) {
		if ( text[i] != delim ) {
			buf += text[i];
		}
		else {
			array.push_back(buf);
			buf = "";
		}
	}
	if ( !buf.empty() ) {
		array.push_back(buf);
	}
    return array;
}

// bool cotains(Relation relation, Tupla tupla) {
// 	// TODO
// }