//erro erroDeExecucao;

	/*printf("\nDigite o conteudo a ser validado: ");
	fflush(stdin);
	fgets(op, 14, stdin);*/

	//if (strlen(op) = < 10) {	}
	//else {	//erro.numeroDeCaracteresExcedido}



///tudo é char
// nenhum caractere pode ser virgula
// nenhum caractece pode ser ponto
// todo caractere deve ser digito 2 147 483 647

//Ler 10 caracteres
//se tiver 10
	//o primeiro deve ser 1 ou 2
//ver um caracter
	//se o caracter é um dígito
		//se não for retorne falso
	//vá pro próximo caracter
#include "estruturas.h"

//#define numeroDeCaracteresExcedido "Numero de caracteres excedido."
//#define erroInicio "Erro no inicio do programa."

#define quantidadeDeErros 20

int listaDeCodigosDeErro[quantidadeDeErros];

void lancarErro(int codigoDeErro) {
	int i = 0;
	if (listaDeCodigosDeErro[i] == 0)
	{
		listaDeCodigosDeErro[i] = codigoDeErro;
	}
	else {
		while (listaDeCodigosDeErro[i] != 0)
		{
			if (listaDeCodigosDeErro[i] == 0)
			{
				listaDeCodigosDeErro[i] = codigoDeErro;
				break;
			}
			i++;
		}
	}
}

typedef struct erro {
	int codigo;
	string mensagem;
}erro;

erro meuerro;

meuerro.codigo = 5;

/*
erro numeroDeCaracteresExcedido;
numeroDeCaracteresExcedido.codigo = 1;
numeroDeCaracteresExcedido.string = "Numero de caracteres excedido.";

erro erroInicio;
erroInicio.codigo = 2;
erroInicio.string = "Erro no inicio do programa..";
*/