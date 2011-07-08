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
 * @deprecated(?)
*/

void guiTelaCursorVai(int x, int y){
    gotoxy(x,y); //lib conio2.h
}


/*
 * Vai para o centro da tela
 * @return void
 * @deprecated
*/
void guiTelaCentroCursorVai(){
    guiTelaCursorVai(10,20);
}

/*
 * Vai para o centro da tela
 * @return void
 * @deprecated
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

    guiTelaCursorVai(0,1);

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

 /*
 * Exibe o mapa, na forma pura
 * @return      int     -2 jogador, -1 destino, 0 nada, 1~10 caixas
 */

int guiMapaExibe(char mapa[24][80]){
    int i,j;


    for(i=0; i<24; i++)
        printf("%s", mapa[i]);

    /*
    for(i=0; i<24; i++){
        for (j=0; j<80; j++){
            printf("%c", mapa[i][j]);
        }
    }
    */
    return 1;
}

void guiMapaExibeObjetos(SokobanObjetos tela){
    Erro erro;
    //Caracteres
    char jogador = 'Q', buraco = 'X', caixa = '*';

    //Exibe jogador
    gotoxy(tela.jogador.x, tela.jogador.y);
        printf("%c",jogador);
    //Exibe buraco
    gotoxy(tela.destino.x, tela.destino.y);
        printf("%c",buraco);

    //Exibe caixas, se existirem
    if(tela.caixa1.x > 0){
        gotoxy(tela.caixa1.x, tela.caixa1.y);
            printf("%c", caixa);
    }
    if(tela.caixa2.x > 0){
        gotoxy(tela.caixa2.x, tela.caixa2.y);
            printf("%c", caixa);
    }
    if(tela.caixa3.x > 0){
        gotoxy(tela.caixa3.x, tela.caixa3.y);
            printf("%c", caixa);
    }
    if(tela.caixa4.x > 0){
        gotoxy(tela.caixa4.x, tela.caixa4.y);
            printf("%c", caixa);
    }
    if(tela.caixa5.x > 0){
        gotoxy(tela.caixa5.x, tela.caixa5.y);
            printf("%c", caixa);
    }
    if(tela.caixa6.x > 0){
        gotoxy(tela.caixa6.x, tela.caixa6.y);
            printf("%c", caixa);
    }
    if(tela.caixa7.x > 0){
        gotoxy(tela.caixa7.x, tela.caixa7.y);
            printf("%c", caixa);
    }
    if(tela.caixa8.x > 0){
        gotoxy(tela.caixa8.x, tela.caixa8.y);
            printf("%c", caixa);
    }
    if(tela.caixa9.x > 0){
        gotoxy(tela.caixa9.x, tela.caixa9.y);
            printf("%c", caixa);
    }
    if(tela.caixa10.x > 0){
        gotoxy(tela.caixa10.x, tela.caixa10.y);
            printf("%c", caixa);
    }
}



int guiTelaCompletaExibe(char tela[24][80]){
    int i, j;
    for(i=0; i<24; i++){
        for(j=0; j<80; j++){
            if(tela[i][j] != '\n'){//Evitar quebrar duas vezes
                printf("%c", tela[i][j]);
            }
        }
        printf("\n");//quebra de linha
    }

}

/*
void guiTelaExibeRodape(SokobanRootMem sokobanRM){

}
*/
#endif // TNTGUI_H_INCLUDED



