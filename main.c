//#include "inicializacao.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <validacoes.h>

/*
#include <stdio.h>
#include <stdbool.h>

bool numeroNatural(int n) {

	if (n>0)
	{

		return true;
	}

	return false;
}


void main(int argc, char const *argv[])
{
	//limparTela();

	//inicializarPrograma();
	int numero;
	printf("\nteste\n");
	bool valor = numeroNatural(scanf("%d",numero));

	printf("\no numero é natural ou nao: %d, numero %d\n", valor,numero);

}
*/
//biblioteca p/ as funções isalpha isdigit toupper tolower

void main(void)
{

	/*
	if (isdigit(op))
	{
		printf("Digito: %c \n\n", op);
	}
	else
		printf("Voce nao digitou um numero!!!\n\n");

*/
	char op[10];

	typedef struct erro
	{
		string numeroDeCaracteresExcedido;

	}erro;

	numeroDeCaracteresExcedido = "Numero de caracteres excedido.";

	erro erroDeExecucao;

	printf("\nDigite o conteudo a ser validado: ");
	fflush(stdin);
	fgets(op, 11, stdin);
	
	if (strlen(op) = < 10) {


	}
	else {

		erroDeExecucao
			;
		erro.numeroDeCaracteresExcedido
	}

	int tam;
	tam = strlen(op);
	
	printf("\nresult %s\n", op);
	printf("\nstring %d\n", tam);	
	
	assert
	
}

///tudo é char
// nenhum caractere pode ser virgula
// nenhum caractece pode ser ponto
// todo caractere deve ser digito 2 147 483 647

//Ler 10 caracteres
//se tiver 10
	//o primeiro deve ser 1 ou 2
//ver um caracter
	//se o caracter é um dígito
		//se não for retorne falso
	//vá pro próximo caracter


