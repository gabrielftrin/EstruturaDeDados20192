#include "execucao.h"

//Criar a árvore
bool criarArvore() {

	raiz = NULL;

	raiz = alocarItemDaArvore();
	
	if (!validarAlocacaoDeMemoria(raiz))
	{
		lancarErro(16);
		return false;
	}

	mensagemSucesso();

	return true;
}

//Inserir palavras do arquivo na árvore
bool inserirPalavraNaArvore() {


}

bool consultarPalavraNaArvore() {


}

bool listarPalavrasDaArvore() {


}

bool removerArvore() {


}