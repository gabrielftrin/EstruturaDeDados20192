#include "estruturas.h"

/*
//Exibe uma pausa na tela para que o usuário possa ler e tomar decisões
void pausa() {
	system("pause");
}

//Limpa tudo que estiver na tela
void limparTela() {
	system("cls");
}

*/
//Fecha o programa
void sairDoPrograma() {
	exit(0);
}

//Retorna true se for um numero natural
bool numeroNatural(int numero) {

	if (numero >= 0) return true;

	return false;
}

//Retorna true se for um numero natural POSITIVO
bool numeroNaturalPositivo(int numero) {

	if (numero > 0) return true;

	return false;
}

//Retorna true se a quantidade de caracteres impressos for maior que 0. Exibe mensagem de erro.
bool validarImpressao(int numero) {

	if (numero > 0)
		return true;

	printf("\nNenhum caractere foi impresso na tela.\n");

	return false;
}