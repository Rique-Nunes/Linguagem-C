/*Desenvolver uma função que exiba os múltiplos
de N compreendidos no intervalo definido por
A e B.*/

#include <stdio.h>

void multiplos(int n, int a, int b)
{
    for (int i = a; i <= b; i++)
    {
        if (i % n == 0)
        {
            printf("%d:%d\n", n, i);
        }
    }
}

void main()
{
    multiplos(2, 2, 10);
}
