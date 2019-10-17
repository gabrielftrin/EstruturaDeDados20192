#include "estruturas.h"
#define quantidadeDeErros 10

int listaDeCodigosDeErro[quantidadeDeErros];
string listaDeMensagensDeErro[quantidadeDeErros];

void lancarErro(int codigoDeErro) {

	int i = 0;
	while (listaDeCodigosDeErro[i] != 0)
	{
		i++;
	}
	listaDeCodigosDeErro[i] = codigoDeErro;	
}

void imprimirListaDeErros() {

	int i = 0;

	//Preencher o vetor
	while (listaDeCodigosDeErro[i] != 0)
	{
		switch (listaDeCodigosDeErro[i])
		{
		case 1:
			listaDeMensagensDeErro[i] = "Numero de caracteres excedido.";
			break;
		case 2:
			listaDeMensagensDeErro[i] = "Erro no inicio do programa.";
			break;
		default:
			break;
		}
		i++;
	}

	//Imprimir lista de erros
	i = 0;
	while (listaDeCodigosDeErro[i] != 0)
	{
		printf("\nMensagem de erro: %s\n", listaDeMensagensDeErro[i]);
		i++;
	}
}