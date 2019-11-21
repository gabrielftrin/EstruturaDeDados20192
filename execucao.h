#include "validacoes.h"

//Imprime uma mensagem de sucesso na tela
void mensagemSucesso() {

	printf("\nOperacao realizada com sucesso.\n");
}

//Verificar se a raiz da �rvore � nula
bool validarArvoreCriada() {

	if (DEBUG == true) printf("Iniciando a funcao, 'validarArvoreCriada'...\n");

	if (!validarAlocacaoDeMemoria(raiz))
	{
		lancarErro(33);
		return false;
	}

	return true;
}

//Alocar mem�ria para um novo item da �rvore
itemDaArvore* alocarItemDaArvore() {

	if (DEBUG == true) printf("Iniciando a funcao, 'alocarItemDaArvore'...\n");

	itemDaArvore* novoItem = (itemDaArvore*)malloc(sizeof(itemDaArvore));

	if (!validarAlocacaoDeMemoria(novoItem)) return NULL;

	novoItem->chave = -1;

	for (int i = 0; i < TAMANHO_DO_ALFABETO; i++)
	{
		novoItem->proximaLetra[i] = NULL;
	}

	QUANTIDADE_ITEM_ARVORE++;

	return novoItem;
}

//Verificar se uma determinada palavra est� cadastrada na arvore
bool consultarUmaDeterminadaPalavraNaArvore(string palavra) {

	if (DEBUG == true) printf("Iniciando a funcao, 'consultarUmaDeterminadaPalavraNaArvore'...\n");

	//Verificar se a palavra � nula
	if (!validarAlocacaoDeMemoria(palavra)) return false;

	if (DEBUG == true) printf("A palavra recebida foi validada com sucesso. Validando raiz da arvore..\n");

	//Verificar se a raiz � nula
	if (!validarArvoreCriada())
	{
		printf("\nA �rvore est� vazia.\n");
		return true;
	}

	if (DEBUG == true) printf("Raiz validada com sucesso. Calculando tamanho da palavra...\n");

	//Criar ponteiro auxiliar do tipo 'item da arvore'
	itemDaArvore* itemAuxiliar = raiz;

	//Verificar o tamanho da palavra
	int tamanho = strlen(palavra);

	if (DEBUG == true) printf("Primeira letra da palavra: '%c'. Tamanho da palavra '%d'. Iniciando iteracao...\n", *palavra, tamanho);

	//Percorrer a �rvore at� o final da palavra ou at� palavra n�o existir
	for (int i = 0; i < tamanho; i++)
	{
		if (DEBUG == true) printf("\nItera��o '%d'. Verificando a letra '%c'. C�digo do item atual '%d'.\n", i, (*palavra), itemAuxiliar->chave);

		//Verifica se a letra corrente/atual est� na �rvore
		if (itemAuxiliar->proximaLetra[*palavra - 'a'] == NULL)
		{
			if (DEBUG == true) printf("A posicao %d do vetor e nula.\n", (*palavra - 'a'));

			printf("\nA palavra '%s' n�o est� na �rvore. Apenas as primeiras %d letras est�o na �rvore.\n", (palavra - i), i);

			if (DEBUG == true) printf("\nDados: itera��o:'%d', palavra:'%s', chave:'%d'. Retornando true...\n", i, (palavra - i), itemAuxiliar->chave);

			return true;
		}

		//Passa para o pr�ximo item
		itemAuxiliar = itemAuxiliar->proximaLetra[*palavra - 'a'];

		if (DEBUG == true) printf("Passando para o pr�ximo item... c�digo: '%d', itera��o '%d'\n", itemAuxiliar->chave, i);

		//Se a chave for positiva encontrou a palavra
		if (itemAuxiliar->chave > -1)
		{
			if (DEBUG == true) printf("O c�digo do item � maior que -1. C�digo: '%d', itera��o '%d'\n", itemAuxiliar->chave, i);

			if (i >= (tamanho - 1))
			{
				printf("\nA palavra '%s' est� na �rvore. Sua chave �: %d\n", (palavra - i), itemAuxiliar->chave);
				return true;
			}
		}

		//Se chegou no final da palavra, retorna true informando que a palavra n�o est� na �rvore
		if (i == (tamanho - 1))
		{
			if (DEBUG == true) printf("\nA itera��o � igual ao tamanho -1 (ultima letra da palavra). Dados: itera��o:'%d', palavra:'%s', chave:'%d'. Retornando true...\n", i, (palavra - i), itemAuxiliar->chave);

			printf("\nA palavra '%s' n�o est� na �rvore. Apenas as primeiras %d letras est�o na �rvore.\n", (palavra - i), i);

			mensagemSucesso();
			return true;
		}

		if (DEBUG == true) printf("Incrementando palavra...\n");

		//Indo para a proxima letra
		palavra++;

		if (DEBUG == true) printf("Palavra incrementada. Nova letra '%c'.\n", *palavra);
	}

	if (DEBUG == true) printf("Lancando erro...\nDados: Tamanho '%d', Letra '%c', Vetor '%d'\n", tamanho, *palavra, (*palavra - 'a'));

	lancarErro(28);
	return false;
}

