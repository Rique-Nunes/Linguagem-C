/*Fazer uma função que calcule o MDC (máximo
divisor comum) entre dois números.*/
#include <stdio.h>
int mdc(int num1, int num2)
{

    int mdc, divisor;
    divisor = (num1 < num2) ? num1 : num2;

    for (int i = 1; i <= divisor; i++)
    {
        if ((num1 % i == 0) && (num2 % i == 0))
        {
            mdc = i;
        }
    }
    return mdc;
}

void main()
{
    printf("%d\n", mdc(150, 120));
}