#include <stdio.h>
#include "inicializacao.h"
 
int main() {

	int quantidadeTestes = lerNaturalValido();

	tipoLista lista = (tipoLista*)malloc(sizeof(tipoLista));
	if (!validarAlocacaoLista(lista)) return 0;
	if (!zerarLista(lista)) return false;
	
	for (int i = 0; i < quantidadeTeste; i++)
	{


	}


	   	  

	//string mina[quantidadeTestes];
	
	string leituraDaLinha;

	leituraDaLinha = "teste"; //scanf("%s", leituraDaLinha);

	int tamanho = strlen(leituraDaLinha);

	char linhaAtual[tamanho];

	linhaAtual[0] = &&leituraDaLinha;

	
	printf("\ntam %s\n", linhaAtual);

	//for (int i = 0; i < quantidadeTestes; i++){ }



	//Ler a quantidade de testes

	
	// para cada teste

	//alocar memoria

	//

	//para cada teste, capturar a string em memoria


	



	return 0;

}
