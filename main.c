//Implementar  uma  lista  duplamente  encadeada  para  o  registro  de pessoas.  O  programa  deve  armazenar,  para  cada  pessoa,  os  seguintes dados:  código  (inteiro,  com  valores  de  1  a  50)  nome  (com  até  30 caracteres), idade (inteiro)e altura (real). O programa deve implementar um menu que permita ao usuário: 1. criar a lista de pessoas; 2. inserir (cadastrar) uma nova pessoa, sempre no final da lista; 3. consultar se uma pessoa está cadastrada, através do seu código. Se estiver, o programa deve  imprimir  os  dados  desta  pessoa;  4.  remover  uma  pessoa;  e  5. encerrar  o  programa,  destruindo  a  lista  de  pessoas.  O  programa  deve implementar uma função para cada opção disponível no menu.

#include <stdio.h>
#include <stdlib.h>

void main(int argc, char const *argv[])
{

	//Definir estrutura da pessoa
	typedef struct tipoPessoa
	{
		int codigo; //Valores de 1 a 50
		char nome[30];
		int idade;
		float altura;
		struct tipoPessoa *anterior;
		struct tipoPessoa *proxima;
	}tipoPessoa;

	//Definir estrutura da lista
	typedef struct tipoLista
	{
		tipoPessoa *inicioDaLista;
		tipoPessoa *finalDaLista;
		int tamanhoDaLista;
	}tipoLista;

	//Alocar uma lista
	tipoLista *lista;
	//lista = (lista *) malloc(sizeof(lista));
	lista = NULL;
	if (lista != NULL) menu();
	else {
		printf("Não foi possível alocar memória para a lista. Por favor tente novamente.\n");
		getchar();
		exit();
	}

	inicializarLista();
	
	tipoPessoa *gabriel = (tipoPessoa *) malloc(sizeof(tipoPessoa));

	gabriel->codigo = 1;

	printf("codigo: %d\n", gabriel->codigo);


}

int inicializarLista(){


	return 1;
}

int menu (){
	return 0;
}