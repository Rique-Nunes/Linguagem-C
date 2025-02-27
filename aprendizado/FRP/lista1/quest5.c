#include <stdio.h>
void somador(int linha, int coluna, int matA[linha][coluna], int vetB[coluna]);
void main()
{
    int vetB[3] = {0};
    int matA[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    somador(3,3, matA, vetB);
    for (int j = 0; j < 3; j++)
        {
            printf("%d",vetB[j]);
        }
}

void somador(int linha, int coluna, int matA[linha][coluna], int vetB[coluna]){
    int i, j, somar = 0;

    for (i = 0; i < coluna; i++)
    {
        somar = 0; //esqueci de resetar a variavel para ser usada por outra coluna 
        for(j = 0; j < linha; j++){
            somar += matA[j][i]; //errei em colocar linha e coluna nos paremtros em vez de i e j 
        }
        vetB[i] = somar; //esqueci de usar i como paramentro
    }
}


