//Desenvolver uma função que, dada uma matriz
//Mm×n, determine se um número X se encontra
//na linha L da matriz.

#include <stdio.h>

void matrizes(int linha, int coluna, int matA[linha][coluna], int matB[linha][coluna]);
void resultado(int linha, int coluna, int matB[linha][coluna]);

void main()
{
    int matB[3][3];
    int matA[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};
    matrizes(3, 3, matA, matB);
    resultado(3, 3, matB);
}
void matrizes(int linha, int coluna, int matA[linha][coluna], int matB[linha][coluna])
{
    int i, j;
    for (i = 0; i < linha; i++)
    {
        for (j = 0; j < coluna; j++)
        {
            matB[i][j] = matA[j][i];
        }
    }
}

void resultado(int linha, int coluna, int matB[linha][coluna])
{
    int i, j;
    for (i = 0; i < linha; i++)
    {
        for (j = 0; j < coluna; j++)
        {
            printf("%d ", matB[i][j]);
        }
    }
}
