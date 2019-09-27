#include <stdbool.h>
#include <stdlib.h>
//#include <conio.h>

void pausa(){
	system("pause");
}
void limparTela(){
	
	//printf("\e[H\e[2J");
	system("cls");

}

int validarAlocacaoLista(tipoLista *lista){
	
	if (lista == NULL) {
		limparTela();
		printf("Não foi possível alocar memória. Por favor tente novamente.\n");		
		return 0;
	}

	return 1;
	
}

bool validacaoListaCriada(int opcao, bool *listaCriada){
	
	if (
		listaCriada == false &&
		opcao != 1 &&
		opcao != 5
		)
	{
		limparTela();
		printf("Por favor, crie a lista primeiro.\n");
		pausa();
		return 0;
	}

	return 1;
	
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

