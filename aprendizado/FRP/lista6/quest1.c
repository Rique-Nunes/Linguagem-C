#include <stdio.h>
int funcao(int A, int B);

void main()
{
    int x;
    x = funcao(32, 6);
    printf("%d", x);
}

// 32 6
// 26 6
// 20 6
// 14 6
// 8 6
// 2 esse que vai retornar

int funcao(int A, int B)
{
    if (A >= B)
    {
        printf("%d e %d\n", A, B);
        return funcao(A - B, B);
    }
    else
    {
        return A;
    }
}