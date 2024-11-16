/*Faça uma função que, dado um vetor de reais,
altere todas as ocorrências do número A pelo
número B.*/

#include <stdio.h>
void trocar(float lista[], int tamanho, float A, float B);

void main()
{
    float a, b, lista[9] = {1, 2, 2, 2, 5, 6, 7, 8, 9};
    printf("digite o valor a ser trocado: ");
    scanf("%f", &a);
    printf("digite o valor para trocar: ");
    scanf("%f", &b);
    printf("antes\n");
    for (int i = 0; i < 9; i++)
    {
        printf("%.2f,", lista[i]);
    }

    trocar(lista, 9, a, b);
    printf("\ndepois \n");
    
    for (int j = 0; j < 9; j++)
    {
        printf("%.2f,", lista[j]);
    }
}

void trocar(float lista[], int tamanho, float A, float B)
{
    for (int i = 0; i < tamanho; i++)
    {
        if (lista[i] == A)
        {
            lista[i] = B;
        }
    }
}
