//#include "inicializacao.h"
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
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>//biblioteca p/ as funções isalpha isdigit toupper tolower

int main(void)
{
	char letra;
	char op;

	printf("Digite uma letra do alfabeto: ");
	scanf("%c", &letra);

	//isalpha verifica se é uma letra do alfabeto
	if (isalpha(letra))
	{
		printf("\nVoce digitou a letra %c \n\n", letra);

		//toupper transforma em maiuscula
		letra = toupper(letra);
		printf("Maiuscula: %c \n\n", letra);

		//tolower transforma em minuscula
		letra = tolower(letra);
		printf("Minuscula: %c \n\n", letra);
	}
	else
	{
		printf("Voce nao digitou uma letra!!!\n");
	}

	printf("\nInforme um numero de 0 a 9: ");
	fflush(stdin);
	scanf("%c", &op);

	//isdigit verifica se o caracater recebido é um dígito
	if (isdigit(op))
	{
		printf("Digito: %c \n\n", op);
	}
	else
		printf("Voce nao digitou um numero!!!\n\n");

	system("pause");
	return 0;
}