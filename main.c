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
#include <conio2.h> //Biblioteca para win32/64

#include "headers/io.h"
#include "headers/gui.h"
#include "headers/sokuban.h"
//#include "core/inicio.c"


int main()
{
    interfaceMenu();
    interfaceRodape();


    telaInicio();
    telaJogo();
    telaCredito();


    return(0);

    return 0;
}
