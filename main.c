#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "excecao.h"

void main()
{
	char n = '2';
	printf("\nnumero completo: %s\n", n);
	
	char c = strpbrk(n,n);

	printf("\nprim carc: %c\n", c);





}

//2 147 483 647
bool validarNumeroNatural(int numero) {

	int tamanho = strlen(numero);

	if (tamanho > 10)
	{
		lancarErro(1);
		return false;
	}

	if (tamanho == 10) {
		if (true)
		{

		}
	}

}

int op;
printf("\nDigite o conteudo a ser validado: ");
fflush(stdin);
fgets(op, 14, stdin);

if (strlen(op) = < 10) {}
else { erro.numeroDeCaracteresExcedido }

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