#include <stdio.h> //Biblioteca padrão
#include <stdbool.h> //Definição do tipo Booleano
#include <stdlib.h> //define várias funções para executar funções gerais (malloc, system, etc.)
#include <string.h> // Manipular strings
#include <ctype.h> //declara várias funções que são úteis para manipular caracteres. (isdigit() por exemplo)
#include <locale.h> //Configurar local/região/país
#include "funcoesdosistema.h"

#define MENSAGEM_DE_ERRO "Mensagem de erro do compilador"
#define TAMANHO_DO_ALFABETO 26
#define CODIGO_FECHA_PROGRAMA 6
#define TAMANHO_DA_LINHA 20

//Definição da variável debug
bool DEBUG = true;

//Definição tipo string
typedef char* string;

//Definir estrutura de um item da árvore
typedef struct itemDaArvore
{
	int chave;
	struct itemDaArvore* proximaLetra[TAMANHO_DO_ALFABETO];
}itemDaArvore;

//Declarar ponteiro da árvore
itemDaArvore* raiz = NULL;