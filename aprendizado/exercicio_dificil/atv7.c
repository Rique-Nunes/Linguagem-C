/*Dado um vetor contendo números reais, desenvolver uma função que determine
o maior valor do vetor inferior à média de seus elementos,
assim como o menor que seja superior a esta média.
Nota: apresentar a main chamando a função implementada.*/

#include <stdio.h>
#include <limits.h>
void maior_valor(float num[], int tamanho, float *maior, float *menor);

void main()
{
    float numeros[5] = {1.5, 2.1, 3.5, 4.1, 5.3};
    float maior_inferior, menor_superior;
    int tamanho = 5;

    maior_valor(numeros, tamanho, &maior_inferior, &menor_superior);

    printf("o maior_inferior e: %.2f\n", maior_inferior);
    printf("o menor_superior e: %.2f", menor_superior);
}

void maior_valor(float num[], int tamanho, float *maior, float *menor)
{
    float maior_inferior = INT_MIN, menor_superior = INT_MAX, media = 0, contador = 0;

    for (int j = 0; j < tamanho; j++)
    {
        media += num[j];
        contador++;
    }

    media /= contador;

    for (int i = 0; i < tamanho; i++)
    {
        if ((num[i] > maior_inferior) && (num[i] < media))
        {
            maior_inferior = num[i];
        }
        if ((num[i] < menor_superior) && (num[i] > media))
        {
            menor_superior = num[i];
        }
    }

    *maior = maior_inferior;
    *menor = menor_superior;
}
