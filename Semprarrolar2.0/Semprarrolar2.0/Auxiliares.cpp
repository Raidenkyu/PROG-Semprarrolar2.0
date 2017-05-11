#include <iostream>
#include "Semprarrolar.h"

using namespace std;
//Ordenação de interios (vector)
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
//Ordenação de strings (vector)
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
//Adaptção de pesquisa sequencial para encontrar o indice de uma paragem , senão devolve -1
int proc_paragem(vector<string> &v, string paragem) { 
	unsigned int i;                                             //No vetor das paragens de uma linha em particular 
	for (i = 0; i < v.size(); i++) {
		if (toUpper(v.at(i)) == toUpper(paragem)) {
			return i;
		}
	}

	return -1;
}
//Implementação de pesquisa sequencial de int. Manda vector e o int e devolve o indice do int ou -1
int proc_linha(vector<class_linha> &v, int ID) { 
	unsigned int i;                                         //Procura o indice da linha ID no vetor das linhas
	for (i = 0; i < v.size(); i++) {
		if (v.at(i).getID() == ID) {
			return i;
		}
	}
	return -1;
}
// String Lowcase para Uppercase
string toUpper(string palavra)
{
	for (int i = 0; i < palavra.size(); i++)
	{
		if (palavra.at(i) >= 97 && palavra.at(i) <= 122) // todos os caracteres que estão em letra minuscula
		{
			palavra.at(i) = palavra.at(i) - 32; // segundo a tabela ascii a distancia que 'a' esta de 'A' é de 32
		}
	}
	return palavra;
}

