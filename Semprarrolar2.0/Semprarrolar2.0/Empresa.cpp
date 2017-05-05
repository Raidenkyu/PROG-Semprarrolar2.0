#include <iostream>
#include "Semprarrolar.h"

using namespace std;
// Definir Empresa
Empresa::Empresa(string nome, string fichCondutores, string fichLinhas)
{
	nome_empresa = nome;
	vector_condutores = ler_condutores(fichCondutores);
	vector_linhas = ler_linhas(fichLinhas);
}
// Get Informação------------------------------------------------------
vector <class_linha> Empresa::getLinhas()
{
	return this->vector_linhas;
}
vector <class_condutor> Empresa::getCondutores()
{
	return this->vector_condutores;
}
string Empresa::getNome() {
	return this->nome_empresa;
}
//---------------------------------------------------------------------
//Definir os vectores
void Empresa::setLinhas(vector <class_linha> vector_linhas)
{
	this->vector_linhas = vector_linhas;
}
void Empresa::setCondutores(vector <class_condutor> vector_condutores)
{
	this->vector_condutores = vector_condutores;
}

void Empresa::distribuiServico() {

}
