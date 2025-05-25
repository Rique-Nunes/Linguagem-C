/*Crie uma função recursiva que exiba todos os números pares entre 1 e N.*/

#include "stdio.h"

void exibir(int lista[], int tamanho);
void main()
{
    int lista[5] = {1, 2, 6, 8, 10};
    exibir(lista, 5);
}

void exibir(int lista[], int tamanho)
{
    if (tamanho > -1)
    {
        exibir(lista, tamanho - 1);
        if (lista[tamanho] % 2 == 0)
        {
            printf("%d\n", lista[tamanho]);
        }
    }
}