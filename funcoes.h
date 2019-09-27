#include "estruturas.h"
#include "validacoes.h"
#include <stdbool.h>
//teste
void imprimirOpcoesDoMenu(){

	//Cabeçalho da impressão do menu
	printf("\n===== Trabalho prático 1 - Lista de pessoas =====\n");
	printf("Aluno: Gabriel Fernandes Trindade, RM 201511287\n\n");

	//1. criar a lista de pessoas;
	printf("1) Criar a lista de pessoas\n");
	//2. inserir (cadastrar) uma nova pessoa, sempre no final da lista;
	printf("2) Cadastrar uma nova pessoa no final da lista\n");
	//3. consultar se uma pessoa está cadastrada, através do seu código. 
	//Se estiver, o programa deve  imprimir  os  dados  desta  pessoa; 
	printf("3) Consultar uma pessoa pelo código\n");
	// 4.  remover  uma  pessoa;
	printf("4) Remover uma pessoa\n");
	//5. encerrar  o  programa,  destruindo  a  lista  de  pessoas.
	printf("5) Encerrar o programa\n\n");
}

//===Funções do Menu===//

int criarListaDePessoas(tipoLista *lista){	

	lista->inicioDaLista = NULL;
	lista->finalDaLista = NULL;
	lista->tamanhoDaLista = 0;

	return 1;
}

int cadastrarUmaPessoa (tipoLista *lista){

	if (lista->inicio == NULL){
	
	}

	tipoPessoa pessoa;
	pessoa = malloc (sizeof(tipoPessoa));


}

int executarFuncaoDoMenu(int opcao, tipoLista *lista){

	switch (opcao){
	
		case 1:
			if (!criarListaDePessoas(lista)) return 0;
			break;
		case 2:
			
			if (!cadastrarUmaPessoa(lista)) return 0;
			break;
		case 3:
			//consultarUmaPessoa();
			break;
		case 4:
			//removerUmaPessoa();
			break;
		case 5:
			//sairDoPrograma();
			break;
		default:
			//sairDoPrograma();
			break;
			
	}

	return 1;
}

int menu (tipoLista *lista){
	
	bool *listaCriada = false;	
	int opcao;
	
	do {

		//Mostrar o menu na tela
		imprimirOpcoesDoMenu();

        //Ler o conteúdo digitado
		scanf("%d", &opcao);	
		
		//Se o conteúdo retornado for zero, fecha o programa
        //if (opcao == 0) return 0;
			
		//Verificar se a lista já foi criada
		//if (!validacaoListaCriada(opcao,listaCriada)) menu(lista);

		//Executar função do menu
		if (!executarFuncaoDoMenu(opcao,lista)) opcao=5;
		
		

	} while(opcao != 5);
	
	return 0;
} 

int inicializarPrograma(){

	//Declarar lista
	tipoLista *lista = NULL;
	//Alocar memória
	lista = malloc(sizeof(tipoLista));
	//Validar alocação
	if (!validarAlocacaoLista(lista)) return 0;

	menu(lista);

	return 1;
}

/* tipoPessoa *gabriel = (tipoPessoa *) malloc(sizeof(tipoPessoa));

	gabriel->codigo = 1;

	printf("codigo: %d\n", gabriel->codigo);

	*/