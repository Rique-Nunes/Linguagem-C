// Desenvolver uma função que receba duas matrizes de inteiros, ambas de ordem 10,
// com as seguintes características : a.M1 : matriz contendo números inteiros quaisquer;
// b.M2 : matriz contendo apenas os valores 0 ou 1.
// Desenvolver uma função que a partir destas matrizes gere a matriz M3, também de ordem 10,
// cujos elementos são definidos da seguinte forma : M2ij = 0 → M3ij = M1ij M2ij = 1 → M3ij =
// soma dos elementos da linha i com os da coluna j da matriz.

//obs: a soma é incluindo o proprio numero ou somente os numeros envolta dele
#include <stdio.h>
void leitor(int linha, int coluna, int matA[linha][coluna]);
int forger(int linha, int coluna, int matA[linha][coluna], int matB[linha][coluna], int matC[linha][coluna]);
void main()
{
    int teste, matC[6][5];
    int matA[6][5] = {
        {1, 2, 3, 8, 9},
        {4, 5, 6, 5, 6},
        {8, 6, 8, 2, 1},
        {4, 9, 7, 5, 3},
        {1, 5, 3, 9, 6},
        {7, 4, 9, 3, 4},
    };
    int matB[6][5] = {
        {1, 0, 1, 0, 1},
        {1, 0, 1, 0, 1},
        {1, 0, 1, 0, 1},
        {1, 0, 1, 0, 1},
        {1, 0, 1, 0, 1},
        {1, 0, 1, 0, 1},
    };
    forger(6, 5, matA, matB, matC);
    leitor(6, 5, matC);
}
int forger(int linha, int coluna, int matA[linha][coluna], int matB[linha][coluna], int matC[linha][coluna])
{
    int i, j, aux = 0;
    for (i = 0; i < linha; i++)
    {
        for (j = 0; j < coluna; j++)
        {
            if (matB[i][j] == 0)
            {
                matC[i][j] = matA[i][j];
            }
            else
            {
                aux = 0;
                for (int y = 0; y < linha; y++)
                {
                    aux += matA[y][j];
                }
                for (int z = 0; z < coluna; z++)
                {
                    aux += matA[i][z];
                }
                aux -= matA[i][j];
                matC[i][j] = aux;
            }
        }
    }
}
void leitor(int linha, int coluna, int matC[linha][coluna])
{
    int i, j;
    for (i = 0; i < linha; i++)
    {
        for (j = 0; j < coluna; j++)
        {
            printf("%d ", matC[i][j]);
        }
        printf("\n");
    }
}