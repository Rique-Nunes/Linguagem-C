/*: Faça um programa que leia
200 números inteiros. Ao final, exibir:
a) O maior número fornecido, de
ordem par (isto é, o maior dentre o
segundo, quarto, sexto, oitavo, etc
valores fornecidos).
b) A média dos valores pares.
*/

#include <stdio.h>

void main()
{
    int num, maior_par = 0, media_par = 0, qtd_par = 0;

    for (int i = 1; i <= 5; i++)
    {
        printf("digite um numero: ");
        scanf("%d", &num);
        if (i % 2 == 0)
        {
            if (num > maior_par)
            {
                maior_par = num;
            }
        }
        if (num % 2 == 0)
        {
            media_par += num;
            qtd_par += 1;
        }
    }
    printf("o maior par: %d", maior_par);
    printf("media dos numeros pares: %d", media_par / qtd_par);
}