//Insere uma determinada palavra e um determinado c�digo na �rvore
bool inserirDeterminadaPalavraNaArvore(string palavraDaArvore, int codigo, int tamanho) {

	if (DEBUG == true) printf("Iniciando a funcao, 'inserirDeterminadoItemNaArvore'...\n");

	//Validar entradas
	if ((!validarAlocacaoDeMemoria(palavraDaArvore)) || (!validarNumeroNaturalPositivo(codigo)))
	{
		if (DEBUG == true) printf("Argumento inv�lido. A palavra ou o c�digo recebidos, s�o inv�lidos. Retornando falso...\n");

		return false;
	}

	//Criar vari�vel auxiliar
	itemDaArvore* itemAuxiliar = raiz;

	if (DEBUG == true) printf("Argumentos recebidos: Palavra:'%s', C�digo:'%d', Tamanho:'%d'. Iniciando itera��o...\n", palavraDaArvore, codigo, tamanho);

	//Percorrer a �rvore at� o final da palavra
	for (int i = 0; i < tamanho; i++)
	{
		if (DEBUG == true) printf("\nIn�cio da itera��o '%d'.\n", i);

		//Aloca mem�ria para um novo item se o caractere for nulo
		if (itemAuxiliar->proximaLetra[*palavraDaArvore - 'a'] == NULL) {

			if (DEBUG == true) printf("A posi��o '%d' � nula. Alocando mem�ria para o novo item...\n", (*palavraDaArvore - 'a'));

			//Alocar novo item da �rvore
			itemDaArvore* novoItem = alocarItemDaArvore();

			//Validar aloca��o
			if (!validarAlocacaoDeMemoria(novoItem)) return false;

			if (DEBUG == true) printf("Mem�ria alocada com sucesso. Inserindo o novo item na �vore...\n");

			//Colocar o novo item na arvore
			itemAuxiliar->proximaLetra[*palavraDaArvore - 'a'] = novoItem;
		}

		if (DEBUG == true) printf("Passando para o pr�ximo item. Letra '%c', Itera��o '%d', Vetor '%d'\n", *palavraDaArvore, i, (*palavraDaArvore - 'a'));

		//Passa para o pr�ximo item
		itemAuxiliar = itemAuxiliar->proximaLetra[*palavraDaArvore - 'a'];

		//Sair do la�o quando for a �ltima letra
		if (i == (tamanho - 1))
		{
			if (DEBUG == true) printf("Esta � a �ltima letra. Itera��o '%d'.\n", i);

			if (itemAuxiliar->chave == -1)
			{
				if (DEBUG == true) printf("A chave deste item e '%d'. Inserido o codigo '%d' na arvore...\n", itemAuxiliar->chave, codigo);

				//Inserir valor
				itemAuxiliar->chave = codigo;

				if (DEBUG == true) printf("Chave inserida: '%d'. Letra atual: '%c'. Vetor atual: '%d'.\nRetornando true...", itemAuxiliar->chave, (*palavraDaArvore), (*palavraDaArvore - 'a'));

				return true;
			}

			if (itemAuxiliar->chave > -1)
			{
				if (DEBUG == true) printf("A chave '%d' e maior que -1.\n", itemAuxiliar->chave);

				if (DEBUG == true) printf("A palavra '%s' ja foi cadastrada na arvore com o codigo '%d'. Atualizando c�digo para '%d'.\n", (palavraDaArvore - i), itemAuxiliar->chave, codigo);

				itemAuxiliar->chave = codigo;

				if (DEBUG == true) printf("Codigo '%d' atualizado com sucesso. Retornando true...\n", itemAuxiliar->chave);

				return true;
			}

			if (DEBUG == true) printf("Dados atuais: Chave: '%d', Letra: '%c'. Vetor: '%d'.\n", itemAuxiliar->chave, (*palavraDaArvore), (*palavraDaArvore - 'a'));
		}

		if (DEBUG == true) printf("Letra atual '%c'. Passando para proxima letra...\n", (i + 'a'));

		//Passar para o pr�ximo caractere
		palavraDaArvore++;

		if (DEBUG == true) printf("Letra incrementada: '%c'\n", *palavraDaArvore);
	}

	if (DEBUG == true) printf("Saiu da iteracao sem inserir o item. Dados: Letra '%c', Chave do item atual '%d'. Lan�ando erro...\n", *palavraDaArvore, itemAuxiliar->chave);

	lancarErro(34);
	return false;
}

