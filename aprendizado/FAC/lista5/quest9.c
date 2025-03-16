/*Escrever um programa que encontre o
quinto número maior que 1000, cuja
divisão por 11 tenha resto 5.
*/
#include "stdio.h"
void main()
{
    int numero = 0, cont = 0;
    for (int i = 1000; cont < 5; i++)
    {
        if ((i % 11) == 5)
        {
            cont++;
            if (cont == 5)
            {
                numero = i;
                break;
            }
        }
    }
    printf("%d", numero);
}