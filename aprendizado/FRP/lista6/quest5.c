/*Pede-se a implementação de uma função
recursiva que exiba os n primeiros termos de
uma PG (Progressão Geométrica), onde a1 é o seu primeiro termo e q a razão.
Observação: uma PG consiste em uma sequência de valores,
iniciadas pelo valor a1. Os demais elementos são definidos como o
anterior multiplicado pela razão.*/

#include <stdio.h>

int pg(int n, int a1, int q);

void main()
{
    int n, a1, q;
    pg(5, 2, 2);
}

int pg(int n, int a1, int q)
{
    if (n > 1)
    {
        pg(n - 1, a1 * q, q);
        printf("\n%d", a1);
    }
    else
    {
        printf("\n%d", a1);
        return a1;
    }
}