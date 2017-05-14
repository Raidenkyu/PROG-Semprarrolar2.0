#include <iostream>
#include "Semprarrolar.h"

using namespace std;
// inicio 7 acaba 19
void imprimirhora(int hora, int minuto)
{
	if (hora < 10)
	{
		cout << "0" << hora << ":";
	}
	else
	{
		cout << hora << ":";
	}
	if (minuto < 10)
	{
		cout << "0" << minuto << " ";
	}
	else
	{
		cout << minuto << " ";
	}
}
int get_tempo_total(vector<unsigned int> tempos)
{
	int total = 0;
	for (unsigned int i = 0; i < tempos.size(); i++)
	{
		total += tempos.at(i);
	}
	return total;
}
int get_tempo(vector<unsigned int> tempos, int indice)
{
	int total=0;
	for (int i = 0; i < indice; i++)
	{
		total += tempos.at(i);
	}
	return total;
}
void imprimir_horario_paragem(class_linha linhas,int indice)
{
	unsigned int primeirotempo, segundotempo;
	unsigned int tempo1 = 420, tempo2 = 420;
	unsigned int freq;
	int hora, minuto;
	primeirotempo = get_tempo(linhas.getTempos(), indice);
	segundotempo = primeirotempo + get_tempo_total(linhas.getTempos());

	cout << "Linha " << linhas.getID() << endl << "Paragem: " << linhas.getParagens().at(indice) << endl;

	cout << "Horário de ida: " << endl;
	tempo1 += primeirotempo;
	tempo2 += segundotempo;
	freq = linhas.getFreq();

	while (tempo1 <= 1140)
	{
		if (tempo1 < tempo2)
		{
			minuto = tempo1 % 60;
			hora = tempo1 / 60;
			imprimirhora(hora, minuto);
			tempo1 += freq;
		}
		else if (tempo2 < tempo1)
		{
			minuto = tempo2 % 60;
			hora = tempo2 / 60;
			imprimirhora(hora, minuto);
			tempo2 += freq;
		}
		else
		{
			minuto = tempo1 % 60;
			hora = tempo1 / 60;
			imprimirhora(hora, minuto);
			cout << "x2 ";
			tempo1 += freq;
			tempo2 += freq;
		}
	}
	for (unsigned int j = 1; j <= segundotempo / freq; j++)
	{
		minuto = tempo2 % 60;
		hora = tempo2 / 60;
		imprimirhora(hora, minuto);
		tempo2 += freq;
	}
	cout << endl << "Horário de volta: " << endl;
	primeirotempo = get_tempo_total(linhas.getTempos()) - primeirotempo;
	segundotempo = get_tempo_total(linhas.getTempos()) + primeirotempo;
	tempo1 = 420 + primeirotempo;
	tempo2 = 420 + segundotempo;
	freq = linhas.getFreq();
	while (tempo1 <= 1140)
	{
		if (tempo1 < tempo2)
		{
			minuto = tempo1 % 60;
			hora = tempo1 / 60;
			imprimirhora(hora, minuto);
			tempo1 += freq;
		}
		else if (tempo2 < tempo1)
		{
			minuto = tempo2 % 60;
			hora = tempo2 / 60;
			imprimirhora(hora, minuto);
			tempo2 += freq;
		}
		else
		{
			minuto = tempo1 % 60;
			hora = tempo1 / 60;
			imprimirhora(hora, minuto);
			cout << "x2 ";
			tempo1 += freq;
			tempo2 += freq;
		}
	}
	for (unsigned int j = 1; j <= segundotempo / freq; j++)
	{
		minuto = tempo2 % 60;
		hora = tempo2 / 60;
		imprimirhora(hora, minuto);
		tempo2 += freq;
	}
}
void horario_linha()
{
	clearScreen();

	unsigned int tempo1 = 420, tempo2 = 420;
	int linhaid;
	bool existe = false;

	vector<class_linha> linhas = semprarrolar.getLinhas();
	while (existe == false)
	{
		cout << "Qual a linha que quer ver o horário? ";
		cin >> linhaid;

		for (unsigned int i = 0; i < linhas.size(); i++)
		{
			if (linhaid == linhas.at(i).getID())
			{
				int tempototal = get_tempo_total(linhas.at(i).getTempos());
				for (unsigned int j = 0; j < linhas.at(i).getParagens().size(); j++)
				{
					imprimir_horario_paragem(linhas.at(i), j);
				}
				existe = true;

			}
		}
		if (existe == false)
		{
			cout << "A linha que inseriu não existe. Porfavor volte a inserir" << endl;
		}
	}
	cin.get();
	cin.get();
}

void horario_paragem()
{
	clearScreen();
	string paragemlida;
	bool existe = false;
	vector<class_linha> linhas =  semprarrolar.getLinhas();
	while (existe == false)
	{
		cin.ignore(INT_MAX, '\n');
		cout << "Qual a paragem que quer ver o horário? ";
		getline(cin, paragemlida);
		for (unsigned int i = 0; i < linhas.size(); i++)
		{
			int indice = proc_paragem(linhas.at(i).getParagens(), paragemlida);
			if (indice != -1)
			{
				imprimir_horario_paragem(linhas.at(i), indice);
				existe = true;
			}
		}
		if (existe== false)
		{
			cout << "A paragem que inseriu não existe. Porfavor volte a inserir" << endl;
		}
	}
	cin.get();

}

int horarios_menu()
{
	int op;
	do {
		clearScreen();
		cout << "+-------------------------------------- +" << endl;
		cout << "| Menu Horário                          |" << endl;
		cout << "+-------------------------------------- +" << endl;
		cout << "| Selecione uma das seguintes opções :  |" << endl;
		cout << "+-------------------------------------- +" << endl;
		cout << "| 1. Horario de uma paragem             |" << endl;
		cout << "| 2. Horario de uma linha               |" << endl;
		cout << "| 0. Sair                               |" << endl;
		cout << "+-------------------------------------- +" << endl << endl;
		cout << "Opção: ";
		cin >> op;
		switch (op)
		{
		case 1:
			horario_paragem();
			break;
		case 2:
			horario_linha();
			break;
		case 0:
			clearScreen();
			cout << "O programa vai encerrar." << endl;
			cout << "Pressione Enter para fechar" << endl;
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