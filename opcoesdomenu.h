#include "execucao.h"

//Criar a arvore
bool criarArvore() {

	if (DEBUG) printf("Iniciando a funcao, 'criarArvore'...\n");

	//Anular a raiz existente
	raiz = NULL;

	//Alocar memoria para raiz
	raiz = alocarItemDaArvore();

	//Validar alocacao de memoria
	if (!validarArvoreCriada(raiz)) return false;

	//Imprimir mensagem de sucesso na tela
	printf("\nA arvore foi criada com sucesso.\n");

	return true;
}

//Inserir palavras do arquivo na arvore
bool inserirPalavraNaArvore() {

	if (DEBUG) printf("Iniciando a funcao, 'inserirPalavraNaArvore'...\n");

	//Verificar se a arvore foi criada
	if (!validarAlocacaoDeMemoria(raiz))
	{
		printf("\nA arvore ainda nao foi criada. Escolha a opcao 1 do menu para criar a arvore.\n");
		limparErros();
		return true;
	}

	//Declarar e abrir arquivo, validar abertura do arquivo
	FILE* arquivo = fopen("palavras.txt", "r");
	if (!validarAlocacaoDeMemoria(arquivo))
	{
		printf("\nNao foi possivel abrir o arquivo 'palavras.txt'.\n"
			"Verifique se o arquivo esta salvo na mesma pasta do arquivo 'main.c'.");
		limparErros();
		return false;
	}

	if (DEBUG) printf("O arquivo foi aberto com sucesso.\n");

	//Declarar linha de leitura atual
	string linha = (string)malloc(sizeof(char) * TAMANHO_DA_LINHA);
	if (!validarAlocacaoDeMemoria(linha)) return false;

	if (DEBUG) printf("Memoria para linha alocada com sucesso. Lendo primeira linha do arquivo...\n");

	//Ler quantidade de entradas e validar alocacao de memoria
	if (!validarAlocacaoDeMemoria(fgets(linha, TAMANHO_DA_LINHA, arquivo))) return false;

	if (DEBUG) printf("Primeira linha lida com sucesso. Linha lida: '%s'.\n", linha);

	//Verificar é todos os caracteres da primeira linha sao numericos
	char primeiraLinha[TAMANHO_DA_LINHA]; primeiraLinha[0] = *linha;
	for (int i = 0; i < (int)strlen(primeiraLinha); i++)
	{
		if (primeiraLinha[i] == '\0') break;

		if (DEBUG) printf("Verificando caractere da primeira linha. Iteracao: '%d'. Caractere '%c'\n", i, primeiraLinha[i]);

		if (isdigit(primeiraLinha[i]) == 0)
		{
			printf("Nao foi possivel ler a quantidade de palavras a serem inseridas.\nVerifique se a primeira linha do arquivo contem APENAS a quantidade de palavras a serem inseridas.\n");
			return true;
		}
	}

	//Converter texto para inteiro e validar conversao
	int entradas = atoi(linha);
	if (!validarNumeroNaturalPositivo(entradas)) return false;

	if (DEBUG) printf("Codigo convertido (%d) com sucesso. Iniciando a leitura das linhas do arquivo...\n", entradas);

	//Ler as linhas do arquivo
	if (!lerLinhasDoArquivo(linha, arquivo, entradas)) return false;

	if (DEBUG) printf("As linhas do arquivo foram lidas com sucesso. Fechando o arquivo...\n");

	//Fehar o arquivo
	if (fclose(arquivo) == EOF)
	{
		lancarErro(30);
		perror(MENSAGEM_DE_ERRO);
		return false;
	}

	if (DEBUG) printf("O arquivo fechou com sucesso.\n");

	//Imprimir mensagem de sucesso na tela
	mensagemSucesso();

	return true;
}

//Ler uma palavra do teclado e consultar na arvore
bool consultarPalavraNaArvore() {

	if (DEBUG) printf("Iniciando a funcao, 'consultarPalavraNaArvore'...\n");

	//Verificar se a arvore foi criada
	if (!validarAlocacaoDeMemoria(raiz))
	{
		printf("\nA arvore esta vazia.\n");
		limparErros();
		return true;
	}

	//Declara palavra a ser lida
	string palavra = NULL;

	//Pedir ao  usuario que digite a palavra
	printf("\nDigite APENAS a palavra que deseja buscar: (Ate %d caracteres)\n\n", TAMANHO_DA_LINHA);

	//Ler palavra do teclado
	palavra = lerTextoDoTeclado(TAMANHO_DA_LINHA);
	if (!validarAlocacaoDeMemoria(palavra)) return false;

	if (DEBUG) printf("Palavra lida com sucesso. Consultando a palavra na arvore...\n");

	//Verificar se a palavra esta na arvore
	if (!consultarUmaDeterminadaPalavraNaArvore(palavra)) return false;

	if (DEBUG) printf("Consulta realizada com sucesso.\n");

	//Imprimir mensagem de sucesso na tela
	mensagemSucesso();

	return true;
}

//Listar todas as palavras cadastradas na arvore
bool listarPalavrasDaArvore() {

	if (DEBUG) printf("Iniciando a funcao, 'listarPalavrasDaArvore'...\n");

	//Verifica se a raiz da arvore esta vazia
	if (raiz == NULL)
	{
		printf("\nA arvore ainda nao foi criada.\n");

		return true;
	}

	if (DEBUG) printf("A raiz da arvore nao e nula.\n");

	//Criar e limpar vetor de caracteres
	char palavraAuxiliar[TAMANHO_DA_LINHA];
	for (int i = 0; i < TAMANHO_DA_LINHA; i++) palavraAuxiliar[i] = '\0';
	int letraAtual = 0;

	string palavraLida = (string)malloc(sizeof(char) * TAMANHO_DA_LINHA);
	palavraLida = &palavraAuxiliar[0];

	//Percorrer cada item da arvore
	bool retornoDaLeitura = lerItemDaArvore(raiz, palavraLida, letraAtual);

	if (DEBUG) printf("Saiu da funcao 'lerItemDaArvore'.\n");

	if (DEBUG) getchar();
	if (DEBUG) pausa();

	if (!retornoDaLeitura) printf("\nA arvore foi percorrida totalmente.\nNenhuma palavra foi encontrada.\n");
	if (retornoDaLeitura) printf("\nA arvore foi percorrida totalmente.\nTodas as palavras encontradas foram listadas.\n");

	if (DEBUG) printf("Saiu do while que percorre a arvore.\nRetorno da leitura '%d'", retornoDaLeitura);

	if (listaDeCodigosDeErro[0] != 0)
	{
		if (DEBUG) printf("Algum erro foi lancado. Retornando falso...\n");

		return false;
	}

	if (DEBUG) printf("Retornando true no final da funcao...\n");

	if (DEBUG) getchar();
	if (DEBUG) pausa();
	if (DEBUG) getchar();

	mensagemSucesso();
	return true;
}

//Limpar todos os nos da arvore
bool removerArvore() {

	if (DEBUG) printf("Iniciando a funcao, 'removerArvore'...\n");

	//Anular a raiz
	raiz = NULL;

	//Zerar a quantidade de palavras cadastradas na arvore
	QUANTIDADE_PALAVRAS_CADASTRADAS = 0;

	//Imprimir mensagem de sucesso na tela
	mensagemSucesso();

	return true;
}