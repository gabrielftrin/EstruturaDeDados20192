#include "excecao.h"

//Alterar localização do programa para a localização do sistema para permitir uso de caracteres especiais
bool configurarLocal() {
	
	string retorno = setlocale(LC_ALL, "Portuguese");

	if (retorno == NULL || retorno == "")
	{
		lancarErro(18);
		perror(MENSAGEM_DE_ERRO);
		return false;
	}

	return true;
}

//Limpa o buffer do teclado (entrada padrão)
void limparBufferDoTeclado() {

	setbuf(stdin, NULL);

}

//[REVISAR] Ter atenção aos numeros terminados em 0
int inverterNumero(int numero) {

	int numeroInvertido = 0;
	while (numero != 0)
	{
		numeroInvertido = numeroInvertido * 10;
		numeroInvertido = numeroInvertido + numero % 10;
		numero = numero / 10;
	}

	return numeroInvertido;

}

//[REVISAR] Converte número em string (apenas entre -69 e +69)
string converterInteiroEmString(int numero) {

	int i = 0;
	bool numeroNegativo = false;
	bool multiploDeDez = false;
	char numeroConvertivoEmString[11];
	string resultado;

	if (numero == 0)
	{
		return "0";
	}

	if (numero < 0)
	{
		numeroNegativo = true;
		numero = -numero;
		numeroConvertivoEmString[i++] = '-';
	}

	if (numero % 10 == 0) multiploDeDez = true;

	if (numero == 10) return "10";
	if (numero == 20) return "20";
	if (numero == 30) return "30";
	if (numero == 40) return "40";
	if (numero == 50) return "50";
	if (numero == 60) return "60";

	numero = inverterNumero(numero);

	while (numero != 0)
	{
		int resto = numero % 10;
		numeroConvertivoEmString[i++] = resto + '0';
		numero = numero / 10;
	}

	numeroConvertivoEmString[i] = '\0'; // Append string terminator 

	resultado = numeroConvertivoEmString;
	return resultado;
}

//Validar alocação de memória, retorna falso se o ponteiro for nulo
bool validarAlocacaoDeMemoria(void* ponteiro) {

	if (ponteiro == NULL)
	{
		lancarErro(15);
		perror(MENSAGEM_DE_ERRO);
		return false;
	}
	
	return true;
}

//Recebe a quantidade de caracteres que devem ser lidos e le essa quantidade do teclado até o usuário apertar enter. Retorna nulo se der erro ou o ponteiro da string lida.
string lerTextoDoTeclado(int quantidade) {

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

}

//=================================================================

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

	if (numero == 0)
	{
		lancarErro(10);
		return false;
	}

	return true;
}

//==========================================================





//Retorna true se a quantidade de caracteres impressos for maior que 0. Exibe mensagem de erro.
bool validarImpressao(int numero) {

	if (numero > 0)
		return true;

	printf("\nNenhum caractere foi impresso na tela.\n");

	return false;
}

//A lista é vazia quando o inicio e o final são nulos, o tamanho é zero e a variavel listaZerada é true
bool listaVazia(tipoLista* lista) {

	if (
		lista->inicioDaLista == NULL &&
		lista->finalDaLista == NULL &&
		lista->tamanhoDaLista == 0 &&
		lista->listaZerada == (bool*)true
		) {
		//printf("\nA lista esta vazia.\n");
		return true;
	}

	return false;
}

//Se a pessoa pontar pra nulo, retorna falso e mostra erro na tela
bool validarAlocacaoPessoa(tipoPessoa* pessoa) {

	if (pessoa == NULL) {
		//limparTela();
		printf("A pessoa esta apontando para nulo.\n");
		return false;
	}

	return true;
}

//Se a lista apontar pra nulo, exibe mensagem de erro e retorna falso
bool validarAlocacaoLista(tipoLista* lista) {

	if (lista == NULL) {

		//Exibe mensagem de erro
		printf("\nNao foi possível alocar memoria para lista.\n");

		return false;
	}

	return true;
}

//Retorna false se a lista NÃO for válida
bool validacaoListaCriada(tipoLista* lista) {

	if (lista->tamanhoDaLista == -1) {
		printf("Por favor, crie a lista primeiro.\n");
		//pausa();
		return false;
	}

	return true;
}

//A lista é inválida se não conseguiu alocar memoria ou ainda não foi criada
bool validarLista(tipoLista* lista) {

	//Validar alocacao de memoria lista
	if (!validarAlocacaoLista(lista)) return false;

	//Verificar se a funcao criarListaDePessoas já foi chamada
	if (!validacaoListaCriada(lista)) return false;

	return true;
}