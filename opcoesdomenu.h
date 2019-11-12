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

//Inserir palavras do arquivo na árvore
bool inserirPalavraNaArvore() {

	//Declarar e abrir arquivo, validar abertura do arquivo
	FILE* arquivo = fopen("arquivo.txt", "r");
	if (!validarAlocacaoDeMemoria(arquivo)) return false;

	//Declarar linha de leitura atual
	string linha = (string)malloc(sizeof(char) * 20);
	if (!validarAlocacaoDeMemoria(linha)) return false;

	//Ler quantidade de entradas e validar alocação de memória
	if (fgets(linha, TAMANHO_DA_LINHA, arquivo) == NULL) return false;

	//Converter texto para inteiro
	int entradas = atoi(linha); if (entradas == 0) return false;

	int codigo = 0;
	string palavra = NULL;
	const char virgula = ',';

	//Ler cada linha
	for (int i = 0; i < entradas; i++)
	{
		if (fgets(linha, TAMANHO_DA_LINHA, arquivo) == NULL) return false;

		
		string retorno = strchr(linha, virgula);

		printf("\nlinha %s retorno: %s", linha, retorno);


		/*

		itemDaArvore* item = raiz;

		struct _trie* aux = raiz; // ponteiro auxiliar, inicia na raiz da arvore
 // laco para percorrer a palavra, enquanto nao for caractere \0
		while (*palavra)
		{
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