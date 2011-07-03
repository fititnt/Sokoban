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
void guiLimpaTela();

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
    guiTelaCursorVai(35,20);
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



#endif // TNTGUI_H_INCLUDED



