/*Fazer uma função que, dados dois vetores A e B
com números inteiros, gerar o vetor C que
consiste na intersecção dos dois primeiros.
Nota: considerar que não existe repetição no
conjunto A, nem no conjunto B.*/

#include <stdio.h>

void intersao_vetor(int lista_a[], int lista_b[], int lista_c[], int tamanho_a, int tamanho_b, int *tamanho_c);

void main()
{
    int lista_A[5] = {1, 2, 3, 5, 8}, lista_B[3] = {5, 8, 3};
    int tamanho_A = 5, tamanho_B = 3, tamanho_C;

    tamanho_C = (tamanho_A < tamanho_B) ? tamanho_A : tamanho_B;

    int lista_C[tamanho_C];

    intersao_vetor(lista_A, lista_B, lista_C, tamanho_A, tamanho_B, &tamanho_C);

    for (int i = 0; i < tamanho_C; i++)
    {
        printf("%d\n", lista_C[i]);
    }
}

void intersao_vetor(int lista_a[], int lista_b[], int lista_c[], int tamanho_a, int tamanho_b, int *tamanho_c)
{
    int i, j, maior, menor, indice = 0;
    // 1 2 3 4 5 6
    // 1 5 2 6 8 7
    // 1 2 5 6
    if (tamanho_a > tamanho_b)
    {
        maior = tamanho_a;
        menor = tamanho_b;
    }
    else
    {
        maior = tamanho_b;
        menor = tamanho_a;
    }
    for (i = 0; i < maior; i++)
    {
        for (j = 0; j < menor; j++)
        {
            if (lista_a[i] == lista_b[j])
            {
                lista_c[indice] = lista_a[i];
                indice++;
                break;
            }
        }
    }
    *tamanho_c = indice;
}