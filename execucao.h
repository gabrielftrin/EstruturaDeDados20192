#include "validacoes.h"

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

		if (DEBUG) printf("Palavra copiada com sucesso. Palavra: '%s', Linha: '%s', Tamanho: '%d'.Copiando, Coletando codigo da palavra...\n", palavra, linha, tamanhoDaPalavra);

		//Tamanho do codigo
		int tamanhoDoCodigo = (int) strlen(ponteiroDaVirgula) - 2;

		//Codigo
		char codigoEmTexto[tamanhoDoCodigo];
		memcpy(codigoEmTexto, (ponteiroDaVirgula + 2), tamanhoDoCodigo);

		//Converter codigo para int
		int codigoEmInteiro = atoi(codigoEmTexto);
		if (!validarNumeroNaturalPositivo(codigoEmInteiro)) return false;

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