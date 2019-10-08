#include "opcoesdomenu.h"

//Executar uma funcao do menu de acordo com a opcao, retorna falso se alguma funcao qualquer der erro
bool executarFuncaoDoMenu(int opcao, tipoLista* lista) {

	//Validar alocação da lista
	if (!validarAlocacaoLista(lista)) return false;

	switch (opcao) {

	case 1:
		if (criarListaDePessoas(lista)) { break; }
		return false;
	case 2:
		if (cadastrarUmaPessoa(lista)) { break; }
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

	if
		(!validarImpressao
		(
			printf(
				"\n===== Trabalho pratico 1 - Lista de pessoas =====\n"
				"Alunos: Denise Alpim e Gabriel Trindade\n\n"

				"\n1) Criar a lista de pessoas"
				"\n2) Cadastrar uma nova pessoa no final da lista"
				"\n3) Consultar uma pessoa pelo codigo"
				"\n4) Remover uma pessoa"
				"\n5) Destruir a lista e encerrar o programa"
				"\n\n"
			)
		)
			)
	{
		return false;
	}

	return true;
}

//Executar o menu
bool menu(tipoLista* lista) {
	
	//Validar alocação da lista
	if (!validarAlocacaoLista(lista)) return false;

	//Declarar a variavel que vai guardar a opcao que o usuario escolher
	int opcao;

	//Rodar o programa
	do {

		//Mostrar as opções do menu na tela
		if (!imprimirOpcoesDoMenu()) return false; 
		fflush(stdin);

		//Ler o conteúdo digitado
		opcao = lerNaturalValido();

		//Validar conteúdo digitado
		if (opcao == -1) return false;

		//Executar função do menu
		if (!executarFuncaoDoMenu(opcao, lista)) opcao = 5;

		//Pausa antes de escolher uma nova opcao
		//pausa();

		//Limpar a tela para o menu aparecer sempre em cima
		limparTela();

	} while (opcao != 5);

	return true;
}

//Inicializar a execução do programa
bool inicializarPrograma() {

	//Declarar lista
	tipoLista* lista = NULL;
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