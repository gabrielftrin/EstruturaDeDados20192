#include <stdbool.h>
#include <stdlib.h>

//Exibe uma pausa na tela para que o usuário possa ler e tomar decisões
void pausa() {
	system("pause");
}

//Limpa tudo que estiver na tela
void limparTela() {
	system("cls");
}

//Fecha o programa
void sairDoPrograma() {
	exit(0);
}

//Retorna true se for um numero natural
bool numeroNatural(int numero) {

	if (numero >= 0) return true;

	return false;
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

//Retorna true se a quantidade de caracteres impressos for maior que 0. Exibe mensagem de erro.
bool validarImpressao(int numero){
	
	if(numero>0)
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
		lista->listaZerada == (bool *) true
	){
		printf("\nA lista esta vazia.\n");
		return true;		
	}
	
	return false;
}

//Retorna false se a lista NÃO for válida
bool validacaoListaCriada(tipoLista *lista){
			 
	if (lista->tamanhoDaLista == -1){		
		printf("Por favor, crie a lista primeiro.\n");
		pausa();
		return false;
	}

	return true;
}

// Se NÃO for um número natural, retorna -1
int lerNaturalValido(){

	int numero;	
	
	if(scanf("%d", &numero)){
		if (numeroNatural(numero)) {
			
			return numero;
		}
	}
		
	limparTela();
	printf("Por favor, informe um número natural.\n");	
	return(-1);
}

