#include "inicializacao.h"
//#include <stdio.h>

void main(int argc, char const *argv[])
{
	//limparTela();

	//inicializarPrograma();
	char nome[21], sobrenome[21];
 
    printf("Primeiro nome: ");
    fgets(nome,20,stdin); //scanf("%s", nome);
 
    printf("Ultimo sobrenome: ");
    //scanf("%s", sobrenome);
 
    printf("Ola senhor %s, %s. Bem-vindo ao curso C Progressivo.\n", nome, sobrenome);

}