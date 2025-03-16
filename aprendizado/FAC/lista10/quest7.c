/*Desenvolver uma função que remova
determinado elemento (todas as suas
ocorrências) de um vetor de float. Ao final,
retornar o número de remoções realizadas*/

#include "stdio.h"
void deletar(float lista[], float lista_removida[], int tamanho, float elemento, int *novo_tamanho);

void main()
{
    float lista[9] = {1, 2, 2, 2, 5, 6, 7, 8, 9}, numero, lista_nova[9];
    int tamanho_novo;

    printf("digite o numero a ser removido:");
    scanf("%f", &numero);

    printf("antiga \n");

    for (int i = 0; i < 9; i++)
    {
        printf("%.2f\n", lista[i]);
    }

    deletar(lista, lista_nova, 9, numero, &tamanho_novo);

    printf("nova \n");

    for (int j = 0; j < tamanho_novo; j++)
    {
        printf("%.2f\n", lista_nova[j]);
    }
}
void deletar(float lista[], float lista_removida[], int tamanho, float elemento, int *novo_tamanho)
{
    int j = 0;
    for (int i = 0; i < tamanho; i++)
    {
        if (lista[i] != elemento)
        {

            lista_removida[j] = lista[i];
            j++;
        }

        // 1 2 3 4 5 3 6
        // 1 2 4 5 6
    }
    *novo_tamanho = j;
}