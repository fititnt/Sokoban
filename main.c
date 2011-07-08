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
#include "headers/debug.h"
#include "headers/io.h"
#include "headers/carregar.h"
#include "headers/salvar.h"
#include "headers/gui.h"
#include "headers/sokoban.h"



int main()
{
    char tecla, mapa[24][80];

    SokobanRoot root; //Struct que contem centraliza toda a memoria do programa
    //SokobanObjetos sokoban;
    //Inicializar variavel
    strcpy(root.erro.local, ""); strcpy(root.erro.rotina, ""); strcpy(root.erro.msg, "");

    //Tela inicial
    sokobanTelaInicio();
    getch();

    //Tela do tutorial
    sokobanTelaAjuda();
    getch();

    //Tela de selecionar nome do jogador
    sokobanTelaJogador(&root.jogador);
    //getch();//Nessa funcao, e' desnecessario

    //Tela de selecionar nome do jogador
    sokobanTelaEscolherMapa(root.mapa);//Nao precisa do & por ja ser um vetor, logo ja aponta para o endereco
    getch();

    //sokobanCore(&root); //Tela efetiva do Jogo
    //getch();

    sokobanTelaEncerramento(root);
    getch();


    return 0;
}
