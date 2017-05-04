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

class shift { //class com a informação relativa a um turno
private:
	unsigned int idLinha;
	unsigned int idCondutor;
	unsigned int nBus;
	unsigned int inicio;
	unsigned fim;
public:
	//Funções que devolvem os parametros da classe
	unsigned int getLinha();
	unsigned int getCondutor();
	unsigned int getBus();
	unsigned int getInicio();
	unsigned int getFim();
	//Funções que modificam os parâmetros da classe
	void setLinhaID(unsigned int idLinha);
	void setCondutorID(unsigned int idCondutor);
	void setBus(unsigned int nBus);
	void setInicio(unsigned int inicio);
	void setFim(unsigned int fim);
};

class class_linha {        //class com a informação relativa a uma linha
private:
	unsigned int ID;
	unsigned int freq;
	vector<string> paragens;
	vector<unsigned int> tempos;
public:
	//Funções get
	unsigned int getID();
	unsigned int getFreq();
	vector<string> getParagens();
	vector<unsigned int> getTempos();
	//Funções set
	void setLinha(unsigned int ID, unsigned int freq, vector<string> paragens, vector<unsigned int> tempos);
};

class class_condutor {       //class com a informação relativa a um condutor
private:
	unsigned int ID;
	string nome;
	unsigned int turno;
	unsigned int max;
	unsigned int descanso;
	vector <shift> shifts;
public:
	//Funções get
	unsigned int getID();
	string getNome();
	unsigned int getTurno();
	unsigned int getMax();
	unsigned int getDescanso();
	vector <shift> getShifts();
	//Funções set
	void setCondutor(unsigned int ID, string nome, unsigned int turno, unsigned int max, unsigned int descanso);
};

class bus {//class com a informação de todos os turnos de um autocarro
private:
	unsigned int nBus;
	unsigned int idCondutor;
	unsigned int idLinha;
	vector <shift> schedule;
public:
	bus(unsigned int nBus, unsigned int idCondutor, unsigned int idLinha);
	vector <shift> getSchedule();
	unsigned int getCondutorID() const;
	unsigned int getLinhaID() const;
};

class Empresa {
private:
	string nome_empresa;
	vector<class_condutor> vector_condutores;
	vector<class_linha> vector_linhas;
public:
	Empresa(string nome, string fichCondutores, string fichLinhas); //Não percebi bem, vê se consegues tu
	// metodos get
	string getNome();
	// metodos set
	void setLinhas(vector <class_linha> vector_linhas);
	void setCondutores(vector <class_condutor> vector_condutores);
	// outros metodos
	void distribuiServico(); // funcao que implementa a afectacao de servico(incompleta)
};

extern Empresa semprarrolar;
extern int hora_inicial;
extern int hora_final;

int linhas_menu();
int condutores_menu();
vector<class_linha> ler_linhas(string lines_filename);
vector<class_condutor> ler_condutores(string drivers_filename);