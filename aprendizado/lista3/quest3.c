/*Implementar um programa que leia um valor
inteiro n1. Se este não estiver no intervalo de
100 a 999, uma mensagem deve ser exibida ao
usuário informando que o número é inválido e,
em seguida, a execução do programa terminará.
Caso o valor esteja no intervalo definido, o
programa deverá criar um novo valor n2 (e exibilo ao final) contendo os mesmos algarismos de
n1, porém em ordem crescente.
Exemplos:
n1 514
n2 145
n1 929
n2 299
n1 124
n2 124
Nota:
Como definido no enunciado, n1 consiste em um
número inteiro positivo, com 3 algarismos. n2
também será um único número!*/
#include "stdio.h"
#include "stdlib.h"

void main()
{
    int valor_inicial, valor_resto1, valor_resto2;

    printf("Digite o valor definidido: ");
    scanf("%d", &valor_inicial);

    if ((valor_inicial >= 100) && (valor_inicial <= 999))
    {
        valor_resto1 = valor_inicial % 10;
        valor_inicial /= 10;
        valor_resto2 = valor_inicial % 10;
        valor_inicial /= 10;

        if ((valor_inicial > valor_resto1) && (valor_inicial > valor_resto2))
        {
            if (valor_resto1 > valor_resto2)
            {
                printf("A nova ordem e: %d%d%d", valor_resto2, valor_resto1, valor_inicial);
            }
            else
            {
                printf("A nova ordem e: %d%d%d", valor_resto1, valor_resto2, valor_inicial);
            }
        }
        if ((valor_resto1 > valor_resto2) && (valor_resto1 > valor_inicial))
        {
            if (valor_resto2 > valor_inicial)
            {
                printf("A nova ordem e: %d%d%d", valor_inicial, valor_resto2, valor_resto1);
            }
            else
            {
                printf("A nova ordem e: %d%d%d", valor_resto2, valor_inicial, valor_resto1);
            }
        }
        if ((valor_resto2 > valor_resto1) && (valor_resto2 > valor_inicial))
        {
            if (valor_resto1 > valor_inicial)
            {
                printf("A nova ordem e: %d%d%d", valor_inicial, valor_resto1, valor_resto2);
            }
            else
            {
                printf("A nova ordem e: %d%d%d", valor_resto1, valor_inicial, valor_resto2);
            }
        }
    }else{
        printf("Valor de entrada invalido");
    }
}