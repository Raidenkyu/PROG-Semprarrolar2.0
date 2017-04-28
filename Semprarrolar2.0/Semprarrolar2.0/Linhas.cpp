#include <iostream>
#include "Semprarrolar.h"

using namespace std;

vector <class_linha> vector_linhas;

unsigned int class_linha::getID()
{
	return this->ID;
}

unsigned int class_linha::getFreq()
{
	return this->freq;
}

vector<string> class_linha::getParagens()
{
	return this->paragens;
}

vector<unsigned int> class_linha::getTempos()
{
	return this->tempos;
}

int linhas_menu() //Mini-interface que permite ao utilizador escolher a função que pretende
{
	do {
		int op;
		clearScreen();
		cout << "+-------------------------------------- +" << endl;
		cout << "| Menu Linhas                           |" << endl;
		cout << "+-------------------------------------- +" << endl;
		cout << "| Selecione uma das seguintes opções :  |" << endl;
		cout << "+-------------------------------------- +" << endl;
		cout << "| 1. Criar linha                        |" << endl;
		cout << "| 2. Ver e modificar linha              |" << endl;
		cout << "| 3. Remover linha                      |" << endl;
		cout << "| 0. Regressar ao menu principal        |" << endl;
		cout << "+-------------------------------------- +" << endl;
		cout << endl;
		cout << "Opção: ";
		cin >> op;
		switch (op)
		{
		case 1:
			//cria_linha();
			break;
		case 2:
			//modifica_linha();
			break;
		case 3:
			//elimina_linha();
			break;
		case 4:
			break;
		case 5:
			break;
		case 0:
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