#include "execucao.h"

//Criar a árvore
bool criarArvore() {

	//Anular a raiz existente
	raiz = NULL;

	//Alocar memória para raiz
	raiz = alocarItemDaArvore();

	//Validar alocação de memória
	if (!validarAlocacaoDeMemoria(raiz)) return false;

	//Imprimir mensagem de sucesso na tela
	mensagemSucesso();

	return true;
}

//Inserir palavras do arquivo na árvore
bool inserirPalavraNaArvore() {

	//Declarar e abrir arquivo, validar abertura do arquivo
	FILE* arquivo = fopen("arquivo.txt", "r");
	if (!validarAlocacaoDeMemoria(arquivo)) return false;

	//Declarar linha de leitura atual
	string linha = (string)malloc(sizeof(char) * TAMANHO_DA_LINHA);
	if (!validarAlocacaoDeMemoria(linha)) return false;

	//Ler quantidade de entradas e validar alocação de memória
	if (!validarAlocacaoDeMemoria(fgets(linha, TAMANHO_DA_LINHA, arquivo))) return false;

	//Converter texto para inteiro e validar conversão
	int entradas = atoi(linha); if (!validarNumeroNaturalPositivo(entradas)) return false;

	//Ler as linhas do arquivo
	if (!lerLinhasDoArquivo(linha, arquivo, entradas)) return false;

	//Fehar o arquivo
	if (fclose(arquivo) == EOF)
	{
		lancarErro(30);
		perror(MENSAGEM_DE_ERRO);
		return false;
	}

	//Imprimir mensagem de sucesso na tela
	mensagemSucesso();

	return true;
}

//Ler uma palavra do teclado e consultar na árvore
bool consultarPalavraNaArvore() {

	//Declara palavra a ser lida
	string palavra = NULL;

	//Pedir ao  usuário que digite a palavra
	printf("\nDigite a palavra que deseja buscar: (Ate %d caracteres)\n\n", TAMANHO_DA_LINHA);

	//Ler palavra do teclado
	palavra = lerTextoDoTeclado(TAMANHO_DA_LINHA);

	//Validar leitura
	if (!validarAlocacaoDeMemoria(palavra)) return false;

	//Verificar se a palavra está na árvore
	if (!consultarUmaDeterminadaPalavraNaArvore(palavra)) return false;

	return true;
}

//Listar todas as palavras cadastradas na árvore
bool listarPalavrasDaArvore() {

	string teste;
	printf("valor: ");
	scanf("%s", teste);
	printf("teste %s\n");

	string apontador = teste;
	printf("apontador %s\n", apontador);

	printf("limpando teste...");
	free(teste);

	printf("valor de apontador %s\n", apontador);

	return true;
}

//Limpar todos os nós da árvore
bool removerArvore() {

	//raiz = alocarItemDaArvore();
	//raiz->proximaLetra[2] = alocarItemDaArvore();

	if (raiz != NULL)
	{
		itemDaArvore* itemAuxiliar = raiz;
		itemDaArvore* itemPai = NULL;
		int posicaoPai = -1;
		int i = 0;
		int contador = -1;
		while (raiz != NULL)
		{
			i = 0;
			if (DEBUG == true) printf("inicio no while PRINCIPAL. iteracao: %d\n", i);
			if (DEBUG == true) printf("ponteiro do pai: %p\n", itemPai);

			while (i < TAMANHO_DO_ALFABETO)
			{
				contador++;
				if (DEBUG == true) printf("percorrendo no, iteracao (i) %d\n", i);
				if (contador > 60) return false;

				if (itemAuxiliar->proximaLetra[i] == NULL)
				{
					if (DEBUG == true) printf("a iteracao %d esta nula\n", i);

					if (i == (TAMANHO_DO_ALFABETO - 1))
					{
						if (DEBUG == true) printf("a posicao %d e a ultima... apagando no...\n");
						free(itemAuxiliar);

						if (itemPai != NULL)
						{
							if (DEBUG == true) printf("apagando referencia do pai, vetor-pai:%d...\n", posicaoPai);
							itemPai->proximaLetra[posicaoPai] = NULL;
							itemPai = NULL;
						}

						if (itemPai == NULL)
						{
							if (DEBUG == true) printf("o pai e nulo. saindo da funcao.\n");
							mensagemSucesso();
							raiz = NULL;
							return true;
						}

						if (DEBUG == true) printf("recebendo ponteiro da raiz...\n");
						itemAuxiliar = raiz;

						if (raiz == NULL)
						{
							if (DEBUG == true) printf("A raiz é nula. Saindo da função...\n");
							return true;
						}

						break;
					}
				}

				if (itemAuxiliar->proximaLetra[i] != NULL)
				{
					if (DEBUG == true) printf("a posicao %d nao e nula\n", i);
					itemPai = itemAuxiliar;
					posicaoPai = i;
					itemAuxiliar = itemAuxiliar->proximaLetra[i];
					if (DEBUG == true) printf("..........indo para o proximo no... i=%d\n", i);
					break;
				}

				if (DEBUG == true) printf("incrementando iteracao... (i) %d\n", i);
				i++;
			}
			if (DEBUG == true) printf("ponteiro do pai: %p\n", itemPai);
			if (DEBUG == true) printf("saiu do while do NO ATUAL\n");
		}

		if (DEBUG == true) printf("saiu do while PRINCIPAL\n");

	}

	lancarErro(31);
	return false;;
}