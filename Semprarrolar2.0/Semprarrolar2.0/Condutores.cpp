#include <iostream>
#include "Semprarrolar.h"

using namespace std;

vector <class_condutor> vector_condutores;

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