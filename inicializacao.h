#include "validacoes.h"
/*
//Executar uma funcao do menu de acordo com a opcao, retorna falso se alguma funcao qualquer der erro
bool executarFuncaoDoMenu(int opcao, tipoLista* lista) {

	//Validar alocação da lista
	if (!validarAlocacaoDeMemoria(lista)) return false;

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
*/
//Imprimir opcoes do menu
void imprimirOpcoesDoMenu() {
	
	printf(
		"\n===== Trabalho pratico =====\n"
		"Aluno: Gabriel Trindade\n\n"

		"\n1) Criar a lista de pessoas"
		"\n2) Cadastrar uma nova pessoa no final da lista"
		"\n3) Consultar uma pessoa pelo codigo"
		"\n4) Remover uma pessoa"
		"\n5) Destruir a lista e encerrar o programa"
		"\n\n"
	);
}

//Executar o menu
bool menu() {

	//Validar alocação da lista
	//if (!validarAlocacaoDeMemoria(lista)) return false;

	//Declarar a variavel que vai guardar a opcao que o usuario escolher
	int opcao;

	//Rodar o programa
	do {

		//Mostrar as opções do menu na tela
		imprimirOpcoesDoMenu();

		//Ler o conteúdo digitado
		opcao = lerNumeroNaturalDoTeclado();

		//Validar conteúdo digitado
		if (opcao == EOF) {
			lancarErro(25);
			return false;
		}

		//Executar função do menu
		//if (!executarFuncaoDoMenu(opcao, lista)) opcao = 5;

		//Pausa antes de escolher uma nova opcao
		//pausa();

		//Limpar a tela para o menu aparecer sempre em cima
		//limparTela();

	} while (opcao != 5);

	return true;
}

//Inicializar a execução do programa
bool inicializarPrograma() {

	//Declarar lista
	//tipoLista* lista = NULL;
	//Alocar memória
	//lista = malloc(sizeof(tipoLista));
	//Validar alocação
	//if (!validarAlocacaoDeMemoria(lista)) return false;

	//Pré configurar lista
	//lista->listaZerada = false;
	//lista->tamanhoDaLista = -1;

	//Exucutar menu
	if (!menu()) {

		lancarErro(24);
		return false;
	}
	
	return true;
}

//Aplicar configurações iniciais básicas antes de iniciar o programa propriamente dito
bool aplicarConfiguracoesIniciais() {

	//Configurar local para permitir acentuação de caracteres especiais
	if (!configurarLocal()) {

		lancarErro(22);
		return false;
	}

	//Iniciar o código do programa
	if (!inicializarPrograma())
	{
		lancarErro(21);
		return false;
	}

	return true;
}