#ifndef ALUNOS_H
#define ALUNOS_H
#include "Aluno.h"
#include "Turnos.h"
#include <list>

using namespace std;

class Alunos {
	list<Aluno> Lista_alunos;

public:
	Alunos();
	~Alunos();

	bool inserir(Aluno&);
	bool existe(Aluno&);
	bool existe(int);
	bool apagar(Aluno&);
	string print(int);

	bool tem_estatuto(int);
	bool inserir_no_turno(Turnos&, int, int);
	bool limpar();

	size_t nr_alunos();
	void print_fich();

};
#endif