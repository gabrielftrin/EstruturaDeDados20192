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


bool lerLinhaDoArquivo() {


}

//Verificar se uma determinada palavra está cadastrada na arvore
bool consultarUmaDeterminadaPalavraNaArvore(string palavra) {

	//Verificar se a palavra é nula
	if (!validarAlocacaoDeMemoria(palavra)) return false;

	//Verificar se a raiz é nula
	if (!validarAlocacaoDeMemoria(raiz)) return false;

	//Criar ponteiro auxiliar do tipo 'item da arvore'
	itemDaArvore* itemAuxiliar = raiz;

	//Verificar o tamanho da palavra
	int tamanho = strlen(palavra);
	printf("antes do for... letra '%c' tamanho do 'for' %d\n", *palavra, tamanho);
	//Percorrer a árvore até o final da palavra ou a palavra não existir
	for (int i = 0; i < tamanho; i++)
	{
		printf("verificando a letra %c\n", (*palavra));
		printf("codigo item atual: %d iteracao %d\n", itemAuxiliar->chave, i);

		//Verifica se a letra corrente/atual está na árvore
		if (itemAuxiliar->proximaLetra[*palavra - 'a'] == NULL) {
			printf("esta posição do vetor de letra é nula.\n");
			//Se ainda não tiver chegado no final da palavra
			if (i < (tamanho - 1))
			{
				//Sai do laço
				printf("\nA palavra nao esta na arvore. iteracao %d\n", i);
				return true;
			}

			//Se chegou no final da palavra
			if (i == (tamanho - 1))
			{
				//Verifica se código foi preenchido
				if (itemAuxiliar->chave > -1)
				{
					printf("\nA palavra %s esta na arvore.\nSua chave e: %d\n", (palavra - i), itemAuxiliar->chave);
					return true;
				}

				//Verifica se o código é -1
				if (itemAuxiliar->chave == -1)
				{
					printf("\nA(s) %d primeira(s) letra(s) da palavra estao na arvore.\nPorém sua chave/código é igual a: %d\n", i, itemAuxiliar->chave);
					return true;
				}

				lancarErro(29);
				return false;
			}
		}

		//Passa para o próximo item
		itemAuxiliar = itemAuxiliar->proximaLetra[*palavra - 'a'];
		printf("próximo item, código: %d iteracao %d\n", itemAuxiliar->chave, i);
		printf("letra %c\n", *palavra);
		palavra++;

		//Se for a ultima iteracao incrementa o tamanho
		if (i == (tamanho - 1)) tamanho++;
	}

	lancarErro(28);
	return false;
}

//Insere uma determinada palavra e um determinado código na árvore
bool inserirDeterminadaPalavraNaArvore(string palavraDaArvore, int codigo) {

	//Criar variável auxiliar
	itemDaArvore* itemAuxiliar = raiz;
	printf("Argumentos recebidos na função de inserir:\npalavra:%s\ncodigo:%d\n", palavraDaArvore, codigo);
	//Calcular tamanho da string para informar no 'for'
	int tamanho = (strlen(palavraDaArvore));
	printf("\ntamanho da palavra (for):%d\n", tamanho);
	//Percorrer a árvore até o final da palavra
	for (int i = 0; i < tamanho; i++)
	{
		//Aloca memória para um novo item se o caractere for nulo
		if (itemAuxiliar->proximaLetra[*palavraDaArvore - 'a'] == NULL) {

			//Alocar novo item da árvore
			itemDaArvore* novoItem = alocarItemDaArvore();
			printf("criando novo no...\n");
			//Validar alocação
			if (!validarAlocacaoDeMemoria(novoItem)) return false;

			//Colocar o novo item na arvore
			itemAuxiliar->proximaLetra[*palavraDaArvore - 'a'] = novoItem;
		}
		printf("%c %d %d\n", *palavraDaArvore, i, (*palavraDaArvore - 'a'));
		//Passa para o próximo item
		itemAuxiliar = itemAuxiliar->proximaLetra[*palavraDaArvore - 'a'];

		//Sair do laço quando for a última letra
		if (i == (tamanho - 1))
		{
			if (itemAuxiliar->chave == -1)
			{
				printf("a chave é -1. Inserido o código %d na árvore\n", codigo);
				//Inserir valor
				itemAuxiliar->chave = codigo;
				printf("chave inserida: %d\n", itemAuxiliar->chave);
				printf("ponteiro do item na letra '%c':%p\n", *palavraDaArvore, itemAuxiliar->proximaLetra[*palavraDaArvore - 'a']);
				return true;
			}

			if (itemAuxiliar->chave > -1)
			{
				printf("a chave é maior que -1... (chave = %d) incrementando tamanho.\n", itemAuxiliar->chave);
				tamanho++;
			}

			printf("a chave (%d) é menor que -1\n", itemAuxiliar->chave);
		}

		//Passar para o próximo caractere
		palavraDaArvore++; printf("proxima letra... ");
	}
	printf("saiu do 'for': %c %d sem inserir a chave na árvore.\n", *palavraDaArvore, (*palavraDaArvore - 'a'));

	return true;
}
