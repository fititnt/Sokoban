#ifndef CARREGAR_H_INCLUDED
#define CARREGAR_H_INCLUDED



/*
 * Carrega mapa puro do disco para a memoria, sem converte-lo
 * @return          void
*/
void carregarMapaPuro(char caminhoMapa[], char mapa[24][80], int *totalLinhas){
    FILE *arquivo;
    char caracter, msgerro[256] = "", linhaBuffer[80], linhaBuffer2[80];
    int coluna = 0, linha = 0, preencherVazios = 0;
    int i,j;

    arquivo = fopen(caminhoMapa, "r");

    if(arquivo == NULL){
        strcat(msgerro, "carregarMapaPuro.ErroDeAbertura>");
        strcat(msgerro, caminhoMapa);
        salvaLogErro(msgerro);
        return;
    }
    i = 0;
    while( !feof(arquivo) &&  i < 24 ){
        fgets(linhaBuffer, sizeof(linhaBuffer), arquivo);
        strcpy(mapa[i], linhaBuffer);
        i++;
    }
    *totalLinhas = i;

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
}

/*
 * Carrega remove objetos do mapa e os transfere para um struct SokobanObjetos, definido em /variaveis.h
 * @return          void
*/
void carregaMapaMemoria(char *mapa[24][80], SokobanObjetos sokoban){
    int i, j, caixa;

    for(i=0; i<24; i++){
        for(j=0; j<80; j++){
            if(mapa[i][j] == "B"){ // B - paredes
                *mapa[i][j] = (char)219;
            } else if (mapa[i][j] == "*"){ //* - as caias
                //Decide em qual slot coloca a caixa
                switch (caixa){
                    case 1:
                        sokoban.caixa1.lin = i;
                        sokoban.caixa1.col = j;
                        *mapa[i][j] = " ";
                        break;
                   case 2:
                        sokoban.caixa2.lin = i;
                        sokoban.caixa2.col = j;
                        *mapa[i][j] = " ";
                        break;
                   case 3:
                        sokoban.caixa3.lin = i;
                        sokoban.caixa3.col = j;
                        *mapa[i][j] = " ";
                        break;
                    case 4:
                        sokoban.caixa4.lin = i;
                        sokoban.caixa4.col = j;
                        *mapa[i][j] = " ";
                        break;
                    case 5:
                        sokoban.caixa5.lin = i;
                        sokoban.caixa5.col = j;
                        *mapa[i][j] = " ";
                        break;
                    case 6:
                        sokoban.caixa6.lin = i;
                        sokoban.caixa6.col = j;
                        *mapa[i][j] = " ";
                        break;
                    case 7:
                        sokoban.caixa7.lin = i;
                        sokoban.caixa7.col = j;
                        *mapa[i][j] = " ";
                        break;
                    case 8:
                        sokoban.caixa8.lin = i;
                        sokoban.caixa8.col = j;
                        *mapa[i][j] = " ";
                        break;
                   case 9:
                        sokoban.caixa9.lin = i;
                        sokoban.caixa9.col = j;
                        *mapa[i][j] = " ";
                        break;
                   case 10:
                        sokoban.caixa10.lin = i;
                        sokoban.caixa10.col = j;
                        *mapa[i][j] = " ";
                        break;
                }
                caixa++;

            } else if (mapa[i][j] == "Q"){ //Q > Jogador
                sokoban.jogador.lin = i;
                sokoban.jogador.col = j;
            } else if (mapa[i][j] == "X"){ //X > Buraco
                sokoban.destino.lin = i;
                sokoban.destino.col = j;
            }
        }
    }
}




#endif // CARREGAR_H_INCLUDED
