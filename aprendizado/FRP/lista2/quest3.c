// Pede-se o desenvolvimento de uma função recursiva que, dada uma matriz M de L linhas e C colunas,
// onde L e C são constantes, e três linhas L1, L2 e L3, altere os elementos de L3, de forma
// que cada um consista na soma dos elementos de L1 e L2, conforme ilustrado no exemplo abaixo:

#include <stdio.h>

int recursiva(int l1, int l2, int l3, int linha, int coluna, int matriz[3][4]);

int main()
{
    int matriz[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {0, 0, 0, 0} // Inicializa L3 com zeros
    };
    int linhas = 3;
    int colunas = 4;

    recursiva(0, 1, 2, linhas, colunas - 1, matriz);

    // Imprime a matriz resultante (para verificar)
    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j < colunas; j++)
        {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    return 0;
}

int recursiva(int l1, int l2, int l3, int linha, int coluna, int matriz[3][4])
{
    if (coluna < 0)
    {
        return 1;
    }
    else
    {
        matriz[l3][coluna] = matriz[l2][coluna] + matriz[l1][coluna];
        recursiva(l1, l2, l3, linha, coluna - 1, matriz);
        return 1;
    }
}
