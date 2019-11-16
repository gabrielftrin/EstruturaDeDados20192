#include "validacoes.h"

void imprimirOpcoesDoMenu();

//Imprime uma mensagem de sucesso na tela
void mensagemSucesso() {

	printf("\nOperacao realizada com sucesso.\n");
}

//Alocar memória para um novo item da árvore
itemDaArvore* alocarItemDaArvore() {

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

	//Verificar se a palavra é nula
	if (!validarAlocacaoDeMemoria(palavra)) return false;

	//Verificar se a raiz é nula
	if (!validarAlocacaoDeMemoria(raiz)) return false;

	//Criar ponteiro auxiliar do tipo 'item da arvore'
	itemDaArvore* itemAuxiliar = raiz;

	//Verificar o tamanho da palavra
	int tamanho = strlen(palavra);
	if (DEBUG == 1) printf("antes do for... letra '%c' tamanho do 'for' %d\n", *palavra, tamanho);
	//Percorrer a árvore até o final da palavra ou a palavra não existir
	for (int i = 0; i < tamanho; i++)
	{
		if (DEBUG == 1) printf("verificando a letra %c\n", (*palavra));
		if (DEBUG == 1) printf("codigo item atual: %d iteracao %d\n", itemAuxiliar->chave, i);

		//Verifica se a letra corrente/atual está na árvore
		if (itemAuxiliar->proximaLetra[*palavra - 'a'] == NULL) {
			if (DEBUG == 1) printf("esta posição do vetor de letra é nula.\n");
			//Se ainda não tiver chegado no final da palavra
			if (i < (tamanho - 1))
			{
				//Sai do laço
				printf("\nA palavra nao esta na arvore. iteracao %d\n", i);
				return true;
			}

			//Se chegou no final da palavra
			if (i == (tamanho - 1))
			{
				//Verifica se código foi preenchido
				if (itemAuxiliar->chave > -1)
				{
					limparTela();
					imprimirOpcoesDoMenu();
					printf("\nA palavra '%s' esta na arvore.\nSua chave e: %d\n", (palavra - i), itemAuxiliar->chave);
					return true;
				}

				//Verifica se o código é -1
				if (itemAuxiliar->chave == -1)
				{
					printf("\nA(s) %d primeira(s) letra(s) da palavra estao na arvore.\nPorém sua chave/código é igual a: %d\n", i, itemAuxiliar->chave);
					return true;
				}

				lancarErro(29);
				return false;
			}
		}

		//Passa para o próximo item
		itemAuxiliar = itemAuxiliar->proximaLetra[*palavra - 'a'];
		if (DEBUG == 1) printf("próximo item, código: %d iteracao %d\n", itemAuxiliar->chave, i);
		if (DEBUG == 1) printf("letra %c\n", *palavra);
		palavra++;

		//Se for a ultima iteracao incrementa o tamanho
		if (i == (tamanho - 1)) tamanho++;
	}

	lancarErro(28);
	return false;
}

