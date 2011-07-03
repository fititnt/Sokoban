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

#include "headers/tntio.h"
#include "headers/tntgui.h"
#include "headers/sokuban.h"
//#include "core/inicio.c"


int main()
{
    telaInicio();
    telaJogo();
    telaCredito();

    return 0;
}
