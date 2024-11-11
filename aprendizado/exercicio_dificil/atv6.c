/*Desenvolver uma função que, dado um número inteiro n,
determine o seu maior algarismo, assim como o menor.
Nota: apresentar a main chamando a função implementada.*/

#include <stdio.h>
#include <limits.h>

void algarismo(int numero, int *maior, int *menor);

void main()
{
    int number, maior, menor;
    printf("digite o numero: ");
    scanf("%d", &number);

    algarismo(number, &maior, &menor);

    printf("o maior e %d\n", maior);
    printf("o menor e %d", menor);
}

void algarismo(int numero, int *maior, int *menor)
{
    int teste_maior = INT_MIN, teste_menor = INT_MAX;

    while (numero > 0)
    {
        if ((numero % 10) > teste_maior)
        {
            teste_maior = numero % 10;
        }
        if ((numero % 10) < teste_menor)
        {
            teste_menor = numero % 10;
        }
        numero /= 10;
    }
    *maior = teste_maior;
    *menor = teste_menor;
}