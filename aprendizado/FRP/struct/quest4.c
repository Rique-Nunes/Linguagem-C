#include "stdio.h"
#include "string.h"

typedef struct
{
    char nome[30];
    char genero;
    int idade;
} tpessoa;

int ordenacao(tpessoa pessoas[], int tamanho);

void main()
{
    int TAMANHO = 3;
    tpessoa pessoas[3] = {
        {"Carlos", 'M', 23},
        {"Ana", 'F', 25},
        {"Beatriz", 'F', 25}};

    printf("%d", ordenacao(pessoas, 3));
}

int ordenacao(tpessoa pessoas[], int tamanho)
{
    int i;

    for (i = 0; i < tamanho - 1; i++)
    {
        if (pessoas[i + 1].idade < pessoas[i].idade)
        {
            return 0;
        }
        if (pessoas[i + 1].idade == pessoas[i].idade)
        {
            if (strcmp(pessoas[i + 1].nome, pessoas[i].nome) < 0)
            {
                return 0;
            }
        }
    }
    return 1;
}