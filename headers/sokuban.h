#ifndef SOKUBAN_H_INCLUDED
#define SOKUBAN_H_INCLUDED


/* Prototipos */
void telaInicio();
void telaJogo();
void telaCredito();


/*
 * Exibe a tela inicial
 * @return      void
*/
void telaInicio(){

    //guiLimpaTela();
    guiTelaCentroCursorVai();

    printf("Tela inicio \n");

    getch();//ioTeclaEsperar(); //Aguarda acao do usuario para passar adiante
}

/*
 * Exibe a tela do jogo
 * @return      void
*/
void telaJogo(){

    //guiLimpaTela();
    guiTelaCentroCursorVai();

    printf("Tela Jogo \n");

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



