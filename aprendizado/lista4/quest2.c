#include "stdio.h"
#include "stdlib.h"

void main()
{
    int count_positivo = 51, count_negativo = 0;

    printf("Vamos mostrar a serie de elementos: \n");
    for (int contador = 50; contador != 0; contador -= 1)
    {
        printf("%d,", count_positivo - contador); //1 a 50
        printf("%d,", count_negativo + contador ); //50 a 1
    }
}