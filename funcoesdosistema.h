//Exibe uma pausa na tela para que o usuário possa ler e tomar decisões
void pausa() {

	printf("\nPressione [ENTER] para continuar... ");
	scanf("[^\n]");
}

//Limpa tudo que estiver na tela
void limparTela() {

	//Caso o sistema seja windows
	#ifdef WIN32 //|| Win32 || win32 || Windows || WINDOWS || windows
	   	system("cls");
		return;
	#endif

	//Caso o sistema seja linux
	#ifdef linux //|| LINUX || Linux || UNIX
		system("tput reset");
		return;
	#endif
}

//Fecha o programa
void sairDoPrograma() {

	limparTela();
	printf("Saindo do programa...\n");
	exit(0);
}