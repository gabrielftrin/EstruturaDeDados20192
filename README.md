# Trabalho Pratico II

Alunos: Denise Alpim e Gabriel Trindade <br />
Disciplina: MATD04 - Estrutura de Dados <br />

## Tutorial de instalacao do compilador GCC
	
* Ambiente Windows: https://terminaldeinformacao.com/2015/10/08/como-instalar-e-configurar-o-gcc-no-windows-mingw/
* Ambiente Linux (ubuntu): http://www.mundodoshackers.com.br/como-instalar-o-gcc-no-linux-ubuntu

## Como compilar e executar o codigo

* No windows: gcc -o programa.exe main.c && "C:Mingw\bin\programa.exe"
* No linux: gcc -o programa main.c ; ./programa

## Descricao de cada arquivo

* main.c: Neste arquivo tem apenas a funcao inicializarPrograma(). Caso esta funcao retorne falso, serao exibidos os erros na tela.
* inicializacao.h: Neste arquivo estao declaradas as funcoes: inicializarPrograma(), menu(), imprimirOpcoesDoMenu() e executarFuncaoDoMenu()
* opcoesdomenu.h: Neste arquivo esta declarada cada uma das funcoes do menu
* execucao.h: Neste arquivo contem algumas funcoes que fazem o trabalho mais 'bracal' para servir de apoio às funcoes do arquivo 'opcoesdomenu.h'
* validacoes.h: Neste arquivo estao algumas funcoes de validacao basica
* excecao.h: Neste aqui estao as funcoes que gerenciam o tratamento de erros
* estruturas.h: Neste arquivo sao declaras as structs e os tipos de dados. Alem disso aqui tambem sao incluidas as bibliotecas do C.
* funcoesdosistema.h: Neste arquivo contem apenas funcoes basicas do sistema como: sairDoPrograma(), pausar() e limparTela()

## Funcionamento do programa

O programa foi pensado para ter funcoes simples que realizam todo o trabalho mecânico deixando o progrador livre para pensar na implementacao das estruturas propriamente ditas.
O único arquivo que deve ser compilado e o main.c. Este arquivo chama todos os outros automaticamente. No arquivo main.c, existe apenas a chamada da funcao inicializarPrograma(). Todo o resto da implementacao acontece nos outros arquivos. O programa funciona com uma cascata de chamadas.

O arquivo 'main.c' chama o 'inicializacao.h' (menu) que chama o 'opcoesdomenu.h' (tem a codificacao de cada uma das funcoes do menu) que chama o arquivo 'execucao.h' que chama o arquivo 'validacoes.h' (que tem algumas validacoes basicas como validarAlocacaoDeMemoria) que chama o arquivo 'excecao.h' (tratamento de erros) que chama o arquivo 'estruturas.h' (definicao das estruturas e tipos de dados) que chama 'funcoesdosistema.h'

## Em quais arquivo mexer para fazer o programa funcionar?

Em apenas 1: No arquivo opcoesdomenu.h PRINCIPAL arquivo onde CADA funcao do menu deve ser escrita. As funcoes que devem ser implementadas sao:

* Criar (zerar) a arvore (feito)
* Inserir valor (palavra) na arvore pelo arquivo .txt (feito)
* Consulta uma palavra na arvore (feito)
* Listar todas as palavras cadastradas na arvore (feito)
* Remover a arvore (feito)
* Encerrar o programa (feito)

## Contato

Qualquer dúvida, enviar e-mail para gabriel.trindade@ufba.br

