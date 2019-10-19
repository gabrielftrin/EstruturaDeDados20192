#include "estruturas.h"
#define quantidadeDeErros 50

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
			listaDeMensagensDeErro[i] = "Numero com mais de 10 caracteres";
			break;
		case 2:
			listaDeMensagensDeErro[i] = "Numero com 10 caracteres, o primeiro digito e diferente de 1 e diferente de 2.";
			break;
		case 3:
			listaDeMensagensDeErro[i] = "A quantidade de caracteres e zero.";
			break;
		case 4:
			listaDeMensagensDeErro[i] = "A quantidade de caracteres e menor que zero.";
			break;
		case 5:
			listaDeMensagensDeErro[i] = "A quantidade de caracteres retornou um valor inesperado.";
			break;
		case 6:
			listaDeMensagensDeErro[i] = "O caractere nao e um digito numerico (de 0 a 9).";
			break;
		case 7:
			listaDeMensagensDeErro[i] = "O numero e menor que zero.";
			break;
		case 8:
			listaDeMensagensDeErro[i] = "Nao foi possivel validar se o caractere e um numero ou nao.";
			break;
		case 9:
			listaDeMensagensDeErro[i] = "Erro nao preenchido";
			break;
		case 10:
			listaDeMensagensDeErro[i] = "Erro nao preenchido";
			break;
		case 11:
			listaDeMensagensDeErro[i] = "Erro nao preenchido";
			break;
		case 12:
			listaDeMensagensDeErro[i] = "Erro nao preenchido";
			break;
		case 13:
			listaDeMensagensDeErro[i] = "Erro nao preenchido";
			break;
		case 14:
			listaDeMensagensDeErro[i] = "Erro nao preenchido";
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