/*





*/
#include <iostream>
#include "Semprarrolar.h"

using namespace std;
Empresa semprarrolar("Semprarrolar", "Input_Condutores.txt", "Input_Linhas.txt");
int hora_inicial = 7;  //vari�veis globais para todos os .cpp
int hora_final = 19;   //Definem a hora inicial de trabalho de todas as linha e a hora em que encerram

int menu_principal()
{
	clearScreen();
	int op;
	do {
		cout << "+--------------+" << endl;
		cout << "| SEMPRARROLAR |" << endl;
		cout << "+--------------+" << endl << endl;
		cout << "Bem-vindo ao gerenciador de linhas e condutores da SEMPRARROLAR" << endl;
		cout << "Com este programa ser� capaz de vizualizar e modificar a informa��o desta base de dados como bem entender" << endl << endl;
		cout << "+-------------------------------------- +" << endl;
		cout << "| Menu Principal                        |" << endl;
		cout << "+-------------------------------------- +" << endl;
		cout << "| Selecione uma das seguintes op��es :  |" << endl;
		cout << "+-------------------------------------- +" << endl;
		cout << "| 1. Gerir linhas                       |" << endl;
		cout << "| 2. Gerir condutores                   |" << endl;
		cout << "| 3. Vizualizar os hor�rios             |" << endl;
		cout << "| 4. Trabalho do condutor               |" << endl;
		cout << "| 5. Procurar paragem                   |" << endl;
		cout << "| 6. Calcular trajeto                   |" << endl;
		cout << "| 0. Sair                               |" << endl;
		cout << "+-------------------------------------- +" << endl << endl;
		cout << "Op��o: ";
		cin >> op;
		switch (op)
		{
		case 1:
			linhas_menu();
			break;
		case 2:
			condutores_menu();
			break;
		case 3:
			horarios_menu();
			break;
		case 4:
			//menu_trabalho();
			break;
		case 5:
			//procurar_paragem();
			break;
		case 6:
			//calcula_trajeto();
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

int main()
{
	SetPTchar();
	menu_principal();
	cin.get();
	return 0;
}
