/*Desenvolver uma função que, dado um número
inteiro n, exiba todos os números existentes no
intervalo definido por a e b (a < b), exceto
aqueles que forem múltiplos de n.
*/

#include "stdio.h"

void exibir(int n, int a, int b)
{

    for (int i = a; i < b; i++)
    {
        if (i % n == 0)
        {
        }
        else
        {
            printf("%d\n", i);
        }
    }
}

void main()
{
    int numero, a, b;
    printf("digite o valor de n:");
    scanf("%d", &numero);
    printf("digite o valor de a:");
    scanf("%d", &a);
    printf("digite o valor de b:");
    scanf("%d", &b);

    exibir(numero, a, b);
}