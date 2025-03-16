/*Desenvolver uma função que exiba todos os
números primos inferiores a determinado valor
inteiro N.*/

#include "stdio.h"

int primos(int num)
{
    int cont = 0;
    for (int i = 2; i < num; i++)
    {
        for (int j = 2; j < i; j++)
        {
            if (i % j == 0)
            {
                cont++;
                break;
            }
        }
        if (cont != 1)
        {
            printf("o cara e primo: %d\n", i);
        }
        cont = 0;
    }
}

void main()
{
    primos(10);
}