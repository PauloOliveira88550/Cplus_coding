#include "Alunos.h"
#include "Aluno.h"
#include <fstream>
#include <sstream>

Alunos::Alunos()
{
}

Alunos::~Alunos()
{
}

bool Alunos::inserir(Aluno& Aluno_temp)
{
	if (existe(Aluno_temp))
		return false;

	Lista_alunos.push_back(Aluno_temp);
	return true;
}

bool Alunos::existe(Aluno& Aluno_temp)
{
	bool presente = false;

	list<Aluno>::iterator  it;

	for (it = Lista_alunos.begin(); it != Lista_alunos.end(); it++) {
		if (Aluno_temp.comparar(*it)) {
			presente = true;
			break;
		}
	}

	return presente;
}

bool Alunos::existe(int number)
{
	bool presente = false;

	list<Aluno>::iterator  it;
	for (it = Lista_alunos.begin(); it != Lista_alunos.end(); it++) {
		if (it->comparar(number)) {
			presente = true;
			break;
		}
	}
	return presente;
}

bool Alunos::apagar(Aluno& a1) {
	
	bool apagado = false;
	list<Aluno>::iterator  it;

	for (it = Lista_alunos.begin(); it != Lista_alunos.end(); it++) {
		if (a1.comparar(*it)) {
			Lista_alunos.erase(it);
			apagado = true;
			break;
		}
	}
	return apagado;
}

string Alunos::print(int number) {
	list<Aluno>::iterator  it;
	
	stringstream aluno;

	for (it = Lista_alunos.begin(); it != Lista_alunos.end(); it++) {
		if(it->comparar(number))
			aluno << *it;
	}

	return aluno.str();
}

bool Alunos::tem_estatuto(int number)
{
	list<Aluno>::iterator  it;
	for (it = Lista_alunos.begin(); it != Lista_alunos.end(); it++) {
		if (it->comparar(number)) {
			return it->tem_estatuto();
		}
	}
	return false;
}

bool Alunos::inserir_no_turno(Turnos& Turnos, int preferencia, int number)
{
	list<Aluno>::iterator  it;
	for (it = Lista_alunos.begin(); it != Lista_alunos.end(); it++) {
		if (it->comparar(number)) {
			return Turnos.inserir_no_turno(*it, preferencia);
		}
	}
	return false;
}

bool Alunos::limpar() {

	ofstream output_alunos_inscritos;
	output_alunos_inscritos.open("Ficheiros_output/InscritosValidos.csv");
	output_alunos_inscritos.close();

	Lista_alunos.clear();
	return true;
}

size_t Alunos::nr_alunos() {
	return Lista_alunos.size();
}

void Alunos::print_fich() {
	
	ofstream output_alunos_inscritos;
	output_alunos_inscritos.open("Ficheiros_output/InscritosValidos.csv");

	list<Aluno>::iterator  it;
	for (it = Lista_alunos.begin(); it != Lista_alunos.end(); it++) {
		output_alunos_inscritos << *it;
	}

	output_alunos_inscritos.close();
}