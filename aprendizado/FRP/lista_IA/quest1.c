/*Implemente uma função recursiva que calcule o
fatorial de um número inteiro positivo*/

#include "stdio.h"

int fatorial(int num);
void main()
{
    printf("%d", fatorial(5));
}

int fatorial(int num)
{
    if (num < 2)
    {
        return 1;
    }
    return fatorial(num - 1) * num;
}