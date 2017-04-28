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