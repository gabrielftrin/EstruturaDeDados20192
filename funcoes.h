#include "estruturas.h"
#include "validacoes.h"
#include <stdbool.h>

bool numeroNatural (int numero){

	if (numero >= 0) return true;

	return false;
}

bool mensagemSucesso(){
	
	if (!validarImpressao(printf("Operacao realizada com sucesso.\n"))) return false;
	
	return true;
}

void imprimirOpcoesDoMenu(){

	//Cabeçalho da impressão do menu
	printf("\n===== Trabalho pratico 1 - Lista de pessoas =====\n");
	printf("Aluno: Gabriel Fernandes Trindade, RM 201511287\n\n");

	//1. criar a lista de pessoas;
	printf("1) Criar a lista de pessoas\n");
	//2. inserir (cadastrar) uma nova pessoa, sempre no final da lista;
	printf("2) Cadastrar uma nova pessoa no final da lista\n");
	//3. consultar se uma pessoa está cadastrada, através do seu código. 
	//Se estiver, o programa deve  imprimir  os  dados  desta  pessoa; 
	printf("3) Consultar uma pessoa pelo codigo\n");
	// 4.  remover  uma  pessoa;
	printf("4) Remover uma pessoa\n");
	//5. encerrar  o  programa,  destruindo  a  lista  de  pessoas.
	printf("5) Destruir a lista e encerrar o programa\n\n");
}

//A lista é inválida se não conseguiu alocar memoria ou ainda não foi criada
bool validarLista(tipoLista *lista){

	//Validar alocacao de memoria lista
	if (!validarAlocacaoLista(lista)) return false;

	//Verificar se a funcao criarListaDePessoas já foi chamada
	if (!validacaoListaCriada(lista)) return false;

	return true;
}

//Retorna true se conseguiu zerar a lista
bool zerarLista (tipoLista *lista) {

	//Validar lista
	if (!validarLista(lista)) return false;
	
	//Zerar lista
	lista->inicioDaLista = NULL;
	lista->finalDaLista = NULL;
	lista->tamanhoDaLista = 0;
	lista->listaZerada = (bool *) true;	
	
	return true;
}

//Zerar uma lista com ponteiro já alocado
bool criarListaDePessoas(tipoLista *lista){	

	//Zerar a lista
	if (!zerarLista(lista)) return false;

	//Mensagem de sucesso ao usuário
	mensagemSucesso();

	return true;
}

tipoPessoa* alocarPessoa(tipoPessoa* pessoa) {

	pessoa = NULL;

	//Alocar memória para a pessoa
	pessoa = malloc(sizeof(tipoPessoa));

	//Validar alocação de memória da pessoa
	if (!validarAlocacaoPessoa(pessoa)) pessoa = NULL;
	
	return pessoa;
}

tipoPessoa* lerDadosPessoa(tipoPessoa* pessoa) {

	printf("Digite os dados da pessoa, codigo, nome, idade e altura, repectivamente:\n(O codigo da pessoa nao pode ser zero)\n");
	scanf("%d", &pessoa->codigo);
	fflush(stdin);
	gets(pessoa->nome);
	scanf("%d", &pessoa->idade);
	scanf("%f", &pessoa->altura);
	return pessoa;
}

bool cadastrarUmaPessoa (tipoLista *lista){
			
	//Validar lista
	if (!validarLista(lista)) return false;

	//Alocar pessoa
	tipoPessoa *pessoa = alocarPessoa(pessoa);
	if (pessoa == NULL) return false;

	//Ler dados da pessoa
	lerDadosPessoa(pessoa);
		
	//Se a lista estiver vazia
	if (listaVazia(lista)) {

		//lista
		lista->inicioDaLista = pessoa;		
		lista->listaZerada = false;

		//ponteiros da pessoa
		pessoa->anterior = NULL;		
	
	//Se a lista não for vazia
	} else {		

		//Ajustar ponteiros da pessoa
		pessoa->anterior = lista->finalDaLista;

	}		
	
	//Configurar estrutura da lista	
	lista->finalDaLista = pessoa;
	lista->tamanhoDaLista++;

	//Configurar estrutura da pessoa
	pessoa->proximo = NULL;	
	
	//Mensagem de sucesso ao usuário
	mensagemSucesso();

	return true;
}

