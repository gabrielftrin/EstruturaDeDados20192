#include "estruturas.h"
#include "validacoes.h"
#include <stdbool.h>

//Zerar uma lista com ponteiro já alocado
bool criarListaDePessoas(tipoLista *lista){	

	//Zerar a lista
	if (!zerarLista(lista)) return false;

	//Mensagem de sucesso ao usuário
	mensagemSucesso();

	return true;
}

//Cadastrar uma pessoa na lista
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

	//Se a lista NÃO for vazia, apagar cada pessoa
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
	sairDoPrograma();	
	
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
			"\n===== Trabalho pratico 1 - Lista de pessoas =====\n"
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

	//Rodar o programa
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