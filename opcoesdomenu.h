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
			if (itemAuxiliar->proximaLetra[*palavraDaArvore - 'a'] == NULL)
			{
				itemDaArvore novoItem = alocarItemDaArvore();

			}

			printf("nao nulo\n");


		}
	

		/*

			// aloca um novo no caso o ponteiro referente ao caractere (letra) da palavra seja nulo
			if (aux->vetor_alfabeto[*palavra - 'a'] == NULL) // posicao eh calcuada via aritmetica de caracteres
				aux->vetor_alfabeto[*palavra - 'a'] = aloca_NovoNo(); // aloca novo no e faz apontamento

			  // avanca para o proximo no na arvore
			aux = aux->vetor_alfabeto[*palavra - 'a'];
			// avanca para o proximo caractere (letra) da palavra
			palavra++;
		}
		// ao final da palavra, insere o valor associado a esta palavra no no folha
		aux->valor = valor;
		return 0;


		*/




		ponteiroDaVirgula = NULL;
		printf("9\n");
		break;
	}

	// recebe como entrada o ponteiro geral da arvore, a palavra a ser inserida e o valor
	fclose(arquivo);

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