//Retorna -1 se não conseguiu ler o codigo
int lerCodigoPessoa (){

	//Imprimir solicitação do código
	if(!validarImpressao(printf("Informe o codigo da pessoa:"))) return false;
	
	//Ler o código
	int codigo = lerNaturalValido();
	
	//Validar código	
	if (!numeroNatural(codigo)) return (-1);

	return codigo;
}

bool numeroNaturalPositivo (int numero){

	if (numero > 0) return true;

	return false;
}

//Retorna nulo quando o código não foi encontrado.
tipoPessoa* buscarCodigoNaLista(tipoLista *lista, int codigo){

	//Validar lista
	if (!validarLista(lista)) return NULL;

	//Validar codigo
	if(!numeroNatural(codigo)) return NULL;

	//Verificar se a lista é vazia
	if (listaVazia(lista)) return NULL;

	//Cria uma variavel auxiliar para procurar a pessoa
	tipoPessoa *pessoaAtual = lista->inicioDaLista;

	//Busca simples, do inicio ao final percorrendo toda a lista
	do {

		//Verifica se o código foi encontrado e retorna o ponteiro da pessoa
		if(pessoaAtual->codigo == codigo){			
			return pessoaAtual;
		}

		//Vai para a proxima pessoa
		pessoaAtual = pessoaAtual->proximo;
	
	//Verifica todas as pessoas da lista o final dela
	}while(pessoaAtual->proximo != NULL);

	printf("O codigo informado não está na lista.\n");
	pessoaAtual = NULL;

	return pessoaAtual; 
}

//Imprimir dados de uma pessoa
bool imprimirDadosDaPessoa(tipoPessoa *pessoa){

	//Validar pessoa
	if (!validarAlocacaoPessoa(pessoa)) return false;

	//Imprimir dados da pessoa
	if(!validarImpressao(printf("Seguem os dados da pessoa:\n\n"))) return false;
	if(!validarImpressao(printf("1 - Codigo: %d\n", pessoa->codigo))) return false;
	if(!validarImpressao(printf("2 - Nome: %s\n", pessoa->nome))) return false;
	if(!validarImpressao(printf("3 - Idade:\n", pessoa->idade))) return false;
	if(!validarImpressao(printf("4 - Altura:\n", pessoa->altura))) return false;

	return true;
}

//Consultar os dados de uma pessoa pelo código
bool consultarUmaPessoa(tipoLista *lista) {

	//Validar lista
	if (!validarLista(lista)) return false;

	//Ler codigo da pessoa
	int codigo = lerCodigoPessoa();
	if (codigo == -1) return false;

	//Declara pessoa
	tipoPessoa *pessoa = NULL;

	//Buscar código na Lista
	pessoa = buscarCodigoNaLista(lista,codigo);

	//Retorna, caso não encotre o código
	if (pessoa == NULL){
		//limpa memoria
		free(pessoa);
		return true;
	}

	//Imprime os dados da pessoa
	imprimirDadosDaPessoa(pessoa);

	//limpa memoria
	free(pessoa);

	return true;
}

//Destroi uma pessoa da lista, a pessoa não pode ser nula
bool destruirPessoa(tipoLista* lista, tipoPessoa* pessoa) {

	//Validar lista
	if (!validarLista(lista)) return false;

	//Validar pessoa, a pessoa não pode ser nulo
	if (!validarAlocacaoPessoa(pessoa)) return false;
	
	//Caso 1 - A lista possui apenas um elemento
	if (
		pessoa->anterior == NULL &&
		pessoa->proximo == NULL &&
		lista->inicioDaLista == pessoa &&
		lista->finalDaLista == pessoa
		) {

		//Zerar lista
		if (!zerarLista(lista)) return false;
	}

	//Caso 2 - A lista possui mais de um elemento e o elemento a ser removido é o PRIMEIRO
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
		lista->tamanho--;
	}

	//Caso 3 - A lista possui mais de um elemento e o elemento a ser removido é o ÚLTIMO
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
		lista->tamanho--;
	}

	//Caso 4 - A lista possui mais de um elemento e o elemento a ser removido está no MEIO da lista
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
		lista->tamanho--;
	}

	//Limpa memoria (apagar de fato a pessoa
	free(pessoa);

	//Mensagem ao usuario
	if (!mensagemSucesso()) return false;
}


