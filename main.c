#include "validacoes.h"

bool lerInteiroDoTeclado(int* numero) {


	//Limpar o buffer do teclado
	limparBufferDoTeclado();

	//Declarar variavel de retorno da leitura e string
	int retornoDaLeitura = 0;
	string texto = (string)malloc(quantidade * sizeof(char));

	//Validar alocação
	if (!validarAlocacaoDeMemoria(texto))
	{
		lancarErro(16);
		perror(MENSAGEM_DE_ERRO);
		return false;
	}

	string numeroConvertidoParaString = converterInteiroEmString(quantidade);
	char parteParametro[20] = " %";
	strcat(parteParametro, numeroConvertidoParaString);
	strcat(parteParametro, "[^\n]");
	const char* parametros = parteParametro;

	//Enquanto nenhum caractere for lido, o programa tentará ler de novo
	do
	{
		//Ler do teclado e guardar o resultado. Para de ler quando o usuário apertar [ENTER]
		retornoDaLeitura = scanf(parametros, texto);

		//Verificar se houver erro de leitura
		if (retornoDaLeitura == EOF)
		{
			lancarErro(13);
			perror(MENSAGEM_DE_ERRO);
			return NULL;
		}

		//Erro inesperado
		if (retornoDaLeitura < 0 && retornoDaLeitura != EOF)
		{
			lancarErro(14);
			perror(MENSAGEM_DE_ERRO);
			return NULL;
		}

		//Limpar o buffer do teclado
		limparBufferDoTeclado();

	} while (retornoDaLeitura == 0);

	//Validar tamanho da string lida
	//if (strlen(texto) != quantidade)
	//{
		//lancarErro(17);
		//perror(MENSAGEM_DE_ERRO);
		//return NULL;
	//}

	return texto;

	return true;
}

void main()
{
	int teste;

	int retorno = 0;

	retorno = scanf("%d", &teste);
	
	printf("\nConteudo digitado: %d retorno %d fim \n", teste, retorno);

	string num = lerTextoDoTeclado(14);

	printf("%s", num);

	imprimirListaDeErros();
}

/*

============================================================
int inteiro_validado() {
	//Buffer para entrada da variável
	char buffer[100];
	//Ponteiro com endereco da String
	char* entrada = gets(buffer); fflush(stdin);
	int i, resultado = 0, teste;
	//Fazemos um loop para checar caractere por caractere da entrada
	for (i = 0; i < strlen(entrada); i++) {
		//Checa se é um numero
		if (entrada[i] >= '0' && entrada[i] <= '9') {
			//Se for, reduz da tabela ASCII
			teste = entrada[i] - '0';
			//Essa soma apenas coloca na casa decimal certa, se for 1024, ele vai fazer 1000 + 20 + 4
			resultado += teste * pow(10, strlen(entrada) - i - 1);
		}
		else {
			//A entrada contem um valor nao numérico
			return -1;
		}
	}

	return resultado;
}

bool validarNumeroNatural(int numero) {

	printf("%d ", numero);
	//Declarar, converter para string e guardar o tamanho do numero
	char texto[20];
	sprintf(texto, "%i", numero);
	int tam = strlen(texto);

	//Verificar se é maior que 10
	if (tam > 10)
	{
		lancarErro(1);
		return false;
	}

	//Quando o tamanho for 10, verificar o primeiro caractere
	if (tam == 10)
	{
		if (texto[0] != 1 && texto[0] != 2)
		{
			lancarErro(2);
			return false;
		}

	}

	//Verificar se o tamanho é zero
	if (tam == 0)
	{
		lancarErro(3);
		return false;
	}

	//Ver se a quantidade é menor que zero
	if (tam < 0)
	{
		lancarErro(4);
		return false;
	}

	//Processar
	if (tam > 0 && tam < 11)
	{
		//Verificar se é negativo
		if (numero < 0)
		{
			lancarErro(7);
			return false;
		}

		int res = -1;
		//Verificar se cada dígito é um número
		for (int i = 0; i < tam; i++)
		{
			res = isdigit(texto[i]);
			if (res == 0)
			{
				lancarErro(6);
				return false;
			}

			if (res != 0 && res != 1)
			{
				lancarErro(8);
				return false;
			}
		}

		return true;
	}

	//Erro inesperado
	lancarErro(5);
	return false;
}
*/