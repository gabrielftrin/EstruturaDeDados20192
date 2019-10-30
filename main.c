#include "inicializacao.h"

int main()
{
	if (!aplicarConfiguracoesIniciais())
	{
		lancarErro(23);
		imprimirListaDeErros();
	}

	return 0;
}