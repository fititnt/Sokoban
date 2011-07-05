#ifndef VARIAVEIS_H_INCLUDED
#define VARIAVEIS_H_INCLUDED

/*
 * Posicao de um objeto
 */
typedef struct{
int lin, col;
} Posicao;

typedef struct{
    Posicao jogador;
    Posicao destino;
    Posicao caixa1;
    Posicao caixa2;
    Posicao caixa3;
    Posicao caixa4;
    Posicao caixa5;
    Posicao caixa6;
    Posicao caixa7;
    Posicao caixa8;
    Posicao caixa9;
    Posicao caixa10;
} SokobanObjetos;


typedef struct{
    char nome[100];
    time_t criado;
    time_t ultimojogo;
} TJogador;

typedef struct{
    time_t time;
    char msg[1024];
}LogDeErro;


#endif // VARIAVEIS_H_INCLUDED
