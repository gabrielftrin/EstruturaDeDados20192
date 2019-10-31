#include "validacoes.h"

void main()
{
	configurarLocal();
	FILE *arquivo;

	arquivo = fopen("arquivo.txt", "r");
	if (!validarAlocacaoDeMemoria(arquivo))
	{
		lancarErro(26);
		perror(MENSAGEM_DE_ERRO);
		sairDoPrograma();
	}
	char c;
	int i = 0;
	do
	{
		c = getc(arquivo);
		printf("%c", c);
		
	} while (!feof(arquivo));
		
	fclose(arquivo);

	printf("\nteste\n");
	imprimirListaDeErros();
}
/*
if (!aplicarConfiguracoesIniciais())
{
	lancarErro(23);
	imprimirListaDeErros();
}

return 0;
*/