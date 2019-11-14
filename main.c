#include "inicializacao.h"

void main()
{
	//Iniciar a execução do programa
	if (!inicializarPrograma())
	{
		imprimirListaDeErros();
		limparErros();
		pausa();
		main();
	}
}
/*

bool consultarPalavraNaArvore() {

	//Declara palavra a ser lida
	string palavra = NULL;

	//Pedir ao  usuário que digite a palavra
	printf("\nDigite a palavra que deseja buscar: (Até 20 caracteres)\n\n");

	//Ler palavra do teclado
	palavra = lerTextoDoTeclado(20);

	//Validar leitura
	if (!validarAlocacaoDeMemoria(palavra)) return false;

	//Verificar se a palavra está na árvore
	if (!consultarUmaDeterminadaPalavraNaArvore(palavra)) return false;

	return true;
}

*/