#include <stdio.h>

/* 8 rainhas usando o algoritimo backtracking
   - A tentativa de colocao das rainhas e feita linha a linha. O que varia e a coluna dela.
   - se nenhuma posicao e valida em um certo ponto, entao volta-se ao estado anterior do algoritmo para tentar um novo caminho.
*/

int colunas[9];
int posicao[9];//armazena a coluna em que a rainha e colocada, o indice do vetor e a coordenada linha
int diagonalPrincipal[15];
int diagonalSecundaria[15];

//verifica se a coordenada (linha, coluna) nao esta sendo atacada por uma rainha
//a linha nunca se repetira, portanto nao precisa testar ela. Portanto, somente a coluna e diagonais principais serao testadas
int posicaoValida(int linha, int coluna){

    if (colunas[coluna] == 0 && diagonalPrincipal[linha+coluna-2] == 0
         && diagonalSecundaria[linha-coluna+7] == 0){
        return 1;
    }else{
        return 0;
    }
}

int posicionarRainha(int linha){

    int coluna;
    if (linha <= 8){//tenta colocar uma rainha ate que nao tenha linha mais no tabuleiro

        for (coluna=1; coluna <=8; coluna++){

            if (posicaoValida(linha, coluna) == 1){//posicao nao esta sendo atacada
                colunas[coluna] = linha;
                posicao[linha] = coluna;
                diagonalPrincipal[linha+coluna - 2] = 1;
                diagonalSecundaria[linha-coluna+7] = 1;

                if (posicionarRainha(linha+1) == 0){
                    return 0;
                }
                colunas[coluna] = 0;
                posicao[linha] = 0;
                diagonalPrincipal[linha+coluna - 2] = 0;
                diagonalSecundaria[linha-coluna+7] = 0;
            }
        }
        return 1;
    }

    return 0;

}
void inicializarVetores(){
    int i;
    for (i=0;i < 15; i++){
        diagonalPrincipal[i] =  0;
        diagonalSecundaria[i] = 0;
    }
    for (i=0;i < 9; i++){
        colunas[i]=0;
    }

}
void imprimirTabuleiro(){
    int i, j;

    for (i=1; i <= 8;i++){
        printf("linha: %d coluna: %d\n", i, posicao[i]);
    }
    printf("\n\n\n");
    printf("Tabuleiro\n\n");
    for (i=1; i <= 8;i++){
        for (j=1; j<=8; j++){
            if (posicao[i] == j){
                printf("R ");
            }else{
                printf("- ");
            }

        }
        printf("\n");
    }

}

int main(){
    inicializarVetores();
    posicionarRainha(1);
    imprimirTabuleiro();
    return 0;
}
