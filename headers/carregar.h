#ifndef CARREGAR_H_INCLUDED
#define CARREGAR_H_INCLUDED



/*
 * Carrega mapa puro do disco para a memoria, sem converte-lo
 * @return          int     0: se erro, 1: se ok
*/
int carregarMapaPuro(Mapa mapa){
    FILE *arquivo;
    char caracter, msgerro[256] = "", linhaBuffer[80], linhaBuffer2[80];
    int coluna = 0, linha = 0, preencherVazios = 0;
    int i,j;

    arquivo = fopen(mapa.local, "r");

    if(arquivo == NULL){
        strcat(msgerro, "carregarMapaPuro.ErroDeAbertura>");
        strcat(msgerro, mapa.local);
        salvaLogErro(msgerro);
        return 0; //Erro
    }
    i = 0;
    while( !feof(arquivo) &&  i < 24 ){
        fgets(linhaBuffer, sizeof(linhaBuffer), arquivo);
        strcpy( mapa.raw[i], linhaBuffer);
        i++;
    }
    mapa.linhas = i + 1;

    /*
    while ( (caracter = fgetc(arquivo)) != EOF){

        if(caracter == '\n' || coluna == 81){ //Quebra de linhas OU limite maximo de colunas
            mapa[linha][coluna] ='\n';
            linha++; //Adiciona proxima linha
            coluna = 0; //Reseta coluna

            if (coluna < 81){
                for( ; coluna <=81; coluna++)
                    mapa[linha][coluna] = ' ';
            }
        } else {
            mapa[linha][coluna] = caracter;
            coluna++; //Adiciona contador
        }
        putchar(caracter);
    }
    */
    return 1;
}

/*
 * Carrega remove objetos do mapa e os transfere para um struct SokobanObjetos, definido em /variaveis.h
 * @return          int     0: se erro, 1: se ok
*/
void carregaMapaMemoria(char mapa[24][80], SokobanObjetos *sokoban){
    int i, j, caixa = 1;

    for(i=0; i<24; i++){
        for(j=0; j<80; j++){
            if(mapa[i][j] == 'B'){ // B - paredes
                mapa[i][j] = 219;
            } else if (mapa[i][j] == '*'){ //* - as caias
                //Decide em qual slot coloca a caixa
                switch (caixa){
                    case 1:
                        (*sokoban).caixa1.x = i;
                        (*sokoban).caixa1.y = j;
                        mapa[i][j] = ' ';
                        break;
                    case 2:
                        (*sokoban).caixa2.x = i;
                        (*sokoban).caixa2.y = j;
                        mapa[i][j] = ' ';
                        break;
                    case 3:
                        (*sokoban).caixa3.x = i;
                        (*sokoban).caixa3.y = j;
                        mapa[i][j] = ' ';
                        break;
                    case 4:
                        (*sokoban).caixa4.x = i;
                        (*sokoban).caixa4.y = j;
                        mapa[i][j] = ' ';
                        break;
                    case 5:
                        (*sokoban).caixa5.x = i;
                        (*sokoban).caixa5.y = j;
                        mapa[i][j] = ' ';
                        break;
                    case 6:
                        (*sokoban).caixa6.x = i;
                        (*sokoban).caixa6.y = j;
                        mapa[i][j] = ' ';
                        break;
                    case 7:
                        (*sokoban).caixa7.x = i;
                        (*sokoban).caixa7.y = j;
                        mapa[i][j] = ' ';
                        break;
                    case 8:
                        (*sokoban).caixa8.x = i;
                        (*sokoban).caixa8.y = j;
                        mapa[i][j] = ' ';
                        break;
                    case 9:
                        (*sokoban).caixa9.x = i;
                        (*sokoban).caixa9.y = j;
                        mapa[i][j] = ' ';
                        break;
                    case 10:
                        (*sokoban).caixa10.x = i;
                        (*sokoban).caixa10.y = j;
                        mapa[i][j] = ' ';
                        break;
                }
                caixa++;

            } else if (mapa[i][j] == 'Q'){ //Q > Jogador
                (*sokoban).jogador.x = i;
                (*sokoban).jogador.y = j;
                mapa[i][j] = ' ';
            } else if (mapa[i][j] == 'X'){ //X > Buraco
                (*sokoban).destino.x = i;
                (*sokoban).destino.y = j;
                mapa[i][j] = ' ';
            }
        }
    }

    //Setar posicao das caixas nao usadas como -1
                switch (caixa){
                    case 1:
                        (*sokoban).caixa1.x = -1;
                        (*sokoban).caixa1.y = -1;
                    case 2:
                        (*sokoban).caixa2.x = -1;
                        (*sokoban).caixa2.y = -1;
                    case 3:
                        (*sokoban).caixa3.x = -1;
                        (*sokoban).caixa3.y = -1;
                    case 4:
                        (*sokoban).caixa4.x = -1;
                        (*sokoban).caixa4.y = -1;
                    case 5:
                        (*sokoban).caixa5.x = -1;
                        (*sokoban).caixa5.y = -1;
                    case 6:
                        (*sokoban).caixa6.x = -1;
                        (*sokoban).caixa6.y = -1;
                    case 7:
                        (*sokoban).caixa7.x = -1;
                        (*sokoban).caixa7.y = -1;
                    case 8:
                        (*sokoban).caixa8.x = -1;
                        (*sokoban).caixa8.y = -1;
                    case 9:
                        (*sokoban).caixa9.x = -1;
                        (*sokoban).caixa9.y = -1;
                    case 10:
                        (*sokoban).caixa10.x = -1;
                        (*sokoban).caixa10.y = -1;
                        break;
                }
    return 1;
}




#endif // CARREGAR_H_INCLUDED
