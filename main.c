#include "validacoes.h"

void main()
{	
	//Alterar localização do programa para a localização do sistema para permitir uso de caracteres especiais
	//setlocale(LC_ALL, "Portuguese");
	
	int quantidade = 500;
	string teste = lerTextoDoTeclado(quantidade);
	printf("\nConteudo digitado: %s\n", teste);
	
	imprimirListaDeErros();
}

/*
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