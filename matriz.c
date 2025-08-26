//matriz 3x4
//estátia
//3 formas dinamicas
//mostrar a soma de linhas
//mostrar a soma de colunas
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void preencherAleatorio(int linha, int coluna, int matriz[linha][coluna]);
void mostrarSomaTotal(int linhas, int colunas, int matriz[linhas][colunas]);

void main()
{

    const int LINHAS = 3;
    const int COLUNAS = 4;
    int matriz[LINHAS][COLUNAS];

    srand(time(NULL));

    preencherAleatorio(LINHAS, COLUNAS, matriz);

    printf("Matriz com valores aleatorios:\n");
    for (int i = 0; i < LINHAS; i++)
    {
        for (int j = 0; j < COLUNAS; j++)
        {
            printf("%3d ", matriz[i][j]);
        }
        printf("\n");
    }

    printf("\n"); 

}

void preencherAleatorio(int linha, int coluna, int matriz[linha][coluna])
{
    for (int i = 0; i < linha; i++)
    {
        for (int j = 0; j < coluna; j++)
        {
            matriz[i][j] = rand() % 21;
        }
    }
}
/*
void mostrarSomaTotal(int linhas, int colunas, int matriz[linhas][colunas])
{
    int soma = 0; // Variável para acumular a soma

    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j < colunas; j++)
        {
            soma += matriz[i][j]; // Adiciona o valor do elemento atual à soma
        }
    }
    printf("A soma de todos os elementos da matriz é: %d\n", soma);
}
*/