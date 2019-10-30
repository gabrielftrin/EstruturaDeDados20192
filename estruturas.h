#include <stdio.h> //Biblioteca padrão
#include <stdbool.h> //Definição do tipo Booleano
#include <stdlib.h> //define quatro tipos de variáveis, várias macros e várias funções para executar funções gerais (malloc, etc.)
//#include <string.h> // Manipular strings
//#include <ctype.h> //declara várias funções que são úteis para testar e mapear caracteres. (isdigit() por exemplo)
#include <locale.h> //Configurar local/região/país
#include "funcoesdosistema.h"

#define MENSAGEM_DE_ERRO "Mensagem de erro do compilador"

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
	tipoItem *inicioDaLista;
	tipoItem *finalDaLista;
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