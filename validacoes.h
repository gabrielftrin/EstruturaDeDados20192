#include <stdbool.h>
#include <stdlib.h>

bool listaVazia(tipoLista* lista) {	
	
	if (
		lista->inicioDaLista == NULL &&
		lista->finalDaLista == NULL &&
		lista->tamanhoDaLista == 0 &&
		lista->listaZerada == (bool *) true
	){
		printf("A lista esta vazia.\n");
		return true;		
	}
	
	return false;
}

void pausa(){
	system("pause");
}

void limparTela(){		
	system("cls");
}

bool validarAlocacaoLista(tipoLista *lista){
	
	if (lista == NULL) {
		limparTela();
		printf("Não foi possível alocar memória para lista. Por favor tente novamente.\n");		
		return false;
	}

	return true;
}

//Retorna false se a lista NÃO for válida
bool validacaoListaCriada(tipoLista *lista){
			 
	if (lista->tamanhoDaLista == -1){
		limparTela();
		printf("Por favor, crie a lista primeiro.\n");
		pausa();
		return false;
	}

	return true;
}

// Se NÃO for natural, retorna zero
int lerNaturalValido(){

	int numero;	
	
	if(scanf("%d", &numero)){
		if(numero >= 0)
			return numero;
	}
		
	limparTela();
	printf("Por favor, informe um número inteiro.\n");	
	return 0;
}


/*
int lerOpcaoValida(){
	
	int opcao;
	opcao = lerInteiroValido();	
			
	if (opcao == 0) lerOpcaoValida();

	return opcao;
}
*/

//Se não conseguir alocar memória, retorna falso e mostra erro na tela
bool validarAlocacaoPessoa(tipoPessoa* pessoa) {

	if (pessoa == NULL) {
		limparTela();
		printf("Não foi possível alocar memória para a pessoa. Por favor tente novamente.\n");
		return false;
	}

	return true;
}
