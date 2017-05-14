#include <iostream>
#include <iomanip>
#include <cmath>
#include "Semprarrolar.h"

using namespace std;

unsigned int shift::getLinha(){
	return this->idLinha;
}

unsigned int shift::getCondutor() {
	return this->idCondutor;
}

unsigned int shift::getBus() {
	return this->nBus;
}

unsigned int shift::getInicio() {
	return this->inicio;
}

unsigned int shift::getFim(){
	return this->fim;
}

void shift::setLinhaID(unsigned int idLinha) {
	this->idLinha = idLinha;
}

void shift::setCondutorID(unsigned int idLinha) {
	this->idCondutor = idCondutor;
}

void shift::setBus(unsigned int nBus) {
	this->nBus = nBus;
}

void shift::setInicio(unsigned int inicio) {
	this->inicio = inicio;
}

void shift:: setFim(unsigned int fim) {
	this->fim = fim;
}


//Imprime o trabalho de um condutor sob a forma de tabela
void visualizar_trabalho(class_condutor c1)
{
	clearScreen();
	int hi, hf, mi, mf;
	cout << "+-------------+----------------+-----------------+----------------+-------------+" << endl;
	cout << "| ID da Linha | ID do Condutor | Nº do autocarro | Hora de inicio | Hora do fim |" << endl;
	cout << "+-------------+----------------+-----------------+----------------+-------------+" << endl;
	for (unsigned int i = 0; i < c1.getShifts().size(); i++)
	{
		hi = c1.getShifts().at(i).getInicio() / 60;
		mi = c1.getShifts().at(i).getInicio() % 60;
		hf = c1.getShifts().at(i).getFim() / 60;
		mf = c1.getShifts().at(i).getFim() % 60;
		cout << "| " << setw(11) << c1.getShifts().at(i).getLinha() << " | "
			<< setw(14) << c1.getShifts().at(i).getCondutor() << " | "
			<< setw(15) << c1.getShifts().at(i).getBus() << " | "
			<< setw(7) << hi << ":" << setw(6) << mi << " | "
			<< setw(5) << hf << ":" << setw(5) << mf << " |" << endl;
	}
}


//Função que permite atribuir trabalho a um condutor
//Incompleta, deixar para o fim
void trabalho_condutor()
{
	clearScreen();
	int idCondutor;
	bool exist = false;
	cout << "Indique um condutor para poder vizualizar o seu trabalho e modificar" << endl;
	cout << "ID do Condutor: ";
	cin >> idCondutor;
	cout << "Trabalho do condutor indicado: " << endl;
	for (unsigned int i = 0; i < semprarrolar.getCondutores().size(); i++)
	{
		if (semprarrolar.getCondutores().at(i).getID() == idCondutor)
		{
			exist = true;
			visualizar_trabalho(semprarrolar.getCondutores().at(i));

		}
	}
}

//Devolve true se ainda puder receber trabalho e false se já tem a semana preenchida
bool disponivel(class_condutor c1)
{
	unsigned int tempo = 0;
	for (unsigned int i = 0; i < c1.getShifts().size(); i++)
	{
		tempo += c1.getShifts().at(i).getFim() - c1.getShifts().at(i).getInicio();
	}
	tempo *= 7;
	tempo = (int) ceil(((double) tempo) / 60);
	if (tempo >= c1.getMax())
		return false;
	else return true;
}

void condutores_disponiveis()
{
	clearScreen();
	cout << "Estes são os condutores que ainda estão disponíveis para atribuir trabalho: " << endl;
	for (unsigned int i = 0; i < semprarrolar.getCondutores().size(); i++)
	{
		if (disponivel(semprarrolar.getCondutores().at(i)))
			visualizar_condutor(semprarrolar.getCondutores().at(i));
	}
}

int menu_trabalho()
{
	clearScreen();
	int op;
	while (true)
	{
		cout << "+--------------------------------------+" << endl;
		cout << "| Menu Trabalho                        |" << endl;
		cout << "+--------------------------------------+" << endl;
		cout << "| Selecione uma das seguintes opções : |" << endl;
		cout << "+--------------------------------------+" << endl;
		cout << "| 1. Ver e Atribuir Trabalho           |" << endl; 
		cout << "| 2. Listar condutores disponíveis     |" << endl; 
		cout << "| 3. Listar autocarros disponíveis     |" << endl;
		cout << "| 0. Regressar ao Menu Principal       |" << endl;
		cout << "+--------------------------------------+" << endl;
		cout << endl << "Opção: ";
		cin >> op;
		switch (op)
		{
		case 1:
			trabalho_condutor();
			break;
		case 2:
			condutores_disponiveis();
			break;
		case 3:
			periodo_disponivel();
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
	}
}