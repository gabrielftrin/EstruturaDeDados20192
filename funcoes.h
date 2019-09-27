#include "estruturas.h"
#define QUANTIDADE_FUNCOES_MENU 2
#define TAMANHO_NOME_FUNCAO 50

void mensagemErroAlocacaoMemoria(){
	
	printf("Não foi possível alocar memória. Por favor tente novamente.\n");
}

int inicializarLista(){
/*
	//Tentar alocar memoria para o cabeçalho da lista
	tipoLista *lista = malloc(sizeof(lista));	

	//Verificar alocação
	if (lista == NULL) {
		mensagemErroAlocacaoMemoria();
		getchar();
		return 0;		
	}
		
	}

*/
	return 0;
}



void imprimirOpcoesDoMenu(){

	//Cabeçalho da impressão do menu
	printf("\n===== Trabalho prático 1 - Lista de pessoas =====\n");
	printf("Aluno: Gabriel Fernandes Trindade, RM 201511287\n");

	//preparação
	char funcoesdomenu[TAMANHO_NOME_FUNCAO][QUANTIDADE_FUNCOES_MENU];
	/*
	for (int i = 0; i < QUANTIDADE_FUNCOES_MENU; ++i)
	{
		funcoesdomenu[i] = "a"; 
	}
	*/

	funcoesdomenu[TAMANHO_NOME_FUNCAO][0] = "nome de teste funcao"; 

/*
	//Opções do menu	
	for (int i = 0; i < QUANTIDADE_FUNCOES_MENU; ++i)
	{
		printf("%d) Letra: %s \n", i,funcoesdomenu[i]);
	}
*/
	printf("\n%s\n", funcoesdomenu[TAMANHO_NOME_FUNCAO][0]);
	

/*
	criar a lista de pessoas; 
	2. inserir (cadastrar) uma nova pessoa, sempre no final da lista; 
	3. consultar se uma pessoa está cadastrada, através do seu código. Se estiver, o programa deve  imprimir  os  dados  desta  pessoa;  
	4.  remover  uma  pessoa;  e  
	5. encerrar  o  programa,  destruindo  a  lista  de  pessoas.
	*/
}

int menu (){


	//inicializarLista();
	imprimirOpcoesDoMenu();
	tipoPessoa *gabriel = (tipoPessoa *) malloc(sizeof(tipoPessoa));

	gabriel->codigo = 1;

	printf("codigo: %d\n", gabriel->codigo);
	return 0;
} 