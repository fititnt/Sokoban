#ifndef VARIAVEIS_H_INCLUDED
#define VARIAVEIS_H_INCLUDED

/*
 * Posicao de um objeto
 */
typedef struct{
int lin, col;
} TPosicao;


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
