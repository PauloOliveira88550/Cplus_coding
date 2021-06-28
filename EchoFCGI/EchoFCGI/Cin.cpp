#include "Cin.h"

bool Cin::ler_alunos(int number, string name, string estatuto,Alunos& Alunos) {
	
	bool inserido = false;
	estatutos s_estatuto = string_to_estatuto(estatuto);

	Aluno* Aluno_temp = new Aluno(number, name, s_estatuto);
	if (!(Aluno_temp == NULL)) {
		inserido = Alunos.inserir(*Aluno_temp);
	}
	delete Aluno_temp;

	return inserido;
}

bool Cin::ler_marcacoes(int number,string name, vector<string> preferencia, size_t nr_turnos, Marcacoes& Marcacoes, Alunos& Alunos)
{
	bool inscrito = false;
	vector<PLx> preferencias;
	Data hora_de_inscricao;

	set_data_atual(hora_de_inscricao);

	for (size_t i = 0; i < nr_turnos ; i++) {
		preferencias.push_back(string_to_PLx(preferencia[i]));
	}
	try {
		Marcacao* Marcacao_temp = new Marcacao(number, name, preferencias, hora_de_inscricao);
		if (!(Marcacao_temp == NULL))
			inscrito = Marcacoes.inserir(*Marcacao_temp, Alunos);
		delete Marcacao_temp;
	}
	catch (exception& exc) {
		cerr << exc.what() << endl;
	}
	return inscrito;
}