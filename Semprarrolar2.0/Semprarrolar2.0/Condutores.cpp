#include <iostream>
#include "Semprarrolar.h"
#include <fstream>
#include <sstream>

using namespace std;

// Obter informação (get)------------------------------------------------------------------------------
unsigned int class_condutor::getID()
{
	return this->ID;
}
string class_condutor::getNome()
{
	return this->nome;
}
unsigned int class_condutor::getTurno()
{
	return this->turno;
}
unsigned int class_condutor::getMax()
{
	return this->max;
}
unsigned int class_condutor::getDescanso()
{
	return this->descanso;
}
vector <shift> class_condutor::getShifts() {
	return this->shifts;
}
//----------------------------------------------------------------------------------------------------
// Definir condutor
void class_condutor::setCondutor(unsigned int ID, string nome, unsigned int turno, unsigned int max, unsigned int descanso)
{
	this->ID = ID;
	this->nome = nome;
	this->turno = turno;
	this->max = max;
	this->descanso = descanso;
}

// Passar inf do ficheiro todo para classes. Devolve um vector de classes de condutores
vector<class_condutor> ler_condutores(string drivers_filename)
{
	ifstream drivers_file(drivers_filename);
	char comma;
	unsigned int ID, turno, max, descanso;
	string line;
	string nome;
	string sturno;
	string smax;
	string sdescanso;
	stringstream ss1;
	vector<class_condutor> vector_condutores;
	class_condutor c1;
	if (drivers_file.is_open())
	{
		while (getline(drivers_file, line))
		{
			ss1.str(line);
			ss1 >> ID >> comma;
			getline(ss1, nome, ';');
			nome = nome.substr(nome.find_first_not_of(' '), nome.find_last_not_of(' '));
			getline(ss1, sturno, ';');
			turno = stoi(sturno);
			getline(ss1, smax, ';');
			max = stoi(smax);
			getline(ss1, sdescanso);
			descanso = stoi(sdescanso);
			c1.setCondutor(ID, nome, turno, max, descanso);
			vector_condutores.push_back(c1);
			ss1.clear();
		}
	}
	else
	{
		clearScreen();
		cout << "Erro. Não foi possível abrir o ficheiro dos condutores" << endl;
		cout << "Pressione Enter para continuar" << endl;
		cin.get();
	}
	return vector_condutores;
}
// Imprimir condutor mandando uma class de condutor
void visualizar_condutor(class_condutor c1)
{
	cout << c1.getID() << " ; " << c1.getNome() << " ; " << c1.getTurno() << " ; " << c1.getMax() << " ; " << c1.getDescanso() << endl;
}
// Menu condutores
int condutores_menu()
{
	do {
		int op;
		clearScreen();
		cout << "+-------------------------------------- +" << endl;
		cout << "| Menu Condutores                       |" << endl;
		cout << "+-------------------------------------- +" << endl;
		cout << "| Selecione uma das seguintes opções :  |" << endl;
		cout << "+-------------------------------------- +" << endl;
		cout << "| 1. Criar condutor                     |" << endl;
		cout << "| 2. Ver e modificar condutores         |" << endl;
		cout << "| 3. Remover condutor                   |" << endl;
		cout << "| 0. Regressar ao menu principal        |" << endl;
		cout << "+-------------------------------------- +" << endl;
		cout << endl;
		cout << "Opção: ";
		cin >> op;
		switch (op)
		{
		case 1:
			//cria_condutor();
			break;
		case 2:
			//modifica_condutor();
			break;
		case 3:
			//elimina_condutor();
			break;
		case 0:
			clearScreen();
			cout << "O programa vai encerrar." << endl;
			cout << "Pressione Enter para fechar" << endl;
			cin.get();
			clearScreen();
			return 0;
		}
		if (cin.fail())
		{
			clearScreen();
			cout << "Erro. Opção inválida. Escolha só uma das opções listadas." << endl;
			cout << "Pressione Enter para continuar" << endl;
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cin.get();
			clearScreen();
		}
	} while (true);
}