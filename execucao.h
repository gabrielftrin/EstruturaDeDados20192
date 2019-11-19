#include "validacoes.h"

//Imprime uma mensagem de sucesso na tela
void mensagemSucesso() {

	printf("\nOperacao realizada com sucesso.\n");
}

//Verificar se a raiz da árvore é nula
bool validarArvoreCriada() {

	if (DEBUG == true) printf("Iniciando a funcao, 'validarArvoreCriada'...\n");

	if (!validarAlocacaoDeMemoria(raiz))
	{
		lancarErro(33);
		return false;
	}

	return true;
}

//Alocar memória para um novo item da árvore
itemDaArvore* alocarItemDaArvore() {

	if (DEBUG == true) printf("Iniciando a funcao, 'alocarItemDaArvore'...\n");

	itemDaArvore* novoItem = (itemDaArvore*)malloc(sizeof(itemDaArvore));

	if (!validarAlocacaoDeMemoria(novoItem)) return NULL;

	novoItem->chave = -1;

	for (int i = 0; i < TAMANHO_DO_ALFABETO; i++)
	{
		novoItem->proximaLetra[i] = NULL;
	}

	return novoItem;
}

//Verificar se uma determinada palavra está cadastrada na arvore
bool consultarUmaDeterminadaPalavraNaArvore(string palavra) {

	if (DEBUG == true) printf("Iniciando a funcao, 'consultarUmaDeterminadaPalavraNaArvore'...\n");

	//Verificar se a palavra é nula
	if (!validarAlocacaoDeMemoria(palavra)) return false;

	if (DEBUG == true) printf("A palavra recebida foi validada com sucesso. Validando raiz da arvore..\n");

	//Verificar se a raiz é nula
	if (!validarArvoreCriada())
	{
		printf("\nA árvore está vazia.\n");
		return true;
	}

	if (DEBUG == true) printf("Raiz validada com sucesso. Calculando tamanho da palavra...\n");

	//Criar ponteiro auxiliar do tipo 'item da arvore'
	itemDaArvore* itemAuxiliar = raiz;

	//Verificar o tamanho da palavra
	int tamanho = strlen(palavra);

	if (DEBUG == true) printf("Primeira letra da palavra: '%c'. Tamanho da palavra '%d'. Iniciando iteracao...\n", *palavra, tamanho);

	//Percorrer a árvore até o final da palavra ou até palavra não existir
	for (int i = 0; i < tamanho; i++)
	{
		if (DEBUG == true) printf("\nIteração '%d'. Verificando a letra '%c'. Código do item atual '%d'.\n", i, (*palavra), itemAuxiliar->chave);

		//Verifica se a letra corrente/atual está na árvore
		if (itemAuxiliar->proximaLetra[*palavra - 'a'] == NULL)
		{
			if (DEBUG == true) printf("A posicao %d do vetor e nula.\n", (*palavra - 'a'));

			printf("\nA palavra '%s' não está na árvore. Apenas as primeiras %d letras estão na árvore.\n", (palavra - i), i);

			if (DEBUG == true) printf("\nDados: iteração:'%d', palavra:'%s', chave:'%d'. Retornando true...\n", i, (palavra - i), itemAuxiliar->chave);

			return true;
		}

		//Passa para o próximo item
		itemAuxiliar = itemAuxiliar->proximaLetra[*palavra - 'a'];

		if (DEBUG == true) printf("Passando para o próximo item... código: '%d', iteração '%d'\n", itemAuxiliar->chave, i);

		//Se a chave for positiva encontrou a palavra
		if (itemAuxiliar->chave > -1)
		{
			if (DEBUG == true) printf("O código do item é maior que -1. Código: '%d', iteração '%d'\n", itemAuxiliar->chave, i);

			if (i >= (tamanho - 1))
			{
				printf("\nA palavra '%s' está na árvore. Sua chave é: %d\n", (palavra - i), itemAuxiliar->chave);
				return true;
			}
		}

		//Se chegou no final da palavra, retorna true informando que a palavra não está na árvore
		if (i == (tamanho - 1))
		{
			if (DEBUG == true) printf("\nA iteração é igual ao tamanho -1 (ultima letra da palavra). Dados: iteração:'%d', palavra:'%s', chave:'%d'. Retornando true...\n", i, (palavra - i), itemAuxiliar->chave);

			printf("\nA palavra '%s' não está na árvore. Apenas as primeiras %d letras estão na árvore.\n", (palavra - i), i);

			mensagemSucesso();
			return true;
		}

		if (DEBUG == true) printf("Incrementando palavra...\n");

		//Indo para a proxima letra
		palavra++;

		if (DEBUG == true) printf("Palavra incrementada. Nova letra '%c'.\n", *palavra);
	}

	if (DEBUG == true) printf("Lançando erro...\nDados: Tamanho '%d', Letra '%c', Vetor '%d'\n", tamanho, palavra, (*palavra - 'a'));

	lancarErro(28);
	return false;
}

