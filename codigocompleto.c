#include <stdio.h> //Biblioteca padrao
#include <stdbool.h> //Definicao do tipo Booleano
#include <stdlib.h> //define varias funcoes para executar funcoes gerais (malloc, system, etc.)
#include <string.h> // Manipular strings
#include <ctype.h> //declara varias funcoes que sao úteis para manipular caracteres. (isdigit() por exemplo)
#include <locale.h> //Configurar local/regiao/país

#define MENSAGEM_DE_ERRO "Mensagem de erro do compilador"
#define TAMANHO_DO_ALFABETO 26
#define CODIGO_FECHA_PROGRAMA 6
#define TAMANHO_DA_LINHA 30

//Definicao tipo string como ponteiro de caractere
typedef char* string;

//Definicao da estrutura de um item da arvore
typedef struct itemDaArvore
{
	int chave;
	struct itemDaArvore* proximaLetra[TAMANHO_DO_ALFABETO];
}itemDaArvore;

//Declarar ponteiro da raiz da arvore
itemDaArvore* raiz = NULL;

//Definicao da variavel debug
bool DEBUG = false;

//Declarar quantidade de itens (nos) existentes na arvore
int QUANTIDADE_PALAVRAS_CADASTRADAS = 0;

//Booleano que identifica se alguma palavra foi encontrada na arvore
bool existePalavraNaArvore = false;

//Exibe uma pausa na tela para que o usuario possa ler e tomar decisoes
void pausa()
{
	printf("\nPressione [ENTER] para continuar... ");
	scanf("[^\n]");
}

//Limpa tudo que estiver na tela
void limparTela()
{
	//Caso o sistema seja windows
#ifdef WIN32 //|| Win32 || win32 || Windows || WINDOWS || windows
	system("cls");
	return;
#endif

	//Caso o sistema seja linux
#ifdef linux //|| LINUX || Linux || UNIX
	system("tput reset");
	return;
#endif
}

//Fecha o programa
void sairDoPrograma()
{
	limparTela();
	printf("Saindo do programa...\n");
	exit(0);
}

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

//Imprimir lista de mensagens de erro lancadas
void mostrarErrosNaTela() {
	int i = 0;
	while (listaDeCodigosDeErro[i] != 0)
	{
		printf("\nMensagem de erro: %s", listaDeMensagensDeErro[i]);
		i++;
	}
	printf("\n");
}

//Preencher vetor de mensagens de erro de acordo com o codigo e mostrar erros na tela
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
			listaDeMensagensDeErro[i] = "O ponteiro recebido e nulo.";
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
			listaDeMensagensDeErro[i] = "Erro nao esperado ao tentar apagar todos os itens da arvore.";
			break;
		case 32:
			listaDeMensagensDeErro[i] = "Erro nao esperado ao inverter DEBUG.";
			break;
		case 33:
			listaDeMensagensDeErro[i] = "A raiz da arvore e nula.";
			break;
		case 34:
			listaDeMensagensDeErro[i] = "Erro nao esperado ao inserir item na arvore.";
			break;
		case 35:
			listaDeMensagensDeErro[i] = "Erro nao esperado ao inserir item na pilha.";
			break;
		case 36:
			listaDeMensagensDeErro[i] = "O ponteiro da pilha de chamadas e nulo.";
			break;
		case 37:
			listaDeMensagensDeErro[i] = "Erro nao esperado ao remover topo da pilha.";
			break;
		case 38:
			listaDeMensagensDeErro[i] = "O item anterior da lista de itens da arvore para verificar, e nulo.";
			break;
		case 39:
			listaDeMensagensDeErro[i] = "O item da arvore nao foi encontrado na lista de itens para verificar.";
			break;
		case 40:
			listaDeMensagensDeErro[i] = "A chave deste item da arvore e menor que -1.";
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

//Limpar a lista de mensagens de erro e a lista de codigos de erro
void limparErros() {

	//De zero ate a quantidade de erros, zerar a variavel
	for (int i = 0; i < quantidadeDeErros; i++)
	{
		listaDeCodigosDeErro[i] = 0;
		listaDeMensagensDeErro[i] = "\0";
	}
}

