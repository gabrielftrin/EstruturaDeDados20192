#include "validacoesespecificas.h"

//Retorna true se conseguiu zerar a lista
bool zerarLista(tipoLista* lista) {

	//Validar alocação da lista
	if (!validarAlocacaoDeMemoria(lista)) return false;

	//Zerar lista
	lista->inicioDaLista = NULL;
	lista->finalDaLista = NULL;
	lista->tamanhoDaLista = 0;
	lista->listaZerada = (bool*)true;

	return true;
}

//Alocar memoria para uma pessoa
tipoPessoa* alocarPessoa(tipoPessoa* pessoa) {

	pessoa = NULL;

	//Alocar memória para a pessoa
	pessoa = (tipoPessoa *) malloc(sizeof(tipoPessoa));

	//Validar alocação de memória da pessoa
	if (!validarAlocacaoDeMemoria(pessoa)) pessoa = NULL;

	return pessoa;
}

//Ler dados de uma pesoa
tipoPessoa* lerDadosPessoa(tipoPessoa* pessoa) {

	printf("\nDigite os dados da pessoa, codigo, nome, idade e altura, repectivamente:\n\n");

	printf("Codigo: ");
	scanf("%d", &pessoa->codigo);
	fflush(stdin);

	printf("Nome: ");
	fgets(pessoa->nome, 31, stdin); 
	//gets(pessoa->nome);
	fflush(stdin);

	printf("Idade: ");
	scanf("%d", &pessoa->idade);
	fflush(stdin);

	printf("Altura: ");
	scanf("%f", &pessoa->altura);
	fflush(stdin);

	return pessoa;
}

//Imprimir dados de uma pessoa
bool imprimirDadosDaPessoa(tipoPessoa* pessoa) {

	//Validar pessoa
	if (!validarAlocacaoDeMemoria(pessoa)) return false;

	//Imprimir dados da pessoa
	printf("\nSeguem os dados da pessoa:\n\n");
	printf("\n Codigo: %d\n", pessoa->codigo);
	printf(" Nome: %s\n", pessoa->nome);
	printf(" Idade: %d\n", pessoa->idade);
	printf(" Altura: %f\n\n", pessoa->altura);

	return true;
}

// Se NÃO for um número natural, retorna -1
int lerNaturalValido() {

	int numero;

	if (scanf("%d", &numero)) {
		if (validarNumeroNatural(numero)) {

			return numero;
		}
	}

	//limparTela();
	printf("Por favor, informe um numero natural.\n");
	return(-1);
}

//Retorna -1 se não conseguiu ler o codigo
int lerCodigoPessoa() {

	//Imprimir solicitação do código
	printf("Informe o codigo da pessoa:");

	//Ler o código
	int codigo = lerNaturalValido();
	
	//Validar código	
	if (!validarNumeroNatural(codigo)) return (-1);

	return codigo;
}

//Retorna nulo quando o código não foi encontrado.
tipoPessoa* buscarCodigoNaLista(tipoLista* lista, int codigo) {
	
	//printf("Validar lista\n");
	if (!validarLista(lista)) return NULL;

	//printf("Validar codigo\n");
	if (!validarNumeroNatural(codigo)) return NULL;

	//printf("Verificar se a lista e vazia\n");
	if (listaVazia(lista)) return NULL;
	
	//printf("Cria uma variavel auxiliar para procurar a pessoa\n");
	tipoPessoa* pessoaAtual = NULL;
	pessoaAtual = lista->inicioDaLista;
	
	//printf("Procurar a pessoa na lista\n");
	if (pessoaAtual != NULL) {

		//printf("A pessoa nao e nula. entrando no while...\n");
		while (pessoaAtual != NULL) {
			
			//printf("Verifica se o código foi encontrado e retorna o ponteiro da pessoa\n");
			
			if (pessoaAtual->codigo == codigo) {
				
				//printf("encontrou o codigo. retortando ao menu...\n");
				return pessoaAtual;
			}
			
			//printf("Vai para a proxima pessoa\n");
			if (pessoaAtual != NULL) {
				//printf("a pessoa nao e nula. tentando apontar para o proximo...\n");
				pessoaAtual = pessoaAtual->proximo;
				//printf("apontou para o proximo com sucesso\n");
			}
			
			if (pessoaAtual == NULL){
				//printf("o break sera acionado pois a pessoa e nulo.\n");
				break;
			}

		}

	}

	printf("\nO codigo informado nao esta na lista.\n\n");
	free(pessoaAtual);

	return NULL;
}

//Imprime uma mensagem de sucesso na tela
void mensagemSucesso() {

	printf("\nOperacao realizada com sucesso.\n");
}

