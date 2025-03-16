// Considerando a existência de uma matriz de inteiros M, de ordem N (ou seja, o no de linhas e o no de colunas são iguais a
// N), onde N é uma constante, desenvolver uma função que retorne 1 se a seguinte regra for atendida por M (caso contrário,
// o valor 0 deverá ser retornado):
//  A soma dos elementos da diagonal principal deve ser igual à soma dos elementos que estão acima desta
// diagonal, assim como à soma dos elementos abaixo da diagonal.

#include <stdio.h>

int verificador_baixo(int tamanho, int matA[tamanho][tamanho]);

void main()
{
    int teste;
    int matA[3][3] = {
        {1, 1, 5},
        {1, 5, 9}, //{0}
        {5, 9, 9}  //{0;1} // 
                   //{0;1;2}
    };
    teste = verificador_baixo(3, matA);
    printf("\n%d", teste);
}

int verificador_baixo(int tamanho, int matA[tamanho][tamanho])
{
    int linha, coluna, soma_abaixo_diagonal = 0, soma_acima_diagonal = 0, soma_diagonal = 0;
    for (linha = 0; linha < tamanho - 1; linha++)
    {
        for (coluna = linha + 1; coluna < tamanho; coluna++)
        {
            soma_acima_diagonal += matA[linha][coluna];
        }
    }
    for (linha = 1; linha < tamanho; linha++)
    {
        for (coluna = 0; coluna < linha; coluna++)
        {
            soma_abaixo_diagonal += matA[linha][coluna];
        }
    }
    for (linha = 0; linha < tamanho; linha++)
    {
        soma_diagonal += matA[linha][linha];
    }
    printf("acima: %d, abaixo: %d, diagonal: %d", soma_acima_diagonal, soma_abaixo_diagonal, soma_diagonal);
    if (soma_acima_diagonal == soma_diagonal && soma_abaixo_diagonal == soma_diagonal)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
