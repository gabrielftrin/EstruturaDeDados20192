#include "estruturas.h"
#include "validacoes.h"
#include <stdbool.h>

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

//Zerar uma lista com ponteiro já alocado
int criarListaDePessoas(tipoLista *lista){	

	lista->inicioDaLista = NULL;
	lista->finalDaLista = NULL;
	lista->tamanhoDaLista = 0;
	lista->listaZerada = true;
	printf("Lista criada com sucesso.\n");

	return 1;

}

bool cadastrarUmaPessoa (tipoLista *lista){

	//Validar alocacao de memoria lista
	if (!validarAlocacaoLista(lista)) return false;

	//Verificar se a funcao criarListaDePessoas já foi chamada
	if (!validacaoListaCriada(lista)) return false;

	//Alocar memória para a pessoa
	tipoPessoa* pessoa;
	pessoa = malloc(sizeof(tipoPessoa));

	//Validar alocação de memória da pessoa
	if (!validarAlocacaoPessoa(pessoa)) return false;

	//Ler dados da pessoa

	//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
	/*
	int codigo; //Valores de 1 a 50
	char nome[30];
	int idade;
	float altura;
	*/
	scanf("numero: %d\n", &pessoa->codigo);
	
	
	//Se a lista estiver vazia
	if (listaVazia(lista)) {

		//lista
		lista->inicioDaLista = pessoa;		
		bool* listaZerada = false;

		//ponteiros da pessoa
		pessoa->anterior = NULL;
		pessoa->proximo = NULL;
	
	//Se a lista não for vazia
	} else {		

		//Ajustar ponteiros da pessoa
		pessoa->anterior = lista->finalDaLista;

	}
	
	//Configurar estrutura da lista	
	lista->finalDaLista = pessoa;
	lista->tamanhoDaLista++;

	//Configurar estrutura da pessoa
	pessoa->proximo = NULL;

	return true;
}

bool executarFuncaoDoMenu(int opcao, tipoLista *lista){

	switch (opcao){
	
		case 1:
			if (criarListaDePessoas(lista)) { break; }
			return false;
		case 2:			
			if (cadastrarUmaPessoa(lista)) { break; }
			return false;
		case 3:
			printf("codigo: %d\n", lista->inicioDaLista->codigo);
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

	return true;
}

int menu (tipoLista *lista){	
	
	int opcao;	

	do {	

		//Mostrar o menu na tela
		imprimirOpcoesDoMenu();

        //Ler o conteúdo digitado
		scanf("%d", &opcao);	
		
		//VALIDAR OPÇÃO DIGITADA====================
		//Se o conteúdo retornado for zero, fecha o programa
        //if (opcao == 0) return 0;
			
		//Verificar se a lista já foi criada
		//if (!validacaoListaCriada(opcao,listaCriada)) menu(lista);
		//===========================================

		//Executar função do menu
		if (!executarFuncaoDoMenu(opcao,lista)) opcao=5;
		
		//pausa();
		//limparTela();		

	} while(opcao != 5);
	
	return 0;
} 

bool inicializarPrograma(){

	//Declarar lista
	tipoLista *lista = NULL;
	//Alocar memória
	lista = malloc(sizeof(tipoLista));
	//Validar alocação
	if (!validarAlocacaoLista(lista)) return false;

	//Pré configurar lista
	lista->listaZerada = false;
	lista->tamanhoDaLista = -1;
	
	//Exucutar menu
	menu(lista);

	return true;
}

/* tipoPessoa *gabriel = (tipoPessoa *) malloc(sizeof(tipoPessoa));

	gabriel->codigo = 1;

	printf("codigo: %d\n", gabriel->codigo);

	*/