//Se a pessoa pontar pra nulo, retorna falso e mostra erro na tela
bool validarAlocacaoPessoa(tipoPessoa* pessoa) {

	if (pessoa == NULL) {
		limparTela();
		printf("A pessoa esta apontando para nulo.\n");
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

//Retorna true se conseguiu zerar a lista
bool zerarLista(tipoLista* lista) {

	//Validar alocação da lista
	if (!validarAlocacaoLista(lista)) return false;

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
	if (!validarAlocacaoPessoa(pessoa)) pessoa = NULL;

	return pessoa;
}

//Ler dados de uma pesoa
tipoPessoa* lerDadosPessoa(tipoPessoa* pessoa) {

	printf("Digite os dados da pessoa, codigo, nome, idade e altura, repectivamente:\n(O codigo da pessoa nao pode ser zero)\n");
	scanf("%d", &pessoa->codigo);
	fflush(stdin);
	gets(pessoa->nome);
	fflush(stdin);
	scanf("%d", &pessoa->idade);
	fflush(stdin);
	scanf("%f", &pessoa->altura);
	fflush(stdin);

	return pessoa;
}

//Imprimir dados de uma pessoa
bool imprimirDadosDaPessoa(tipoPessoa* pessoa) {

	//Validar pessoa
	if (!validarAlocacaoPessoa(pessoa)) return false;

	//Imprimir dados da pessoa
	if (!validarImpressao(printf("Seguem os dados da pessoa:\n\n"))) return false;
	if (!validarImpressao(printf("1 - Codigo: %d\n", pessoa->codigo))) return false;
	if (!validarImpressao(printf("2 - Nome: %s\n", pessoa->nome))) return false;
	if (!validarImpressao(printf("3 - Idade: %d\n", pessoa->idade))) return false;
	if (!validarImpressao(printf("4 - Altura: %f\n", pessoa->altura))) return false;

	return true;
}

//Retorna -1 se não conseguiu ler o codigo
int lerCodigoPessoa() {

	//Imprimir solicitação do código
	if (!validarImpressao(printf("Informe o codigo da pessoa:"))) return false;

	//Ler o código
	int codigo = lerNaturalValido();
	
	//Validar código	
	if (!numeroNatural(codigo)) return (-1);

	return codigo;
}

bool imprimirDadosDaLista(tipoLista *lista);

//Retorna nulo quando o código não foi encontrado.
tipoPessoa* buscarCodigoNaLista(tipoLista* lista, int codigo) {
	
	printf("Validar lista\n");
	if (!validarLista(lista)) return NULL;

	printf("Validar codigo\n");
	if (!numeroNatural(codigo)) return NULL;

	printf("Verificar se a lista e vazia\n");
	if (listaVazia(lista)) return NULL;
	
	printf("Cria uma variavel auxiliar para procurar a pessoa\n");
	tipoPessoa* pessoaAtual = NULL;
	pessoaAtual = lista->inicioDaLista;
	
	printf("Procurar a pessoa na lista\n");
	if (pessoaAtual != NULL) {

		printf("A pessoa nao e nula. entrando no while...\n");
		while (pessoaAtual != NULL) {
			
			printf("Verifica se o código foi encontrado e retorna o ponteiro da pessoa\n");
			
			if (pessoaAtual->codigo == codigo) {
				
				printf("encontrou o codigo. retortando ao menu...\n");
				return pessoaAtual;
			}
			
			printf("Vai para a proxima pessoa\n");
			if (pessoaAtual != NULL) {
				printf("a pessoa nao e nula. tentando apontar para o proximo...\n");
				pessoaAtual = pessoaAtual->proximo;
				printf("apontou para o proximo com sucesso\n");
			}
			
			if (pessoaAtual == NULL){
				printf("o break sera acionado pois a pessoa e nulo.\n");
				break;
			}

		}

	}

	printf("\nO codigo informado nao esta na lista.\n\n");
	free(pessoaAtual);

	return NULL;
}

//Imprime uma mensagem de sucesso na tela
bool mensagemSucesso() {

	if (!validarImpressao(printf("\nOperacao realizada com sucesso.\n\n"))) return false;

	return true;
}

//Destroi uma pessoa da lista, a pessoa não pode ser nula
bool destruirPessoa(tipoLista* lista, tipoPessoa* pessoa) {

	printf("Validar lista\n");
	if (!validarLista(lista)) return false;

	printf("Validar pessoa, a pessoa não pode ser nulo\n");
	if (!validarAlocacaoPessoa(pessoa)) return false;

	printf("Caso 1 - A lista possui apenas um elemento\n");
	if (
		pessoa->anterior == NULL &&
		pessoa->proximo == NULL &&
		lista->inicioDaLista == pessoa &&
		lista->finalDaLista == pessoa
		) {

		//Zerar lista
		if (!zerarLista(lista)) return false;
	}

	printf("Caso 2 - A lista possui mais de um elemento e o elemento a ser removido é o PRIMEIRO\n");
	if (
		pessoa->anterior == NULL &&
		pessoa->proximo != NULL &&
		lista->inicioDaLista == pessoa &&
		lista->finalDaLista != pessoa
		) {

		//Atribuir o segundo item da lista como sendo o primeiro
		lista->inicioDaLista = pessoa->proximo;

		//O agora novo primeiro item da lista deve ter seu "anterior" apontado para nulo
		lista->inicioDaLista->anterior = NULL;

		//Decrementar o tamanho da lista
		lista->tamanhoDaLista--;
	}

	printf("Caso 3 - A lista possui mais de um elemento e o elemento a ser removido é o ÚLTIMO\n");
	if (
		pessoa->anterior != NULL &&
		pessoa->proximo == NULL &&
		lista->inicioDaLista != pessoa &&
		lista->finalDaLista == pessoa
		) {

		//Atribuir o item anterior como último da lista
		lista->finalDaLista = pessoa->anterior;

		//O agora novo último item da lista deve ter seu "proximo" apontado para nulo
		lista->finalDaLista->proximo = NULL;

		//Decrementar o tamanho da lista
		lista->tamanhoDaLista--;
	}

	printf("Caso 4 - A lista possui mais de um elemento e o elemento a ser removido está no MEIO da lista\n");
	if (
		pessoa->anterior != NULL &&
		pessoa->proximo != NULL &&
		lista->inicioDaLista != pessoa &&
		lista->finalDaLista != pessoa
		) {

		//O "proximo" do item anterior ao que está sendo removido deve apontar para o "proximo" do item removido
		tipoPessoa* pessoaAuxiliar = pessoa->anterior;
		pessoaAuxiliar->proximo = pessoa->proximo;

		//O "anterior" do item seguinte ao que está sendo removido deve apontar para o "anterior" do item removido
		pessoaAuxiliar = pessoa->proximo;
		pessoaAuxiliar->anterior = pessoa->anterior;

		//Decrementar o tamanho da lista
		lista->tamanhoDaLista--;
	}

	printf("Limpa memoria (apagar de fato a pessoa)\n");
	free(pessoa);

	printf("Mensagem ao usuario\n");
	if (!mensagemSucesso()) return false;

	return true;
}