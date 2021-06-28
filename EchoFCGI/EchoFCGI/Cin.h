#pragma once
#ifndef CIN_H
#define CIN_H

#include "IOput.h"

using namespace std;

class Cin : IOput {

public:
	Cin() {};
	~Cin() {};

	bool ler_alunos(int number, string name, string estatuto,Alunos&);
	bool ler_marcacoes(int,string,vector<string>,size_t,Marcacoes&,Alunos&);

};

#endif // CIN_H