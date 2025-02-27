//Faça uma função que, dada uma matriz Mm×n de
//reais, gere a matriz Mt sua transposta.

#include <stdio.h>

void main(){
    float matB[3][3];
    float matA[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    matrizes(3,3,matA,matB);
    resultado(3,3,matB);
}
void matrizes(int linha, int coluna, float matA[linha][coluna], float matB[linha][coluna]){
    int i,j;
    for(i=0;i<linha; i++){
        for(j=0; j<coluna; j++){
        matB[i][j] = matA[j][i];
    }

}
}

void resultado(int linha, int coluna, float matB[linha][coluna]){
    int i,j;
    for(i=0;i<linha; i++){
        for(j=0; j<coluna; j++){
        printf("%.2f ",matB[i][j]);
    }
    printf("\n");
}
}
