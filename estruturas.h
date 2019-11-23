#include <stdio.h> //Biblioteca padrao
#include <stdbool.h> //Definicao do tipo Booleano
#include <stdlib.h> //define varias funcoes para executar funcoes gerais (malloc, system, etc.)
#include <string.h> // Manipular strings
#include <ctype.h> //declara varias funcoes que sao úteis para manipular caracteres. (isdigit() por exemplo)
#include <locale.h> //Configurar local/regiao/país
#include "funcoesdosistema.h"

#define MENSAGEM_DE_ERRO "Mensagem de erro do compilador"
#define TAMANHO_DO_ALFABETO 26
#define CODIGO_FECHA_PROGRAMA 6
#define TAMANHO_DA_LINHA 30

//Definicao tipo string como ponteiro de caractere
typedef char* string;

//Definicao da estrutura de um item da arvore
typedef struct itemDaArvore
{
	int chave;
	struct itemDaArvore* proximaLetra[TAMANHO_DO_ALFABETO];
}itemDaArvore;

//Declarar ponteiro da raiz da arvore
itemDaArvore* raiz = NULL;

//Definicao da variavel debug
bool DEBUG = false;

//Declarar quantidade de itens (nos) existentes na arvore
int QUANTIDADE_PALAVRAS_CADASTRADAS = 0;