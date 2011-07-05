#ifndef SOKUBAN_H_INCLUDED
#define SOKUBAN_H_INCLUDED


/* Prototipos
Se faz necessario indicar as funcoes antes, de modo que possam ser usadas em
qualquer parte do programa
*/

void sokubanCore();
void telaInicio();
void telaJogo();
void telaCredito();
void interfaceMenu();
void interfaceRodape();
void telaJogador(char *nomeJogador);




/*
 * CORE!
 * @return      void
*/
void sokubanCore(){
    char tecla, nomeJogador[100];
    int goHorse = 1;

    if (DEBUG == 1) salvaLogAcao("sokubanCore","Novo jogo");

    telaInicio();
    telaJogador(&nomeJogador);
    clrscr();
    printf("%s",&nomeJogador);


    do {
        //interfaceMenu();
        //interfaceRodape();

        tecla = ioTeclaPressinada();

        telaJogo();


    } while (goHorse != 0);

    telaCredito();


}

/*
 * Exibe a tela inicial
 * @return      void
*/
void telaInicio(){

    //guiLimpaTela();
    guiTelaCentroCursorVai();

    printf("Sokuban v0.3");

    getch();//ioTeclaEsperar(); //Aguarda acao do usuario para passar adiante
}


void telaJogador(char *nomeJogador){
    clrscr();
    guiTelaCentroCursorVai();
    printf("Seu nome>");
    gets(nomeJogador);

    salvaJogador(nomeJogador, -1);

    salvaLogAcao("telaJogador:Nome do Jogador",nomeJogador);
}

/*
 * Exibe a tela do jogo
 * @return      void
*/
void telaJogo(){

    //guiLimpaTela();
    //guiTelaCentroCursorVai();

    //printf("Tela Jogo \n");

    getch();//ioTeclaEsperar(); //Aguarda acao do usuario para passar adiante
}

/*
 * Exibe a tela de creditos
 * @return      void
*/
void telaCredito(){

    //guiLimpaTela();
    guiTelaCentroCursorVai();

    printf("Tela Creditos \n");

    getch();//ioTeclaEsperar(); //Aguarda acao do usuario para passar adiante
}

/*
 * Exibe menu
 * @return      void
*/
void interfaceMenu(){
    guiTelaCursorVai(2,0);
    printf("1-Novo | 2-Reiniciar | 3-Escore | 4-Sair");

    guiTelaFinalCursorVai();
}

/*
 * Exibe rodape
 * @return      void
*/
void interfaceRodape(){
    guiTelaCursorVai(2,25);
    printf("(x) Tentativa(s) | (x) movimentos | (x) recorde | \n");
    guiTelaFinalCursorVai();

}









#endif // SOKUBAN_H_INCLUDED



