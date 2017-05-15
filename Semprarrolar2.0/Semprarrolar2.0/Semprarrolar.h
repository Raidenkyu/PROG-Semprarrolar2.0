#include <vector>
#include <string>

#ifdef _WIN32         //Para o windows reconhecer os caracteres portugueses
#include <windows.h>
#define SetPTchar() SetConsoleCP(1252); SetConsoleOutputCP(1252);
#else 
#define SetPTchar() void
#endif

#ifdef _WIN32 //Para limpar o ecr� quer seja em Windows, quer seja em linux
#define clearScreen() system("cls"); 
#else
#define clearScreen() system("clear");
#endif

using namespace std;

#pragma once
//class com a informa��o relativa a um turno
class shift { 
private:
	unsigned int idLinha;
	unsigned int idCondutor;
	unsigned int nBus;
	unsigned int inicio;
	unsigned fim;
public:
	//Fun��es que devolvem os parametros da classe
	unsigned int getLinha();
	unsigned int getCondutor();
	unsigned int getBus();
	unsigned int getInicio();
	unsigned int getFim();
	//Fun��es que modificam os par�metros da classe
	void setLinhaID(unsigned int idLinha);
	void setCondutorID(unsigned int idCondutor);
	void setBus(unsigned int nBus);
	void setInicio(unsigned int inicio);
	void setFim(unsigned int fim);
};

//class com a informa��o de todos os turnos de um autocarro
class bus {
private:
	unsigned int nBus;
	unsigned int idCondutor;
	unsigned int idLinha;
	vector <shift> schedule;
public:
	//Fun��es get
	bus(unsigned int nBus, unsigned int idCondutor, unsigned int idLinha);
	vector <shift> getSchedule();
	unsigned int getCondutorID() const;
	unsigned int getLinhaID() const;
	unsigned int getBus() const;
	//Fun��es set
	void setSchedule(vector<shift> schedule);
};

//class com a informa��o relativa a uma linha
class class_linha {        
private:
	unsigned int ID;
	unsigned int freq;
	vector<string> paragens;
	vector<unsigned int> tempos;
	vector<bus> autocarros;
public:
	//Fun��es get
	unsigned int getID();
	unsigned int getFreq();
	vector<string> getParagens();
	vector<unsigned int> getTempos();
	vector<bus> getAutocarros();
	//Fun��es set
	void setLinha(unsigned int ID, unsigned int freq, vector<string> paragens, vector<unsigned int> tempos);
	void setID(unsigned int ID);
	void setFreq(unsigned int freq);
	void setParagens(vector<string> paragens);
	void setTempos(vector<unsigned int> tempos);
	void setAutocarros(vector<bus> autocarros);
};
//class com a informa��o relativa a um condutor
class class_condutor {      
private:
	unsigned int ID;
	string nome;
	unsigned int turno;
	unsigned int max;
	unsigned int descanso;
	vector <shift> shifts;
public:
	//Fun��es get
	unsigned int getID();
	string getNome();
	unsigned int getTurno();
	unsigned int getMax();
	unsigned int getDescanso();
	vector <shift> getShifts();
	//Fun��es set
	void setCondutor(unsigned int ID, string nome, unsigned int turno, unsigned int max, unsigned int descanso);
	void setID(unsigned int ID);
	void setNome(string nome);
	void setTurno(unsigned int turno);
	void setMax(unsigned int max);
	void setDescanso(unsigned int descanso);
	void setShifts(vector<shift> shifts);
};

class Empresa {
private:
	string nome_empresa;
	string FichDrivers;
	string FichLines;
	vector<class_condutor> vector_condutores;
	vector<class_linha> vector_linhas;
public:
	Empresa(string nome, string fichCondutores, string fichLinhas); //N�o percebi bem, v� se consegues tu
	// metodos get
	string getNome();
	string getFichDrivers();
	string getFichLines();
	vector <class_linha> getLinhas();
	vector <class_condutor> getCondutores();
	// metodos set
	void setLinhas(vector <class_linha> vector_linhas);
	void setCondutores(vector <class_condutor> vector_condutores);
	void setFichDrivers(string FichDrivers);
	void setFichLines(string FichLines);
	// outros metodos
	void distribuiServico(); // funcao que implementa a afectacao de servico(incompleta)
};


//Classe auxialiar para a fun��o que calcula um trajeto
//Todas as variaveis s�o p�blicas pois como ser� utilizadas para uma fun��o, n�o haver� problema;
class trajeto {
public:
	vector<string> paragens;
	unsigned int tempo;
	unsigned int linha1;
	unsigned int linha2;
};

extern Empresa semprarrolar;
extern unsigned int hora_inicial;
extern unsigned int hora_final;

int linhas_menu();
int condutores_menu();
int menu_trabalho();
void visualizar_linha(class_linha l1);
void visualizar_condutor(class_condutor c1);
vector<class_linha> ler_linhas(string lines_filename);
vector<class_condutor> ler_condutores(string drivers_filename);
int proc_paragem(vector<string> &v, string paragem);
int proc_linha(vector<class_linha> &v, int ID);
int horarios_menu();
string toUpper(string palavra);
int procurar_paragem();
void atribui_autocarro(class_linha &linha);
void guardar_linhas(string lines_filename);
void guardar_condutores(string drivers_filename);
int periodo_disponivel();
void select_sort(vector<trajeto> &v);
int calcula_trajeto();