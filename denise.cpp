#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <ctime>
#define max 10

using namespace std;

//Chamada ao programa principal

int main(int argc, char const* argv[])
{
	string nome;
	char opcao;
	int numero, N;
	int vet[max];

	cout << "Informe a quantidade a ser cadastrada" << endl;
	cin >> N;

	system("cls");								// LIMPA TELA

	//std::srand(120);      					//especifica q quantidade aleatória a ser gerada
	srand(time(NULL));

	for (int i = 0; i < max; i++)
	{
		if (i == 0) cout << "\n\nEntrou no primeiro 'for'\n\n";

		vet[i] = rand() % 2;  //gera dados aleatórios ate o valor determinado anterior tava std::srand() % 120	;
		//Só uma pequena correção, std::cout não é uma função mas sim um objeto global
	}

	for (int i = 0; i < max; i++)
	{
		if (i == 0) cout << "\n\nEntrou no segundo 'for'\n\n";

		// mostra a posição do elemento que acabei de criar
		cout << "o valor desta posicao é: ", vet[i], " ";
		cout << " SUCESS " << endl;

	}

	cout << "informe o nome e o numero correspondente " << endl;
	cout << "o nome e o numero sao: ", nome, numero, "\n";

	//Parte do código que estava com o segundo main

	do
	{
		cout << " 1: Arvore criada" << endl;
		cout << " 2: Insercao do nome e numero na Arvore" << endl;
		cout << " 3: consulta de dados inseridos na Arvore" << endl;
		cout << " 4: Insercao do nome e numero na Arvore" << endl;
		cout << " 5: Incinerar Arvore" << endl;
		cout << " 6: Sair do Programa" << endl;

		opcao = 6;

		switch (opcao) {

		case 1: cout << " Criar arvore \n";
			break;

		case 2: cout << " Inserir palavra na arvore \n";
			break;

		case 3: cout << " Consultar a palavra na arvore \n";
			break;

		case 4: cout << " Listar todas as palavras da arvore ";
			break;

		case 5: cout << " Incinerar a arvore ";
			break;

		case 6: cout << " Encerrar o Programa...Chega de estresse por hoje ";
			return 0;
		default: cout << "Opcao invalida\n";
			break;

		}
	} while (opcao != 0);

	return 0;
}
