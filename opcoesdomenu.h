#include "execucao.h"

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
	
	//printf("\nValidar lista");
	if (!validarLista(lista)) return false;

	//printf("\nAlocar pessoa");
	tipoPessoa *pessoa = alocarPessoa(pessoa);
	if (!validarAlocacaoPessoa(pessoa)) return false;

	//printf("\nLer dados da pessoa");
	lerDadosPessoa(pessoa);
	
	//Inserir pessoa na lista
	if (!inserirPessoaNaLista(lista, pessoa)) return false;
	
	//printf("\nMensagem de sucesso ao usuario");
	mensagemSucesso();
	
	return true;
}

//Consultar os dados de uma pessoa pelo código
bool consultarUmaPessoa(tipoLista *lista) {
	
	//printf("\nValidar lista");
	if (!validarLista(lista)) return false;

	//printf("\nLer codigo da pessoa\n");
	int codigo = lerCodigoPessoa();
	
	//printf("\nValidar codigo retornado");
	if (codigo == -1) return false;

	//printf("\nDeclara pessoa");
	tipoPessoa *pessoa = NULL;
	
	//printf("\nBuscar codigo na Lista");
	pessoa = buscarCodigoNaLista(lista,codigo);	

	//printf("\nRetorna, caso não encotre o código");
	if (pessoa == NULL){
		//limpa memoria
		free(pessoa);
		return true;
	}
	
	//printf("\nImprime os dados da pessoa\n");
	imprimirDadosDaPessoa(pessoa);
	
	return true;
}

//Retorna falso se der algum erro
bool removerUmaPessoaPeloCodigo (tipoLista *lista){
	
	//printf("Validar lista\n");
	if(!validarLista(lista)) return false;
	
	//printf("Ler codigo da pessoa\n");
	int codigo = lerCodigoPessoa();

	//printf("Validar codigo\n");
	if(!numeroNatural(codigo)) return false;
	
	//printf("Buscar codigo na Lista\n");
	tipoPessoa *pessoa = buscarCodigoNaLista(lista,codigo);

	//printf("Se a busca nao retornar nenhuma pessoa, exibe mensagem de erro e retorna true\n");
	if (pessoa == NULL){
		
		//Mensagem ao usuario
		if (!validarImpressao(printf("Nenhuma pessoa foi removida da lista.\n"))) return false;
		
		return true;	
	}
		
	//printf("Destruir a pessoa\n");
	if (!destruirPessoa(lista, pessoa)) return false;

	//mensagem de sucesso
	if (!mensagemSucesso()) return false;
	
	return true;
}

//Apaga todos os itens da lista e destroi a lista
bool destruirLista(tipoLista* lista) {

	//Validar Lista
	if (!validarLista(lista)) return false;

	//Se a lista NÃO for vazia, apagar cada pessoa
	if (!listaVazia(lista)) {

		//Apagar cada pessoa da lista
		while (!listaVazia(lista)) {

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