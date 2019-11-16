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
	if (fgets(linha, TAMANHO_DA_LINHA, arquivo) == NULL) return false;

	//Converter texto para inteiro
	int entradas = atoi(linha); if (entradas == 0) return false;

	//Declarar vírgula
	const char virgula = ',';

	//Ler cada linha
	for (int i = 0; i < entradas; i++)
	{
		//Pegar a linha do arquivo
		if (fgets(linha, TAMANHO_DA_LINHA, arquivo) == NULL) return false;
		printf("lendo linha do arquivo:%s;\n", linha);
		//Encontrar a vírgula na linha
		string ponteiroDaVirgula = strchr(linha, virgula);
		printf("resto da linha a partir da virgula:%s;\n", ponteiroDaVirgula);
		//Tamanho da palavra
		int tamanhoDaPalavra = strlen(linha) - strlen(ponteiroDaVirgula);
		printf("tamanhos: linha:%d resto da linha:%d; diferenca:%d\n", strlen(linha), strlen(ponteiroDaVirgula), tamanhoDaPalavra);
		//Palavra
		char palavra[tamanhoDaPalavra];
		memcpy(palavra, linha, tamanhoDaPalavra);
		printf("copiando palavra para o vetor. Palavra:%s\nlinha:%s\ntamanho:%d\n", palavra, linha, tamanhoDaPalavra);
		//Tamanho do código
		int tamanhoDoCodigo = strlen(ponteiroDaVirgula) - 2;

		//Código
		char codigoEmTexto[tamanhoDoCodigo];
		memcpy(codigoEmTexto, (ponteiroDaVirgula + 2), tamanhoDoCodigo);

		//Converter código para int
		int codigoEmInteiro = atoi(codigoEmTexto);

		//Validar se a raiz foi criada
		if (!validarAlocacaoDeMemoria(raiz)) return false;

		//Criar variável auxiliar
		itemDaArvore* itemAuxiliar = raiz;

		//Colocar a palavra em minúsculo
		for (int i = 0; i < (tamanhoDaPalavra - 1); i++)
		{
			palavra[i] = tolower(palavra[i]);
		}

		//Criar ponteiro da palavra
		string palavraDaArvore = "joao";//&palavra[0];
		printf("passando palavra pro ponteiro:%s;\ntamanho:%d\n", palavraDaArvore, strlen(palavraDaArvore));
		//Inserir a palavra na árvore
		if (!inserirDeterminadaPalavraNaArvore(palavraDaArvore, codigoEmInteiro)) return false;
		printf("terminou de ler a linha...\n\n");
		ponteiroDaVirgula = NULL;
	}
	printf("\nleu todas as linhas\n");
	//Fehar o arquivo
	fclose(arquivo);
	consultarUmaDeterminadaPalavraNaArvore("joao");
	//Imprimir mensagem de sucesso na tela
	mensagemSucesso();

	return true;
}

//Ler uma palavra do teclado e consultar na árvore
bool consultarPalavraNaArvore() {

	//Declara palavra a ser lida
	string palavra = NULL;

	//Pedir ao  usuário que digite a palavra
	printf("\nDigite a palavra que deseja buscar: (Ate 20 caracteres)\n\n");

	//Ler palavra do teclado
	palavra = lerTextoDoTeclado(20);

	//Validar leitura
	if (!validarAlocacaoDeMemoria(palavra)) return false;

	//Verificar se a palavra está na árvore
	if (!consultarUmaDeterminadaPalavraNaArvore(palavra)) return false;

	return true;
}

//Listar todas as palavras cadastradas na árvore
bool listarPalavrasDaArvore() {



	return true;
}

//Limpar todos os nós da árvore
bool removerArvore() {



	return true;
}