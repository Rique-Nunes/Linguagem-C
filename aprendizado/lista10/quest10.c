/*Fazer uma função que, dados dois vetores A e B
com números inteiros, gerar o vetor C que
consiste na união dos dois primeiros.
Nota: considerar que não existe repetição no
conjunto A, nem no conjunto B.*/
#include <stdio.h>
void elementos_C(int tamanho_a, int tamanho_b, int *tamanho_c);
void soma_vetor(int lista_a[], int lista_b[], int lista_c[], int tamanho_a, int tamanho_b);

void main()
{
    int lista_A[3] = {1, 2, 3}, lista_B[3] = {5, 8, 9};
    int tamanho_C;

    elementos_C(3, 3, &tamanho_C);
    int lista_C[tamanho_C];
    soma_vetor(lista_A, lista_B, lista_C, 3, 3);

    for (int i = 0; i < tamanho_C; i++)
    {
        printf("%d\n", lista_C[i]);
    }
}

void elementos_C(int tamanho_a, int tamanho_b, int *tamanho_c)
{
    *tamanho_c = tamanho_a + tamanho_b;
}

void soma_vetor(int lista_a[], int lista_b[], int lista_c[], int tamanho_a, int tamanho_b)
{
    int i, j;
    for (i = 0; i < tamanho_a; i++)
    {
        lista_c[i] = lista_a[i];
    }

    for (j = 0; j < tamanho_b; j++)
    {
        lista_c[tamanho_a + j] = lista_b[j];
    }
}