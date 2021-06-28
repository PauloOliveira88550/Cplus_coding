#ifndef ALUNO_H
#define ALUNO_H
#include <string>
#include <exception>

enum class estatutos { INV = -1, SE , DLG, AAC, TE, PDef, DAE };

using namespace std;

class Aluno {
	int number;
	string name;
	estatutos s_estatuto;
public:
	Aluno(const int, const string, const estatutos);
	~Aluno();

	friend ostream& operator<<(ostream& os, Aluno& m1);

	bool validar_nome(const string&);
	bool validar_numero(const int&);
	bool validar_estatuto(const estatutos&);
	bool comparar(Aluno&);
	bool comparar(int);
	bool tem_estatuto();
	
};
#endif //ALUNO_H