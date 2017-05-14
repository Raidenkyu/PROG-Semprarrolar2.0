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
	int idlinha;
	int idautocarro;
	int hora1, hora2;
	int total;
	bool exist = false;
	class_condutor condutor;
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
			condutor = semprarrolar.getCondutores().at(i);
		}
	}
	cout << "Qual a linha que pretende atribuir trabalho?";
	cin >> idlinha;
	int existe = proc_linha(semprarrolar.getLinhas(), idlinha);
	if (existe != -1)
	{
		for (int i = 0; i < semprarrolar.getLinhas().at(existe).getAutocarros().size(); i++)
		{
			bus autocarrinho = semprarrolar.getLinhas().at(existe).getAutocarros().at(i);
			cout << "Autocarro " << autocarrinho.getBus() << " :" << endl;
			for (int j = 0; j < autocarrinho.getSchedule().size(); j++)
			{
				cout << "Horario " << j + 1 << " : " << autocarrinho.getSchedule().at(j).getInicio() << "->" << autocarrinho.getSchedule().at(j).getFim() << endl;
			}
		}
		cout << "Qual o autocarro que prentede criar um novo turno?";
		cin >> idautocarro;
		idautocarro--;
		bus autocarrinho = semprarrolar.getLinhas().at(existe).getAutocarros().at(idautocarro);
		cout << "De que horas a que horas prentede que o turno tenha?" << endl;
		cout << "Primeira hora: ";
		cin >> hora1;
		cout << "Segunda hora: ";
		cin >> hora2;
		bool pode = true;
		total = 0;
		for (int i = 0; i < condutor.getShifts().size(); i++)
		{
			if (condutor.getShifts().at(i).getInicio() < hora1-condutor.getDescanso() && condutor.getShifts().at(i).getFim() < hora1- condutor.getDescanso());
			else if (condutor.getShifts().at(i).getInicio() > hora2+ condutor.getDescanso() && condutor.getShifts().at(i).getFim() > hora2+ condutor.getDescanso());
			else
			{
				pode = false;
			}
			total = total + condutor.getShifts().at(i).getFim() - condutor.getShifts().at(i).getInicio();
		}
		if (total >= condutor.getMax())pode = false;
		for (int i = 0; i < autocarrinho.getSchedule().size(); i++)
		{
			if (autocarrinho.getSchedule().at(i).getInicio() < hora1 && autocarrinho.getSchedule().at(i).getFim() < hora1);
			else if (autocarrinho.getSchedule().at(i).getInicio() > hora2 && autocarrinho.getSchedule().at(i).getFim() > hora2);
			else
			{
				pode = false;
			}
		}
		if (pode)
		{
			total += hora2 - hora1;
			if (total >= condutor.getMax())pode = false;
			else
			{
				if (hora2 - hora1 <= condutor.getTurno())
				{
					shift sf;
					sf.setBus(autocarrinho.getBus());
					sf.setCondutorID(condutor.getID());
					sf.setFim(hora2);
					sf.setInicio(hora1);
					sf.setLinhaID(idlinha);
					vector < shift > v1= autocarrinho.getSchedule();
					vector < shift > v2 = condutor.getShifts();
					v1.push_back(sf);
					v2.push_back(sf);
					condutor.setShifts(v2);
					cout << "ola";
					//FALTA ALGO AQUI E NS O QUE ÉÉÉÉÉÉÉÉÉ´!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
				}
				else
				{
					pode = false;
				}
			}
		}
		if(pode==false)
		{
			cout << "O horario que inseriu já se encontra ocupado no horario do autocarro ou do condutor." << endl;
		}
	}

	cin.get();
	cin.get();
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
		cout << "| 2. Listar trabalho dos condutores    |" << endl; 
		cout << "| 3. Listar trabalho dos autocarros    |" << endl;
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