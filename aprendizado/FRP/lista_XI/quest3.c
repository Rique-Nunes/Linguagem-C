/* Considere a existência de um vetor de structs
com quant posições, onde cada uma destas
armazena os seguintes dados sobre os
funcionários de uma empresa: matricula (int),
nome (string), gênero (char) e salário (float).
Pede-se uma função que, dado um gênero,
desloque todos os funcionários deste gênero
para o início do vetor (e, consequentemente, os
funcionários do outro gênero ficarão ao final do
conjunto). */

#include "stdio.h"
#include "string.h"

typedef struct
{
    int matricula;
    char nome[30];
    char genero;
    float salario;

} Tdados;

void trocador_genero(Tdados lista[], int tamanho, char g);

void main()
{
    Tdados funcionarios[5] = {
        {101, "Ana", 'F', 3000.0},
        {102, "Bruno", 'M', 3200.0},
        {103, "Carla", 'F', 3100.0},
        {104, "Diego", 'M', 3500.0},
        {105, "Elaine", 'F', 3300.0}};

    char generoDesejado = 'F';

    printf("Antes da troca:\n");
    for (int i = 0; i < 5; i++)
    {
        printf("%d %s %c %.2f\n", funcionarios[i].matricula, funcionarios[i].nome, funcionarios[i].genero, funcionarios[i].salario);
    }

    trocador_genero(funcionarios, 5, generoDesejado);

    printf("\nDepois da troca:\n");
    for (int i = 0; i < 5; i++)
    {
        printf("%d %s %c %.2f\n", funcionarios[i].matricula, funcionarios[i].nome, funcionarios[i].genero, funcionarios[i].salario);
    }
}

void trocador_genero(Tdados lista[], int tamanho, char g)
{
    int i, j;
    Tdados vet[1];
    for (i = 0; i < tamanho; i++)
    {
        if (lista[i].genero != g)
        {
            for (j = i; j < tamanho; j++)
            {
                if (lista[j].genero == g)
                {
                    vet[0] = lista[i];
                    lista[i] = lista[j];
                    lista[j] = vet[0];
                    break;
                }
            }
        }
    }
}