#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

//Definir tipo string
typedef char* string;

//Definir estrutura do item da lista
typedef struct tipoitem
{
	int codigo; 
	char nome[30];
	int idade;
	float altura;
	string string;
	struct tipoItem *anterior;
	struct tipoItem *proximo;
}tipoPessoa;

//Definir estrutura da lista
typedef struct tipoLista
{
	string *inicioDaLista;
	string *finalDaLista;
	int tamanhoDaLista;
	bool *listaZerada;
}tipoLista;