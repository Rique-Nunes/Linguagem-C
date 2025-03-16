/*Fazer uma função que calcule o MMC (mínimo
múltiplo comum) entre dois números.*/

#include <stdio.h>

int mmc(int num1, int num2)
{
    int mmc = 1, i = 2;

    while (num1 > 1 || num2 > 1)
    {
        if ((num1 % i == 0) && (num2 % i == 0))
        {
            mmc *= i;
            num1 /= i;
            num2 /= i;
        }
        else if (((num1 % i == 0) && (num2 % i != 0)))
        {
            mmc *= i;
            num1 /= i;
        }
        else if (((num1 % i != 0) && (num2 % i == 0)))
        {
            mmc *= i;
            num2 /= i;
        }
        else
        {
            i++;
        }
    }
    return mmc;
}

void main()
{
    printf("%d\n", mmc(48, 84));
}