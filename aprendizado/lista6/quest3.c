/*Implementar um programa
que calcule o valor de baseexpoente, onde
base e expoente são números inteiros
dados pelo usuário.
*/

#include <stdio.h>

void main()
{
    int base, expoente;

    printf("digite a base: ");
    scanf("%d", &base);
    printf("digite o expoente: ");
    scanf("%d", &expoente);

    for (int i = 2; i <= expoente; i++)
    {
        base = base * base;
    }
    printf("Resulta em: %d", base);
}