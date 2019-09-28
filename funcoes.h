#include "estruturas.h"
#include "validacoes.h"
#include <stdbool.h>

void mensagemSucesso(){
	printf("Operacao realizada com sucesso.\n");
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
	printf("5) Encerrar o programa\n\n");
}

//Zerar uma lista com ponteiro já alocado
bool criarListaDePessoas(tipoLista *lista){	

	lista->inicioDaLista = NULL;
	lista->finalDaLista = NULL;
	lista->tamanhoDaLista = 0;
	lista->listaZerada = (bool *) true;	

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

//A lista é inválida se não conseguiu alocar memoria ou ainda não foi criada
bool validarLista(tipoLista *lista){

	//Validar alocacao de memoria lista
	if (!validarAlocacaoLista(lista)) return false;

	//Verificar se a funcao criarListaDePessoas já foi chamada
	if (!validacaoListaCriada(lista)) return false;

	return true;
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

bool lerCodigoPessoa (){

	printf("Informe o codigo da pessoa:");
	int codigo = lerNaturalValido();
	if (codigo == 0) return false;

	return true;
}

bool numeroNaturalPositivo (int numero){

	if (numero > 0) return true;

	return false;
}

//Retorna nulo quando a lista é invalida ou vazia
tipoPessoa* buscarCodigoNaLista(tipoLista *lista, int codigo){

	//Validar lista
	if (!validarLista(lista)) return NULL;

	//Validar codigo
	if(!numeroNaturalPositivo(codigo)) return NULL;

	//Verificar se a lista é vazia
	if (listaVazia(lista)) return NULL;

	//Cria ua variavel auxiliar para procurar a pessoa
	tipoPessoa *pessoaAtual = lista->inicioDaLista;

	//Busca simples, do inicio ao final percorrendo toda a lista
	do {

		//Verifica se o código foi encontrado e retorna o ponteiro da pessoa
		if(pessoaAtual->codigo == codigo){			
			return pessoaAtual;
		}

		//Vai para  a proxima pessoa
		pessoaAtual = pessoaAtual->proximo;
	
	//Verifica todas as pessoas da lista o final dela
	}while(aux->proximo != NULL);

	return pessoaAtual = NULL);
}

void imprimirDadosDaPessoa(tipoPessoa *pessoa){



}

//Consultar os dados de uma pessoa pelo código
bool consultarUmaPessoa(tipoLista *lista) {

	//Validar lista
	if (!validarLista(lista)) return false;

	//Ler codigo da pessoa
	int codigo = lerCodigoPessoa();
	if (codigo == 0) return false;

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

bool executarFuncaoDoMenu(int opcao, tipoLista *lista){
	
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
			//removerUmaPessoa();
			break;
		case 5:
			//sairDoPrograma();
			break;
		default:
			//sairDoPrograma();
			break;
			
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