//Retorna falso se der algum erro
bool removerUmaPessoaPeloCodigo (tipoLista *lista){
	
	//Validar lista
	if(validarLista(lista)) return false;
	
	//Ler código da pessoa
	int codigo = lerCodigoPessoa();

	//Validar codigo
	if(!numeroNatural(codigo)) return false;
	
	//Buscar código na Lista
	tipoPessoa* pessoa = buscarCodigoNaLista(lista,codigo);

	//Se a busca bão retornar nenhuma pessoa, exibe mensagem de erro e retorna true
	if (pessoa == NULL){
		
		//Mensagem ao usuario
		if (!validarImpressao(printf("Nenhuma pessoa foi removida da lista."))) return false;
		
		return true;	
	}
		
	//Destruir a pessoa
	if (!destruirPessoa(pessoa)) return false;

	return true;
}

//Fecha o programa
bool sairDoPrograma() {
	
	
	
	return true;
}


//Apaga todos os itens da lista e destroi a lista
bool destruirLista(tipoLista* lista) {

	//Validar Lista
	if (!validarLista(lista)) return false;

	//Se a lista NÃO for vazia
	if (!listaVazia(lista)) {

		tipoPessoa* pessoaAuxiliar = NULL;

		//Apagar cada pessoa da lista
		while (!listaVazia(lista)) {

			//Pegar o primeiro elemento da lista
			pessoaAuxiliar = lista->inicioDaLista;

			//removerUmaPessoa

			//Apagar o primeiro

		}

	}

	//Destruir a lista
	free(lista);
	
	//Mensagem ao usuario
	if (!mensagemSucesso()) return false;
	
	//Sair do programa
	if(!sairDoPrograma()) return false;	
	
	return true;
}

//Executar uma funcao do menu de acordo com a opcao, retorna falso se alguma funcao qualquer der erro
bool executarFuncaoDoMenu(int opcao, tipoLista *lista){

	//Validar Lista
	if (!validarLista(lista)) return false;
	
	switch (opcao){
	
		case 1:
			if (criarListaDePessoas(lista)) { break; }
			return false;
		case 2:	
			if (cadastrarUmaPessoa(lista)) { break;	}
			return false;
		case 3:
			if (consultarUmaPessoa(lista)) { break; }
			return false;
		case 4:
			if (removerUmaPessoaPeloCodigo(lista)) { break; }
			return false;
		case 5:
			if (destruirLista(lista)) { break; };
			return false;
		default:
			if (sairDoPrograma()) { break; }
			return false;			
	}

	return true;
}

bool menu (tipoLista *lista){	
	
	int opcao;	

	do {	

		//Mostrar o menu na tela
		imprimirOpcoesDoMenu();

        //Ler o conteúdo digitado
		opcao = lerNaturalValido();

		//Validar conteúdo digitado
		if (opcao == -1) return false;

		//Executar função do menu
		if (!executarFuncaoDoMenu(opcao,lista)) opcao=5;
		
		//Pausa antes de escolher uma nova opcao
		pausa();

		//Limpar a tela para o menu aparecer sempre em cima
		limparTela();		

	} while(opcao != 5);
	
	return true;
} 

bool inicializarPrograma(){

	//Declarar lista
	tipoLista *lista = NULL;
	//Alocar memória
	lista = malloc(sizeof(tipoLista));
	//Validar alocação
	if (!validarAlocacaoLista(lista)) return false;

	//Pré configurar lista
	lista->listaZerada = false;
	lista->tamanhoDaLista = -1;
	
	//Exucutar menu
	menu(lista);

	return true;
}