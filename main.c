/*
 * @file            main.c
 * @package         Sudoku
 * @name            main
 * @description     Biblioteca de suporte ao projeto Sudoku, aplicação de console, escrito em ANSI-C
 * @author          Emerson Rocha Luiz
 * @license         GPL3
 * @version         0.2 (2011-07-03)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio2.h> //Biblioteca para win32/64

#define DEBUG 1 // 0 desativa debug


#include "headers/variaveis.h"
#include "headers/io.h"
#include "headers/carregar.h"
#include "headers/salvar.h"
#include "headers/gui.h"
#include "headers/sokoban.h"



int main()
{
    char tecla, mapa[24][80];
    int totalLinhas;
    SokobanObjetos sokoban;

    carregarMapaPuro("mapas/labirinto1.txt", mapa, &totalLinhas);

    //guiMapaExibe(mapa);

    carregaMapaMemoria(mapa, &sokoban);

    guiMapaExibe(mapa);

    do {

        guiMapaExibeObjetos(sokoban);

        tecla = getch();

        sokobanMoveObjetos(&sokoban, tecla);


        printf("%c", tecla);

    } while (tecla != 'q');



    //printf("%i", sokoban.caixa9.col);


    //guiMapaExibe(mapa);
    getch();
    //guiMapaExibe(mapa);

    //sokubanCore();

    return 0;
}