//Insere uma determinada palavra e um determinado código na árvore
bool inserirDeterminadaPalavraNaArvore(string palavraDaArvore, int codigo, int tamanho) {

	if (DEBUG == true) printf("Iniciando a funcao, 'inserirDeterminadoItemNaArvore'...\n");

	//Validar entradas
	if ((!validarAlocacaoDeMemoria(palavraDaArvore)) || (!validarNumeroNaturalPositivo(codigo)))
	{
		if (DEBUG == true) printf("Argumento inválido. A palavra ou o código recebidos, são inválidos. Retornando falso...\n");

		return false;
	}

	//Criar variável auxiliar
	itemDaArvore* itemAuxiliar = raiz;

	if (DEBUG == true) printf("Argumentos recebidos: Palavra:'%s', Código:'%d', Tamanho:'%d'. Iniciando iteração...\n", palavraDaArvore, codigo, tamanho);

	//Percorrer a árvore até o final da palavra
	for (int i = 0; i < tamanho; i++)
	{
		if (DEBUG == true) printf("\nInício da iteração '%d'.\n", i);

		//Aloca memória para um novo item se o caractere for nulo
		if (itemAuxiliar->proximaLetra[*palavraDaArvore - 'a'] == NULL) {

			if (DEBUG == true) printf("A posição '%d' é nula. Alocando memória para o novo item...\n", (*palavraDaArvore - 'a'));

			//Alocar novo item da árvore
			itemDaArvore* novoItem = alocarItemDaArvore();

			//Validar alocação
			if (!validarAlocacaoDeMemoria(novoItem)) return false;

			if (DEBUG == true) printf("Memória alocada com sucesso. Inserindo o novo item na ávore...\n");

			//Colocar o novo item na arvore
			itemAuxiliar->proximaLetra[*palavraDaArvore - 'a'] = novoItem;
		}

		if (DEBUG == true) printf("Passando para o próximo item. Letra '%c', Iteração '%d', Vetor '%d'\n", *palavraDaArvore, i, (*palavraDaArvore - 'a'));

		//Passa para o próximo item
		itemAuxiliar = itemAuxiliar->proximaLetra[*palavraDaArvore - 'a'];

		//Sair do laço quando for a última letra
		if (i == (tamanho - 1))
		{
			if (DEBUG == true) printf("Esta é a última letra. Iteração '%d'.\n", i);

			if (itemAuxiliar->chave == -1)
			{
				if (DEBUG == true) printf("A chave deste item é '%d'. Inserido o código '%d' na árvore...\n", itemAuxiliar->chave, codigo);

				//Inserir valor
				itemAuxiliar->chave = codigo;

				if (DEBUG == true) printf("Chave inserida: '%d'. Letra atual: '%c'. Vetor atual: '%d'.\nRetornando true...", itemAuxiliar->chave, (*palavraDaArvore), (*palavraDaArvore - 'a'));

				return true;
			}

			if (itemAuxiliar->chave > -1)
			{
				if (DEBUG == true) printf("A chave '%d' é maior que -1.\n", itemAuxiliar->chave);

				if (DEBUG == true) printf("A palavra '%s' já foi cadastrada na árvore com o código '%d'. Atualizando código para '%d'.\n", (palavraDaArvore - i), itemAuxiliar->chave, codigo);

				itemAuxiliar->chave = codigo;

				if (DEBUG == true) printf("Código '%d' atualizado com sucesso. Retornando true...\n", itemAuxiliar->chave);

				return true;
			}

			if (DEBUG == true) printf("Dados atuais: Chave: '%d', Letra: '%c'. Vetor: '%d'.\n", itemAuxiliar->chave, (*palavraDaArvore), (*palavraDaArvore - 'a'));
		}

		if (DEBUG == true) printf("Letra atual '%c'. Passando para próxima letra...\n");

		//Passar para o próximo caractere
		palavraDaArvore++;

		if (DEBUG == true) printf("Letra incrementada: '%c'\n", *palavraDaArvore);
	}

	if (DEBUG == true) printf("Saiu da iteração sem inserir o item. Dados: Letra '%c', Chave do item atual '%d'. Lançando erro...\n", *palavraDaArvore, itemAuxiliar->chave);

	lancarErro(34);
	return false;
}

