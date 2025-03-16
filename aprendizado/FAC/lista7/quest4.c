/*Faça um programa que leia
um número inteiro N e informe se o
mesmo é ou não primo.
Nota: um número é dito primo quando for
divisível apenas por 1 e por ele mesmo.
*/

#include <stdio.h>

void main()
{
    int n, contador = 0;

    printf("digite o numero: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0)
        {
            contador += 1;
        }
    }
    if (contador > 2)
    {
        printf("o cara nao e primo %d", n);
    }
    else
    {
        printf("o cara e primo %d", n);
    }
}