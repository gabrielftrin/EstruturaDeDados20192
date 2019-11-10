#include "opcoesdomenu.h"

//Executar uma funcao do menu de acordo com a opcao, retorna falso se alguma funcao qualquer der erro
bool executarFuncaoDoMenu(int opcao) {

	//Validar opção informada
	if (!validarNumeroNaturalPositivo(opcao))
	{
		lancarErro(20);
		return false;
	}

	switch (opcao) {

		case 1:
			if (criarArvore()) { break; }
			return false;
		case 2:
			if (inserirPalavraNaArvore()) { break; }
			return false;
		case 3:
			if (consultarPalavraNaArvore()) { break; }
			return false;
		case 4:
			if (listarPalavrasDaArvore()) { break; }
			return false;
		case 5:
			if (removerArvore()) { break; };
			return false;
		case 6:
			sairDoPrograma();
			break;
		default:
			printf("\nOpção inválida\n");
			break;
	}

	return true;
}

//Imprimir opcoes do menu
void imprimirOpcoesDoMenu() {
	
	printf(
		"\n=================== Trabalho prático II ===================\n"
		" Alunos: Denise Alpim e Gabriel Trindade\n"

		"\n	1) Criar (zerar) a árvore"
		"\n	2) Inserir valor (palavra) na árvore pelo arquivo .txt"
		"\n	3) Consulta uma palavra na árvore"
		"\n	4) Listar todas as palavras cadastradas na árvore"
		"\n	5) Remover a árvore"
		"\n	6) Encerrar o programa"
		"\n\n"
	);
}

//Executar o menu
bool menu() {

	//Declarar a variavel para guardar a opcao que o usuario escolher
	int opcao;

	//Limpar a tela para o menu aparecer sempre em cima
	limparTela();

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
		if (!executarFuncaoDoMenu(opcao)) {

			lancarErro(27);
			return false;
		}

		//Pausa antes de escolher uma nova opcao
		pausa();

		//Limpar a tela para o menu aparecer sempre em cima
		limparTela();

	} while (opcao != 6);

	return true;
}

//Inicializar a execução do programa
bool inicializarPrograma() {

	//Configurar local para permitir acentuação de caracteres especiais
	if (!configurarLocal()) {

		lancarErro(22);
		return false;
	}
	
	//Exucutar menu
	if (!menu()) {

		lancarErro(24);
		return false;
	}
	
	return true;
}