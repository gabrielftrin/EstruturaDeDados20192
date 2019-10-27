#include <iostream>
#include <string>
#define max 100

// if  h    * FIFO [F], SJF[S], Round-Robin[R],EDF [E]."<<endl;      codigos: 'F','S','R','E';

using namespace std;

int main() {
	//string algoritmo, FIFO, SJF, Round_Robin, EDF;
	char codigo;			//char codigo=[];
	int t_espera[10];		// anterior t_espera=10; 
	int fatia_tempo[10];	//fatia_tempo=10;
	int freq_clock[10];		// anterior freq_clock=10; 
	int qt_Page[10];		//total paginas
	int cheg, exec, D, Pr, Qt, Sob;
	int qt_processos[max];	//tam_processos
	int N, i, j, opcao, cont;
	int tam_processos[max], n, TEP, T_exec;	       //  TEP=tempo espera ,      T_exec=Tempo de execução      tam_processos[max]

	cout << "Qual o Numero de processos que serao escalonados" << endl;
	cin >> N;

	cout << "Indique o codigo dos processos a serem escalonados: FIFO [F], SJF[S], Round-Robin[R],EDF [E]" << endl;
	cin >> codigo;

	//cout<<"Informe os detalhes do processo como: Tempo de chegada, Tempo de execução, Deadline, Prioridade, Quantum e a Sobrecarga do sistema, nesta respectiva ordem; "<<endl;
	//cin>>cheg, exec, D, Pr, Qt, Sob;

	if (codigo == 'F') { //

		cout << "Informe os detalhes do processo como: Tempo de chegada, Tempo de execucao, De acordo com a quantidade de processos. " << endl;
		cout << "Qual o tempo de chegada?" << endl;
		cin >> cheg;
		cout << "Qual o tempo de execução?" << endl;
		cin >> exec;
	}
	//tam_processos[max]=i+j;
	//cont=(cheg-exec)/N;

	for (i = 0; i <= max; i++) {
		for (j = 0; j <= max; j++) {
			//N=qt_processos[max]
			//tam_processos[max]=i+j;
			tam_processos[i, j] = (i + j);
			//tam_processos[max]= qt_processos[i]+qt_processos[j];
			//verif_ordem=
			cont = (tam_processos[i, j] - cheg - exec) / N;
			T_exec = (cont / N);
		}
		cout << "O Tempo Medio de Resposta e de:" << T_exec << " Unidades de Tempo." << endl;
		//cin>> T_exec;
	}
	if (codigo == 'S') {

		cout << "Informe os detalhes do processo como: Tempo de chegada, Tempo de execucao" << endl;
		cin >> cheg;
		cin >> exec;
	}


	if (codigo == 'R') {

		cout << "Informe O Tempo de chegada, Tempo de execucao, Deadline, Prioridade, Quantum e a Sobrecarga do sistema, nesta respectiva ordem; ." << endl;
		cin >> cheg;
		cin >> exec;
	}	cin >> D;
	cin >> Pr;
	cin >> Qt;
	cin >> Sob;
	//tam_processos[max]=i+j;
	//cont=(cheg-exec)/N;

	for (i = 0; i <= max; i++) {
		for (j = 0; j <= max; j++) {
			//N=qt_processos[max]
			//tam_processos[max]=i+j;
			tam_processos[i, j] = (i + j);
			//tam_processos[max]= qt_processos[i]+qt_processos[j];
			//verif_ordem=
			cont = (tam_processos[i, j] - cheg - exec) / N;
			T_exec = (cont / N);
		}
		cout << "O Tempo Medio de Resposta e de:" << T_exec << " Unidades de Tempo." << endl;
		//cin>> T_exec;
	}


	//if ()
		//codigo='F';
//	else 
//	if ("algoritmo" == "SJF")	   "         "
//		codigo='S';



//programa principal
	/*while (opcao!= 0) do {

	cout<<"Escolha a opção desejada"<<opcao<< endl;

	switch (opcao) {

	case 1:
		if (Cria processo) { break; }

	case 2:
		if (Suspende processo) { break; }

	case 3:
		if (Prossegue processo) { break; }

	case 4:
		if (Finaliza processo) { break; }

	case 5:
		if (Prioridade do processo) { break; };

	Case 6:
		if (Bloco de controle dos processos) { break; };

	//Case 7:
		//if (Sair do programa) { break; };

	default:
		sairDoPrograma();
		break;
	}
*/
	return 0;
}