/*Criar um programa que exiba os N
primeiros termos da seguinte série:
1,2,4,8,16,32,...*/

#include "stdio.h"
#include "stdlib.h"

void main()
{
    int termo, serie = 1;

    printf("digite o numero: ");
    scanf("%d", &termo);

    for (int i = 1; i <= termo; i++)
    {
        printf("%d\n", serie);
        serie *= 2;
    }
}