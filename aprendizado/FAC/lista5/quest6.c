/*Criar um programa que exiba os N
primeiros termos da seguinte série:
1,2,8,64,1024,...*/
//*2*4*8*16*32
#include "stdio.h"

void main()
{
    long int termos, numero = 1, multiplicador = 2;
    printf("quantos termos quer que aparececa: ");
    scanf("%d", &termos);

    for (int i = 0; i < termos; i++)
    {
        printf("%d\n", numero);
        numero *= multiplicador;
        multiplicador *= 2;
    }
}
