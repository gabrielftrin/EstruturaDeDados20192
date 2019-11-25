#include "inicializacao.h"

//Funcao principal
int main()
{
	//Iniciar a execucao do programa
	if (!inicializarPrograma())
	{
		imprimirListaDeErros();
		limparErros();
		pausa();
		main();
	}
	
	return 0;
}
