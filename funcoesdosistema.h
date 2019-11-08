#include "estruturas.h"

//Exibe uma pausa na tela para que o usuário possa ler e tomar decisões
void pausa() {

	printf("\nPressione [ENTER] para continuar...");
	scanf("[^\n]");
}

////Limpa tudo que estiver na tela
//void limparTela() {
//	system("cls");
//system("tput reset");
//system("clear");
//}


//Fecha o programa
void sairDoPrograma() {
	exit(0);
}