//Alterar localizacao do programa para a localizacao do sistema para permitir uso de caracteres especiais
bool configurarLocal()
{
	string retorno = setlocale(LC_ALL, "Portuguese");

	if (retorno == NULL)
	{
    
		retorno = setlocale(LC_ALL, "");

		if (retorno == NULL)
		{
      
			retorno = setlocale(LC_ALL, "C");
			
			if (retorno == NULL)
			{
				lancarErro(18);
				perror(MENSAGEM_DE_ERRO);
				return false;
			}
		}
	}

	return true;
}

//Limpa o buffer do teclado (entrada padrao)
void limparBufferDoTeclado() {

	setbuf(stdin, NULL);
}

//Validar alocacao de memoria, retorna falso se o ponteiro for nulo
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

//Retorna o ponteiro do número lido ou NULL em caso de erro (caso leia um número maior que int o ponteiro retornara o VALOR -1)
int* lerNumeroInteiroDoTeclado() {

	//Limpar o buffer do teclado
	limparBufferDoTeclado();

	//Declarar variavel de retorno da leitura e string
	int retornoDaLeitura = 0;

	//Declarar numero, alocar e validar memoria
	int* numero = (int*)malloc(sizeof(int));
	if (!validarAlocacaoDeMemoria(numero)) {
		lancarErro(16);
		perror(MENSAGEM_DE_ERRO);
		return NULL;
	}

	//Enquanto nenhum caractere for lido, o programa tentara ler de novo
	do {
		//Ler do teclado e guardar o resultado. Para de ler quando o usuario apertar [ENTER]
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

	//Validar alocacao
	if (!validarAlocacaoDeMemoria(texto)) {

		lancarErro(16);
		perror(MENSAGEM_DE_ERRO);
		return false;
	}

	//Enquanto nenhum caractere for lido, o programa tentara ler de novo
	do {
		//Ler do teclado e guardar o resultado. Para de ler quando o usuario apertar [ENTER]
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

//Imprime uma mensagem de sucesso na tela
void mensagemSucesso() {

	printf("\nOperacao realizada com sucesso.\n");
}

//Verificar se a raiz da arvore e nula
bool validarArvoreCriada() {

	if (DEBUG) printf("Iniciando a funcao, 'validarArvoreCriada'...\n");

	if (!validarAlocacaoDeMemoria(raiz))
	{
		lancarErro(33);
		return false;
	}

	return true;
}

//Alocar memoria para um novo item da arvore
itemDaArvore* alocarItemDaArvore() {

	if (DEBUG) printf("Iniciando a funcao, 'alocarItemDaArvore'...\n");

	itemDaArvore* novoItem = (itemDaArvore*)malloc(sizeof(itemDaArvore));

	if (!validarAlocacaoDeMemoria(novoItem)) return NULL;

	novoItem->chave = -1;

	for (int i = 0; i < TAMANHO_DO_ALFABETO; i++)
	{
		novoItem->proximaLetra[i] = NULL;
	}

	return novoItem;
}

//Verificar se uma determinada palavra esta cadastrada na arvore
bool consultarUmaDeterminadaPalavraNaArvore(string palavra) {

	if (DEBUG) printf("Iniciando a funcao, 'consultarUmaDeterminadaPalavraNaArvore'...\n");

	//Verificar se a palavra e nula
	if (!validarAlocacaoDeMemoria(palavra)) return false;

	if (DEBUG) printf("A palavra recebida foi validada com sucesso. Validando raiz da arvore..\n");

	//Verificar se a raiz e nula
	if (!validarArvoreCriada())
	{
		printf("\nA arvore esta vazia.\n");
		return true;
	}

	if (DEBUG) printf("Raiz validada com sucesso. Calculando tamanho da palavra...\n");

	//Criar ponteiro auxiliar do tipo 'item da arvore'
	itemDaArvore* itemAuxiliar = raiz;

	//Verificar o tamanho da palavra
	int tamanho = strlen(palavra);

	if (DEBUG) printf("Primeira letra da palavra: '%c'. Tamanho da palavra '%d'. Iniciando iteracao...\n", *palavra, tamanho);

	//Percorrer a arvore ate o final da palavra ou ate palavra nao existir
	for (int i = 0; i < tamanho; i++)
	{
		if (DEBUG) printf("\nIteracao '%d'. Verificando a letra '%c'. Codigo do item atual '%d'.\n", i, (*palavra), itemAuxiliar->chave);

		//Verifica se a letra corrente/atual esta na arvore
		if (itemAuxiliar->proximaLetra[*palavra - 'a'] == NULL)
		{
			if (DEBUG) printf("A posicao %d do vetor e nula.\n", (*palavra - 'a'));

			printf("\nA palavra '%s' nao esta na arvore.\nApenas as primeiras '%d' letras desta palavra estao na arvore.\n", (palavra - i), i);

			if (DEBUG) printf("\nDados: iteracao:'%d', palavra:'%s', chave:'%d'. Retornando true...\n", i, (palavra - i), itemAuxiliar->chave);

			return true;
		}

		//Passa para o proximo item
		itemAuxiliar = itemAuxiliar->proximaLetra[*palavra - 'a'];

		if (DEBUG) printf("Passando para o proximo item... codigo: '%d', iteracao '%d'\n", itemAuxiliar->chave, i);

		//Se a chave for positiva encontrou a palavra
		if (itemAuxiliar->chave > -1)
		{
			if (DEBUG) printf("O codigo do item e maior que -1. Codigo: '%d', iteracao '%d'\n", itemAuxiliar->chave, i);

			if (i >= (tamanho - 1))
			{
				printf("\nA palavra '%s' esta na arvore. Sua chave e: %d\n", (palavra - i), itemAuxiliar->chave);
				return true;
			}
		}

		//Se chegou no final da palavra, retorna true informando que a palavra nao esta na arvore
		if (i == (tamanho - 1))
		{
			if (DEBUG) printf("\nA iteracao e igual ao tamanho -1 (ultima letra da palavra). Dados: iteracao:'%d', palavra:'%s', chave:'%d'. Retornando true...\n", i, (palavra - i), itemAuxiliar->chave);

			printf("\nA palavra '%s' nao esta na arvore.\nApenas as primeiras %d letras estao na arvore.\n", (palavra - i), i);

			mensagemSucesso();
			return true;
		}

		if (DEBUG) printf("Incrementando palavra...\n");

		//Indo para a proxima letra
		palavra++;

		if (DEBUG) printf("Palavra incrementada. Nova letra '%c'.\n", *palavra);
	}

	if (DEBUG) printf("Lancando erro...\nDados: Tamanho '%d', Letra '%c', Vetor '%d'\n", tamanho, *palavra, (*palavra - 'a'));

	lancarErro(28);
	return false;
}

//Insere uma determinada palavra e um determinado codigo na arvore
bool inserirDeterminadaPalavraNaArvore(string palavraDaArvore, int codigo, int tamanho) {

	if (DEBUG) printf("Iniciando a funcao, 'inserirDeterminadoItemNaArvore'...\n");

	//Validar entradas
	if ((!validarAlocacaoDeMemoria(palavraDaArvore)) || (!validarNumeroNaturalPositivo(codigo)))
	{
		if (DEBUG) printf("Argumento invalido. A palavra ou o codigo recebidos, sao invalidos. Retornando falso...\n");

		return false;
	}

	//Criar variavel auxiliar
	itemDaArvore* itemAuxiliar = raiz;

	if (DEBUG) printf("Argumentos recebidos: Palavra:'%s', Codigo:'%d', Tamanho:'%d'. Iniciando iteracao...\n", palavraDaArvore, codigo, tamanho);

	//Percorrer a arvore ate o final da palavra
	for (int i = 0; i < tamanho; i++)
	{
		if (DEBUG) printf("\nInício da iteracao '%d'.\n", i);

		//Aloca memoria para um novo item se o caractere for nulo
		if (itemAuxiliar->proximaLetra[*palavraDaArvore - 'a'] == NULL) {

			if (DEBUG) printf("A posicao '%d' e nula. Alocando memoria para o novo item...\n", (*palavraDaArvore - 'a'));

			//Alocar novo item da arvore
			itemDaArvore* novoItem = alocarItemDaArvore();

			//Validar alocacao
			if (!validarAlocacaoDeMemoria(novoItem)) return false;

			if (DEBUG) printf("Memoria alocada com sucesso. Inserindo o novo item na avore...\n");

			//Colocar o novo item na arvore
			itemAuxiliar->proximaLetra[*palavraDaArvore - 'a'] = novoItem;
		}

		if (DEBUG) printf("Passando para o proximo item. Letra '%c', Iteracao '%d', Vetor '%d'\n", *palavraDaArvore, i, (*palavraDaArvore - 'a'));

		//Passa para o proximo item
		itemAuxiliar = itemAuxiliar->proximaLetra[*palavraDaArvore - 'a'];

		//Sair do laco quando for a última letra
		if (i == (tamanho - 1))
		{
			if (DEBUG) printf("Esta e a última letra. Iteracao '%d'.\n", i);

			if (itemAuxiliar->chave == -1)
			{
				if (DEBUG) printf("A chave deste item e '%d'. Inserido o codigo '%d' na arvore...\n", itemAuxiliar->chave, codigo);

				//Inserir valor
				itemAuxiliar->chave = codigo;

				if (DEBUG) printf("Chave inserida: '%d'. Letra atual: '%c'. Vetor atual: '%d'.\nIncrementando quantidade de palavras cadastradas...", itemAuxiliar->chave, (*palavraDaArvore), (*palavraDaArvore - 'a'));

				QUANTIDADE_PALAVRAS_CADASTRADAS++;

				if (DEBUG) printf("Quantidade de palavras cadastradas '%d'\n", QUANTIDADE_PALAVRAS_CADASTRADAS);

				return true;
			}

			if (itemAuxiliar->chave > -1)
			{
				if (DEBUG) printf("A chave '%d' e maior que -1.\n", itemAuxiliar->chave);

				if (DEBUG) printf("A palavra '%s' ja foi cadastrada na arvore com o codigo '%d'. Atualizando codigo para '%d'.\n", (palavraDaArvore - i), itemAuxiliar->chave, codigo);

				itemAuxiliar->chave = codigo;

				if (DEBUG) printf("Codigo '%d' atualizado com sucesso. Retornando true...\n", itemAuxiliar->chave);

				return true;
			}

			if (DEBUG) printf("Chave menor que -1. Lancando erro... Dados atuais: Chave: '%d', Letra: '%c'. Vetor: '%d'.\n",
				itemAuxiliar->chave, (*palavraDaArvore), (*palavraDaArvore - 'a'));

			lancarErro(40);
			return false;
		}

		if (DEBUG) printf("Letra atual '%c'. Passando para proxima letra...\n", i + 'a');

		//Passar para o proximo caractere
		palavraDaArvore++;

		if (DEBUG) printf("Letra incrementada: '%c'\n", *palavraDaArvore);
	}

	if (DEBUG) printf("Saiu da iteracao sem inserir o item. Dados: Letra '%c', Chave do item atual '%d'. Lancando erro...\n", *palavraDaArvore, itemAuxiliar->chave);

	lancarErro(34);
	return false;
}

//Ler uma quantidade de linhas de um arquivo
bool lerLinhasDoArquivo(string linha, FILE* arquivo, int entradas) {

	if (DEBUG) printf("Iniciando a funcao, 'lerLinhasDoArquivo'...\n");

	//Validar entradas da funcao
	if (
		(!validarAlocacaoDeMemoria(linha)) ||
		(!validarAlocacaoDeMemoria(arquivo)) ||
		(!validarNumeroNaturalPositivo(entradas)) ||
		(!validarAlocacaoDeMemoria(raiz))
		)
		return false;

	if (DEBUG) printf("A linha, a quantidade de entradas, raiz e o arquivo sao validos. Iniciando a iteracao.\n");

	//Iterar sobre as linhas
	for (int i = 0; i < entradas; i++)
	{
		if (DEBUG) printf("Início da iteracao. Iteracao '%d'. Entradas (%d). Lendo linha do arquivo...\n", i, entradas);

		//Pegar a linha do arquivo
		if (!validarAlocacaoDeMemoria(fgets(linha, TAMANHO_DA_LINHA, arquivo)))
		{
			printf("Nao foi possivel ler a linha %d do arquivo corretamente.\nVerifique se existe uma palavra nessa linha.\n", i + 2);
			limparErros();
			return true;
		}

		if (DEBUG) printf("Linha lida com sucesso. Linha: '%s'. Procurando vírgula na linha...\n", linha);

		//Encontrar a vírgula na linha
		string ponteiroDaVirgula = strchr(linha, ',');
		if (!validarAlocacaoDeMemoria(ponteiroDaVirgula))
		{
			printf("Nao foi possivel encontrar a virgula que separa a palavra do codigo.\nVerifique se existe uma virgula na linha %d do arquivo 'palavras.txt'.\n", i + 1);
			limparErros();
			return true;
		}

		if (DEBUG) printf("Virgula encontrada. Resto da linha a partir da virgula: '%s'.\nCalculando tamanho da palavra...", ponteiroDaVirgula);

		//Tamanho da palavra
		int tamanhoDaPalavra = strlen(linha) - strlen(ponteiroDaVirgula);

		if (DEBUG) printf("Resultado: Linha '%d', Resto da linha: '%d', Diferenca '%d'. Copiando palavra da linha...\n", (int)strlen(linha), (int)strlen(ponteiroDaVirgula), tamanhoDaPalavra);

		//Palavra
		char palavra[tamanhoDaPalavra];
		memcpy(palavra, linha, tamanhoDaPalavra);

		if (DEBUG) printf("Palavra copiada com sucesso. Palavra: '%s', Linha: '%s', Tamanho: '%d'.Copiando, Calculando e convertendo chave...\n", palavra, linha, tamanhoDaPalavra);

		//Tamanho do codigo
		int tamanhoDoCodigo = strlen(ponteiroDaVirgula) - 2;

		//Codigo
		char codigoEmTexto[tamanhoDoCodigo];
		memcpy(codigoEmTexto, (ponteiroDaVirgula + 2), tamanhoDoCodigo);

		//Converter codigo para int
		int codigoEmInteiro = atoi(codigoEmTexto);
		if (!validarNumeroNaturalPositivo(codigoEmInteiro)) return false;

		//Criar variavel auxiliar
		itemDaArvore* itemAuxiliar = raiz;

		if (DEBUG) printf("Chave copiada com sucesso. Chave '%d'. Colocando palavra em minúsculo...\n", codigoEmInteiro);

		//Colocar a palavra em minúsculo
		for (int i = 0; i < (tamanhoDaPalavra - 1); i++) palavra[i] = tolower(palavra[i]);

		//Criar ponteiro da palavra
		string palavraDaArvore = &palavra[0];

		if (DEBUG) printf("Dados atuais: Palavra:'%s', Tamanho:'%d', Codigo:'%d'.\nEntrando na funcao 'inserirDeterminadaPalavra'...\n", palavraDaArvore, (int)strlen(palavraDaArvore), codigoEmInteiro);

		//Inserir a palavra na arvore
		if (!inserirDeterminadaPalavraNaArvore(palavraDaArvore, codigoEmInteiro, tamanhoDaPalavra)) return false;

		if (DEBUG) printf("Insercao da palavra retornou 'true'. A linha foi lida.\n\n");

		ponteiroDaVirgula = NULL;
	}

	if (DEBUG) printf("Saiu do laco de insercao. Todas as linhas foram lidas.\n");

	return true;
}

//Inverter booleano de ativacao do modo DEBUG
bool inverterDebug() {

	if (DEBUG) printf("Iniciando a funcao, 'inverterDebug'...\n");

	if (DEBUG)
	{
		DEBUG = false;
		printf("\nModo DEBUG desativado.\n");
		mensagemSucesso();
		return true;
	}

	if (!DEBUG)
	{
		DEBUG = true;
		printf("\nModo DEBUG ativado.\n");
		mensagemSucesso();
		return true;
	}

	lancarErro(32);
	return false;
}

//Ler recursivamente um item da arvore
bool lerItemDaArvore(itemDaArvore* itemAuxiliar, string palavra, int letraAtual)
{
	if (DEBUG) printf("\nInicio a funcao 'lerItemDaArvore'...\n");
	if (DEBUG) getchar();
	if (DEBUG) pausa();

	string ultimaPalavra = NULL;

	for (int i = 0; i < TAMANHO_DO_ALFABETO; i++)
	{
		if (DEBUG) printf("\nInicio da iteracao '%d'...\n", i);

		if (itemAuxiliar->proximaLetra[i] != NULL)
		{
			if (DEBUG) printf("A letra '%c' deste item nao esta vazia...\n", i + 'a');

			//Concatenar letra encontrada
			palavra[letraAtual] = i + 'a';
			if (DEBUG) printf("Palavra concatenada no momento '%s' iniciando leitura do proximo item...\n", palavra);

			if (DEBUG) getchar();
			if (DEBUG) pausa();
			if (DEBUG) limparTela();

			lerItemDaArvore(itemAuxiliar->proximaLetra[i], palavra, (letraAtual + 1));
		}

		if (itemAuxiliar->proximaLetra[i] == NULL)
		{
			if (DEBUG) printf("A letra '%c' esta vazia neste item. Iteracao '%d'\n", (i + 'a'), i);

			if (itemAuxiliar->chave > -1)
			{
				if (DEBUG) printf("A chave deste item e maior que '-1'. Sua chave e: '%d'\n", itemAuxiliar->chave);

				if (palavra != ultimaPalavra)
				{
					if (DEBUG) printf("Nova palavra encontrada. Imprimindo na tela...\n");

					printf("Palavra: '%s'\n", palavra);

					existePalavraNaArvore = true;
					if (DEBUG) printf("Existe palavra na arvore '%d'", existePalavraNaArvore);
					if (DEBUG) getchar();
					if (DEBUG) pausa();

					ultimaPalavra = palavra;
				}
			}

			//Verificar se e ultima letra do alfabeto
			if (i == (TAMANHO_DO_ALFABETO - 1))
			{
				if (DEBUG) printf("Esta e a ultima letra do alfabeto. '%d'\n", itemAuxiliar->chave);

				if (DEBUG) printf("Colocando '\\0' na posicao '%d' (letraAtual - 1) da palavra '%s'\n", letraAtual, palavra);

				palavra[letraAtual - 1] = '\0';

				if (DEBUG) printf("Palavra atual: '%s'\n", palavra);
			}
		}
	}
	if (DEBUG) printf("Existe palavra na arvore '%d'", existePalavraNaArvore);

	if (DEBUG) printf("\nFinal da funcao 'lerItemDaArvore'. Retornando true...\n");
	if (DEBUG) getchar();
	if (DEBUG) pausa();

	return existePalavraNaArvore;
}

//Criar a arvore
bool criarArvore() {

	if (DEBUG) printf("Iniciando a funcao, 'criarArvore'...\n");

	//Anular a raiz existente
	raiz = NULL;

	//Atulizar palavras da arvore
	QUANTIDADE_PALAVRAS_CADASTRADAS = 0;

	//Alocar memoria para raiz
	raiz = alocarItemDaArvore();

	//Validar alocacao de memoria
	if (!validarArvoreCriada()) return false;

	//Imprimir mensagem de sucesso na tela
	printf("\nA arvore foi criada com sucesso.\n");

	return true;
}

//Inserir palavras do arquivo na arvore
bool inserirPalavraNaArvore() {

	if (DEBUG) printf("Iniciando a funcao, 'inserirPalavraNaArvore'...\n");

	//Verificar se a arvore foi criada
	if (!validarAlocacaoDeMemoria(raiz))
	{
		printf("\nA arvore ainda nao foi criada. Escolha a opcao 1 do menu para criar a arvore.\n");
		limparErros();
		return true;
	}

	//Declarar e abrir arquivo, validar abertura do arquivo
	FILE* arquivo = fopen("palavras.txt", "r");
	if (!validarAlocacaoDeMemoria(arquivo))
	{
		printf("\nNao foi possivel abrir o arquivo 'palavras.txt'.\n"
			"Verifique se o arquivo esta salvo na mesma pasta do arquivo 'main.c'.");
		limparErros();
		return false;
	}

	if (DEBUG) printf("O arquivo foi aberto com sucesso.\n");

	//Declarar linha de leitura atual
	string linha = (string)malloc(sizeof(char) * TAMANHO_DA_LINHA);
	if (!validarAlocacaoDeMemoria(linha)) return false;

	if (DEBUG) printf("Memoria para linha alocada com sucesso. Lendo primeira linha do arquivo...\n");

	//Ler quantidade de entradas e validar alocacao de memoria
	if (!validarAlocacaoDeMemoria(fgets(linha, TAMANHO_DA_LINHA, arquivo)))
	{
		printf("O arquivo esta vazio. Nenhuma palavra foi inserida na arvore.\n"
			"Para inserir palavras na arvore informe na primeira linha do arquivo a quantidade de palavras a serem inseridas.\n"
			"Nas demais linhas informe a palavra e o seu codigo.\nVeja o exemplo abaixo (sem as aspas):\n"
			"\"palavra, 19\"\n");
		limparErros();
		return true;
	}

	if (DEBUG) printf("Primeira linha lida com sucesso. Linha lida: '%s' Tamanho: '%d'.\n", linha, (int)strlen(linha));

	//Verificar é todos os caracteres da primeira linha sao numericos
	int i = 0; char primeiraLinha[TAMANHO_DA_LINHA]; strcpy(primeiraLinha, linha);
	while (strcmp(&primeiraLinha[i], "\n") != 0)//for (int i = 0; i < (int)strlen(linha); i++)
	{
		if (DEBUG) printf("Verificando caractere da primeira linha. Iteracao: '%d'. Caractere '%c'\n", i, primeiraLinha[i]);

		if (isdigit(primeiraLinha[i]) == 0)
		{
			printf("Nao foi possivel ler a quantidade de palavras a serem inseridas.\nVerifique se a primeira linha do arquivo contem APENAS a quantidade de palavras a serem inseridas.\n");
			return true;
		}

		i++;
	}

	//Converter texto para inteiro e validar conversao
	int entradas = atoi(linha);
	if (!validarNumeroNaturalPositivo(entradas)) return false;

	if (DEBUG) printf("Codigo convertido (%d) com sucesso. Iniciando a leitura das linhas do arquivo...\n", entradas);

	//Ler as linhas do arquivo
	if (!lerLinhasDoArquivo(linha, arquivo, entradas)) return false;

	if (DEBUG) printf("As linhas do arquivo foram lidas com sucesso. Fechando o arquivo...\n");

	//Fehar o arquivo
	if (fclose(arquivo) == EOF)
	{
		lancarErro(30);
		perror(MENSAGEM_DE_ERRO);
		return false;
	}

	if (DEBUG) printf("O arquivo fechou com sucesso.\n");

	//Imprimir mensagem de sucesso na tela
	mensagemSucesso();

	return true;
}

//Ler uma palavra do teclado e consultar na arvore
bool consultarPalavraNaArvore() {

	if (DEBUG) printf("Iniciando a funcao, 'consultarPalavraNaArvore'...\n");

	//Verificar se a arvore foi criada
	if (!validarAlocacaoDeMemoria(raiz))
	{
		printf("\nA arvore esta vazia.\n");
		limparErros();
		return true;
	}

	//Declara palavra a ser lida
	string palavra = NULL;

	//Pedir ao  usuario que digite a palavra
	printf("\nDigite APENAS a palavra que deseja buscar: (Ate %d caracteres)\n\n", TAMANHO_DA_LINHA);

	//Ler palavra do teclado
	palavra = lerTextoDoTeclado(TAMANHO_DA_LINHA);
	if (!validarAlocacaoDeMemoria(palavra)) return false;

	if (DEBUG) printf("Palavra lida com sucesso. Consultando a palavra na arvore...\n");

	//Verificar se a palavra esta na arvore
	if (!consultarUmaDeterminadaPalavraNaArvore(palavra)) return false;

	if (DEBUG) printf("Consulta realizada com sucesso.\n");

	//Imprimir mensagem de sucesso na tela
	mensagemSucesso();

	return true;
}

//Listar todas as palavras cadastradas na arvore
bool listarPalavrasDaArvore() {

	if (DEBUG) printf("Iniciando a funcao, 'listarPalavrasDaArvore'...\n");

	//Verifica se a raiz da arvore esta vazia
	if (raiz == NULL)
	{
		printf("\nA arvore ainda nao foi criada.\n");

		return true;
	}

	if (DEBUG) printf("A raiz da arvore nao e nula.\n");

	//Criar e limpar vetor de caracteres
	char palavraAuxiliar[TAMANHO_DA_LINHA];
	for (int i = 0; i < TAMANHO_DA_LINHA; i++) palavraAuxiliar[i] = '\0';
	int letraAtual = 0;

	string palavraLida = (string)malloc(sizeof(char) * TAMANHO_DA_LINHA);
	palavraLida = &palavraAuxiliar[0];

	//Percorrer cada item da arvore
	bool retornoDaLeitura = lerItemDaArvore(raiz, palavraLida, letraAtual);

	if (DEBUG) printf("Saiu da funcao 'lerItemDaArvore'.\n");

	if (DEBUG) getchar();
	if (DEBUG) pausa();

	if (!retornoDaLeitura) printf("\nA arvore foi percorrida totalmente.\nNenhuma palavra foi encontrada.\n");
	if (retornoDaLeitura) printf("\nA arvore foi percorrida totalmente.\nTodas as palavras encontradas foram listadas.\n");

	if (DEBUG) printf("Saiu do while que percorre a arvore.\nRetorno da leitura '%d'", retornoDaLeitura);

	if (listaDeCodigosDeErro[0] != 0)
	{
		if (DEBUG) printf("Algum erro foi lancado. Retornando falso...\n");

		return false;
	}

	if (DEBUG) printf("Retornando true no final da funcao...\n");

	if (DEBUG) getchar();
	if (DEBUG) pausa();
	if (DEBUG) getchar();

	mensagemSucesso();
	return true;
}

//Limpar todos os nos da arvore
bool removerArvore() {

	if (DEBUG) printf("Iniciando a funcao, 'removerArvore'...\n");

	//Anular a raiz
	raiz = NULL;

	//Zerar a quantidade de palavras cadastradas na arvore
	QUANTIDADE_PALAVRAS_CADASTRADAS = 0;

	//Imprimir mensagem de sucesso na tela
	mensagemSucesso();

	return true;
}

//Executar uma funcao do menu de acordo com a opcao informada
bool executarFuncaoDoMenu(int opcao)
{
	//Validar opcao informada
	if (!validarNumeroNaturalPositivo(opcao)) return false;

	switch (opcao) {

	case 1:
		if (criarArvore()) { break; }
		return false;
	case 2:
		if (inserirPalavraNaArvore()) { break; }
		return false;
	case 3:
		if (consultarPalavraNaArvore()) { break; }
		return false;
	case 4:
		if (listarPalavrasDaArvore()) { break; }
		return false;
	case 5:
		if (removerArvore()) { break; }
		return false;
	case 6:
		sairDoPrograma();
		break;
	case 99:
		if (inverterDebug()) { break; }
		return false;
	default:
		printf("\nOpcao invalida\n");
		break;
	}

	return true;
}

//Imprimir opcoes do menu
void imprimirOpcoesDoMenu()
{
	string status = "DESATIVADO";

	if (DEBUG) status = "ATIVADO";

	printf(
		"\n======================= Trabalho pratico II =======================\n"
		" Alunos: Denise Alpim e Gabriel Trindade\n"
		" O modo DEBUG esta '%s'\n"
		" Escolha a opcao 99 para ativar/desativar o modo DEBUG\n"
		" Quantidade de palavras cadastradas na arvore: '%d'\n"

		"\n	1) Criar (zerar) a arvore"
		"\n	2) Inserir valor (palavra) na arvore pelo 'palavras.txt'"
		"\n	3) Consulta uma palavra na arvore"
		"\n	4) Listar todas as palavras cadastradas na arvore"
		"\n	5) Remover a arvore"
		"\n	6) Encerrar o programa"
		"\n\n"
		, status, QUANTIDADE_PALAVRAS_CADASTRADAS
	);
}

//Executar o menu
bool menu() {

	//Declarar a variavel para guardar a opcao que o usuario escolher
	int opcao = 0;

	//Rodar o programa
	do {

		//Limpar a tela para o menu aparecer sempre em cima
		limparTela();

		//Mostrar as opcoes do menu na tela
		imprimirOpcoesDoMenu();

		//Ler o conteúdo digitado
		opcao = lerNumeroNaturalDoTeclado();

		//Validar conteúdo digitado
		if (opcao == EOF) return false;

		//Executar funcao do menu
		if (!executarFuncaoDoMenu(opcao)) return false;

		//Pausa antes de escolher uma nova opcao
		pausa();

	} while (opcao != CODIGO_FECHA_PROGRAMA);

	return true;
}

//Inicializar a execucao do programa
bool inicializarPrograma() {

	//Configurar local para permitir acentuacao de caracteres especiais
	if (!configurarLocal())
	{
		imprimirListaDeErros();
		pausa();
		sairDoPrograma();
		return false;
	}

	//Exucutar menu
	if (!menu()) return false;

	return true;
}

//Funcao principal
int main()
{
	//Iniciar a execucao do programa
	if (!inicializarPrograma())
	{
		imprimirListaDeErros();
		limparErros();
		pausa();
		main();
	}
	
	return 0;
}
