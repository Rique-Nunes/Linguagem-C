/*
Considere a existência de um vetor de structs
com quant posições, onde cada uma destas
armazena os seguintes dados sobre um grupo
de pessoas: nome (string), gênero (char) e
idade (int). Pede-se uma função que determine
se os elementos deste vetor estão ordenados e
retorne 1, caso estejam ordenados, e 0, caso
contrário.
Observação: o vetor será considerado ordenado se
estiver organizado crescentemente em função da
idade. Porém, no caso de pessoas com a mesma
idade, estas devem estar ordenadas crescentemente
pelo nome.
*/

#include "stdio.h"
#include "string.h"

typedef struct
{
    char nome[30];
    char genero;
    int idade;
} Tdados;

int ordenacao(Tdados lista[], int tamanho);
void main()
{
    Tdados pessoas[5] = {
        {"Ana", 'F', 25},
        {"Bruno", 'M', 26},
        {"Carla", 'F', 28},
        {"Diego", 'M', 28},
        {"Elaine", 'F', 40}};

    if (ordenacao(pessoas, 5) == 0)
    {
        printf("nao esta ordenado");
    }
    else
    {
        printf("esta ordenado");
    }

    for (int i=0; i < 5; i++)
    {
        printf("\n%s - %c - %d", pessoas[i].nome, pessoas[i].genero, pessoas[i].idade);
    }
}
int ordenacao(Tdados lista[], int tamanho)
{
    int i, j;
    for (i = 0; i < tamanho - 1; i++)
    {

        if (lista[i].idade > lista[i + 1].idade)
        {
            return 0;
        }
        if (lista[i].idade == lista[i + 1].idade)
        {
            if (strcmp(lista[i].nome, lista[i + 1].nome) == 1)
            {
                return 0;
            }
        }
    }
    return 1;
}