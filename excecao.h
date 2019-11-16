#include "estruturas.h"
#define quantidadeDeErros 50

int listaDeCodigosDeErro[quantidadeDeErros];
string listaDeMensagensDeErro[quantidadeDeErros];

//Armazenar codigo de erro num vetor de erros
void lancarErro(int codigoDeErro) {

	int i = 0;
	while (listaDeCodigosDeErro[i] != 0)
	{
		i++;
	}
	listaDeCodigosDeErro[i] = codigoDeErro;	
}

//Imprimir lista de mensagens de erro lançadas
void mostrarErrosNaTela() {
	int i = 0;
	while (listaDeCodigosDeErro[i] != 0)
	{
		printf("\nMensagem de erro: %s", listaDeMensagensDeErro[i]);
		i++;
	}
	printf("\n");
}

//Preencher vetor de mensagens de erro de acordo com o código e mostrar erros na tela
void imprimirListaDeErros() {

	int i = 0;

	//Preencher o vetor
	while (listaDeCodigosDeErro[i] != 0)
	{
		switch (listaDeCodigosDeErro[i])
		{
		case 1:
			listaDeMensagensDeErro[i] = "Numero com mais de 10 caracteres.";
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
			listaDeMensagensDeErro[i] = "O numero nao e natural.";
			break;
		case 10:
			listaDeMensagensDeErro[i] = "O numero e zero.";
			break;
		case 11:
			listaDeMensagensDeErro[i] = "Nenhum caractere foi lido.";
			break;
		case 12:
			listaDeMensagensDeErro[i] = "Nao foi possivel ler o texto do teclado.";
			break;
		case 13:
			listaDeMensagensDeErro[i] = "Erro na leitura de dados do teclado.";
			break;
		case 14:
			listaDeMensagensDeErro[i] = "Erro inesperado na leitura de dados do teclado.";
			break;
		case 15:
			listaDeMensagensDeErro[i] = "Nao foi possivel alocar memoria.";
			break;
		case 16:
			listaDeMensagensDeErro[i] = "Alocacao de memoria invalida.";
			break;
		case 17:
			listaDeMensagensDeErro[i] = "O tamanho do texto lido e maior que tamanho solicitado.";
			break;
		case 18:
			listaDeMensagensDeErro[i] = "O local e nulo ou vazio.";
			break;
		case 19:
			listaDeMensagensDeErro[i] = "Nao foi possivel ler o numero do teclado.";
			break;
		case 20:
			listaDeMensagensDeErro[i] = "O numero nao e positivo.";
			break;
		case 21:
			listaDeMensagensDeErro[i] = "O programa nao executou corretamente.";
			break;
		case 22:
			listaDeMensagensDeErro[i] = "Nao foi possivel configurar o local corretamente.";
			break;
		case 23:
			listaDeMensagensDeErro[i] = "Algo nao executou corretamente.";
			break;
		case 24:
			listaDeMensagensDeErro[i] = "Menu nao executou corretamente.";
			break;
		case 25:
			listaDeMensagensDeErro[i] = "Erro ao ler numero do teclado.";
			break;
		case 26:
			listaDeMensagensDeErro[i] = "Nao foi possivel abrir o arquivo.";
			break;
		case 27:
			listaDeMensagensDeErro[i] = "Erro ao executar funcao do menu.";
			break;
		case 28:
			listaDeMensagensDeErro[i] = "Erro nao esperado ao consultar palavra na arvore.";
			break;
		case 29:
			listaDeMensagensDeErro[i] = "A chave (codigo) da palavra e menor que -1.";
			break;
		case 30:
			listaDeMensagensDeErro[i] = "Erro ao fechar arquivo.";
			break;
		case 31:
			listaDeMensagensDeErro[i] = "Erro nao preenchido";
			break;
		case 32:
			listaDeMensagensDeErro[i] = "Erro nao preenchido";
			break;
		case 33:
			listaDeMensagensDeErro[i] = "Erro nao preenchido";
			break;
		case 34:
			listaDeMensagensDeErro[i] = "Erro nao preenchido";
			break;
		case 35:
			listaDeMensagensDeErro[i] = "Erro nao preenchido";
			break;
		case 36:
			listaDeMensagensDeErro[i] = "Erro nao preenchido";
			break;
		case 37:
			listaDeMensagensDeErro[i] = "Erro nao preenchido";
			break;
		case 38:
			listaDeMensagensDeErro[i] = "Erro nao preenchido";
			break;
		case 39:
			listaDeMensagensDeErro[i] = "Erro nao preenchido";
			break;
		case 40:
			listaDeMensagensDeErro[i] = "Erro nao preenchido";
			break;
		case 41:
			listaDeMensagensDeErro[i] = "Erro nao preenchido";
			break;
		case 42:
			listaDeMensagensDeErro[i] = "Erro nao preenchido";
			break;
		case 43:
			listaDeMensagensDeErro[i] = "Erro nao preenchido";
			break;
		case 44:
			listaDeMensagensDeErro[i] = "Erro nao preenchido";
			break;
		case 45:
			listaDeMensagensDeErro[i] = "Erro nao preenchido";
			break;
		case 46:
			listaDeMensagensDeErro[i] = "Erro nao preenchido";
			break;
		case 47:
			listaDeMensagensDeErro[i] = "Erro nao preenchido";
			break;
		case 48:
			listaDeMensagensDeErro[i] = "Erro nao preenchido";
			break;
		case 49:
			listaDeMensagensDeErro[i] = "Erro nao preenchido";
			break;
		case 50:
			listaDeMensagensDeErro[i] = "Erro nao preenchido";
			break;




		default:
			break;
		}
		i++;
	}

	//Imprimir lista de erros
	mostrarErrosNaTela();
}

//Limpar a lista de mensagens de erro e a lista de códigos de erro
void limparErros() {

	//De zero até a quantidade de erros, zerar a variável
	for (int i = 0; i < quantidadeDeErros; i++)
	{
		listaDeCodigosDeErro[i] = 0;
		listaDeMensagensDeErro[i] = " ";
	}
}