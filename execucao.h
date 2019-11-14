#include "validacoes.h"

//Imprime uma mensagem de sucesso na tela
void mensagemSucesso() {

	printf("\nOperacao realizada com sucesso.\n");
}

//Alocar memória para um novo item da árvore
itemDaArvore* alocarItemDaArvore() {

	itemDaArvore* novoItem = (itemDaArvore*)malloc(sizeof(itemDaArvore));

	if (!validarAlocacaoDeMemoria(novoItem)) return NULL;

	novoItem->chave = -1;

	for (int i = 0; i < TAMANHO_DO_ALFABETO; i++)
	{
		novoItem->proximaLetra[i] = NULL;
	}

	return novoItem;
}

//Verificar se uma determinada palavra está cadastrada na arvore
bool consultarUmaDeterminadaPalavraNaArvore(string palavra) {

	//Verificar se a palavra é nula
	if (!validarAlocacaoDeMemoria(palavra)) return false;

	//Verificar se a raiz é nula
	if (!validarAlocacaoDeMemoria(raiz)) return false;

	//Criar ponteiro auxiliar do tipo 'item da arvore'
	itemDaArvore* itemAuxiliar = raiz;

	//Percorrer a árvore até o final da palavra ou a palavra não existir
	for (int i = 0; i < (strlen(palavra) - 1); i++)
	{
		//Verifica se a letra corrente/atual está na árvore
		if (itemAuxiliar->proximaLetra[*palavra - 'a'] == NULL) {

			//Se ainda não tiver chegado no final da palavra
			if (i < (strlen(palavra) - 2))
			{
				//Sai do laço
				printf("\nA palavra nao esta na arvore.\n");
				return true;
			}

			//Se chegou no final da palavra
			if (i == (strlen(palavra) - 2))
			{
				//Verifica se código foi preenchido
				if (itemAuxiliar->chave > -1)
				{
					printf("\nA palavra '%s' esta na arvore.\nSua chave e: %d\n", palavra, itemAuxiliar->chave);
					return true;
				}

				//Verifica se o código é -1
				if (itemAuxiliar->chave == -1)
				{
					printf("\nA letras da palavra '%s' estao na arvore.\nPorém sua chave/código é igual a: %d\n", palavra, itemAuxiliar->chave);
					return true;
				}

				lancarErro(29);
				return false;
			}
		}

		//Passa para o próximo item
		itemAuxiliar = itemAuxiliar->proximaLetra[*palavra - 'a'];
	}

	lancarErro(28);
	return false;
}