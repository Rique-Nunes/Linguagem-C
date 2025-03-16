// Dada uma matriz MLxC, onde L e C são constantes,
// desenvolver uma função que verifique se os elementos da matriz estão ordenados de forma crescente.
// Para isto, as seguintes regras devem ser atendidas :
// a.Os elementos de cada linha devem estar ordenados crescentemente
//(ou seja, cada elemento será maior ou igual àquele da mesma linha, porém da coluna anterior – caso exista);
// b.O primeiro elemento de cada linha deve ser maior ou igual ao último da linha anterior(caso exista).
// Caso a matriz M atenda aos critérios definidos, o valor 1 deverá ser retornado pela função;
// caso contrário, 0.
#include "stdio.h"
int verificador(int linha, int coluna, int matA[linha][coluna]);
void leitor(int linha, int coluna, int matA[linha][coluna]);
void main()
{
    int teste;
    int matA[2][5] = {
        {1, 2, 3, 5, 6},
        {7, 8, 9, 10, 11},
        //{8, 6, 8, 2, 1},
        //{4, 9, 7, 5, 3},
        //{1, 5, 3, 9, 6},
        //{7, 4, 9, 3, 4},
    };
    teste = verificador(2, 5, matA);
    printf("%d\n", teste);
    leitor(2, 5, matA);
}
int verificador(int linha, int coluna, int matA[linha][coluna])
{
    int i, j;
    for (i = 0; i < linha; i++)
    {
        for (j = 0; j < coluna; j++)
        {
            if (matA[i][j + 1] < matA[i][j])
            {
                return 0;
            }
        }
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