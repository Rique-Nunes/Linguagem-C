// Crie uma matriz 3x4
// Estática / 3 formas dinâmicas
// Preenchelas com valores aleatórios
// mostrar a soma de linhas e soma de colunas

#include <stdio.h>
#include <stdlib.h>

void preencheraleatorio_v1(int linha, int coluna, int matriz[linha * coluna]);
void mostrarqtdlinhas_v1(int linhas, int colunas, int matriz[linhas * colunas]);
void mostrarqtdcolunas_v1(int linhas, int colunas, int matriz[linhas * colunas]);

void preencheraleatorio_v2(int linha, int coluna, int **matriz);
void mostrarqtdlinhas_v2(int linhas, int colunas, int **matriz);
void mostrarqtdcolunas_v2(int linhas, int colunas, int **matriz);

void preencheraleatorio(int linha, int coluna, int matriz[linha][coluna]);
void mostrarqtdlinhas(int linhas, int colunas, int matriz[linhas][colunas]);
void mostrarqtdcolunas(int linhas, int colunas, int matriz[linhas][colunas]);
void main()
{
    // int matriz[3][4];
    int lin = 3, col = 4;

    // 1° método uma alocação linear onde só tem um ponteiro bem grande

    // int *matriz = malloc(lin * col * sizeof(int));
    // preencheraleatorio_v1(lin, col, matriz);
    /*
    for (int i = 0; i < 3; i++)
    {
        printf("\n");
        for (int j = 0; j < 4; j++)
        {
            printf("%d,", matriz[(i * col) + j]);
        }
    }
    printf("\n");

    // free(matriz);




    // 2° método uma alocação de em um vetor de vetores
    /*

    int **matriz = malloc(lin * sizeof(int *));

    for (int k = 0; k < lin; k++)
    {
        matriz[k] = malloc(col * sizeof(int));
    }

    
    preencheraleatorio_v2(3, 4, matriz);

    for (int i = 0; i < 3; i++)
    {
        printf("\n");
        for (int j = 0; j < 4; j++)
        {
            printf("%d,", matriz[i][j]);
        }
    }


    printf("\n");
    mostrarqtdcolunas_v2(lin, col, matriz);
    printf("\n");
    mostrarqtdlinhas_v2(lin, col, matriz);
    printf("\n");

    // Liberar a memória alocada
    for (int k = 0; k < lin; k++)
    {
        free(matriz[k]);
    }

    free(matriz);

    */

    // método 3 uma alocação de vetores em matriz[0]

    int **matriz = malloc(lin * sizeof(int *));
    matriz[0] = malloc(lin * col * sizeof(int));

    for (int i = 1; i < lin; i++)
    {
        matriz[i] = matriz[0] + i * col;
    }
    // o v2 serve para o v3 pois ambos são acessados por matriz[i][j], sendo a matriz **
    preencheraleatorio_v2(3, 4, matriz);
    for (int i = 0; i < 3; i++)
    {
        printf("\n");
        for (int j = 0; j < 4; j++)
        {
            printf("%d,", matriz[i][j]);
        }
    }
    free(matriz[0]);
    free(matriz);

    //  mostrarqtdlinhas(3, 4, matriz);
    //  printf("\n");
    //  mostrarqtdcolunas(3, 4, matriz);
}

// 1° método version
void preencheraleatorio_v1(int linha, int coluna, int matriz[linha * coluna])
{
    int i, j;

    for (i = 0; i < linha; i++)
    {
        for (j = 0; j < coluna; j++)
        {
            matriz[(i * coluna) + j] = rand() % 21;
        }
    }
}
// 1° método version
void mostrarqtdlinhas_v1(int linhas, int colunas, int matriz[linhas * colunas])
{
    int i, j, soma = 0;
    for (i = 0; i < linhas; i++)
    {
        for (j = 0; j < colunas; j++)
        {
            soma += matriz[(i * colunas) + j];
        }
        printf("a quantidade na linha %d e: %d\n", i, soma);
        soma = 0;
    }
}
// 1° método version
void mostrarqtdcolunas_v1(int linhas, int colunas, int matriz[linhas * colunas])
{
    int i, j, soma = 0;
    for (i = 0; i < colunas; i++)
    {
        for (j = 0; j < linhas; j++)
        {
            soma += matriz[(j * colunas) + i];
        }
        printf("a quantidade na coluna %d e: %d\n", i, soma);
        soma = 0;
    }
}

// método 2 version
void preencheraleatorio_v2(int linha, int coluna, int **matriz)
{
    int i, j;

    for (i = 0; i < linha; i++)
    {
        for (j = 0; j < coluna; j++)
        {
            matriz[i][j] = rand() % 21;
        }
    }
}
// método 2 version
void mostrarqtdlinhas_v2(int linhas, int colunas, int **matriz)
{
    int i, j, soma = 0;
    for (i = 0; i < linhas; i++)
    {
        for (j = 0; j < colunas; j++)
        {
            soma += matriz[i][j];
        }
        printf("a quantidade na linha %d e: %d\n", i, soma);
        soma = 0;
    }
}
// método 2 version
void mostrarqtdcolunas_v2(int linhas, int colunas, int **matriz)
{
    int i, j, soma = 0;
    for (i = 0; i < colunas; i++)
    {
        for (j = 0; j < linhas; j++)
        {
            soma += matriz[j][i];
        }
        printf("a quantidade na coluna %d e: %d\n", i, soma);
        soma = 0;
    }
}

/*
void preencheraleatorio(int linha, int coluna, int matriz[linha][coluna])
{
    int i, j;

    for (i = 0; i < linha; i++)
    {
        for (j = 0; j < coluna; j++)
        {
            matriz[i][j] = rand() % 21;
        }
    }
}

void mostrarqtdlinhas(int linhas, int colunas, int matriz[linhas][colunas])
{
    int i, j, soma = 0;
    for (i = 0; i < linhas; i++)
    {
        for (j = 0; j < colunas; j++)
        {
            soma += matriz[i][j];
        }
        printf("a quantidade na linha %d e: %d\n", i, soma);
        soma = 0;
    }
}

void mostrarqtdcolunas(int linhas, int colunas, int matriz[linhas][colunas])
{
    int i, j, soma = 0;
    for (i = 0; i < colunas; i++)
    {
        for (j = 0; j < linhas; j++)
        {
            soma += matriz[j][i];
        }
        printf("a quantidade na coluna %d e: %d\n", j, soma);
        soma = 0;
    }
}
*/
