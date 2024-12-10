/*Considere a existência de dois conjuntos
numéricos A e B contendo n1 e n2 elementos,
respectivamente. Pede-se o desenvolvimento
de uma função que determine se um dos
conjuntos está contido no outro, retornando os
seguintes códigos:
 1, se A estiver contido em B;
 2, se B estiver contido em A;
 0, caso contrário.*/
#include <stdio.h>

int testa_contido(int A[], int tamanho_A, int B[], int tamanho_B);

void main()
{
    int A[5] = {1, 2, 3, 4, 5};
    int B[7] = {1, 2, 3, 4, 5, 6, 7};
    int tamanho_b = 7, tamanho_a = 5;
    int teste;

    teste = testa_contido(A, tamanho_a, B, tamanho_b);
    printf("%d", teste);
}

int testa_contido(int A[], int tamanho_A, int B[], int tamanho_B)
{
    int teste_b = 0;
    int teste_a = 0;
    // verifica se A está contido em B
    for (int i = 0; i < tamanho_A; i++)
    {
        for (int j = 0; i < tamanho_B; j++)
        {
            if (A[i] == B[j])
            {
                teste_a += 1;
                break;
            }
        }
    }
    // verifica se b está contido em a
    for (int i = 0; i < tamanho_B; i++)
    {
        for (int j = 0; i < tamanho_A; j++)
        {
            if (B[i] == A[j])
            {
                teste_b += 1;
                break;
            }
        }
    }
    if (teste_a == tamanho_A)
    {
        return 1;
    }
    else if (teste_b == tamanho_B)
    {
        return 2;
    }
    else
    {
        return 0;
    }
}