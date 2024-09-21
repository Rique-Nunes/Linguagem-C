#include "stdio.h"
#include "stdlib.h"

/*Dado um número inteiro N, fazer um
programa que exiba os números pares
iguais ou inferiores a N. */
void main()
{
    int numero;
    printf("Digite um número: ");
    scanf("%d", &numero);

    for (int i = 1; i <= numero; i++)
    {
        if ((i % 2) == 0)
        {
            printf("%d\n", i);
        }
    }
}