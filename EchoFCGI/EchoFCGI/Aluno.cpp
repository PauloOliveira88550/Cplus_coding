#include "Aluno.h"
#include "IOput.h"
#include <exception>
#include <iostream>

using namespace std;

Aluno::Aluno(const int nr, const string name, const estatutos estatuto)
	: number(nr), name(name), s_estatuto(estatuto)
{
	if (!validar_nome(name) || !validar_numero(nr) || !validar_estatuto(estatuto))
		throw exception("Aluno com mal identificado\n");
}


Aluno::~Aluno()
{
}

bool Aluno::validar_nome(const string& nome)
{
	if (nome == "")
		return false;

	 return true;
}

bool Aluno::validar_numero(const int& nr)
{
	if (nr > 99999 || nr < 0)
		return false;

	return true;
}

bool Aluno::validar_estatuto(const estatutos& estatuto)
{
	int i;
	i = (int)estatuto;

	if (i < 0 || i > 5)
		return false;

	return true;
}

bool Aluno::comparar(Aluno& a1)
{
	if (a1.number == number && a1.name == name && a1.s_estatuto ==s_estatuto)
		return true;

	return false;
}

bool Aluno::tem_estatuto()
{
	if (s_estatuto == estatutos::AAC)
		return false;
	if (s_estatuto == estatutos::DAE)
		return false;
	if (s_estatuto == estatutos::DLG)
		return false;
	if (s_estatuto == estatutos::PDef)
		return true;
	if (s_estatuto == estatutos::TE)
		return true;

	return false;
}

bool Aluno::comparar(int number)
{
	if (number == this->number)
		return true;

	return false;
}

ostream& operator<<(ostream& os, Aluno& a1) {
	IOput output;
	os << a1.number << ";" << a1.name << ";" << output.estatuto_to_String(a1.s_estatuto) << endl;
	return os;
}