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



	return true;
}

//Limpar todos os nós da árvore
bool removerArvore() {



	return true;
}