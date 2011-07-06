/*
 * @file            tntgui.h
 * @package         Sudoku
 * @name            GUI - Graphic User Interface
 * @description     Biblioteca de suporte ao projeto Sudoku, aplicação de console, escrito em ANSI-C
 * @author          Emerson Rocha Luiz
 * @license         GPL3
 * @version         0.2 (2011-07-03)
*/

#ifndef TNTGUI_H_INCLUDED
#define TNTGUI_H_INCLUDED


void guiTelaCursorVai(int x, int y);
void guiTelaCentroCursorVai();
void guiTelaFinalCursorVai();
void guiLimpaTela();
void guiTelaMapaExibe(char mapa[24][80]);
void guiTelaOpcoesIniciais();

/*
 * Move o cursor para a posicao determinada
 *
*/

void guiTelaCursorVai(int x, int y){
    gotoxy(x,y); //lib conio2.h
}


/*
 * Vai para o centro da tela
 * @return void
*/
void guiTelaCentroCursorVai(){
    guiTelaCursorVai(10,20);
}

/*
 * Vai para o centro da tela
 * @return void
*/
void guiTelaFinalCursorVai(){
    guiTelaCursorVai(0,80);
}


/*
 * Limpa tela
 * @return          void
*/

void guiLimpaTela(){
    clrscr(); //Limpar tela, ANSI-C
}

/*
 * @deprecated
*/
void guiTelaMapaExibe(char mapa[24][80]){
    int i, j;

    for(i=0; i<24; i++){
        for(j=0; j<80; j++){
            //Replace
            if (mapa[i][j] == 'B'){
                mapa[i][j] = (char)219;
            }
            printf("%c", mapa[i][j]);
        }
        //Linebreak
        printf("\n");
    }
}

void guiMapaExibe(char mapa[24][80]){
    int i,j;

    for(i=0; i<24; i++)
        printf(mapa[i]);

}

void guiMapaExibeObjetos(SokobanObjetos sokoban){
    Erro erro;
    //Caracteres
    char jogador = 'Q', buraco = 'X', caixa = '*';

    //Exibe jogador
    gotoxy(sokoban.jogador.col, sokoban.jogador.lin);
        printf("%c",jogador);
    //Exibe buraco
    gotoxy(sokoban.destino.col, sokoban.destino.lin);
        printf("%c",buraco);

    //Exibe caixas, se existirem
    if(sokoban.caixa1.lin > 0){
        gotoxy(sokoban.caixa1.col, sokoban.caixa1.lin);
            printf("%c", caixa);
    }
    if(sokoban.caixa2.lin > 0){
        gotoxy(sokoban.caixa2.col, sokoban.caixa2.lin);
            printf("%c", caixa);
    }
    if(sokoban.caixa3.lin > 0){
        gotoxy(sokoban.caixa3.col, sokoban.caixa3.lin);
            printf("%c", caixa);
    }
    if(sokoban.caixa4.lin > 0){
        gotoxy(sokoban.caixa4.col, sokoban.caixa4.lin);
            printf("%c", caixa);
    }
    if(sokoban.caixa5.lin > 0){
        gotoxy(sokoban.caixa5.col, sokoban.caixa5.lin);
            printf("%c", caixa);
    }
    if(sokoban.caixa6.lin > 0){
        gotoxy(sokoban.caixa6.col, sokoban.caixa6.lin);
            printf("%c", caixa);
    }
    if(sokoban.caixa7.lin > 0){
        gotoxy(sokoban.caixa7.col, sokoban.caixa7.lin);
            printf("%c", caixa);
    }
    if(sokoban.caixa8.lin > 0){
        gotoxy(sokoban.caixa8.col, sokoban.caixa8.lin);
            printf("%c", caixa);
    }
    if(sokoban.caixa9.lin > 0){
        gotoxy(sokoban.caixa9.col, sokoban.caixa9.lin);
            printf("%c", caixa);
    }
    if(sokoban.caixa10.lin > 0){
        gotoxy(sokoban.caixa10.col, sokoban.caixa10.lin);
            printf("%c", caixa);
    }
}



#endif // TNTGUI_H_INCLUDED



