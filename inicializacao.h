#include "opcoesdomenu.h"

//Executar uma funcao do menu de acordo com a opcao informada
bool executarFuncaoDoMenu(int opcao)
{
	//Validar opcao informada
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
		if (removerArvore()) { break; }
		return false;
	case 6:
		sairDoPrograma();
		break;
	case 99:
		if (inverterDebug()) { break; }
		return false;
	default:
		printf("\nOpcao invalida\n");
		break;
	}

	return true;
}

//Imprimir opcoes do menu
void imprimirOpcoesDoMenu()
{
	string status = "DESATIVADO";

	if (DEBUG) status = "ATIVADO";

	printf(
		"\n======================= Trabalho pratico II =======================\n"
		" Alunos: Denise Alpim e Gabriel Trindade (O modo DEBUG esta %s)\n"
		" (opcao 99 para ativar/desativar o modo DEBUG)\n"

		"\n	1) Criar (zerar) a arvore"
		"\n	2) Inserir valor (palavra) na arvore pelo 'arquivo.txt'"
		"\n	3) Consulta uma palavra na arvore"
		"\n	4) Listar todas as palavras cadastradas na arvore"
		"\n	5) Remover a arvore"
		"\n	6) Encerrar o programa"
		"\n\n"
		, status
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

		//Mostrar as opcoes do menu na tela
		imprimirOpcoesDoMenu();

		//Ler o conteúdo digitado
		opcao = lerNumeroNaturalDoTeclado();

		//Validar conteúdo digitado
		if (opcao == EOF) return false;

		//Executar funcao do menu
		if (!executarFuncaoDoMenu(opcao)) return false;

		//Pausa antes de escolher uma nova opcao
		pausa();

	} while (opcao != CODIGO_FECHA_PROGRAMA);

	return true;
}

//Inicializar a execucao do programa
bool inicializarPrograma() {

	//Configurar local para permitir acentuacao de caracteres especiais
	if (!configurarLocal())
	{
		imprimirListaDeErros();
		pausa();
		sairDoPrograma();
		return false;
	}

	//Exucutar menu
	if (!menu()) return false;

	return true;
}