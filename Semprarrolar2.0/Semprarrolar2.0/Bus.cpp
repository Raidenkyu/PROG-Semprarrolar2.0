#include <iostream>
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

//Calcula o número de autocarros necessários por linha
int numeroBus(class_linha linha)
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

void visualizar_bus(bus b1)
{

}