//Destroi uma pessoa da lista, a pessoa não pode ser nula
bool destruirPessoa(tipoLista* lista, tipoPessoa* pessoa) {

	//printf("Validar lista\n");
	if (!validarLista(lista)) return false;

	//printf("Validar pessoa, a pessoa não pode ser nulo\n");
	if (!validarAlocacaoDeMemoria(pessoa)) return false;

	//printf("Caso 1 - A lista possui apenas um elemento\n");
	if (
		pessoa->anterior == NULL &&
		pessoa->proximo == NULL &&
		lista->inicioDaLista == pessoa &&
		lista->finalDaLista == pessoa
		) {

		//printf("Zerar lista\n");
		if (!zerarLista(lista)) return false;
	}

	//printf("Caso 2 - A lista possui mais de um elemento e o elemento a ser removido é o PRIMEIRO\n");
	if (
		pessoa->anterior == NULL &&
		pessoa->proximo != NULL &&
		lista->inicioDaLista == pessoa &&
		lista->finalDaLista != pessoa
		) {

		//printf("Atribuir o segundo item da lista como sendo o primeiro\n");
		lista->inicioDaLista = pessoa->proximo;

		//printf("O agora novo primeiro item da lista deve ter seu 'anterior' apontado para nulo\n");
		lista->inicioDaLista->anterior = NULL;

		//printf("Decrementar o tamanho da lista\n");
		lista->tamanhoDaLista--;
	}

	//printf("Caso 3 - A lista possui mais de um elemento e o elemento a ser removido é o ÚLTIMO\n");
	if (
		pessoa->anterior != NULL &&
		pessoa->proximo == NULL &&
		lista->inicioDaLista != pessoa &&
		lista->finalDaLista == pessoa
		) {

		//printf("Atribuir o item anterior como último da lista\n");
		lista->finalDaLista = pessoa->anterior;

		//printf("O agora novo último item da lista deve ter seu 'proximo' apontado para nulo\n");
		lista->finalDaLista->proximo = NULL;

		//printf("Decrementar o tamanho da lista\n");
		lista->tamanhoDaLista--;
	}

	//printf("Caso 4 - A lista possui mais de um elemento e o elemento a ser removido está no MEIO da lista\n");
	if (
		pessoa->anterior != NULL &&
		pessoa->proximo != NULL &&
		lista->inicioDaLista != pessoa &&
		lista->finalDaLista != pessoa
		) {

		//printf("O proximo do item anterior ao que está sendo removido deve apontar para o proximo do item removido\n");
		tipoPessoa* pessoaAuxiliar = pessoa->anterior;
		pessoaAuxiliar->proximo = pessoa->proximo;

		//printf("O anterior do item seguinte ao que está sendo removido deve apontar para o anterior do item removido\n");
		pessoaAuxiliar = pessoa->proximo;
		pessoaAuxiliar->anterior = pessoa->anterior;

		//printf("Decrementar o tamanho da lista\n");
		lista->tamanhoDaLista--;
	}

	//printf("Limpa memoria (apagar de fato a pessoa)\n");
	free(pessoa);

	//printf("Mensagem ao usuario\n");
	//mensagemSucesso();

	return true;
}

bool inserirPessoaNaLista(tipoLista* lista, tipoPessoa* item) {

	//printf("\nSe a lista estiver vazia");
	if (listaVazia(lista)) {

		//lista
		lista->inicioDaLista = item;
		lista->listaZerada = false;

		//ponteiros da pessoa
		item->anterior = NULL;

		//Se a lista não for vazia
	}
	else {

		//Ajustar ponteiros da pessoa
		item->anterior = lista->finalDaLista;
		lista->finalDaLista->proximo = item;

	}

	//printf("\nConfigurar estrutura da lista");
	lista->finalDaLista = item;
	lista->tamanhoDaLista++;

	//printf("\nConfigurar estrutura da pessoa");
	item->proximo = NULL;

	return true;
}

bool inserirItemNaLista(tipoLista* lista, string item) {

	//printf("\nSe a lista estiver vazia");
	if (listaVazia(lista)) {

		//lista
		lista->inicioDaLista = item;
		lista->listaZerada = false;

		//ponteiros da pessoa
		item->anterior = NULL;

		//Se a lista não for vazia
	}
	else {

		//Ajustar ponteiros da pessoa
		item->anterior = lista->finalDaLista;
		lista->finalDaLista->proximo = item;

	}

	//printf("\nConfigurar estrutura da lista");
	lista->finalDaLista = item;
	lista->tamanhoDaLista++;

	//printf("\nConfigurar estrutura da pessoa");
	item->proximo = NULL;

	return true;
}