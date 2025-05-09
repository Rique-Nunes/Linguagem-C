#include <stdio.h>

// Protótipo da função
int verificador(int linha, int coluna, int mat[linha][coluna], int num);

int verificador(int linha, int coluna, int mat[linha][coluna], int num)
{
    int i, j;
    int temp = num;
    int digits[10], len = 0;

    // Extrai os dígitos do número para um vetor
    while (temp > 0)
    {
        digits[len++] = temp % 10;
        temp /= 10;
    }

    // Inverte os dígitos para ordem correta
    for (i = 0; i < len / 2; i++)
    {
        int aux = digits[i];
        digits[i] = digits[len - i - 1];
        digits[len - i - 1] = aux;
    }

    // Verifica horizontalmente
    for (i = 0; i < linha; i++)
    {
        for (j = 0; j <= coluna - len; j++)
        {
            int k;
            for (k = 0; k < len; k++)
            {
                if (mat[i][j + k] != digits[k])
                    break;
            }
            if (k == len)
                return 1;
        }
    }

    // Verifica verticalmente
    for (j = 0; j < coluna; j++)
    {
        for (i = 0; i <= linha - len; i++)
        {
            int k;
            for (k = 0; k < len; k++)
            {
                if (mat[i + k][j] != digits[k])
                    break;
            }
            if (k == len)
                return 1;
        }
    }

    return 0;
}

int main()
{
    int teste;
    int num = 31975;
    int mat[6][8] = {
        {5, 0, 1, 3, 6, 8, 4, 0},
        {2, 3, 1, 9, 7, 5, 0, 1},
        {8, 5, 4, 2, 2, 5, 5, 7},
        {4, 6, 3, 5, 3, 3, 2, 6},
        {2, 4, 5, 1, 2, 4, 3, 5},
        {5, 5, 1, 0, 1, 9, 1, 8}};
    teste = verificador(6, 8, mat, num);
    printf("%d\n", teste); // Esperado: 1 (verdadeiro)
    return 0;
}
