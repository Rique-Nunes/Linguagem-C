// Dada uma matriz MLxC, onde L e C são constantes, desenvolver uma função que “troque” os elementos de duas colunas
// c1 e c2, respeitadas as seguintes regras : a.A troca só será possível se as colunas c1 e c2 existirem na matriz.
// Caso existam, a troca será realizada e o valor 1 retornado pela função;
// por outro lado, 0 será retornado se uma ou as duas colunas forem inválidas;
// b.Após a troca, a coluna c2 conterá exatamente os elementos originais da coluna c1,
// na mesma ordem.Porém, os valores da coluna c1 serão os originais da c2, na ordem inversa.

#include <stdio.h>
void leitor(int linha, int coluna, int matA[linha][coluna]);
int changer(int linha, int col1, int col2, int matA[linha][5], int matB[linha][5]);
void main()
{
    int teste;
    int matA[6][5] = {
        {1, 2, 3, 8, 9},
        {4, 5, 6, 5, 6},
        {8, 6, 8, 2, 1},
        {4, 9, 7, 5, 3},
        {1, 5, 3, 9, 6},
        {7, 4, 9, 3, 4},
    };
    int matB[6][5] = {
        {1, 2, 3, 8, 9},
        {4, 5, 6, 5, 6},
        {8, 6, 8, 2, 1},
        {4, 9, 7, 5, 3},
        {1, 5, 3, 9, 6},
        {7, 4, 9, 3, 4},
    };

    changer(6, 1, 3, matA, matB);
    leitor(6, 5, matB);
}
int changer(int linha, int col1, int col2, int matA[linha][5], int matB[linha][5])
{
    if (col1 < 0 || col1 >= 5 || col2 < 0 || col2 >= 5)
    {
        return 0;
    }
    int i, j;

    for (i = 0; i < linha; i++)
    {
        matB[i][col2] = matA[i][col1];
    }
    for (j = 0; j < linha; j++)
    {
        matB[j][col1] = matA[linha - 1 - j][col2];
    }
    return 1;
}

void leitor(int linha, int coluna, int matA[linha][coluna])
{
    int i, j;
    for (i = 0; i < linha; i++)
    {
        for (j = 0; j < coluna; j++)
        {
            printf("%d ", matA[i][j]);
        }
        printf("\n");
    }
}