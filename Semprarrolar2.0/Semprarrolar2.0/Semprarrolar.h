#include <vector>
#include <string>

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
	unsigned int getID();
	unsigned int getFreq();
	vector<string> getParagens();
	vector<unsigned int> getTempos();
};

class class_condutor {       //class com a informação relativa a um condutor
private:
	unsigned int ID;
	string nome;
	unsigned int turno;
	unsigned int max;
	unsigned int descanso;
public:
	unsigned int getID();
	string getNome();
	unsigned int getTurno();
	unsigned int getMax();
	unsigned int getDescanso();
};

class shift { //class com a informação relativa a um turno
private:
	unsigned int idLinha;
	unsigned int idCondutor;
	unsigned int nBus;
	unsigned int inicio;
	unsigned fim;
public: 
	unsigned int getLinha();
	unsigned int getCondutor();
	unsigned int getBus();
	unsigned int getInicio();
	unsigned int getFim();
};

class bus {//class com a informação de todos os turnos de um autocarro
private:
	vector <shift> schedule;
public:
	vector <shift> getSchedule();
};

class driver {//class com todos os turnos de um condutor
private:
	vector <shift> shifts;
public:
	vector <shift> getshifts();
};

extern vector <class_linha> vector_linhas;
extern vector <class_condutor> vector_condutores;

int linhas_menu();
int condutores_menu();