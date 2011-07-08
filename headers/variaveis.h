#ifndef VARIAVEIS_H_INCLUDED
#define VARIAVEIS_H_INCLUDED

/* Structs em C
 * Referencias:
 *          Aula 22 - Estruturas (structs)
 *          Aula 23 - Estruturas (structs)
 *          Aula 23 - Exercicios de estruturas (structs)
 *
*/


/*
 * Posicao de um objeto
 */
typedef struct{
int x, y;
} Posicao;  // = { -1, -1 }; Diferente do falado em aula, inicializar a variavel gera um erro
            // error: typedef 'Posicao' is initialized (use __typeof__ instead)
            // @todo: rever erro anterior;
            // Workaround: inicializar o tipo quando for usa-lo

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

typedef struct{
    char local[100];
    char rotina[100];
    char msg[255];
}Erro; // = {"","", ""}; iferente do falado em aula, inicializar a variavel gera um erro
       // error: typedef 'Posicao' is initialized (use __typeof__ instead)
       // @todo: rever erro anterior;
       // Workaround: inicializar o tipo quando for usa-lo

typedef struct{
    char local[500];//caminho
    char raw[24][80];//formato bruto
    int  linhas;//numero de linhas
    char tela[24][80];
}Mapa;


typedef struct{
    SokobanObjetos tela;
    TJogador jogador;
    Erro erro;
    Mapa mapa;
    //char mapa[500]; //caminho do mapa

}SokobanRoot;

#endif // VARIAVEIS_H_INCLUDED
