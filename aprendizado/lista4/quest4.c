#include "stdio.h"
#include "stdlib.h"

void main()
{
    float numero, cont_negativo = 0, qtd_positivo = 0, cont_positivo = 0;

    for (int i = 0; i <= 300; i += 1)
    {
        printf("digite o numero: ");
        scanf("%f", &numero);
        if (numero < 0)
        {
            cont_negativo += 1;
        }
        else
        {
            cont_positivo += 1;
            qtd_positivo += numero;
        }
    }
    printf("deu %f valores negativos, %f de media de valores positivos", cont_negativo, qtd_positivo / cont_positivo);
}