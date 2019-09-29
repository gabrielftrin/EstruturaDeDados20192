/*Implementar  uma  lista  duplamente  encadeada  para  o  registro  de pessoas. 
O  programa  deve  armazenar,  para  cada  pessoa,  os  seguintes dados:  
código  (inteiro,  com  valores  de  1  a  50)  nome  (com  até  30 caracteres), idade (inteiro)e altura (real).

O programa deve implementar um menu que permita ao usuário: 
1. criar a lista de pessoas; 
2. inserir (cadastrar) uma nova pessoa, sempre no final da lista; 
3. consultar se uma pessoa está cadastrada, através do seu código. Se estiver, o programa deve  imprimir  os  dados  desta  pessoa;  
4.  remover  uma  pessoa;  e  
5. encerrar  o  programa,  destruindo  a  lista  de  pessoas.  O  programa  deve implementar uma função para cada opção disponível no menu.
*/
#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"

void main(int argc, char const *argv[])
{
	limparTela();

	//inicializarPrograma();

	int retorno = printf("\n");

	printf("\nretorno: %d\n",retorno);
	//return 0;

	//Compilar na trends no caminho "C:\Users\gtrindade>"
	//gcc.lnk -o objeto.exe "C:\Users\gtrindade\OneDrive - TecnoTRENDS\GitHub\main.c" && obj.lnk

	//Compilar em casa no caminho "C:\Users\Gabriel\Desktop"
	//gcc.lnk -o objeto.exe O:\OneDrive\GitHub\EstruturaDeDados20192\main.c && obj.lnk
}