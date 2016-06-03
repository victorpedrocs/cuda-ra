/*
 * =====================================================================================
 *
 *       Filename:  readers.cpp
 *
 *    Description:  Arquivo com a implementação dos leitores
 *
 *        Version:  1.0
 *        Created:  05/26/16 12:10:16
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Victor Silva
 *
 * =====================================================================================
 */
#include "readers.h"
#include "util.h"

vector< vector<string> > lerAlunos() {
	const string filePath = "data/Alunos.txt";
	vector< vector<string> > alunos;
	alunos.clear();

	ifstream file(filePath.data());

	if(file) {
		for( string line; getline(file, line) ;) {
			vector<string> fields = splitString(line, '	');
			alunos.push_back(fields);
		}
	}

	return alunos;
}

vector< vector<string> > lerCursos() {
	const string filePath = "data/Cursos.txt";
	vector< vector<string> > cursos;
	cursos.clear();

	ifstream file(filePath.data());

	if(file) {
		for( string line; getline(file, line) ;) {
			vector<string> fields = splitString(line, '	');
			cursos.push_back(fields);
		}
	}

	return cursos;
}

vector< vector<string> > lerDisciplinas() {
	const string filePath = "data/Disciplinas.txt";
	vector< vector<string> > disciplinas;
	disciplinas.clear();

	ifstream file(filePath.data());

	if(file) {
		for( string line; getline(file, line) ;) {
			vector<string> fields = splitString(line, '	');
			disciplinas.push_back(fields);
		}
	}

	return disciplinas;
}
vector< vector<string> > lerDisciplinaHistorico() {
	const string filePath = "data/DisciplinaHistorico.txt";
	vector< vector<string> > disciplinaHistorico;
	disciplinaHistorico.clear();

	ifstream file(filePath.data());

	if(file) {
		for( string line; getline(file, line) ;) {
			vector<string> fields = splitString(line, '	');
			disciplinaHistorico.push_back(fields);
		}
	}

	return disciplinaHistorico;
}

vector< vector<string> > lerDadosITBI() {
	const string filePath = "data/itbi_guia_nao_isenta_total_.csv";
	vector< vector<string> > itbi;
	itbi.clear();

	ifstream file(filePath.data());

	if(file) {
		for( string line; getline(file, line) ;) {
			vector<string> fields = splitString(line, ',');
			itbi.push_back(fields);
		}
	}

	return itbi;
}