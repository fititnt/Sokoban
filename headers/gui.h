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



#endif // TNTGUI_H_INCLUDED



