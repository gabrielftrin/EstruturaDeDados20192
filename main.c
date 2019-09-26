//Implementar  uma  lista  duplamente  encadeada  para  o  registro  de pessoas.  O  programa  deve  armazenar,  para  cada  pessoa,  os  seguintes dados:  código  (inteiro,  com  valores  de  1  a  50)  nome  (com  até  30 caracteres), idade (inteiro)e altura (real). O programa deve implementar um menu que permita ao usuário: 1. criar a lista de pessoas; 2. inserir (cadastrar) uma nova pessoa, sempre no final da lista; 3. consultar se uma pessoa está cadastrada, através do seu código. Se estiver, o programa deve  imprimir  os  dados  desta  pessoa;  4.  remover  uma  pessoa;  e  5. encerrar  o  programa,  destruindo  a  lista  de  pessoas.  O  programa  deve implementar uma função para cada opção disponível no menu.

#include <stdio.h>
#include <stdlib.h>

void main(int argc, char const *argv[])
{

	
	
	pessoa *gabriel = (pessoa *) malloc(sizeof(pessoa));

	gabriel->codigo = 1;

	printf("codigo: %d\n", gabriel->codigo);


}

int inicializarLista(){

	//Definir estrutura da pessoa
	typedef struct pessoa
	{
		int codigo; //Valores de 1 a 50
		char nome[30];
		int idade;
		float altura;
		struct pessoa *anterior;
		struct pessoa *proxima;

	}pessoa;

	//Definir estrutura da lista
	typedef struct lista
	{
		pessoa *inicioDaLista;
		pessoa *finalDaLista;
		int tamanhoDaLista;
	}lista;

	//Alocar uma lista
	lista = (lista *) malloc(sizeof(lista));
	
	return 1;
}