#include "execucao.h"

//Criar a árvore
bool criarArvore() {

	//Alocar memória para raiz
	raiz = NULL; raiz = alocarItemDaArvore();

	//Validar alocação de memória
	if (!validarAlocacaoDeMemoria(raiz)) return false;
	mensagemSucesso();

	return true;
}


bool lerLinhaDoArquivo() {


}

//Inserir palavras do arquivo na árvore
bool inserirPalavraNaArvore() {

	//Declarar e abrir arquivo, validar abertura do arquivo
	FILE* arquivo = fopen("arquivo.txt", "r");
	if (!validarAlocacaoDeMemoria(arquivo)) return false;

	//Declarar linha de leitura atual
	string linha = (string)malloc(sizeof(char) * TAMANHO_DA_LINHA);
	if (!validarAlocacaoDeMemoria(linha)) return false;

	//Ler quantidade de entradas e validar alocação de memória
	if (fgets(linha, TAMANHO_DA_LINHA, arquivo) == NULL) return false;

	//Converter texto para inteiro
	int entradas = atoi(linha); if (entradas == 0) return false;

	//Declarar vírgula
	const char virgula = ',';

	//Ler cada linha
	for (int i = 0; i < entradas; i++)
	{
		//Pegar a linha do arquivo
		if (fgets(linha, TAMANHO_DA_LINHA, arquivo) == NULL) return false;

		//Encontrar a vírgula na linha
		string ponteiroDaVirgula = strchr(linha, virgula);

		//Tamanho da palavra
		int tamanhoDaPalavra = strlen(linha) - strlen(ponteiroDaVirgula);

		//Palavra
		char palavra[tamanhoDaPalavra];
		memcpy(palavra, linha, tamanhoDaPalavra);

		//Tamanho do código
		int tamanhoDoCodigo = strlen(ponteiroDaVirgula) - 2;

		//Código
		char codigoEmTexto[tamanhoDoCodigo];
		memcpy(codigoEmTexto, (ponteiroDaVirgula + 2), tamanhoDoCodigo);

		//Converter código para int
		int codigoEmInteiro = atoi(codigoEmTexto);

		//Validar se a raiz foi criada
		if (!validarAlocacaoDeMemoria(raiz)) return false;

		//Criar variável auxiliar
		itemDaArvore* itemAuxiliar = raiz;

		//Colocar a palavra em minúsculo
		for (int i = 0; i < (tamanhoDaPalavra - 1); i++)
		{
			palavra[i] = tolower(palavra[i]);
		}

		//Criar ponteiro da palavra
		string palavraDaArvore = &palavra[0];

		//Percorrer a árvore até o final da palavra
		for (int i = 0; i < (strlen(palavra) - 1); i++)
		{
			//Aloca memória para um novo item se o caractere for nulo
			if (itemAuxiliar->proximaLetra[*palavraDaArvore - 'a'] == NULL) {
				printf("criando no na posicao %d\n", (*palavraDaArvore - 'a'));
				//Alocar novo item
				itemDaArvore* novoItem = alocarItemDaArvore();

				//Validar alocação
				if (!validarAlocacaoDeMemoria(novoItem)) return false;

				//Colocar o novo item na arvore
				itemAuxiliar->proximaLetra[*palavraDaArvore - 'a'] = novoItem;
			}
			printf("chave antes de ir ao proximo no: %d\n", itemAuxiliar->chave);
			//Passa para o próximo item
			itemAuxiliar = itemAuxiliar->proximaLetra[*palavraDaArvore - 'a'];
			int numero = (*palavraDaArvore - 'a'); 
			

			char c;
			int i = 12;
			
			printf("\n\nUsando int\n");
			
				printf("Pos %d: char %c \t", i, i);
			pausa();
			//Passar para o próximo caractere
			palavraDaArvore++;
		}

		//Inserir valor
		itemAuxiliar->chave = codigoEmInteiro;
		printf("chave aux: %d\n", itemAuxiliar->chave);
		ponteiroDaVirgula = NULL;
		printf("9\n");

		itemDaArvore* teste = raiz;
		int i = 0; int cont = 0;
		while (teste->chave == -1)
		{
			if (teste->proximaLetra[i] != NULL) {
				printf("%c\n", (i + 'a'));
				teste = teste->proximaLetra[i + 'a'];
				printf("diferente de nulo\n");
				printf("chave %d", teste->chave);
			}
			printf("testess %d\n", i);
			printf("chave %d", teste->chave);

			i++;
		}

		printf("saiu do laco\n");
		break;
	}

	// recebe como entrada o ponteiro geral da arvore, a palavra a ser inserida e o valor
	fclose(arquivo);
	printf("chegou aqui\n");
	return true;
}

bool consultarPalavraNaArvore() {



	return true;
}

bool listarPalavrasDaArvore() {



	return true;
}

bool removerArvore() {



	return true;
}