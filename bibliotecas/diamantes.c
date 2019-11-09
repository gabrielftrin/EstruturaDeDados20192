#include <stdio.h>
#include "inicializacao.h"
 
int main() {

	int quantidadeTestes = lerNaturalValido();

	tipoLista lista = (tipoLista*)malloc(sizeof(tipoLista));
	if (!validarAlocacaoLista(lista)) return 0;
	if (!zerarLista(lista)) return false;
	
	for (int i = 0; i < quantidadeTeste; i++)
	{
		string linhaAtual = (string)malloc(sizeof(string));
		if (!validarAlocacaoPessoa(linhaAtual)) return 0;

		scanf("%s", linhaAtual->string);

		inserirItemNaLista(lista, linhaAtual);

	}

	string aux = lista->inicioDaLista;
	for (int i = 0; i < quantidadeTestes; i++)
	{		
		printf("\n%s", aux);
		aux = aux->proximo;
	}

	


	   	  

	//string mina[quantidadeTestes];



	//Ler a quantidade de testes

	
	// para cada teste

	//alocar memoria

	//

	//para cada teste, capturar a string em memoria


	



	return 0;

}
