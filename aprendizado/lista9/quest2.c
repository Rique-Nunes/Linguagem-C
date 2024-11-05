/*Dados dois números inteiros A e B, fazer uma
função que determine o número de potências
de 2 existentes no intervalo definido pelos dois
valores, assim como a maior delas.*/

#include "stdio.h"
void potencia(int a, int b, int *cont, int *maior)
{
    int pot = 1, contador = 0;

    while (pot < b)
    {
        pot *= 2;
        for (int i = a; i < b; i++)
        {
            if (i == pot)
            {
                contador += 1;
                *maior = i;
            }
        }
    }
    *cont = contador;
}
void main()
{
    int num1, num2, contador, maior;

    printf("digite o valor de n1:");
    scanf("%d", &num1);
    printf("digite o valor de n2:");
    scanf("%d", &num2);

    potencia(num1, num2, &contador, &maior);
    printf("%d\n", contador);
    printf("%d", maior);
}
