// Desenvolver uma função que gere uma matriz
// Mnn, nos moldes do exemplo apresentado a
// seguir (que consiste em uma matriz de ordem 5)
// 1 2 3 4 5
// 2 3 4 5 6
// 3 4 5 6 7
// 4 5 6 7 8
// 5 6 7 8 9

#include <stdio.h>
void transform(int linha, int coluna, int matA[linha][coluna]);
void resultado(int linha, int coluna, int matA[linha][coluna]);

void main()
{
    int matA[5][5];
    transform(5, 5, matA);
    resultado(5, 5, matA);
}
void transform(int linha, int coluna, int matA[linha][coluna])
{
    int i, j;
    for (i = 0; i < linha; i++)
    {
        for (j = 0; j < coluna; j++)
        {
            matA[i][j] = i + j + 1;
        }
    }
}
void resultado(int linha, int coluna, int matA[linha][coluna])
{
    int i, j;
    for (i = 0; i < linha; i++)
    {
        for (j = 0; j < coluna; j++)
        {
            printf("%d", matA[i][j]);
        }
    }
}