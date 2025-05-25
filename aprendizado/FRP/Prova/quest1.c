#include <stdio.h>
void questao01(int n, int matriz[n][n]);
void exibir(int lin, int col, int matriz[lin][col]);
void main()
{
    int mat[5][5];
    questao01(5, mat);
}
void questao01(int n, int matriz[n][n])
{
    int i, j, k = 1;
    for (i = 0; i < n; i++, k *= 2)
    {
        matriz[i][i] = k;
    }
    for (i = 1; i < n; i++)
    {
        for (j = 0; j < i; j++)
        {
            matriz[i][j] = matriz[i - 1][j] - i;
            matriz[j][i] = matriz[j][i - 1] * (j + 1);
        }
    }
    exibir(n, n, matriz);
    for (i = 0, j = n - 1; j >= 0; i++, j--)
    {
        k = matriz[i][i];
        matriz[i][i] = matriz[i][j];
        matriz[i][j] = k;
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