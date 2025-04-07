// Desenvolver uma função recursiva que exiba
// todos os múltiplos do número N, inferiores ou
// iguais ao valor V.
#include "stdio.h"

void multiplo(int n, int v);

void main()
{
    int n, v;
    printf("Digite o valor de N: ");
    scanf("%d", &n);
    printf("Digite o valor de V: ");
    scanf("%d", &v);
    multiplo(n, v);
}

void multiplo(int n, int v)
{
    if (v >= n)
    {
        multiplo(n, v - 1);
        if (v % n == 0)
        {
            printf("%d ", v);
        }
    }
}
// 2 10
// 2 9
// 2 8
// 2 7
// 2 6
// 2 5
// 2 4
// 2 3
// 2 2
// 2 1
