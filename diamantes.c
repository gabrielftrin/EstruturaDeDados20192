#include <stdio.h>
#include "inicializacao.h"

 
int main() {

	typedef char* string;

	//Ler a quantidade de testes
	int quantidadeTestes = lerNaturalValido();

	//Validar valor digitado
	if (!numeroNaturalPositivo(quantidadeTestes)) return 0;
	
	//Definir a estrutura da mina
	typedef struct mina {

		string casoDeTeste;
		int quantidadeDeDiamantes;

	}mina;

	//Criar lista
	tipoLista lista = (tipoLista*)malloc(sizeof(tipolista));
	if (!validarAlocacaoLista(lista)) return 0;
	if (!criarListaDePessoas(lista)) return 0;

	//Coletar dados
	int contador = quantidadeTestes;
	for (int i = 0; i <= contador; i++){
		
		lista[mina] = ;
	//Imprimir
	//for (int i = 0; i <= quantidadeTestes; i++)		{
		//printf("\njhihih\n");
		//quantidadeTestes++;		}
 
	return 0;
}