//Ler uma quantidade de linhas de um arquivo
bool lerLinhasDoArquivo(string linha, FILE* arquivo, int entradas) {

	if (DEBUG == true) printf("Iniciando a funcao, 'lerLinhasDoArquivo'...\n");

	//Validar entradas da fun��o
	if (
		(!validarAlocacaoDeMemoria(linha)) ||
		(!validarAlocacaoDeMemoria(arquivo)) ||
		(!validarNumeroNaturalPositivo(entradas)) ||
		(!validarAlocacaoDeMemoria(raiz))
		)
		return false;

	if (DEBUG == true) printf("A linha, a quantidade de entradas, raiz e o arquivo sao validos. Iniciando a iteracao.\n");

	//Iterar sobre as linhas
	for (int i = 0; i < entradas; i++)
	{
		if (DEBUG == true) printf("In�cio da itera��o. Itera��o '%d'. Lendo linha do arquivo...\n", i);

		//Pegar a linha do arquivo
		if (!validarAlocacaoDeMemoria(fgets(linha, TAMANHO_DA_LINHA, arquivo))) return false;

		if (DEBUG == true) printf("Linha lida com sucesso. Linha: '%s'. Procurando v�rgula na linha...\n", linha);

		//Encontrar a v�rgula na linha
		string ponteiroDaVirgula = strchr(linha, ',');
		if (!validarAlocacaoDeMemoria(ponteiroDaVirgula)) return false;

		if (DEBUG == true) printf("V�rgula encontrada. Resto da linha a partir da v�rgula: '%s'.\nCalculando tamanho da palavra...", ponteiroDaVirgula);

		//Tamanho da palavra
		int tamanhoDaPalavra = strlen(linha) - strlen(ponteiroDaVirgula);

		if (DEBUG == true) printf("Resultado: Linha '%d', Resto da linha: '%d', Diferenca '%d'. Copiando palavra da linha...\n", (int) strlen(linha), (int) strlen(ponteiroDaVirgula), tamanhoDaPalavra);

		//Palavra
		char palavra[tamanhoDaPalavra];
		memcpy(palavra, linha, tamanhoDaPalavra);

		if (DEBUG == true) printf("Palavra copiada com sucesso. Palavra: '%s', Linha: '%s', Tamanho: '%d'.Copiando, Calculando e convertendo chave...\n", palavra, linha, tamanhoDaPalavra);

		//Tamanho do c�digo
		int tamanhoDoCodigo = strlen(ponteiroDaVirgula) - 2;

		//C�digo
		char codigoEmTexto[tamanhoDoCodigo];
		memcpy(codigoEmTexto, (ponteiroDaVirgula + 2), tamanhoDoCodigo);

		//Converter c�digo para int
		int codigoEmInteiro = atoi(codigoEmTexto);
		if (!validarNumeroNaturalPositivo(codigoEmInteiro)) return false;

		//Criar vari�vel auxiliar
		itemDaArvore* itemAuxiliar = raiz;

		if (DEBUG == true) printf("Chave copiada com sucesso. Chave '%d'. Colocando palavra em min�sculo...\n", codigoEmInteiro);

		//Colocar a palavra em minusculo
		for (int i = 0; i < (tamanhoDaPalavra - 1); i++) palavra[i] = tolower(palavra[i]);

		//Criar ponteiro da palavra
		string palavraDaArvore = &palavra[0];

		if (DEBUG == true) printf("Dados atuais: Palavra:'%s', Tamanho:'%d', Codigo:'%d'.\nEntrando na funcao 'inserirDeterminadaPalavraNaArvore'...\n", palavraDaArvore, (int) strlen(palavraDaArvore), codigoEmInteiro);

		//Inserir a palavra na arvore
		if (!inserirDeterminadaPalavraNaArvore(palavraDaArvore, codigoEmInteiro, tamanhoDaPalavra)) return false;

		if (DEBUG == true) printf("Insercao da palavra retornou 'true'. A linha foi lida.\n\n");

		ponteiroDaVirgula = NULL;
	}

	if (DEBUG == true) printf("Saiu do la�o de inser��o. Todas as linhas foram lidas.\n");

	return true;
}

//Inverter booleano de ativacao do modo DEBUG
bool inverterDebug() {

	if (DEBUG == true) printf("Iniciando a funcao, 'inverterDebug'...\n");

	if (DEBUG == true)
	{
		DEBUG = false;
		printf("\nModo DEBUG desativado.\n");
		mensagemSucesso();
		return true;
	}

	if (DEBUG == false)
	{
		DEBUG = true;
		printf("\nModo DEBUG ativado.\n");
		mensagemSucesso();
		return true;
	}

	lancarErro(32);
	return false;
}
