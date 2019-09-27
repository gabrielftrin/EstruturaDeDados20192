#include <stdbool.h>
#include <stdlib.h>

bool listaVazia(tipoLista* lista) {

	if (
		lista->inicioDaLista == NULL &&
		lista->finalDaLista == NULL &&
		lista->tamanhoDaLista == 0 &&
		lista->listaZerada == true
		)
		return true;

	return false;

}

void pausa(){
	system("pause");
}

void limparTela(){
	
	//printf("\e[H\e[2J");
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

/*
int lerInteiroValido(){

	char caractere;
	int tipo;
	
	scanf("%c", &caractere);
	
	if (caractere < '1' || caractere > '5'){
		limparTela();
		printf("Por favor, informe um número natural entre 1 e 5.\n");
		return 0;
	}
	
	return caractere;
}
*/

/*
int lerOpcaoValida(){
	
	int opcao;
	opcao = lerInteiroValido();	
			
	if (opcao == 0) lerOpcaoValida();

	return opcao;
}
*/

bool validarAlocacaoPessoa(tipoPessoa* pessoa) {

	if (pessoa == NULL) {
		limparTela();
		printf("Não foi possível alocar memória para a pessoa. Por favor tente novamente.\n");
		return false;
	}

	return true;

}