//Ler uma quantidade de linhas de um arquivo
bool lerLinhasDoArquivo(string linha, FILE* arquivo, int entradas) {

	if (DEBUG == true) printf("Iniciando a funcao, 'lerLinhasDoArquivo'...\n");

	//Validar entradas da função
	if (
		(!validarAlocacaoDeMemoria(linha)) ||
		(!validarAlocacaoDeMemoria(arquivo)) ||
		(!validarNumeroNaturalPositivo(entradas)) ||
		(!validarAlocacaoDeMemoria(raiz))
		)
		return false;

	if (DEBUG == true) printf("A linha, a quantidade de entradas, raiz e o arquivo são válidos. Iniciando a iteração.\n");

	//Iterar sobre as linhas
	for (int i = 0; i < entradas; i++)
	{
		if (DEBUG == true) printf("Início da iteração. Iteração '%d'. Lendo linha do arquivo...\n", i);

		//Pegar a linha do arquivo
		if (!validarAlocacaoDeMemoria(fgets(linha, TAMANHO_DA_LINHA, arquivo))) return false;

		if (DEBUG == true) printf("Linha lida com sucesso. Linha: '%s'. Procurando vírgula na linha...\n", linha);

		//Encontrar a vírgula na linha
		string ponteiroDaVirgula = strchr(linha, ',');
		if (!validarAlocacaoDeMemoria(ponteiroDaVirgula)) return false;

		if (DEBUG == true) printf("Vírgula encontrada. Resto da linha a partir da vírgula: '%s'.\nCalculando tamanho da palavra...", ponteiroDaVirgula);

		//Tamanho da palavra
		int tamanhoDaPalavra = strlen(linha) - strlen(ponteiroDaVirgula);

		if (DEBUG == true) printf("Resultado: Linha '%d', Resto da linha: '%d', Diferenca '%d'. Copiando palavra da linha...\n", strlen(linha), strlen(ponteiroDaVirgula), tamanhoDaPalavra);

		//Palavra
		char palavra[tamanhoDaPalavra];
		memcpy(palavra, linha, tamanhoDaPalavra);

		if (DEBUG == true) printf("Palavra copiada com sucesso. Palavra: '%s', Linha: '%s', Tamanho: '%d'.Copiando, Calculando e convertendo chave...\n", palavra, linha, tamanhoDaPalavra);

		//Tamanho do código
		int tamanhoDoCodigo = strlen(ponteiroDaVirgula) - 2;

		//Código
		char codigoEmTexto[tamanhoDoCodigo];
		memcpy(codigoEmTexto, (ponteiroDaVirgula + 2), tamanhoDoCodigo);

		//Converter código para int
		int codigoEmInteiro = atoi(codigoEmTexto);
		if (!validarNumeroNaturalPositivo(codigoEmInteiro)) return false;

		//Criar variável auxiliar
		itemDaArvore* itemAuxiliar = raiz;

		if (DEBUG == true) printf("Chave copiada com sucesso. Chave '%d'. Colocando palavra em minúsculo...\n", codigoEmInteiro);

		//Colocar a palavra em minúsculo
		for (int i = 0; i < (tamanhoDaPalavra - 1); i++) palavra[i] = tolower(palavra[i]);

		//Criar ponteiro da palavra
		string palavraDaArvore = &palavra[0];

		if (DEBUG == true) printf("Dados atuais: Palavra:'%s', Tamanho:'%d', Código:'%d'.\nEntrando na função 'inserirDeterminadaPalavra'...\n", palavraDaArvore, strlen(palavraDaArvore), codigoEmInteiro);

		//Inserir a palavra na árvore
		if (!inserirDeterminadaPalavraNaArvore(palavraDaArvore, codigoEmInteiro, tamanhoDaPalavra)) return false;

		if (DEBUG == true) printf("Inserção da palavra retornou 'true'. A linha foi lida.\n\n");

		ponteiroDaVirgula = NULL;
	}

	if (DEBUG == true) printf("Saiu do laço de inserção. Todas as linhas foram lidas.\n");

	return true;
}

//Inverter booleano de ativação do modo DEBUG
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

