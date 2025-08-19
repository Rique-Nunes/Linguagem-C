/*Desenvolver um programa que, dado um número inteiro n, exiba um triângulo conforme ilustrado pelo exemplo a
seguir:
n = 7
1
2 1
1 2 3
4 3 2 1
1 2 3 4 5
6 5 4 3 2 1
1 2 3 4 5 6 7*/
#include <stdio.h>
void main()
{
    int numero;

    printf("digite o numero: ");
    scanf("%d", &numero);

    for (int i = 1; i <= numero; i++)
    {
        // 2
        if ((i % 2) == 0)
        {
            for (int j = i; j > 0; j--)
            {
                printf("%d", j);
            }
        }
        else
        {
            for (int h = 1; h <= i; h++){
                printf("%d", h);
            }
        }
        printf("\n");
    }
}