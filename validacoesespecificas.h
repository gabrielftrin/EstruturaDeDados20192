#include "validacoes.h"

//A lista é vazia quando o inicio e o final são nulos, o tamanho é zero e a variavel listaZerada é true
bool listaVazia(tipoLista* lista) {

	if (
		lista->inicioDaLista == NULL &&
		lista->finalDaLista == NULL &&
		lista->tamanhoDaLista == 0 &&
		lista->listaZerada == (bool*)true
		)
	{
		return true;
	}

	return false;
}

//Retorna false se a lista NÃO for válida
bool validacaoListaCriada(tipoLista* lista) {

	if (lista->tamanhoDaLista == -1) {
		printf("Por favor, crie a lista primeiro.\n");
		//pausa();
		return false;
	}

	return true;
}

//A lista é inválida se não conseguiu alocar memoria ou ainda não foi criada
bool validarLista(tipoLista* lista) {

	//Validar alocacao de memoria lista
	if (!validarAlocacaoDeMemoria(lista)) return false;

	//Verificar se a funcao criarListaDePessoas já foi chamada
	if (!validacaoListaCriada(lista)) return false;

	return true;
}