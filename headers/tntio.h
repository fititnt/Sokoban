/*
 * @file            tntio.h
 * @package         Sudoku
 * @name            IO - input output
 * @description     Biblioteca de suporte ao projeto Sudoku, aplicação de console, escrito em ANSI-C
 * @author          Emerson Rocha Luiz
 * @license         GPL3
 * @version         0.2 (2011-07-03)
*/


#ifndef TNTIO_H_INCLUDED
#define TNTIO_H_INCLUDED



#endif // TNTIO_H_INCLUDED


/*
 * @return          char        Caracter pressionado
*/
char ioTeclaPressinada()
{
    char tecla;
    tecla = getch();
    return tecla;
}

void ioTeclaEsperar(){
    //ioTeclaPressinada();
}


void ioStringObtem(char legenda[], char resposta[])
{
    printf("%s", legenda);
    resposta = getch();//Possivel erro aqui.
}



/*
 * @description                 Abre um arquivo
 * @return          ponteiro    Arquivo a ser aberto
*/
void ioArquivoAbrir(char modo, int plus, int binario){

}

/*
 * @description                 Salva arquivo no modo texto
 * @return          ponteiro    Arquivo a ser aberto
*/
void ioArquivoSalvarTexto(){

}

/*
 * @description                 Salva arquivo no modo binario
 * @return          ponteiro    Arquivo a ser aberto
*/
void ioArquivoSalvarBinario(){

}


