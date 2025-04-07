#include <stdio.h>
int funcao(int a, int b)
{
    if (a > 0)
    {
        if (a > b)
        {
            return funcao(a - 1, b + 2) + funcao(b - a, b);
        }
        else
        {
            return funcao(a - 2, b);
        }
    }
    else
    {
        return b;
    }
}
//  0(10, 5) = 21
//  1(9, 7) =  {16               +       5} 1(-5, 5)
//  2(8, 9) = 9  {9 +  7} 2(-2, 7) = 7     (5)
//  3(6, 9) = 9        3(7)
//  4(4, 9) = 9
//  5(2, 9) = 9
//  6(0, 9) = 9
//  7(9)
void main()
{
    printf("Resposta = %d", funcao(10, 5));
}