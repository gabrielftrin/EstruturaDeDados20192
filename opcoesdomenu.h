#include "execucao.h"

//Criar a árvore
bool criarArvore() {

	//Alocar memória para raiz
	raiz = NULL; raiz = alocarItemDaArvore();

	//Validar alocação de memória
	if (!validarAlocacaoDeMemoria(raiz)) return false;
	mensagemSucesso();

	return true;
}

//Inserir palavras do arquivo na árvore
bool inserirPalavraNaArvore() {

	//Declarar e abrir arquivo, validar abertura do arquivo
	FILE* arquivo = fopen("arquivo.txt", "r");
	if (!validarAlocacaoDeMemoria(arquivo)) return false;

	//Declarar linha de leitura atual
	string linha = (string)malloc(sizeof(char) * 20);
	if (!validarAlocacaoDeMemoria(linha)) return false;

	//Ler quantidade de entradas e validar alocação de memória
	if (fgets(linha, sizeof(linha), arquivo) == NULL) return false;

	//Converter texto para inteiro
	int entradas = atoi(linha); if (entradas == 0) return false; linha = NULL;
	
	//Ler cada linha
	for (int i = 0; i < entradas; i++)
	{
		if (fgets(linha, sizeof(linha), arquivo) == NULL) return false;




		linha = NULL;
	}




	// recebe como entrada o ponteiro geral da arvore, a palavra a ser inserida e o valor
	fclose(arquivo);

	return true;
}

bool consultarPalavraNaArvore() {



	return true;
}

bool listarPalavrasDaArvore() {



	return true;
}

bool removerArvore() {



	return true;
}