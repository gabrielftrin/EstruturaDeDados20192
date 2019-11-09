# Trabalho Prático II
## Denise Alpim e Gabriel Trindade

Disciplina: MATD04 - Estrutura de Dados <br />

## Instalar o compilador GCC
	
* Ambiente Windows: https://terminaldeinformacao.com/2015/10/08/como-instalar-e-configurar-o-gcc-no-windows-mingw/
* Ambiente Linuz: http://www.mundodoshackers.com.br/como-instalar-o-gcc-no-linux-ubuntu

## Como compilar e executar o código

* Windows: gcc -o programa.exe main.c && "C:Mingw\bin\programa.exe"
* Linux: gcc -o programa.exe main.c ; programa.exe

## Descrição de cada arquivo

* main.c: Neste arquivo tem apenas a funcao ininicalizarPrograma(). Caso esta função retorne falso, serão exibidos os erros na tela.
* inicializacao.h: Neste arquivo estão declaradas as funções: inicializarPrograma(), menu(), imprimirOpcoesDoMenu() e executarFuncaoDoMenu()
* opcoesdomenu.h: Neste arquivo está declarada cada uma das funções do menu
* validacoes.h: Neste arquivo estão algumas funções de validação básica
* excecao.h: Neste aqui estão as funções que gerenciam o tratamento de erros
* estruturas.h: Neste arquivo são declaras as structs e os tipos de dados. Além disso aqui também são incluidas as bibliotecas do C.
* funcoesdosistema.h: nNeste arquivo contém apenas funções básicas do sistema como: sairDoPrograma(), pausar() e limparTela()

##Contato

Qualquer dúvida, enviar e-mail para gabriel.trindade@ufba.br

//Comando para compilar fora de casa no caminho "C:\Users\gtrindade>"
//gcc.lnk -o objeto.exe "C:\Users\gtrindade\OneDrive - TecnoTRENDS\Arquivos\GitHub\EstruturaDeDados20192\main.c" && obj.lnk
	
//Comando para compilar em casa no caminho "C:\Users\Gabriel\Desktop"
//gcc.lnk -o objeto.exe O:\OneDrive\GitHub\EstruturaDeDados20192\main.c && obj.lnk	
