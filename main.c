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