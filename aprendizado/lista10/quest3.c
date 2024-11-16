/*Pede-se a implementação de uma função que,
dado um vetor contendo números reais,
determine se o mesmo encontra-se ordenado
de forma crescente.*/

#include <stdio.h>

int ordem(float lista[], int tamanho);

void main()
{
    float lista[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int teste;

    teste = ordem(lista, 10);
    if (teste == 1)
    {
        printf("esta ordenado!");
    }
    else
    {
        printf("nao esta ordenado");
    }
}

int ordem(float lista[], int tamanho)
{
    for (int i = 0; i < tamanho - 1; i++)
    {
        if (lista[i] > lista[i + 1])
        {
            return 0;
        }
    }
    return 1;
}