//Insere uma determinada palavra e um determinado código na árvore
bool inserirDeterminadaPalavraNaArvore(string palavraDaArvore, int codigo) {

	//Validar entradas
	if ((!validarAlocacaoDeMemoria(palavraDaArvore)) || (!validarNumeroNaturalPositivo(codigo)))
		return false;

	//Criar variável auxiliar
	itemDaArvore* itemAuxiliar = raiz;
	if (DEBUG == 1) printf("Argumentos recebidos na função de inserir:\npalavra:%s\ncodigo:%d\n", palavraDaArvore, codigo);
	//Calcular tamanho da string para informar no 'for'
	int tamanho = (strlen(palavraDaArvore));
	if (DEBUG == 1) printf("\ntamanho da palavra (for):%d\n", tamanho);
	//Percorrer a árvore até o final da palavra
	for (int i = 0; i < tamanho; i++)
	{
		//Aloca memória para um novo item se o caractere for nulo
		if (itemAuxiliar->proximaLetra[*palavraDaArvore - 'a'] == NULL) {

			//Alocar novo item da árvore
			itemDaArvore* novoItem = alocarItemDaArvore();
			if (DEBUG == 1) printf("criando novo no...\n");
			//Validar alocação
			if (!validarAlocacaoDeMemoria(novoItem)) return false;

			//Colocar o novo item na arvore
			itemAuxiliar->proximaLetra[*palavraDaArvore - 'a'] = novoItem;
		}
		if (DEBUG == 1) printf("%c %d %d\n", *palavraDaArvore, i, (*palavraDaArvore - 'a'));
		//Passa para o próximo item
		itemAuxiliar = itemAuxiliar->proximaLetra[*palavraDaArvore - 'a'];

		//Sair do laço quando for a última letra
		if (i == (tamanho - 1))
		{
			if (itemAuxiliar->chave == -1)
			{
				if (DEBUG == 1) printf("a chave é -1. Inserido o código %d na árvore\n", codigo);
				//Inserir valor
				itemAuxiliar->chave = codigo;
				if (DEBUG == 1) printf("chave inserida: %d\n", itemAuxiliar->chave);
				if (DEBUG == 1) printf("ponteiro do item na letra '%c':%p\n", *palavraDaArvore, itemAuxiliar->proximaLetra[*palavraDaArvore - 'a']);
				return true;
			}

			if (itemAuxiliar->chave > -1)
			{
				if (DEBUG == 1) printf("a chave é maior que -1... (chave = %d) incrementando tamanho.\n", itemAuxiliar->chave);
				tamanho++;
			}

			if (DEBUG == 1) printf("a chave (%d) é menor que -1\n", itemAuxiliar->chave);
		}

		//Passar para o próximo caractere
		palavraDaArvore++;
		if (DEBUG == 1) printf("proxima letra... ");
	}
	if (DEBUG == 1) printf("saiu do 'for': %c %d sem inserir a chave na árvore.\n", *palavraDaArvore, (*palavraDaArvore - 'a'));

	return true;
}

//Ler uma quantidade de linhas de um arquivo
bool lerLinhasDoArquivo(string linha, FILE* arquivo, int entradas) {

	//Validar entradas da função
	if (
		(!validarAlocacaoDeMemoria(linha)) ||
		(!validarAlocacaoDeMemoria(arquivo)) ||
		(!validarNumeroNaturalPositivo(entradas)) ||
		(!validarAlocacaoDeMemoria(raiz))
		)
		return false;

	//Iterar sobre as linhas
	for (int i = 0; i < entradas; i++)
	{
		//Pegar a linha do arquivo
		if (!validarAlocacaoDeMemoria(fgets(linha, TAMANHO_DA_LINHA, arquivo))) return false;
		//printf("lendo linha do arquivo:%s;\n", linha);
				//Encontrar a vírgula na linha
		string ponteiroDaVirgula = strchr(linha, ',');
		if (!validarAlocacaoDeMemoria(ponteiroDaVirgula)) return false;
		//printf("resto da linha a partir da virgula:%s;\n", ponteiroDaVirgula);
				//Tamanho da palavra
		int tamanhoDaPalavra = strlen(linha) - strlen(ponteiroDaVirgula);
		//printf("tamanhos: linha:%d resto da linha:%d; diferenca:%d\n", strlen(linha), strlen(ponteiroDaVirgula), tamanhoDaPalavra);
				//Palavra
		char palavra[tamanhoDaPalavra];
		memcpy(palavra, linha, tamanhoDaPalavra);
		//printf("copiando palavra para o vetor. Palavra:%s\nlinha:%s\ntamanho:%d\n", palavra, linha, tamanhoDaPalavra);
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

		//Colocar a palavra em minúsculo
		for (int i = 0; i < (tamanhoDaPalavra - 1); i++) palavra[i] = tolower(palavra[i]);

		//Criar ponteiro da palavra
		string palavraDaArvore = &palavra[0];
		//printf("passando palavra pro ponteiro:%s;\ntamanho:%d\n", palavraDaArvore, strlen(palavraDaArvore));
				//Inserir a palavra na árvore
		if (!inserirDeterminadaPalavraNaArvore(palavraDaArvore, codigoEmInteiro)) return false;
		//printf("terminou de ler a linha...\n\n");
		ponteiroDaVirgula = NULL;
	}
	if (DEBUG == 1) printf("\nleu todas as linhas\n");
	return true;
}
