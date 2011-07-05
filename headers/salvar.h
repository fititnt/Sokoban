#ifndef SALVAR_H_INCLUDED
#define SALVAR_H_INCLUDED


void salvarNome(){
    /*
    FILE *arquivo;
    char local[200], modo [3];

    local = "teste.bin";
    modo = "wb";

    if ((arquivo = fopen(local,modo)) == NULL ){
        printf("\nErro ao abrir arquivo!");
        return;
    }

    fwrite ( &informacao, ,sizeof(informacao), 1, arquivo);
    */
}

/* Salva jogador
 * @var     char    nomeJogador[100] nome do jogador
 * @var     int     tipo: -1, indefinido, 0 novo jogador, 1 ultimo jogo
 */

void salvaJogador(char nomeJogador[100], int tipo){
    TJogador jogador; //TJogador definido em variaveis.h
    char caminhoJogador[200] = "", msgerro[256];
    FILE *arquivo;
    time_t     tempoAgora;
    char       buf[100];

    //Monta caminho do arquivo do jogador
    strcat(caminhoJogador, "salvo/jogador/");
    strcat(caminhoJogador, nomeJogador);
    strcat(caminhoJogador, ".jogador");


    /* Get the current time */
    tempoAgora = time(0);

    if (tipo == -1){
        arquivo = fopen(caminhoJogador,"rb");
        if( arquivo == NULL){
            //Nao ha um jogador com esse nome, loco, criar um
            *jogador.nome = nomeJogador;
            jogador.criado = tempoAgora;
            jogador.ultimojogo = tempoAgora;

            arquivo = fopen(caminhoJogador, "r+b");

            if( arquivo == NULL){
                strcat(msgerro, "salvarJogador> erro ao abrir para salvar ");
                strcat(msgerro, caminhoJogador);
                salvaLogErro(msgerro);
            } else {
                //Escreve o primeiro jogador
                if ( fwrite(&jogador, sizeof(TJogador), 1, arquivo) != 1){
                    strcat(msgerro, "salvarJogador> erro ao salvar struct do jogador");
                    strcat(msgerro, caminhoJogador);
                    salvaLogErro(msgerro);
                }
            }

            if(DEBUG ==1) salvaLogAcao("salvaJogador.JogadorNaoEncontrado", nomeJogador);

        } else {
            fread(&jogador, sizeof(TJogador), 1, arquivo);
        }

    }

    if (tipo == 0){
        *jogador.nome = nomeJogador; // @todo: possivel bug aqui
        jogador.criado = tempoAgora;
        jogador.ultimojogo = tempoAgora;
    }

    if (tipo == 1){
        jogador.ultimojogo = tempoAgora;
    }

    /* debug */
    struct tm  *ts1, *ts2;
    char buf1[100], buf2[100];

    ts1 = localtime(&jogador.criado);
    strftime(buf1, sizeof(buf1), "%a %Y-%m-%d %H:%M:%S %Z", ts1);
    ts2 = localtime(&jogador.ultimojogo);
    strftime(buf2, sizeof(buf2), "%a %Y-%m-%d %H:%M:%S %Z", ts2);


    printf("Nome:%s \nCriado em:%s \nUltimo jogo em: %s", jogador.nome, buf1, buf2);

    //Criar caminho do arquivo do jogador
    strcat(caminhoJogador, "salvo/jogadores/");
    strcat(caminhoJogador, nomeJogador);
    strcat(caminhoJogador, ".jogador");

    printf("\n %s", caminhoJogador);


    if ((arquivo = fopen(caminhoJogador,"w+b")) == NULL){
            printf("\n Erro ao criar arquivo");
    } else {
        printf("\n Arquivo aberto");
        //fwrite( &jogador , sizeof(jogador) ,1 , arquivo);

        if ( fwrite( &jogador , sizeof(jogador) ,1 , arquivo) != 1 ){
             printf( "\n Erro na escrita!" );
        } else {
            printf( "\n Jogador salvo" );
        }

        fclose(arquivo);
    }

}

/*
 * Salva log de erro em formato texto
 * Destino: 'erros.log', mesma pasta do excecutavel
 * @return          void
*/

void salvaLogErro(char msg[]){
    FILE *arquivo;
    time_t tempo = time(0); //tempo agora
    struct tm *ts;
    char timeBuffer[100];

    ts = localtime(&tempo);//Faz uma copia do tempo agora
    strftime(timeBuffer, sizeof(timeBuffer), "%Y-%m-%d %H:%M:%S", ts);//Formata o tempo agora

    arquivo = fopen("erros.log","a+");//abre arquivo, modo append +, escreve ao final

    if (arquivo == NULL){
        printf("\nHouve um erro grave e nem mesmo o log de erro pode ser aberto e salvo\n");
        return;
    } else {
        fprintf(arquivo, "%s | %s\n", timeBuffer, msg);
        fflush(arquivo);//forca descarregar do buffer para o arquivo, antes de fechar
    }
    fclose(arquivo);//fecha arquivo
}

/*
 * Salva log de acoes em formato texto
 * Destino: 'erros.log', mesma pasta do excecutavel
 * @return          void
*/
void salvaLogAcao(char acao[], char msg[]){
FILE *arquivo;
    time_t tempo = time(0); //tempo agora
    struct tm *ts;
    char timeBuffer[100], msgerror[500] = "";

    ts = localtime(&tempo);//Faz uma copia do tempo agora
    strftime(timeBuffer, sizeof(timeBuffer), "%Y-%m-%d %H:%M:%S", ts);//Formata o tempo agora

    arquivo = fopen("salvo/acoes.log","a+");//abre arquivo, modo append +, escreve ao final

    if (arquivo == NULL){
        strcat(msgerror, "Erro ao salvaz acao '"); strcat(msgerror, acao); strcat(msgerror, "> "); strcat(msgerror, msg); strcat(msgerror, "'");
        salvaLogErro(msgerror);
        return;
    } else {
        fprintf(arquivo, "%s | %s> %s\n", timeBuffer, acao, msg);
        fflush(arquivo);//forca descarregar do buffer para o arquivo, antes de fechar
    }
    fclose(arquivo);//fecha arquivo


}

#endif // SALVAR_H_INCLUDED
