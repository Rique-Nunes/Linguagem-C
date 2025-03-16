/*Desenvolver uma função que determine o
número de ocorrências de um número inteiro x
em um vetor A.*/

#include <stdio.h>

int ocorre(int lista[], int tamanho, int A);

void main()
{
    // desgraça!!
    int numero;
    int lista[14] = {1, 1, 2, 2, 3, 3, 4, 5, 6, 7, 8, 9, 9, 9};
    printf("qual numero voce esta procurando: ");
    scanf("%d", &numero);

    printf("%d vezes", ocorre(lista, 14, numero));
}

int ocorre(int lista[], int tamanho, int A)
{
    int contador = 0;
    for (int i = 0; i < tamanho; i++)
    {
        if (lista[i] == A)
        {
            contador++;
        }
    }
    return contador;
}