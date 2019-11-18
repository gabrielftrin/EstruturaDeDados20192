#include "execucao.h"

//Criar a árvore
bool criarArvore() {

	if (DEBUG == true) printf("Iniciando a funcao, 'criarArvore'...\n");

	//Anular a raiz existente
	raiz = NULL;

	//Alocar memória para raiz
	raiz = alocarItemDaArvore();

	//Validar alocação de memória
	if (!validarArvoreCriada(raiz)) return false;

	//Imprimir mensagem de sucesso na tela
	mensagemSucesso();

	return true;
}

//Inserir palavras do arquivo na árvore
bool inserirPalavraNaArvore() {

	if (DEBUG == true) printf("Iniciando a funcao, 'inserirPalavraNaArvore'...\n");

	//Declarar e abrir arquivo, validar abertura do arquivo
	FILE* arquivo = fopen("arquivo.txt", "r");
	if (!validarAlocacaoDeMemoria(arquivo)) return false;

	if (DEBUG == true) printf("O arquivo foi aberto com sucesso.\n");

	//Declarar linha de leitura atual
	string linha = (string)malloc(sizeof(char) * TAMANHO_DA_LINHA);
	if (!validarAlocacaoDeMemoria(linha)) return false;

	if (DEBUG == true) printf("Memoria para linha alocada com sucesso. Lendo primeira linha do arquivo...\n");

	//Ler quantidade de entradas e validar alocação de memória
	if (!validarAlocacaoDeMemoria(fgets(linha, TAMANHO_DA_LINHA, arquivo))) return false;

	if (DEBUG == true) printf("Primeira linha lida com sucesso. Convertendo codigo para inteiro...\n");

	//Converter texto para inteiro e validar conversão
	int entradas = atoi(linha);
	if (!validarNumeroNaturalPositivo(entradas)) return false;

	if (DEBUG == true) printf("Codigo convertido com sucesso. Iniciando a leitura das linhas do arquivo...\n");

	//Ler as linhas do arquivo
	if (!lerLinhasDoArquivo(linha, arquivo, entradas)) return false;

	if (DEBUG == true) printf("As linhas do arquivo foram lidas com sucesso. Fechando o arquivo...\n");

	//Fehar o arquivo
	if (fclose(arquivo) == EOF)
	{
		lancarErro(30);
		perror(MENSAGEM_DE_ERRO);
		return false;
	}

	if (DEBUG == true) printf("O arquivo fechou com sucesso.\n");

	//Imprimir mensagem de sucesso na tela
	mensagemSucesso();

	return true;
}

//Ler uma palavra do teclado e consultar na árvore
bool consultarPalavraNaArvore() {

	if (DEBUG == true) printf("Iniciando a funcao, 'consultarPalavraNaArvore'...\n");

	//Declara palavra a ser lida
	string palavra = NULL;

	//Pedir ao  usuário que digite a palavra
	printf("\nDigite a palavra que deseja buscar: (Ate %d caracteres)\n\n", TAMANHO_DA_LINHA);

	//Ler palavra do teclado
	palavra = lerTextoDoTeclado(TAMANHO_DA_LINHA);
	if (!validarAlocacaoDeMemoria(palavra)) return false;

	if (DEBUG == true) printf("Palavra lida com sucesso. Consultando a palavra na arvore...\n");

	//Verificar se a palavra está na árvore
	if (!consultarUmaDeterminadaPalavraNaArvore(palavra)) return false;

	if (DEBUG == true) printf("Consulta realizada com sucesso.\n");

	//Imprimir mensagem de sucesso na tela
	mensagemSucesso();

	return true;
}

//Listar todas as palavras cadastradas na árvore
bool listarPalavrasDaArvore() {

	if (DEBUG == true) printf("Iniciando a funcao, 'listarPalavrasDaArvore'...\n");

	//Verifica se a raiz da árvore está vazia
	if (raiz == NULL)
	{
		printf("\nA raiz da arvore esta vazia.\n");
		mensagemSucesso();
		return true;
	}

	if (DEBUG == true) printf("A raiz da arvore nao e nula.\n");

	//Criar e limpar vetor de caracteres
	char palavra[TAMANHO_DA_LINHA];
	for (int i = 0; i < TAMANHO_DA_LINHA; i++) palavra[i] = '\0';
	int letraAtual = 0;

	//Criar item auxiliar
	itemDaArvore* itemAuxiliar = raiz;
	itemDaPilha* itemPilha = NULL;
	int vetorDoItemDaArvore = 0;

	//Percorrer cada item da árvore
	while (itemAuxiliar != NULL)
	{
		if (DEBUG == true) printf("\nInicio da iteracao no item...\n");

		if (itemPilha != NULL)
		{
			vetorDoItemDaArvore = itemPilha->vetorParaVerificar;
		}

		//Percorrer cada vetor de um item da árvore
		for (int i = vetorDoItemDaArvore; i < TAMANHO_DO_ALFABETO; i++)
		{
			if (DEBUG == true) printf("\nInicio da iteracao '%d'...\n", i);

			if (itemAuxiliar->proximaLetra[i] == NULL)
			{
				if (DEBUG == true) printf("O vetor e nulo. Iteracao '%d'\n", i);

				//Verificar se foi cadastrado um código
				if (itemAuxiliar->chave > -1)
				{
					printf("Palavra: '%s'\n", palavra);


					vetorDoItemDaArvore = (i + 1);
					if (vetorDoItemDaArvore >= TAMANHO_DO_ALFABETO)
					{
						itemPilha = removerTopoDaPilha(pilhaDeChamadas);

						if (itemPilha == NULL)
						{
							mensagemSucesso();
							return true;
						}
					}
					break;
				}

				//Verifica se esta é a última letra do alfabeto
				if (i == (TAMANHO_DO_ALFABETO - 1))
				{
					if (itemAuxiliar->chave == -1)
					{
						itemPilha = removerTopoDaPilha(pilhaDeChamadas);

						if (itemPilha == NULL)
						{
							mensagemSucesso();
							return true;
						}
					}
				}
			}

			if (itemAuxiliar->proximaLetra[i] != NULL)
			{
				if (DEBUG == true) printf("O vetor nao e nulo. Iteracao '%d'\n", i);

				palavra[letraAtual] = i + 'a';
				letraAtual++;
				if (!inserirItemNaPilha((i + 1), itemAuxiliar, pilhaDeChamadas)) return false;
				itemAuxiliar = itemAuxiliar->proximaLetra[i];
				break;
			}

			if (DEBUG == true) printf("Final de uma iteracao '%d' do for...\n", i);
		}

		if (DEBUG == true) printf("Saiu do for. VetorDoItemDaArvore '%d' palavra '%s' letraAtual '%d' '%c'\n", vetorDoItemDaArvore, palavra, letraAtual, letraAtual);
	}

	if (DEBUG == true) printf("Saiu o while que percorre a arvore.\n");


	if (listaDeCodigosDeErro[0] != 0)
	{
		if (DEBUG == true) printf("Algum erro foi lancado. Retornando falso...\n");

		return false;
	}

	if (DEBUG == true) printf("Retornando true no final da funcao...\n");

	return true;
}

//Limpar todos os nós da árvore
bool removerArvore() {

	if (DEBUG == true) printf("Iniciando a funcao, 'removerArvore'...\n");

	//Anular a raiz
	raiz = NULL;

	//Imprimir mensagem de sucesso na tela
	mensagemSucesso();

	return true;
}