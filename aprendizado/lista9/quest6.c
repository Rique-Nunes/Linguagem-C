/**/
#include "stdio.h"

float formula(int numero)
{
    float soma = 1, pow = 1, fatorial = 1;

    for (int j = 1; j < numero; j++)
    {
        float pow = 1;
        float fatorial = 1;

        for (int h = 1; h <= j; h++)
        {
            pow *= numero - j;
        }
        for (int i = 1; i <= j; i++)
        {

            fatorial *= i;
        }
        soma += pow / fatorial;
    }
    printf("%f\n", fatorial);
    printf("%f\n", pow);
    return soma;
}

void main()
{
    printf("%f", formula(3));
}