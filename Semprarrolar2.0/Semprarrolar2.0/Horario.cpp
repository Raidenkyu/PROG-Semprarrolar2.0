#include <iostream>
#include "Semprarrolar.h"

using namespace std;
// inicio 7 acaba 19
void horario_paragem()
{
	clearScreen();
	string paragemlida;
	cin.ignore(INT_MAX, '\n');
	cout << "Qual a paragem que quer ver o hor�rio? ";
	getline(cin, paragemlida);

}

int horarios_menu()
{
	int op;
	do {
		clearScreen();
		cout << "+-------------------------------------- +" << endl;
		cout << "| Menu Hor�rio                          |" << endl;
		cout << "+-------------------------------------- +" << endl;
		cout << "| Selecione uma das seguintes op��es :  |" << endl;
		cout << "+-------------------------------------- +" << endl;
		cout << "| 1. Horario de uma paragem             |" << endl;
		cout << "| 0. Sair                               |" << endl;
		cout << "+-------------------------------------- +" << endl << endl;
		cout << "Op��o: ";
		cin >> op;
		switch (op)
		{
		case 1:
			horario_paragem();
			break;
		case 0:
			clearScreen();
			cout << "O programa vai encerrar." << endl;
			cout << "Pressione Enter para fechar" << endl;
			return 0;
		}

		if (cin.fail())
		{
			clearScreen();
			cout << "Erro. Op��o inv�lida. Escolha s� uma das op��es listadas." << endl;
			cout << "Pressione Enter para continuar" << endl;
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cin.get();
			clearScreen();
		}

	} while (true);
}