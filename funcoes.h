#include "estruturas.h"
#include "validacoes.h"
#include <stdbool.h>

bool numeroNatural (int numero){

	if (numero >= 0) return true;

	return false;
}

bool mensagemSucesso(){
	
	if (!validarImpressao(printf("\nOperacao realizada com sucesso.\n\n"))) return false;
	
	return true;
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

	//Validar alocação da lista
	if (!validarAlocacaoLista(lista)) return false;
		
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

bool cadastrarUmaPessoa (tipoLista *lista){
	
	//Validar lista
	if (!validarLista(lista)) return false;

	//Alocar pessoa
	tipoPessoa *pessoa = alocarPessoa(pessoa);
	if (!validarAlocacaoPessoa(pessoa)) return false;

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

	while (pessoaAtual != NULL) {

		//Verifica se o código foi encontrado e retorna o ponteiro da pessoa
		if (pessoaAtual->codigo == codigo) {
			return pessoaAtual;
		}
		//Vai para a proxima pessoa
		pessoaAtual = pessoaAtual->proximo;	
	}

	printf("\nO codigo informado nao esta na lista.\n\n");
	pessoaAtual = NULL;

	return pessoaAtual; 
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
bool destruirPessoa(tipoLista* lista, tipoPessoa *pessoa) {

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
		lista->tamanhoDaLista--;
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
		lista->tamanhoDaLista--;
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
		lista->tamanhoDaLista--;
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
	tipoPessoa *pessoa = buscarCodigoNaLista(lista,codigo);

	//Se a busca bão retornar nenhuma pessoa, exibe mensagem de erro e retorna true
	if (pessoa == NULL){
		
		//Mensagem ao usuario
		if (!validarImpressao(printf("Nenhuma pessoa foi removida da lista."))) return false;
		
		return true;	
	}
		
	//Destruir a pessoa
	if (!destruirPessoa(lista, pessoa)) return false;

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

			//Pegar o segundo elemento da lista
			pessoaAuxiliar = lista->inicioDaLista->proximo ;

			//Apagar o primeiro item da lista
			if (!destruirPessoa(lista, lista->inicioDaLista)) return false;
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

	//Validar alocação da lista
	if (!validarAlocacaoLista(lista)) return false;
	
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
			sairDoPrograma();
			break;
	}

	return true;
}



//Imprimir opcoes do menu
bool imprimirOpcoesDoMenu() {

	if (!validarImpressao(
		printf(
			"\n===== Trabalho pratico 1 - Lista de pessoas =====\n");
	"Aluno: Gabriel Fernandes Trindade, RM 201511287\n\n"

		"\n1) Criar a lista de pessoas"
		"\n2) Cadastrar uma nova pessoa no final da lista"
		"\n3) Consultar uma pessoa pelo codigo"
		"\n4) Remover uma pessoa"
		"\n5) Destruir a lista e encerrar o programa"
		"\n\n"
		)
		)
		)
	{ return false; }

	return true;
}

//Executar o menu
bool menu (tipoLista *lista) {
	
	//Validar alocação da lista
	if (!validarAlocacaoLista(lista)) return false;

	//Declarar a variavel que vai guardar a opcao que o usuario escolher
	int opcao;


	do {

		//Mostrar as opções do menu na tela
		if (!imprimirOpcoesDoMenu()) return false;

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

	} while (opcao != 5);
	
	return true;
} 

//Inicializar a execução do programa
bool inicializarPrograma() {

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
	if (!menu(lista)) return false;

	return true;
}