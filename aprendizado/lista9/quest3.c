/*Fazer uma função leituraDados que permaneça
lendo valores reais até que o número 0 seja
digitado. Ao final, a função deve determinar a
quantidade de elementos fornecidos (excluindo
o 0) e o maior dentre eles.
*/

#include "stdio.h"

void leituraDados(int *cont, float *maior)
{
    float num = 1;
    int contador;

    while (num != 0)
    {
        printf("digite o numero: ");
        scanf("%f", &num);
        if (num != 0)
        {
            contador++;
        }
        if (*maior < num)
        {
            *maior = num;
        }
    }
    *cont = contador;
}
void main()
{
    int contador;
    float maior;

    leituraDados(&contador, &maior);
    printf("%.2f e %d", maior, contador);
}
