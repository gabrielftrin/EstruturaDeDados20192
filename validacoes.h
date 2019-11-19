#include "excecao.h"

//Alterar localização do programa para a localização do sistema para permitir uso de caracteres especiais
bool configurarLocal() {

	string retorno = setlocale(LC_ALL, "Portuguese");

	if ((retorno == NULL) || (retorno == "") || (retorno == "\0")|| (retorno == " "))
	{

		retorno = setlocale(LC_ALL, "");

		if ((retorno == NULL) || (retorno == "") || (retorno == "\0")|| (retorno == " "))
		{
			lancarErro(18);
			perror(MENSAGEM_DE_ERRO);
			return false;
		}
	}

	return true;
}

//Limpa o buffer do teclado (entrada padrão)
void limparBufferDoTeclado() {

	setbuf(stdin, NULL);
}

//Validar alocação de memória, retorna falso se o ponteiro for nulo
bool validarAlocacaoDeMemoria(void* ponteiro) {

	if (ponteiro == NULL)
	{
		lancarErro(15);
		//perror(MENSAGEM_DE_ERRO);
		return false;
	}

	return true;
}

// Retorna verdadeiro se for um número natural
bool validarNumeroNatural(int numero) {

	if (numero < 0) {

		lancarErro(7);
		return false;
	}

	return true;
}

// Retorna verdadeiro se for um número natural maior que zero
bool validarNumeroNaturalPositivo(int numero) {

	if (!validarNumeroNatural(numero)) {

		lancarErro(9);
		return false;
	}

	if (numero == 0) {
		lancarErro(10);
		return false;
	}

	return true;
}

//Retorna o ponteiro do número lido ou NULL em caso de erro (caso leia um número maior que int o ponteiro retornará o VALOR -1)
int* lerNumeroInteiroDoTeclado() {

	//Limpar o buffer do teclado
	limparBufferDoTeclado();

	//Declarar variavel de retorno da leitura e string
	int retornoDaLeitura = 0;

	//Declarar numero, alocar e validar memória
	int* numero = (int*)malloc(sizeof(int));
	if (!validarAlocacaoDeMemoria(numero)) {
		lancarErro(16);
		perror(MENSAGEM_DE_ERRO);
		return NULL;
	}

	//Enquanto nenhum caractere for lido, o programa tentará ler de novo
	do {
		//Ler do teclado e guardar o resultado. Para de ler quando o usuário apertar [ENTER]
		retornoDaLeitura = scanf("%d", numero);

		//Verificar se houver erro de leitura
		if (retornoDaLeitura == EOF) {
			lancarErro(13);
			perror(MENSAGEM_DE_ERRO);
			return NULL;
		}

		//Erro inesperado
		if (retornoDaLeitura < 0 && retornoDaLeitura != EOF) {
			lancarErro(14);
			perror(MENSAGEM_DE_ERRO);
			return NULL;
		}

		//Limpar o buffer do teclado
		limparBufferDoTeclado();
	} while (retornoDaLeitura == 0);

	//Limpar o buffer do teclado
	limparBufferDoTeclado();

	return numero;
}

//Retorna o número NATURAL lido ou EOF (-1) em caso de erro
int lerNumeroNaturalDoTeclado() {

	//Declarar e ler o número
	int* numero = lerNumeroInteiroDoTeclado();

	//Validar leitura do número
	if (numero == NULL) {

		lancarErro(19);
		return EOF;
	}

	//Declarar número natural
	int numeroNatural = *numero;

	//Validar número natural
	if (!validarNumeroNatural(numeroNatural)) {

		lancarErro(9);
		return EOF;
	}

	return numeroNatural;
}

//Recebe a quantidade de caracteres que devem ser lidos. Retorna nulo se der erro ou o ponteiro da string lida.
string lerTextoDoTeclado(int quantidade) {

	//Limpar o buffer do teclado
	limparBufferDoTeclado();

	//Validar quantidade
	if (!validarNumeroNaturalPositivo(quantidade)) {

		lancarErro(20);
		return NULL;
	}

	//Declarar variavel de retorno da leitura e string
	int retornoDaLeitura = 0;
	string texto = (string)malloc(quantidade * sizeof(char));

	//Validar alocação
	if (!validarAlocacaoDeMemoria(texto)) {

		lancarErro(16);
		perror(MENSAGEM_DE_ERRO);
		return false;
	}

	//Enquanto nenhum caractere for lido, o programa tentará ler de novo
	do {
		//Ler do teclado e guardar o resultado. Para de ler quando o usuário apertar [ENTER]
		retornoDaLeitura = scanf("%[^\n]", texto);

		//Verificar se houver erro de leitura
		if (retornoDaLeitura == EOF) {
			lancarErro(13);
			perror(MENSAGEM_DE_ERRO);
			return NULL;
		}

		//Erro inesperado
		if (retornoDaLeitura < 0 && retornoDaLeitura != EOF) {
			lancarErro(14);
			perror(MENSAGEM_DE_ERRO);
			return NULL;
		}

		//Limpar o buffer do teclado
		limparBufferDoTeclado();
	} while (retornoDaLeitura == 0);

	//Validar tamanho da string lida
	if (strlen(texto) > quantidade) {

		lancarErro(17);
		perror(MENSAGEM_DE_ERRO);
		return NULL;
	}

	return texto;
}
