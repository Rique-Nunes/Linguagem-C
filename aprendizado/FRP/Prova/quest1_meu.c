#include "stdio.h"
void preencherMatriz(int n, int matriz[n][n]);
void exibir(int lin, int col, int matriz[lin][col]);
void main()
{
    int mat[6][6];
    preencherMatriz(6, mat);
}
void preencherMatriz(int n, int matriz[n][n])
{
    int i, j;
    for (j = 0; j < n; j++)
    {
        matriz[0][j] = j * j;
    }
    for (i = 1; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (i % 2 == 1)
            {
                matriz[i][j] = i + j;
            }
            else
            {
                matriz[i][j] = matriz[i - 2][j] * j;
            }
        }
    }
    exibir(n, n, matriz);
    for (i = 0; i < n - 1; i += 2)
    {
        for (j = i + 1; j < n; j++)
        {
            matriz[i][j] = matriz[i][j - 1] + matriz[i + 1][j];
        }
    }
    exibir(n, n, matriz);
}
void exibir(int lin, int col, int matriz[lin][col])
{
    int i, j;
    for (i = 0; i < lin; i++)
    {
        for (j = 0; j < col; j++)
        {
            printf("%3d ", matriz[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");
}