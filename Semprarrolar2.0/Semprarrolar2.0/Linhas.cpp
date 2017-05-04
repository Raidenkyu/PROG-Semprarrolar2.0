#include <iostream>
#include <fstream>
#include <sstream>
#include "Semprarrolar.h"

using namespace std;

unsigned int class_linha::getID()
{
	return this->ID;
}

unsigned int class_linha::getFreq()
{
	return this->freq;
}

vector<string> class_linha::getParagens()
{
	return this->paragens;
}

vector<unsigned int> class_linha::getTempos()
{
	return this->tempos;
}

void class_linha::setLinha(unsigned int ID, unsigned int freq, vector<string> paragens, vector<unsigned int> tempos)
{
	this->ID = ID;
	this->freq = freq;
	this->paragens = paragens;
	this->tempos = tempos;
}

vector<class_linha> ler_linhas(string lines_filename)
{
	ifstream Lines_file(lines_filename);
	char comma;
	unsigned int ID, freq;
	string line;
	string paragens;
	string tempos;
	string paragem;
	string tempo;
	vector <class_linha> vector_linhas;
	vector <class_condutor> vector_condutores;
	vector<string> vector_paragens;
	vector<unsigned int> vector_tempos;
	stringstream ss1;
	class_linha l1;
	if (Lines_file.is_open())
	{
		while (getline(Lines_file, line))
		{
			ss1.str(line);
			ss1 >> ID >> comma >> freq >> comma;
			paragens = ss1.str();
			//converteu-se a stringstream em string para efectuar as operações seguintes
			paragens = paragens.substr(paragens.find_first_of(';') + 2);
			//Criar substring que contem tudo o que está depois do primeiro ponto e virgula
			paragens = paragens.substr(paragens.find_first_of(';') + 2);
			//Criar substring que contem tudo o que está depois do segundo ponto e virgula
			tempos = paragens.substr(paragens.find_first_of(';') + 2);
			//Criar substring que contem tudo o que está depois do terceiro ponto e virgula
			//e assim obtem-se a lista dos tempos
			paragens = paragens.substr(0, paragens.length() - tempos.length());
			// Retiramos a lista dos tempos para obter-mos a lista das paragens
			while (paragens.length() != 0)
			{
				if (paragens.find_first_of(',') != -1)
				{
					paragem = paragens;
					paragens = paragens.substr(paragens.find_first_of(',') + 2);
					//Cortou-se a 1ª paragem da lista atual com a intenção de se poder extrair na próxima instrução
					paragem = paragem.substr(0, paragem.length() - paragens.length() - 2);
					//Extração da primeira paragem da lista atual 
				}
				else
				{
					paragem = paragens.substr(0, paragens.length() - 2);
					paragens = "";
					//Como a ultima paragem é seguida de ponto e virgula em vez de virgula, faz-se uma estratérgia diferente
					//Apenas se retirou o ponto e vírgula
					//A lista passa a ficar nula e o ciclo encerra
				}
				vector_paragens.push_back(paragem);
			}
			while (tempos.length() != 0)
			{
				if (tempos.find_first_of(',') != -1)
				{
					tempo = tempos;
					tempos = tempos.substr(tempos.find_first_of(',') + 2);
					//Cortou-se a 1ª paragem da lista atual com a intenção de se poder extrair na próxima instrução
					tempo = tempo.substr(0, tempo.length() - tempos.length() - 2);
					//Extração da primeira paragem da lista atual 
				}
				else
				{
					tempo = tempos;
					tempos = "";
					//Usa-se a mesma estratégia que se usou com as paragens
				}
				vector_tempos.push_back(stoi(tempo));
			}
			l1.setLinha(ID, freq, vector_paragens, vector_tempos);
			vector_linhas.push_back(l1);
			vector_paragens.clear();
			vector_tempos.clear();
		}
	}
	else
	{
		clearScreen();
		cout << "Erro. Não foi possível abrir o ficheiro das linhas" << endl;
		cout << "Pressione Enter para continuar" << endl;
		cin.get();
	}
	return vector_linhas;
}

int linhas_menu() //Mini-interface que permite ao utilizador escolher a função que pretende
{
	do {
		int op;
		clearScreen();
		cout << "+-------------------------------------- +" << endl;
		cout << "| Menu Linhas                           |" << endl;
		cout << "+-------------------------------------- +" << endl;
		cout << "| Selecione uma das seguintes opções :  |" << endl;
		cout << "+-------------------------------------- +" << endl;
		cout << "| 1. Criar linha                        |" << endl;
		cout << "| 2. Ver e modificar linha              |" << endl;
		cout << "| 3. Remover linha                      |" << endl;
		cout << "| 0. Regressar ao menu principal        |" << endl;
		cout << "+-------------------------------------- +" << endl;
		cout << endl;
		cout << "Opção: ";
		cin >> op;
		switch (op)
		{
		case 1:
			//cria_linha();
			break;
		case 2:
			//modifica_linha();
			break;
		case 3:
			//elimina_linha();
			break;
		case 4:
			break;
		case 5:
			break;
		case 0:
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
	} while (true);
}