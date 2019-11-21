#include "inicializacao.h"

//Funcao principal
void main()
{
	//Iniciar a execucao do programa
	if (!inicializarPrograma())
	{
		imprimirListaDeErros();
		limparErros();
		pausa();
		main();
	}
}
