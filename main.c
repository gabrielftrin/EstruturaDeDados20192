#include "validacoes.h"
	//Alterar localização do programa para a localização do sistema para permitir uso de caracteres especiais
	//setlocale(LC_ALL, "Portuguese");

void main()
{	
	int quantidade = 5;
	string teste ;//= lerTextoDoTeclado(quantidade);
		
		//scanf(" ", teste);
		//limparBufferDoTeclado();
	
		string parteParametro = " %";		printf("\npassou aqui1\n");
		const string numeroConvertidoParaString = "3";	printf("\npassou aqui2\n");
		parteParametro = strcat(parteParametro, numeroConvertidoParaString); printf("\npassou aqui3\n");
		parteParametro = strcat(parteParametro, "[^\n]");printf("\npassou aqui4\n");
				
	const char * parametros = parteParametro;printf("\npassou aqui5\n");
	
	string texto = " %3[^\n]";printf("\npassou aqui6\n");
	printf("\n %s \n",parametros);	printf("\npassou aqui7\n");
	
	//scanf(" %3[^\n]", teste);

	//printf("\nConteudo digitado: %s fim\n", teste);
	
	imprimirListaDeErros();
}

/*
printf("\npassou aqui\n");
converter inteiro para string

char * _my_itoa( int i )
{
    static char res[11]; // buffer for max 4G value
    char * p = res + sizeof res - 1; // pointer to end of buffer
    *p-- = 0; // 0 - end of string
    while ( i > 0 )
    {
      *p-- = (char)( ( i % 10 ) + '0' );
      i /= 10;
    }
    return p;
}
=====
void Converter(int numero, char* Out)
{
     if(numero<10)
     {
           Out[0] = '0';
           itoa(numero, &Out[1], 10);
     }
     else
           itoa(numero, Out, 10);
}
======
// Implementation of itoa() 
char* itoa(int num, char* str, int base) 
{ 
    int i = 0; 
    bool isNegative = false; 
  
     Handle 0 explicitely, otherwise empty string is printed for 0 
    if (num == 0) 
    { 
        str[i++] = '0'; 
        str[i] = '\0'; 
        return str; 
    } 
  
    // In standard itoa(), negative numbers are handled only with  
    // base 10. Otherwise numbers are considered unsigned. 
    if (num < 0 && base == 10) 
    { 
        isNegative = true; 
        num = -num; 
    } 
  
    // Process individual digits 
    while (num != 0) 
    { 
        int rem = num % base; 
        str[i++] = (rem > 9)? (rem-10) + 'a' : rem + '0'; 
        num = num/base; 
    } 
  
    // If number is negative, append '-' 
    if (isNegative) 
        str[i++] = '-'; 
  
    str[i] = '\0'; // Append string terminator 
  
    // Reverse the string 
    reverse(str, i); 
  
    return str; 
} 
*/
/*
====================================
converter quantidade em string

string st = strcat(" %", quantidade);
string st2 = strcat(st2, "[^\n]");
scanf(st2, texto);

string teste = strcat(" %", 10);
string teste2 = strcat(teste, "[^\n]");

============================================================
int inteiro_validado() {
	//Buffer para entrada da variável
	char buffer[100];
	//Ponteiro com endereco da String
	char* entrada = gets(buffer); fflush(stdin);
	int i, resultado = 0, teste;
	//Fazemos um loop para checar caractere por caractere da entrada
	for (i = 0; i < strlen(entrada); i++) {
		//Checa se é um numero
		if (entrada[i] >= '0' && entrada[i] <= '9') {
			//Se for, reduz da tabela ASCII
			teste = entrada[i] - '0';
			//Essa soma apenas coloca na casa decimal certa, se for 1024, ele vai fazer 1000 + 20 + 4
			resultado += teste * pow(10, strlen(entrada) - i - 1);
		}
		else {
			//A entrada contem um valor nao numérico
			return -1;
		}
	}

	return resultado;
}

bool validarNumeroNatural(int numero) {

	printf("%d ", numero);
	//Declarar, converter para string e guardar o tamanho do numero
	char texto[20];
	sprintf(texto, "%i", numero);
	int tam = strlen(texto);

	//Verificar se é maior que 10
	if (tam > 10)
	{
		lancarErro(1);
		return false;
	}

	//Quando o tamanho for 10, verificar o primeiro caractere
	if (tam == 10)
	{
		if (texto[0] != 1 && texto[0] != 2)
		{
			lancarErro(2);
			return false;
		}

	}

	//Verificar se o tamanho é zero
	if (tam == 0)
	{
		lancarErro(3);
		return false;
	}

	//Ver se a quantidade é menor que zero
	if (tam < 0)
	{
		lancarErro(4);
		return false;
	}

	//Processar
	if (tam > 0 && tam < 11)
	{
		//Verificar se é negativo
		if (numero < 0)
		{
			lancarErro(7);
			return false;
		}

		int res = -1;
		//Verificar se cada dígito é um número
		for (int i = 0; i < tam; i++)
		{
			res = isdigit(texto[i]);
			if (res == 0)
			{
				lancarErro(6);
				return false;
			}

			if (res != 0 && res != 1)
			{
				lancarErro(8);
				return false;
			}
		}

		return true;
	}

	//Erro inesperado
	lancarErro(5);
	return false;
}
*/