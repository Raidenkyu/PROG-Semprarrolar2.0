#include <iostream>
#include "Semprarrolar.h"

using namespace std;

Empresa::Empresa(string nome, string fichCondutores = "Input_Condutores.txt", string fichLinhas = "Input_Linhas.txt")
{
	this->nome = nome;
}

string Empresa::getNome() {
	return this->nome;
}

void Empresa::distribuiServico() {

}