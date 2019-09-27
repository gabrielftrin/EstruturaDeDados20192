#include "estruturas.h"

int validarAlocacaoLista(tipoLista *lista){
	
	if (lista == NULL) {
		printf("Não foi possível alocar memória. Por favor tente novamente.\n");
		return 0;
	}

	return 1;
	
}

void imprimirOpcoesDoMenu(){

	//Cabeçalho da impressão do menu
	printf("\n===== Trabalho prático 1 - Lista de pessoas =====\n");
	printf("Aluno: Gabriel Fernandes Trindade, RM 201511287\n\n");

	//1. criar a lista de pessoas;
	printf("1) Criar a lista de pessoas\n");
	//2. inserir (cadastrar) uma nova pessoa, sempre no final da lista;
	printf("2) Cadastrar uma nova pessoa no final da lista\n");
	//3. consultar se uma pessoa está cadastrada, através do seu código. Se estiver, o programa deve  imprimir  os  dados  desta  pessoa; 
	printf("3) Consultar uma pessoa pelo código\n");
	// 4.  remover  uma  pessoa;
	printf("4) Remover uma pessoa\n");
	//5. encerrar  o  programa,  destruindo  a  lista  de  pessoas.
	printf("5) Encerrar o programa\n\n");

}

int lerInteiroValido(){

	char caractereDigitado;
	int tipo;

	tipo = scanf("%d", &caractereDigitado);

	if (tipo == 1)
		return caractereDigitado;

	return 0;

}

//===Funções do Menu===//

int criarListaDePessoas(){

	//Declarar variável
	tipoLista *lista;

	//Alocar memória
	lista = malloc(sizeof(tipoLista));
	//Validar alocação
	if (!validarAlocacaoLista(lista)) return 0;

	lista->inicioDaLista = NULL;
	lista->finalDaLista = NULL;
	lista->tamanhoDaLista = 0;

	return 1;

}

int executarFuncaoDoMenu(int opcao){

	switch (opcao){
	
		case 1:
			criarListaDePessoas();
			break;
		case 2:
			//cadastrarUmaPessoa();
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

int menu (){

	int opcao;
	
	do {

		//Mostrar o menu na tela
		imprimirOpcoesDoMenu();

        //Ler o conteúdo digitado
		opcao = lerInteiroValido();

		//Executar função do menu
		if (!executarFuncaoDoMenu(opcao)) opcao=5;
		//Limpar a tela e sair ou abri o menu de novo??

		printf("tamanho> %d\n", lista->tamanhoDaLista);
		printf("inicio %p\n", lista->inicioDaLista);
		printf("final %p\n", lista->finalDaLista);
	} while(opcao != 5);
	
	return 0;

} 
/*
tipoPessoa *gabriel = (tipoPessoa *) malloc(sizeof(tipoPessoa));

	gabriel->codigo = 1;

	printf("codigo: %d\n", gabriel->codigo);

	*/