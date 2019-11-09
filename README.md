# Trabalho Prático II

Alunos: Denise Alpim e Gabriel Trindade <br />
Disciplina: MATD04 - Estrutura de Dados <br />

## Tutorial de instalação do compilador GCC
	
* Ambiente Windows: https://terminaldeinformacao.com/2015/10/08/como-instalar-e-configurar-o-gcc-no-windows-mingw/
* Ambiente Linux (ubuntu): http://www.mundodoshackers.com.br/como-instalar-o-gcc-no-linux-ubuntu

## Como compilar e executar o código

* No windows: gcc -o programa.exe main.c && "C:Mingw\bin\programa.exe"
* No linux: gcc -o programa main.c ; ./programa

## Descrição de cada arquivo

* main.c: Neste arquivo tem apenas a funcao ininicalizarPrograma(). Caso esta função retorne falso, serão exibidos os erros na tela.
* inicializacao.h: Neste arquivo estão declaradas as funções: inicializarPrograma(), menu(), imprimirOpcoesDoMenu() e executarFuncaoDoMenu()
* opcoesdomenu.h: Neste arquivo está declarada cada uma das funções do menu
* validacoes.h: Neste arquivo estão algumas funções de validação básica
* excecao.h: Neste aqui estão as funções que gerenciam o tratamento de erros
* estruturas.h: Neste arquivo são declaras as structs e os tipos de dados. Além disso aqui também são incluidas as bibliotecas do C.
* funcoesdosistema.h: nNeste arquivo contém apenas funções básicas do sistema como: sairDoPrograma(), pausar() e limparTela()

## Funcionamento do programa

O único arquivo que deve ser compilado é o main.c. Este arquivo chama todos os outros automaticamente. No arquivo main.c, existe apenas a chamada da função inicializarPrograma(). Todo o resto da implementação acontece nos outros arquivos. O programa funciona com uma cascata de chamadas.

O arquivo 'main.c' chama o 'inicializacao.h' (menu) que chama o 'opcoesdomenu.h' (tem a codificação de cada uma das funções do menu) que chama o arquivo 'validacoes.h' (que tem algumas validações básicas como validarAlocacaoDeMemoria) que chama o arquivo 'excecao.h' (tratamento de erros) que chama o arquivo 'estruturas.h' (definição das estruturas e tipos de dados) que chama 'funcoesdosistema.h'

## Em quais arquivo mexer para fazer o programa funcionar?

Em apenas 2:

* No arquivo opcoesdomenu.h PRINCIPAL arquivo onde CADA função do menu deve ser escrita
* No arquivo estruturas.h para declarar a definição dos tipos de dados (typedef struct...)

## Contato

Qualquer dúvida, enviar e-mail para gabriel.trindade@ufba.br

Comando para compilar fora de casa no caminho "C:\Users\gtrindade>"

gcc.lnk -o objeto.exe "C:\Users\gtrindade\OneDrive - TecnoTRENDS\Arquivos\GitHub\EstruturaDeDados20192\main.c" && obj.lnk

Comando para compilar em casa no caminho "C:\Users\Gabriel\Desktop"

gcc.lnk -o objeto.exe O:\OneDrive\GitHub\EstruturaDeDados20192\main.c && obj.lnk	
