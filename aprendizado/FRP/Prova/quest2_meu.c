#include "stdio.h"
int funcao1(int a, int b, int c);
int funcao2(int x, int y);
void main()
{
    int resp = funcao2(4, 27);
    printf("Resultado: %d", resp);
}
int funcao1(int a, int b, int c)
{
    int d = a;
    if (b < d)
    {
        d = b;
    }
    if (c < d)
    {
        d = c;
    }
    return d;
}
int funcao2(int x, int y)
{
    int z;
    if (x < y)
    {
        z = y - x;
        if (z > x)
        {
            return funcao2(x + 1, z);
        }
        else
        {
            return funcao2(funcao1(x, y, z), y) +
                   funcao2(x, z);
        }
    }
    else
    {
        return x;
    }
}