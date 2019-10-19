#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


//Definição tipo string
typedef char* string;

typedef struct tipoPessoa
{
	int codigo;
	char nome[30];
	int idade;
	float altura;
}tipoPessoa;

//Definição da estrutura de um item genérico de lista
typedef struct tipoItem
{
	string string;
	tipoPessoa pessoa;
	struct tipoItem *anterior;
	struct tipoItem *proximo;
}tipoItem;

//Definição da estrutura de uma lista genérica
typedef struct tipoLista
{
	string *inicioDaLista;
	string *finalDaLista;
	int tamanhoDaLista;
	bool *listaZerada;
}tipoLista;

//Definição da estrutura de uma fila genérica
typedef struct tipoFila
{
	int tamanhoDaFila;
}tipoFila;

//Definição da estrutura de uma pilha genérica
typedef struct tipoPilha
{
	int tamanhoDaPilha;
}tipoPilha;