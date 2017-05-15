/* File   : Semprarrolar2.0
Date   : 2017/04/28
Author : JCM & JAL
Program Purpose:
- Escalonamento de uma empresa de autocarros*/
#include <iostream>
#include "Semprarrolar.h"

using namespace std;
Empresa semprarrolar("Semprarrolar", "Input_Condutores.txt", "Input_Linhas.txt");
unsigned int hora_inicial = 7;  //vari�veis globais para todos os .cpp
unsigned int hora_final = 19;   //Definem a hora inicial de trabalho de todas as linha e a hora em que encerram

void localizar_ficheiros()
{
	clearScreen();
	string lines_filename, drivers_filename;
	cout << "   _____                                               _            " << endl;
	cout << "  / ____|                                             | |           " << endl;
	cout << " | (___   ___ _ __ ___  _ __  _ __ __ _ _ __ _ __ ___ | | __ _ _ __ " << endl;
	cout << "  \\___ \\ / _ \\ '_ ` _ \\| '_ \\| '__/ _` | '__| '__/ _ \\| |/ _` | '__|" << endl;
	cout << "  ____) |  __/ | | | | | |_) | | | (_| | |  | | | (_) | | (_| | |   " << endl;
	cout << " |_____/ \\___|_| |_| |_| .__/|_|  \\__,_|_|  |_|  \\___/|_|\\__,_|_|   " << endl;
	cout << "                       | |                                          " << endl;
	cout << "                       |_|                                          " << endl << endl << endl;
	cout << "Antes de come�ar a usufruir deste software, indique onde pretende guardar a informa��o" << endl;
	cout << "Indique o endere�o e o nome dos ficheiros para guardar a informa��o das linhas e condutores" << endl;
	cout << "Caso esse ficheiro j� possua dados, essa informa��o ser� importada" << endl << endl;
	cout << "Introduza a localiza��o e nome do ficheiro que cont�m a informa��o das linhas";
	cout << endl << "Ficheiro das linhas: ";
	getline(cin, lines_filename);
	cout << "Introduza a localiza��o do ficheiro que cont�m a informa��o dos condutores";
	cout << endl << "Ficheiro dos condutores: ";
	getline(cin, drivers_filename);
	semprarrolar.setFichLines(lines_filename);
	semprarrolar.setFichDrivers(drivers_filename);
}

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
			menu_trabalho();
			break;
		case 5:
			procurar_paragem();
			break;
		case 6:
			calcula_trajeto();
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
		clearScreen();
	} while (true);
}

int main()
{
	SetPTchar();
	//localizar_ficheiros();
	ler_condutores(semprarrolar.getFichDrivers());
	ler_linhas(semprarrolar.getFichLines());
	menu_principal();
	guardar_linhas(semprarrolar.getFichLines());
	guardar_condutores(semprarrolar.getFichDrivers());
	cin.get();
	return 0;
}
