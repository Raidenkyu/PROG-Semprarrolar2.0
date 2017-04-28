#include <iostream>
#include "Semprarrolar.h"

using namespace std;

void select_sort(vector<int> &v)   //Implementação de um overload de select sort para inteiros
{
	int tmp;
	for (unsigned int i = 0; i < v.size() - 1; i++)
	{
		for (unsigned int j = i; j < v.size(); j++)
		{
			if (v.at(i) > v.at(j))
			{
				tmp = v.at(i);
				v.at(i) = v.at(j);
				v.at(j) = tmp;
			}
		}
	}
}

void select_sort(vector<string> &v)    //Implementação de um overload de select sort para strings
{
	string tmp;
	for (unsigned int i = 0; i < v.size() - 1; i++)
	{
		for (unsigned int j = i; j < v.size(); j++)
		{
			if (v.at(i) > v.at(j))
			{
				tmp = v.at(i);
				v.at(i) = v.at(j);
				v.at(j) = tmp;
			}
		}
	}
}

int proc_paragem(vector<string> &v, string paragem) {  //Adaptção de pesquisa sequencial para encontrar o indice de uma paragem
	unsigned int i;                                             //No vetor das paragens de uma linha em particular 
	for (i = 0; i < v.size(); i++) {
		if (v.at(i) == paragem) {
			return i;
		}
	}

	return -1;
}

int proc_linha(vector<class_linha> &v, int ID) {  //Implementação de pesquisa sequencial
	unsigned int i;                                         //Procura o indice da linha ID no vetor das linhas
	for (i = 0; i < v.size(); i++) {
		if (v.at(i).getID() == ID) {
			return i;
		}
	}

	return -1;
}
