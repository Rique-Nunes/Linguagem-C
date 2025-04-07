// Fazer uma função recursiva que, dado um
// número inteiro N, exiba o mesmo na base 2(binária).
#include <stdio.h>
void exibeBinario(int n);

void main()
{
    int n;
    exibeBinario(4);
    printf("\n");
    exibeBinario(10);
}

void exibeBinario(int n)
{
    if (n > 0)
    {
        exibeBinario(n / 2);
        printf("%d", n % 2);
    }
}