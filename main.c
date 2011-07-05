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
#include "headers/sokuban.h"



int main()
{
    char mapa[24][81];
    carregarMapaPuro("mapas/labirinto1.txt", &mapa);
    getch();
    //guiMapaExibe(mapa);

    //sokubanCore();

    return 0;
}
