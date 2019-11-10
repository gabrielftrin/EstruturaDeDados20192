#include "validacoes.h"

//Imprime uma mensagem de sucesso na tela
void mensagemSucesso() {

	printf("\nOperacao realizada com sucesso.\n");
}

//Alocar memória para um novo item da árvore
itemDaArvore* alocarItemDaArvore() {

	itemDaArvore* novoItem = (itemDaArvore *) malloc(sizeof(itemDaArvore));

	if (!validarAlocacaoDeMemoria(novoItem)) return NULL;

	novoItem->chave = -1;

	for (int i = 0; i < TAMANHO_DO_ALFABETO; i++)
	{
		novoItem->proximaLetra[i] = NULL;
	}

	return novoItem;
}