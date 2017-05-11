#include <iostream>
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

vector <shift> bus::getSchedule(){
	return this->schedule;
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