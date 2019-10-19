#include "excecao.h"
#include <math.h>

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



/// <summary>
/// Retorna verdadeiro se for um número natural
/// </summary>
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

//Retorna true se for um numero natural POSITIVO
bool numeroNaturalPositivo(int numero) {

	if (numero > 0) return true;

	return false;
}

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
bool validacaoListaCriada(tipoLista *lista){
			 
	if (lista->tamanhoDaLista == -1){		
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