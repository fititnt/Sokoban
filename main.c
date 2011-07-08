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
    int totalLinhas;
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
    getch();

    //Tela de selecionar nome do jogador
    sokobanTelaEscolherMapa(&root.mapa);
    getch();


    if( carregarMapaPuro(root.mapa, mapa, &totalLinhas) != 1 && DEBUG == 1){
        printf("\n Erro ao carregar mapa\n");
        getch();
        return 0;
    };
    /*
    if( guiMapaExibe(mapa) != 1 && DEBUG == 1){
        printf("\n Erro ao exibir mapa\n");
        getch();
        return 0;
    }
    */
    //guiTelaCentroCursorVai(0,0); printf("test");
    carregaMapaMemoria(mapa, &root.tela);//Somente coordenadas root.xy sao repassadas

    guiMapaExibe(mapa);

    //printf("linha %i, coluna %i", root.tela.jogador.x, root.tela.jogador.y);

    getch();
    clrscr();
    getch();
    //guiLimpaTela();
    do {


        //Prepara tela
        //guiMapaExibe(mapa);

        //Aguarda entrada do usuario e modifica o sokoban

        sokobanMoveObjetos(&root.tela, mapa, tecla);


        printf("%c", tecla);

        //debug
        guiTelaCentroCursorVai(0,25);
        debugExibeRoot(root);
        //pega a tecla ja para o proximo loop
        tecla = getch();

        //Exibe mapa
        clrscr();
        guiTelaCentroCursorVai(-24,1);
        guiMapaExibe(mapa);

    } while (tecla != 'q');



    //printf("%i", sokoban.caixa9.col);


    //guiMapaExibe(mapa);
    getch();
    //guiMapaExibe(mapa);

    //sokubanCore();

    return 0;
}
