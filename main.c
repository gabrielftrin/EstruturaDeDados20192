#include "inicializacao.h"

void main()
{
	//Declarar ponteiro da árvore
	itemDaArvore* raiz = NULL;
	
	//Iniciar a execução do programa
	if (!inicializarPrograma())
	{
		lancarErro(21);
		imprimirListaDeErros();
	}
}