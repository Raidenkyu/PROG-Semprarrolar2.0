#include <iostream>
#include "Semprarrolar.h"

using namespace std;
// inicio 7 acaba 19
void horario_paragem()
{
	clearScreen();
	string paragemlida;
	cin.ignore(INT_MAX, '\n');
	cout << "Qual a paragem que quer ver o horário? ";
	getline(cin, paragemlida);

}

int horarios_menu()
{
	int op;
	do {
		clearScreen();
		cout << "+-------------------------------------- +" << endl;
		cout << "| Menu Horário                          |" << endl;
		cout << "+-------------------------------------- +" << endl;
		cout << "| Selecione uma das seguintes opções :  |" << endl;
		cout << "+-------------------------------------- +" << endl;
		cout << "| 1. Horario de uma paragem             |" << endl;
		cout << "| 0. Sair                               |" << endl;
		cout << "+-------------------------------------- +" << endl << endl;
		cout << "Opção: ";
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
			cout << "Erro. Opção inválida. Escolha só uma das opções listadas." << endl;
			cout << "Pressione Enter para continuar" << endl;
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cin.get();
			clearScreen();
		}

	} while (true);
}