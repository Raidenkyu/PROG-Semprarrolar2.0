#include <vector>
#include <string>
#include <iostream>

#ifdef _WIN32         //Para o windows reconhecer os caracteres portugueses
#include <windows.h>
#define SetPTchar() SetConsoleCP(1252); SetConsoleOutputCP(1252);
#else 
#define SetPTchar() void
#endif

#ifdef _WIN32 //Para limpar o ecrã quer seja em Windows, quer seja em linux
#define clearScreen() system("cls"); 
#else
#define clearScreen() system("clear");
#endif

using namespace std;

#pragma once

class class_linha {        //class com a informação relativa a uma linha
private:
	unsigned int ID;
	unsigned int freq;
	vector<string> paragens;
	vector<unsigned int> tempos;
public:
	getID(class_linha l1);
};

class class_condutor {       //class com a informação relativa a um condutor
private:
	int ID;
	string nome;
	int turno;
	int max;
	int descanso;
};

class shift { //class com a informação relativa a um turno
private:
	unsigned int idLinha;
	unsigned int idCondutor;
	unsigned int nBus;
	unsigned int inicio;
	unsigned fim;
};

class Bus {//class com a informação de todos os turnos de um autocarro
private:
	vector <shift> schedule;
};

class Driver {//class com todos os turnos de um condutor
private:
	vector <shift> shifts;
};