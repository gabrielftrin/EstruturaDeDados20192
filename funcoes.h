#include "estruturas.h"

void mensagemErroAlocacaoMemoria(){
	
	printf("Não foi possível alocar memória. Por favor tente novamente.\n");
}

int inicializarLista(){

	return 1;
}

int menu (){

	inicializarLista();
	
	tipoPessoa *gabriel = (tipoPessoa *) malloc(sizeof(tipoPessoa));

	gabriel->codigo = 1;

	printf("codigo: %d\n", gabriel->codigo);
	return 0;
}