//Criar a pilha de chamadas
pilha* criarPilha() {

	if (DEBUG == true) printf("Iniciando a funcao, 'criarPilha'...\n");

	pilha* novaPilha = NULL;

	novaPilha = (pilha*)malloc(sizeof(pilha));
	if (!validarAlocacaoDeMemoria(novaPilha)) return NULL;

	novaPilha->quantidadeDeItens = 0;
	novaPilha->topo = NULL;

	if (DEBUG == true) printf("Imprimindo NOVA pilha: '%d'...\n", novaPilha);
	return novaPilha;
}

//Inserir item na pilha de chamadas de itens da árvore
bool inserirItemNaPilha(int vetorParaVerificar, itemDaArvore* itemParaVerificar, pilha* pilhaDeChamadas) {

	if (DEBUG == true) printf("Iniciando a funcao, 'inserirItemNaPilha'...\n");

	if (!validarNumeroNatural(vetorParaVerificar)) return false;

	if (!validarAlocacaoDeMemoria(itemParaVerificar)) return false;

	if (DEBUG == true) printf("Imprimindo pilha de chamadas: '%d'...\n", pilhaDeChamadas);

	if (pilhaDeChamadas == NULL) {

		if (DEBUG == true) printf("Imprimindo pilha de chamadas: '%d'...\n", pilhaDeChamadas);
		pilhaDeChamadas = criarPilha();
		if (DEBUG == true) printf("Imprimindo pilha de chamadas: '%d'...\n", pilhaDeChamadas);
		if (pilhaDeChamadas == NULL) return false;
	}

	if (DEBUG == true) printf("Imprimindo pilha de chamadas: '%d'...\n", pilhaDeChamadas);

	if (DEBUG == true) printf("Alocando memória para o item da pilha...\n");

	itemDaPilha* item = (itemDaPilha*)malloc(sizeof(itemDaPilha));
	if (!validarAlocacaoDeMemoria(item)) return false;

	item->itemParaVerificar = itemParaVerificar;
	item->vetorParaVerificar = vetorParaVerificar;
	item->itemAnteriorDaPilha = NULL;

	if (pilhaDeChamadas->topo == NULL && pilhaDeChamadas->quantidadeDeItens == 0)
	{
		if (DEBUG == true) printf("O topo é nulo. Retornando true...\n");

		pilhaDeChamadas->topo = item;
		pilhaDeChamadas->quantidadeDeItens = 1;
		if (DEBUG == true) printf("Quantidade de itens da pilha '%d'. Retornando true\n", pilhaDeChamadas->quantidadeDeItens);
		if (DEBUG == true) printf("Imprimindo pilha de chamadas: '%d'...\n", pilhaDeChamadas);

		return true;
	}

	if (pilhaDeChamadas->topo != NULL && pilhaDeChamadas->quantidadeDeItens > 0)
	{
		if (DEBUG == true) printf("O topo da pilha NÃO é nulo.\n");

		item->itemAnteriorDaPilha = pilhaDeChamadas->topo;
		pilhaDeChamadas->topo = item;
		pilhaDeChamadas->quantidadeDeItens++;

		if (DEBUG == true) printf("O item foi inserido no topo da pilha\n");
		if (DEBUG == true) printf("Quantidade de itens da pilha '%d'.\n", pilhaDeChamadas->quantidadeDeItens);

		return true;
	}

	if (DEBUG == true) printf("\nLançando erro nao esperado ao INSERIR ITEM NA PILHA...\n");

	lancarErro(35);
	return false;
}

//Remover topo da pilha de chamadas de itens da árvore
itemDaPilha* removerTopoDaPilha(pilha* pilhaDeChamadas) {

	if (DEBUG == true) printf("Iniciando a funcao, 'removerItemDaPilha'...\n");

	if (pilhaDeChamadas == NULL)
	{
		if (DEBUG == true) printf("O ponteiro da pilha de chamadas e nulo. Nenhum item foi removido. Retornando nulo...\n");

		return NULL;
	}

	if ((pilhaDeChamadas->topo == NULL) && (pilhaDeChamadas->quantidadeDeItens == 0))
	{
		if (DEBUG == true) printf("A pilha de chamadas está vazia. Nenhum item foi removido. Retornando nulo...\n");

		return NULL;
	}

	if (pilhaDeChamadas->topo != NULL && pilhaDeChamadas->quantidadeDeItens > 0)
	{
		itemDaPilha* topoRemovido = pilhaDeChamadas->topo;
		pilhaDeChamadas->topo = pilhaDeChamadas->topo->itemAnteriorDaPilha;
		pilhaDeChamadas->quantidadeDeItens--;
		return topoRemovido;
	}

	lancarErro(37);
	return false;
}