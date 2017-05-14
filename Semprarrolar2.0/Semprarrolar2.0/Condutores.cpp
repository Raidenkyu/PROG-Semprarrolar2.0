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

// mofificar informação (set)-------------------------------------------------------------------------
void class_condutor::setID(unsigned int ID) {
	this->ID = ID;
}

void class_condutor::setNome(string nome) {
	this->nome = nome;
}

void class_condutor::setTurno(unsigned int turno) {
	this->turno = turno;
}

void class_condutor::setMax(unsigned int max) {
	this->max = max;
}

void class_condutor::setDescanso(unsigned int descanso) {
	this->descanso = descanso;
}

void class_condutor::setShifts(vector<shift> shifts) {
	this->shifts = shifts;
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

void cria_condutor()
{
	clearScreen();
	vector<class_condutor> vector_condutores = semprarrolar.getCondutores();
	class_condutor c1;
	string nome;
	int ID,turno,max,descanso;
	char r;
	while (true)
	{
		cout << "Indique o ID do condutor que pretende criar: ";
		cin >> ID;
		if (cin.good())
			break;
		else
		{
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cout << "Erro. Introduziu um valor inválido. Só pode introduzir números inteiros" << endl;
		}
	}
	while (true)
	{
		cout << "Indique o nome do condutor que pretende criar que pretende criar: ";
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		getline(cin, nome);
		if (cin.good())
			break;
		else
		{
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cout << "Erro. Introduziu um valor inválido. Só pode introduzir palavras" << endl;
		}
	}
	while (true)
	{
		cout << "Indique o numero de horas, por cada turno de condutor: ";
		cin >> turno;
		if (cin.good())
			break;
		else
		{
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cout << "Erro. Introduziu um valor inválido. Só pode introduzir números inteiros" << endl;
		}
	}
	while (true)
	{
		cout << "Indique o número máximo de horas de trabalho por semana, de cada condutor: ";
		cin >> max;
		if (cin.good())
			break;
		else
		{
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cout << "Erro. Introduziu um valor inválido. Só pode introduzir números inteiros" << endl;
		}
	}
	while (true)
	{
		cout << "Indique o nome de horas de descanso entre cada turno: ";
		cin >> descanso;
		if (cin.good())
			break;
		else
		{
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cout << "Erro. Introduziu um valor inválido. Só pode introduzir números inteiros" << endl;
		}
	}
	while (true)
	{
		clearScreen();
		c1.setCondutor(ID, nome, turno, max, descanso);
		cout << "Pretende criar o seguinte condutor(S/N):" << endl << endl;
		visualizar_condutor(c1);
		cout << "Confirmar: ";
		cin >> r;
		cout << endl;
		if (r == 'S' || r == 's')
		{
			vector_condutores.push_back(c1);
			semprarrolar.setCondutores(vector_condutores);
			cout << "Condutor criada com sucesso" << endl;
			cout << "Pressione Enter para regressar ao menu condutores" << endl;
			cin.get();
			cin.get();
			clearScreen();
			break;
		}
		else if (r == 'N' || r == 'n')
		{
			cout << "Operação abortada" << endl;
			cout << "Pressione Enter para regressar ao menu condutores" << endl;
			cin.get();
			cin.get();
			clearScreen();
			break;
		}
		else
		{
			cin.clear();
			cin.ignore();
			cout << "Resposta Inválida. Só pode responder S(sim) ou N(não)" << endl;
			cin.get();
			cin.get();
			clearScreen();
		}
	}
}

int menu_modifica_condutores(int i)  // Permite escolher o parâmetro a modificar,
{                         //para o utilizador não ter o trabalho de criar uma condutor nova e substituí-la
	vector<class_condutor> vector_condutores = semprarrolar.getCondutores();
	int turno;
	int max;
	int descanso;
	int param;
	class_condutor c1 = vector_condutores.at(i);
	string nome;
	bool modified = false;
	char r;
	while (true) {
		clearScreen();
		cout << "Condutor: " << endl;
		visualizar_condutor(vector_condutores.at(i));
		cout << endl;
		cout << "+ ----------------------------------------------+" << endl;
		cout << "| Menu Modificar                                |" << endl;
		cout << "+-----------------------------------------------+" << endl;
		cout << "| Selecione o parâmetro que pretende modificar: |" << endl;
		cout << "+-----------------------------------------------+" << endl;
		cout << "| 1. Nome do condutor                           |" << endl;
		cout << "| 2. Número de horas por turno                  |" << endl;
		cout << "| 3. Máximo de horas de trabalho por semana     |" << endl;
		cout << "| 4. Número de horas de descanso entre turnos   |" << endl;
		cout << "| 0. Sair                                       |" << endl;
		cout << "+-----------------------------------------------+" << endl;
		cout << "Opção: ";
		cin >> param;
		switch (param) {
		case 1:
			cout << "Atualize o nome do condutor: ";
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			getline(cin, nome);
			c1.setNome(nome);
			modified = true;
			break;
		case 2:
			cout << "Atualize o número de horas de cada turno, deste condutore: ";
			cin >> turno;
			c1.setTurno(turno);
			modified = true;
			break;
		case 3:
			cout << "Atualize o número máximo de horas por semana: ";
			cin >> max;
			c1.setMax(max);
			modified = true;
			break;
		case 4:
			cout << "Atualize o número de horas de descanso entre cada turno:";
			cin >> descanso;
			c1.setDescanso(descanso);
			modified = true;
			break;
		case 0:
			clearScreen();
			return 0;
		default:
			cout << "Essa opção não existe. Tente outra vez" << endl;
			clearScreen();
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
		if (modified)
		{
			while (true)
			{
				clearScreen();
				cout << "Pretende guardar a seguinte condutorS/N):" << endl << endl;
				visualizar_condutor(c1);
				cout << "Confirmar: ";
				cin >> r;
				cout << endl;
				if (r == 'S' || r == 's')
				{
					vector_condutores.at(i) = c1;
					semprarrolar.setCondutores(vector_condutores);
					cout << "Linha modificada com sucesso" << endl;
					cout << "Pressione Enter para regressar ao menu linhas" << endl;
					cin.get();
					cin.get();
					clearScreen();
					return 0;
				}
				else if (r == 'N' || r == 'n')
				{
					cout << "Operação abortada" << endl;
					cout << "Pressione Enter para regressar ao menu linhas" << endl;
					cin.get();
					cin.get();
					clearScreen();
					return 0;
				}
				else
				{
					cin.clear();
					cin.ignore();
					cout << "Resposta Inválida. Só pode responder S(sim) ou N(não)" << endl;
					cin.get();
					cin.get();
					clearScreen();
				}
			}
		}
	}
}

int modifica_condutor()
{
	clearScreen();
	vector <class_condutor> vector_condutores = semprarrolar.getCondutores();
	int ID;
	bool exist = false; // variavel que representa a existencia da condutores que se pretende criar
	cout << "Para regressar faça 0 e pressione Enter" << endl;
	cout << "Condutores existentes: " << endl;
	for (unsigned int i = 0; i < vector_condutores.size(); i++)
	{
		visualizar_condutor(vector_condutores.at(i));
	}
	while (true)
	{
		cout << "Indique o ID do condutor que pretende modificar: ";
		cin >> ID;
		if (cin.good())
			break;
		else
		{
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cout << "Erro. Introduziu um valor inválido. Só pode introduzir números inteiros" << endl;
		}
	}
	if (ID == 0)
		return 0;
	for (unsigned int i = 0; i < vector_condutores.size(); i++)
	{
		if (vector_condutores.at(i).getID() == ID)
		{
			exist = true;
			menu_modifica_condutores(i);
		}
	}
	if (!exist)
		cout << "Essa linha não existe tem que criar uma primeiro" << endl;
	cout << "Presione Enter para regressar ao menu condutores" << endl;
	cin.get();
	cin.get();
	return 0;
}

void elimina_condutor()
{
	clearScreen();
	int ID;
	vector<class_condutor> vector_condutores;
	do {
		cout << "Indique o ID do condutor que pretende eliminar: ";
		cin >> ID;
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
	} while (cin.good());
	for (unsigned int i = 0; i < vector_condutores.size(); i++)
	{
		if (vector_condutores.at(i).getID() == ID)
		{
			vector_condutores.erase(vector_condutores.begin() + i);
			semprarrolar.setCondutores(vector_condutores);
			cout << "Linha eliminada com sucesso" << endl;
		}
	}
	cout << "Pressione uma tecla para contiuar" << endl;
	cin.get();
	cin.get();
}

void guardar_condutores(string drivers_filename)
{
	vector<class_condutor> vector_condutores = semprarrolar.getCondutores();
	ofstream drivers_file(drivers_filename);
	for (unsigned int i = 0; i < vector_condutores.size(); i++)
	{
		drivers_file << vector_condutores.at(i).getID() << " ; " << vector_condutores.at(i).getNome() << " ; " << vector_condutores.at(i).getTurno() << " ; " << vector_condutores.at(i).getMax() << " ; " << vector_condutores.at(i).getDescanso();
		if (i != vector_condutores.size() - 1)
			drivers_file << endl;
	}

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
			cria_condutor();
			break;
		case 2:
			modifica_condutor();
			break;
		case 3:
			elimina_condutor();
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