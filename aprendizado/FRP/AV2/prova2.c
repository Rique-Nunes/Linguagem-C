#include <stdio.h>
#include <stdlib.h>

void ordenacao(int vetor[], int *tamanho);
void main()
{
    int vetor[7] = {15, 6, 15, 11, 8, 1, 24};
    int tamanho = 7;
    ordenacao(vetor, &tamanho);

    for (int i = 0; i < tamanho; i++)
    {
        printf("%d ", vetor[i]);
    }
}

void ordenacao(int vetor[], int *tamanho)
{
    int i, j, k, *min, aux;

    for (i = 0; i < *tamanho - 1; i++)
    {

        min = vetor + i;

        for (j = i + 1; j < *tamanho; j++)
        {

            if (vetor[j] < *min)
            {
                min = vetor + j;
            }
            else if (vetor[j] == *min)
            {

                for (k = j; k < *tamanho - 1; k++)
                {
                    vetor[k] = vetor[k + 1];
                }
                (*tamanho)--;
                j--;          
            }
        }
        aux = vetor[i];
        vetor[i] = *min;
        *min = aux;
    }
}