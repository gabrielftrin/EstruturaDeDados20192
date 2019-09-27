#include <stdbool.h>

	//Definir estrutura da pessoa
	typedef struct tipoPessoa
	{
		int codigo; //Valores de 1 a 50
		char nome[30];
		int idade;
		float altura;
		struct tipoPessoa *anterior;
		struct tipoPessoa *proximo;

	}tipoPessoa;

	//Definir estrutura da lista
	typedef struct tipoLista
	{
		tipoPessoa *inicioDaLista;
		tipoPessoa *finalDaLista;
		int tamanhoDaLista;
		bool listaZerada;

	}tipoLista;