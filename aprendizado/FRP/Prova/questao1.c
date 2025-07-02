#include "stdio.h"

void funcao2(int v[], int n);
void funcao1(int *x, int *y);

void main()
{
    int v[] = {1, 2, 3, 4, 5};
    funcao2(v, 5);

    for (int i = 0; i < 5; i++)
    {
        printf("%d ", v[i]);
    }
}

void funcao1(int *x, int *y)
{
    int temp = *x;
    *x = *x + *y;
    *y = *x - (2 * temp);
}

void funcao2(int v[], int n)
{
    int i, *p;
    for (i = 0, p = v; i < n - 1; i++, p++)
    {
        funcao1(p, p + 1);
    }
}
