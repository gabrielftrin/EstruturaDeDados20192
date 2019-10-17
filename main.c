#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "excecao.h"

bool teste(int x) {
	if (x > 0)
	{
		lancarErro(1);
		return false;
	}
}

bool funcao() {
	int x = 0;
	if (!teste(x)) {
		lancarErro(2);
		return false;
	}
}
/*
void retornarListaDeErros() {
	imprimirListaDeErros();
	destruirListaDeErros();
}
*/
void main()
{
	/*if (!funcao()){
		retornarListaDeErros();
		return	1;
	}*/

	printf("\n\ndeu tudo certo\n\n");

	printf("\nres %d\n", meuerro.codigo);
}