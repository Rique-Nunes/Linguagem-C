/*implementar uma função que, dado um vetor
contendo números reais, determine o maior e o
segundo maior elementos.
Nota: considerar que não há repetição de
elementos no vetor.*/

#include <stdio.h>

void maiores(float vet[], int tamanho_vet, float *maior, float *segundo_maior);

void main()
{
    float vet[3] = {10.0, 20.0, 30.0};
    int tamanho = 3;
    float maior_first, maior_second;

    maiores(vet, tamanho, &maior_first, &maior_second);
    printf("Maior: %.2f\n", maior_first);
    printf("Segundo maior: %.2f\n", maior_second);
}

void maiores(float vet[], int tamanho_vet, float *maior, float *segundo_maior)
{
    int i;
    float maior1 = 0, maior2 = 0;
    for (i = 0; i < tamanho_vet; i++)
    {
        if (vet[i] > maior2)
        {
            maior2 = maior1;
            maior1 = vet[i];
        }
        else if (vet[i] > maior2)
        {
            maior2 = vet[i];
        }
    }
    *maior = maior1;
    *segundo_maior = maior2;
}
