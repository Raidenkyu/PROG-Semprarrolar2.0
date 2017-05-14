#include <iostream>
#include <iomanip>
#include "Semprarrolar.h"

using namespace std;

bus::bus(unsigned int nBus, unsigned int idCondutor, unsigned int idLinha) {
	this->nBus = nBus;
	this->idCondutor = idCondutor;
	this->idLinha = idLinha;
}

unsigned int bus::getCondutorID() const {
	return this->idCondutor;
}

unsigned int bus::getLinhaID() const {
	return this->idLinha;
}

vector <shift> bus::getSchedule() {
	return this->schedule;
}

unsigned int bus::getBus() const {
	return this->nBus;
}
//Mostra a informação de um autocarro
void visualizar_bus(bus b1)
{

}

//Calcula o número de autocarros necessários por linha
unsigned int numeroBus(class_linha linha)
{
	int tempo = 0;
	for (unsigned int i = 0; i < linha.getTempos().size(); i++)
	{
		tempo += linha.getTempos().at(i);
	}
	tempo *= 2;
	int n = (int)((double)tempo / linha.getFreq() + 1.0);
	return n;
}

void autocarros_linha()
{
	clearScreen();
	int idLinha;
	bool exist = false;
	cout << "Indique uma linha para saber quantos autocarros serão necessários" << endl;
	cout << "Linha: ";
	cin >> idLinha;
	for (unsigned int i = 0; i < semprarrolar.getLinhas().size(); i++)
	{
		if (semprarrolar.getLinhas().at(i).getID() == idLinha)
		{
			exist = true;
			cout << endl << "Na linha " << semprarrolar.getLinhas().at(i).getID() << " são necessários " << numeroBus(semprarrolar.getLinhas().at(i)) << " autocarros" << endl;
			break;
		}
	}
	if (cin.fail())
	{
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cout << "Erro. O ID de uma linha só pode ser um número inteiro" << endl;
	}
	else if (!exist)
		cout << endl << "A linha que indicou não se encontra registada nesta base de dados" << endl;
	cout << "Pressione qualquer tecla para continuar" << endl;
	cin.get();
	cin.get();
	clearScreen();
}

void atribui_autocarro(class_linha &linha)
{
	vector<bus> autocarros;
	for (unsigned int i = 0; i < numeroBus(linha); i++)
	{
		bus b1(i + 1, 0, linha.getID());
		autocarros.push_back(b1);
	}
	linha.setAutocarros(autocarros);
}


//Função que lista os peridos de tempo em que os autocarros estão sem trabalho

void lista_periodos(bus b1)
{
	int hora = hora_inicial;
	int minuto;
	cout << "Periodos sem trabalho atribuido:" << endl << endl;
	if (b1.getSchedule().size() == 0)
		cout << "Este autocarro encontra-se desocupado o dia todo" << endl;
	else
	{
		if (hora_inicial * 60 != b1.getSchedule().at(1).getInicio())
		{
			hora = b1.getSchedule().at(1).getInicio() / 60;
			minuto = b1.getSchedule().at(1).getInicio() % 60;
			cout << setw(2) << setfill('0') << hora_inicial << ":" << 0 << " -> " << hora << ":" << minuto << endl;
		}
		for (unsigned int i = 0; i < b1.getSchedule().size() - 1; i++)
		{
			if (b1.getSchedule().at(i).getFim() != b1.getSchedule().at(i + 1).getInicio())
			{
				hora = b1.getSchedule().at(i).getFim() / 60;
				minuto = b1.getSchedule().at(i).getFim() % 60;
				cout << setw(2) << setfill('0') << hora << ":" << minuto << " -> ";
				hora = b1.getSchedule().at(i).getInicio() / 60;
				minuto = b1.getSchedule().at(i).getInicio() % 60;
				cout << setw(2) << setfill('0') << hora << ":" << minuto << endl;
			}
		}
		if (b1.getSchedule().at(b1.getSchedule().size() - 1).getFim() != hora_final * 60)
		{
			hora = b1.getSchedule().at(b1.getSchedule().size() - 1).getFim() / 60;
			minuto = b1.getSchedule().at(b1.getSchedule().size() - 1).getFim() % 60;
			cout << setw(2) << setfill('0') << hora << ":" << minuto << " -> " << hora_final << ":" << 0;
		}
	}
	cout << endl << endl << "Pressione qualque tecla para continuar" << endl;
	cin.get();
	cin.get();
}

int periodo_disponivel()
{
	while (true) {
		clearScreen();
		int ID;
		int nBus;
		bool exist1 = false, exist2 = false;
		cout << "Com esta opção pode consultar os périodos de tempo, em que determinado autocarro não está ser utilizado" << endl;
		cout << endl;
		for (unsigned int i = 0; i < semprarrolar.getLinhas().size(); i++)
		{
			visualizar_linha(semprarrolar.getLinhas().at(i));
		}
		cout << "Indique o ID da linha em que se encontra o autocarro que pretende consultar" << endl;
		cout << "Para sair digite 0 no lugar do ID" << endl;
		while (true)
		{
			cout << "Indique o ID da linha onde se encontra o autocarro que pretende consultar: ";
			cin >> ID;
			if (cin.good())
				break;
			else
			{
				cin.clear();
				cin.ignore(INT_MAX, '\n');
				cout << "Erro. Introduziu um valor inválido. Só pode introduzir números inteiros" << endl;
			}
		}
		if (ID == 0)
		{
			clearScreen();
			return 0;
		}
		for (unsigned int i = 0; i < semprarrolar.getLinhas().size(); i++)
		{
			if (semprarrolar.getLinhas().at(i).getID() == ID)
			{
				exist1 = true;
				cout << endl << "Lista de autocarros: " << endl;
				for (unsigned int j = 0; j < semprarrolar.getLinhas().at(i).getAutocarros().size(); j++)
				{
					cout << semprarrolar.getLinhas().at(i).getAutocarros().at(j).getBus();
					if (j != semprarrolar.getLinhas().at(i).getAutocarros().size() - 1)
						cout << ", ";
					else cout << endl << endl;
				}
				while (true)
				{
					cout << "Numero do autocarro: ";
					cin >> nBus;
					if (cin.good())
						break;
					else
					{
						cin.clear();
						cin.ignore(INT_MAX, '\n');
						cout << "Erro. Introduziu um valor inválido. Só pode introduzir números inteiros" << endl;
					}
				}
				for (unsigned int j = 0; j < semprarrolar.getLinhas().at(i).getAutocarros().size(); j++)
				{
					if (semprarrolar.getLinhas().at(i).getAutocarros().at(j).getBus() == nBus)
					{
						exist2 = true;
						lista_periodos(semprarrolar.getLinhas().at(i).getAutocarros().at(j));
					}
				}
			}
			
		}
		if (!exist1)
			cout << "A linha que indicou não está listada" << endl;
		else if (!exist2)
			cout << "O autocarro que indicou não está listado" << endl;
	}
}

