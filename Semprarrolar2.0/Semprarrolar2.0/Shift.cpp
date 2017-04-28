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

vector <shift> driver::getshifts() {
	return this->shifts;
}