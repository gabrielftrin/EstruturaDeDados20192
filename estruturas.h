#include <stdio.h> //Biblioteca padrão
#include <stdbool.h> //Definição do tipo Booleano
#include <stdlib.h> //define várias funções para executar funções gerais (malloc, system, etc.)
#include <string.h> // Manipular strings
#include <ctype.h> //declara várias funções que são úteis para manipular caracteres. (isdigit() por exemplo)
#include <locale.h> //Configurar local/região/país
#include "funcoesdosistema.h"

#define MENSAGEM_DE_ERRO "Mensagem de erro do compilador"
#define TAMANHO_DO_ALFABETO 26

//Definição tipo string
typedef char* string;

typedef struct itemDaArvore
{
	int chave;
	struct itemDaArvore *proximaLetra[TAMANHO_DO_ALFABETO];
}itemDaArvore;