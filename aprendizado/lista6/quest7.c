/*Faça um programa que leia
150 números reais e, ao final, exiba:
a) A soma dos 50 primeiros;
b) menor número do 51° ao 100°
valores fornecidos;
c) A média entre os últimos 50
valores.*/

#include <stdio.h>

void main()
{
    int numero, soma_primeiro = 0, menor_num = 2147483647, media_ultimo = 0;

    for (int i = 1; i <= 10; i++)
    {
        printf("digite um numero: ");
        scanf("%d", &numero);
        if (i <= 5)
        {
            soma_primeiro += numero;
        }
        else if ((i > 5) && (i <= 8))
        {
            if (numero < menor_num)
            {
                menor_num = numero;
            }
        }
        else if (i > 8)
        {
            media_ultimo += numero;
        }
    }
    printf("soma dos primeiros 50: %d", soma_primeiro);
    printf("menor entre 50 e 100: %d", menor_num);
    printf("media dos ultimos 50: %d", media_ultimo / 2);
}