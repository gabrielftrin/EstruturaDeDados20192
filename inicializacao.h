#include "opcoesdomenu.h"

//Executar uma função do menu de acordo com a opção informada
bool executarFuncaoDoMenu(int opcao) {

	//Validar opção informada
	if (!validarNumeroNaturalPositivo(opcao)) return false;

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

//Imprimir opções do menu
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
	int opcao = 0;

	//Rodar o programa
	do {

		//Limpar a tela para o menu aparecer sempre em cima
		limparTela();

		//Mostrar as opções do menu na tela
		imprimirOpcoesDoMenu();

		//Ler o conteúdo digitado
		opcao = lerNumeroNaturalDoTeclado();

		//Validar conteúdo digitado
		if (opcao == EOF) return false;

		//Executar função do menu
		if (!executarFuncaoDoMenu(opcao)) return false;

		//Pausa antes de escolher uma nova opcao
		pausa();

	} while (opcao != CODIGO_FECHA_PROGRAMA);

	return true;
}

//Inicializar a execução do programa
bool inicializarPrograma() {

	//Configurar local para permitir acentuação de caracteres especiais
	if (!configurarLocal()) return false;

	//Exucutar menu
	if (!menu()) return false;

	return true;
}