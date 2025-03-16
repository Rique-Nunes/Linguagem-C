/*Desenvolver um programa no qual o
usuário entre com vários números inteiros
e positivos e imprima o produto dos
números ímpares e a soma dos números
pares.
Desenvolver um programa no qual o
usuário entre com vários números inteiros
e positivos e imprima o produto dos
números ímpares e a soma dos números
pares.
*/

#include "stdio.h"
#include "stdlib.h"

void main()
{
    int numero, cont_par = 0, cont_impar = 1;
    char teste;
    while (1)
    {
        printf("digite o numero desejado");
        scanf("%d", &numero);
        if ((numero % 2) == 0)
        {
            cont_par += numero;
        }
        else
        {
            cont_impar *= numero;
        }
        printf("quer parar?: (s/n)");
        scanf("%s", &teste);
        if (teste == 's')
        {
            printf("parou");
            break;
        }
    }
    printf("a soma dos numeros pares: %d\n", cont_par);
    printf("o produto dos numeros impares: %d", cont_impar);
}