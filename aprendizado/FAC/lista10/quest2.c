/*Implementar uma função que, dado um vetor
de reais, troque o 1° e o 2° elementos, em
seguida o 3° e o 4° elementos e assim
sucessivamente, até se chegar ao final do vetor.*/
#include <stdio.h>
void trocador(float lista[], int tamanho);

void main()
{
    float lista[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (int i = 0; i < 10; i++)
    {
        printf("%.2f", lista[i]);
    }

    trocador(lista, 10);
    printf("\n");
    for (int i = 0; i < 10; i++)
    {
        printf("%.2f", lista[i]);
    }
}

void trocador(float lista[], int tamanho)
{
    int suporte;
    for (int i = 0; i < tamanho; i += 2)
    {
        suporte = lista[i + 1];
        lista[i + 1] = lista[i];
        lista[i] = suporte;
        // 0 1 2 3 4 5
        // 2 3 4 5 6 7
        // 3 2 5 4 7 6
    }
}