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

	//Verificar se a arvore foi criada
	if (!validarAlocacaoDeMemoria(raiz))
	{
		printf("\nA arvore ainda nao foi criada. Escolha a opcao 1 do menu para criar a arvore.\n");
		limparErros();
		return true;
	}

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

	//Verificar se a arvore foi criada
	if (!validarAlocacaoDeMemoria(raiz))
	{
		printf("\nA arvore esta vazia.\n");
		limparErros();
		return true;
	}

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
		printf("\nA arvore esta vazia.\n");

		return true;
	}

	if (DEBUG == true) printf("A raiz da arvore nao e nula.\n");

	//Criar e limpar vetor de caracteres
	char palavra[TAMANHO_DA_LINHA];
	for (int i = 0; i < TAMANHO_DA_LINHA; i++) palavra[i] = '\0';
	int letraAtual = 0;

	//Criar item auxiliar e lista de itens para verificar
	itemDaArvore* itemAuxiliar = raiz;
	itemDaArvore* listaDeItens[QUANTIDADE_ITEM_ARVORE];

	//Incluir a raiz na lista
	listaDeItens[0] = raiz;

	//Percorrer cada item da árvore
	while (listaDeItens[0] != NULL)
	{
		if (DEBUG == true) printf("\nInicio da busca de letras em um item da arvore...\n");

		//Percorrer cada vetor do item da árvore
		for (int i = 0; i < TAMANHO_DO_ALFABETO; i++)
		{
			if (DEBUG == true) printf("\nInicio da iteracao '%d'...\n", i);

			if (itemAuxiliar->proximaLetra[i] == NULL)
			{
				if (DEBUG == true) printf("A letra '%c' esta vazia neste item. Iteracao '%d'\n", (i + 'a'), i);

				//Verificar se foi cadastrado um código
				if (itemAuxiliar->chave > -1)
				{
					if (DEBUG == true) printf("A chave deste item e maior que '-1'. Sua chave e: '%d'\n", itemAuxiliar->chave);

					printf("Palavra: '%s'\n", palavra);
				}

				//Verifica se esta é a última letra do alfabeto
				if (i == (TAMANHO_DO_ALFABETO - 1))
				{
					if (DEBUG == true) printf("Esta e a ultima letra do item. Letra '%c'. O item foi percorrido completamente.\n", (i + 'a'));

					//Verificar se a lista de itens esta vazia
					if (listaDeItens[0] == NULL)
					{
						if (DEBUG == true) printf("O primeiro elemento da lista de itens esta vazio. A arvore foi percorrida completamente. Retornando true...\n", (i + 'a'));

						return true;
					}

					//Verifica se a lista nao esta vazia
					if (listaDeItens[0] != NULL)
					{
						if (DEBUG == true) printf("O primeiro elemento da lista de itens nao esta vazio. Procurando este item na lista para remove-lo...\n");

						//Procurar item na lista para apaga-lo
						for (int j = 0; j < QUANTIDADE_ITEM_ARVORE; j++)
						{
							if (DEBUG == true) printf("Procurando na posicao '%d' da lista...\n", j);

							//Procurando item na lista para apaga-lo
							if (listaDeItens[j] == itemAuxiliar)
							{

								if (DEBUG == true) printf("O item foi encontrado na posicao '%d' da lista. Removendo o item...\n", j);

								listaDeItens[j] = NULL;

								//Realocar espaços em branco na lista
								if (j < (QUANTIDADE_ITEM_ARVORE - 1))
								{
									if (DEBUG == true) printf("Este nao e o ultimo elemento da lista. Posicao '%d' da lista. Removendo espacos vazios da lista...\n", j);

									if (listaDeItens[j + 1] != NULL)
									{
										if (DEBUG == true) printf("A proxima posicao da lista nao esta vazia. Proxima posicao: '%d'\n", j);

										int k = j;
										while (k < QUANTIDADE_ITEM_ARVORE)
										{
											if (DEBUG == true) printf("Inicio da busca por elementos nao vazios. Posicao '%d' da lista.\n", k);

											if ((listaDeItens[k + 1]) != NULL)
											{
												if (DEBUG == true) printf("A proxima posicao da lista nao esta vazia. Proxima posicao '%d'. Copiando a proxima posicao para a posicao atual ('%d')...\n", (k + 1), k);

												listaDeItens[k] = listaDeItens[k + 1];
											}
											if (DEBUG == true) printf("Incrementando posicao '%d' da lista.\n", k);

											k++;
										}
									}
								}

								break;
							}

							if (j == (QUANTIDADE_ITEM_ARVORE - 1))
							{
								lancarErro(39);
								return false;
							}
						}

						if (listaDeItens[0] == NULL) break;

						//Procurar item mais recente da lista
						for (int j = 0; j < QUANTIDADE_ITEM_ARVORE; j++)
						{
							if (DEBUG == true) printf("Procurando na posicao '%d' da lista...\n", j);

							if (listaDeItens[j] == NULL) {

								if (DEBUG == true) printf("O item foi encontrado na posicao '%d' da lista.\n", j);

								if (listaDeItens[j - 1] == NULL)
								{
									lancarErro(38);
									return false;
								}

								if (DEBUG == true) printf("Coletando item anterior da lista. Iteracao '%d'.\n", j);

								itemAuxiliar = listaDeItens[j - 1];

								if (DEBUG == true) printf("O item foi coletado. Iteracao '%d'. Saindo do 'for'... \n", j);

								break;
							}

							if (j == (QUANTIDADE_ITEM_ARVORE - 1))
							{
								itemAuxiliar = listaDeItens[j];
							}
						}

						if (DEBUG == true) printf("saindoooo\n");

						return true;
					}
				}

				if (itemAuxiliar->proximaLetra[i] != NULL)
				{
					if (DEBUG == true) printf("O vetor nao e nulo. Iteracao '%d'\n", i);

					palavra[letraAtual] = i + 'a';
					letraAtual++;

					itemAuxiliar = itemAuxiliar->proximaLetra[i];

					break;
				}

				if (DEBUG == true) printf("Final da iteracao '%d' do for...\n", i);
			}

			if (itemAuxiliar->proximaLetra[i] != NULL)
			{



			}

			if (DEBUG == true) printf("Saiu do for. quantidade '%d'\n", QUANTIDADE_ITEM_ARVORE);

		}
	}

	if (palavra[0] == '\0') printf("\nA arvore foi percorrida totalmente. Nenhuma palavra foi encontrada.\n");
	if (palavra[0] != '\0') printf("\nA arvore foi percorrida totalmente. Todas as palavras encontradas foram listadas.\n");

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