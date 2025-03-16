/*Desenvolver um programa que calcule a
soma dos números de 1 a N, sendo N um
número inteiro fornecido pelo usuário.
*/
#include "stdio.h"
#include "stdlib.h"

void main()
{
    int numero, contador;
    printf("digite o numero: ");
    scanf("%d", &numero);

    for (int i; i <= numero; i++){
        contador += i;
    }
    printf("soma: %d", contador);
}