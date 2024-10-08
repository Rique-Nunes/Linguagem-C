/*QUESTÃO 02: Pede-se o desenvolvimento
de um programa que leia n valores e
determine o maior e o menor elementos
do conjunto fornecido.*/

#include <stdio.h>

void main()
{
    int numero, numero_maior = 0, numero_menor = 2147483647;
    char teste = 'n';
    /*while (teste == 'n')
    {
        printf("digite o numero: ");
        scanf("%d", &numero);
        if (numero > numero_maior)
        {
            numero_maior = numero;
        }
        if (numero < numero_menor)
        {
            numero_menor = numero;
        }
        printf("quer parar?");
        scanf(" %c", &teste);
    } */
    do
    {
        printf("digite o numero: ");
        scanf("%d", &numero);
        if (numero > numero_maior)
        {
            numero_maior = numero;
        }
        if (numero < numero_menor)
        {
            numero_menor = numero;
        }
        printf("quer parar?");
        scanf(" %c", &teste);
    } while (teste == 'n');
    printf("o numero maior e: %d\n", numero_maior);
    printf("o numero menor e: %d", numero_menor);
}