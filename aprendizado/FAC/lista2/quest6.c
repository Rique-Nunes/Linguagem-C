#include "stdio.h"
#include "stdlib.h"

void main()
{
    int a, b, c, i, maior, menor, meio;
    printf("Digite os tres numeros em sequencia: ");
    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &c);
    printf("\nDigite 1 para os tres valores em ordem crescente\nDigite 2 para os tres valores em ordem decrescente\nDigite 3 o maior valor deve ser apresentado no meio dos outros");
    scanf("%d", &i);

    maior = a;
    if (b > maior)
    {
        maior = b;
    }
    if (c > maior)
    {
        maior = c;
    }
    menor = a;
    if (b < menor)
    {
        menor = b;
    }
    if (c < menor)
    {
        menor = c;
    }
    meio = a + b + c - maior - menor;

    if (i == 1)
    {
        printf("A ordem crescente e %d, %d, %d", menor, meio, maior);
    }
    else if (i == 2)
    {
        printf("A ordem decrescente e:  %d, %d, %d", maior, meio, menor);
    }
    else if (i == 3)
    {
        printf("A ordem maior no meio e:  %d, %d, %d", menor, maior, meio);
    }
}