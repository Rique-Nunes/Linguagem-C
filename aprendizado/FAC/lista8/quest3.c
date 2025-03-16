#include <stdio.h>
int fibo(int numero)
{
    int termo;
    if (numero <= 2)
    {
        return 1;
    }
    int a = 0, b = 1, c;
    printf("%d\n", a);
    for (int i = 3; i <= numero; i++)
    {
        c = a + b;
        a = b;
        b = c;
    }
    termo = c;
    return termo;
}

void main()
{
    int numero;
    numero = fibo(6);
    printf("%d", numero);
}