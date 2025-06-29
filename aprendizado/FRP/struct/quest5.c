#include <stdio.h>
#include <string.h>

typedef struct
{
    int codigo;
    int semestre;
    int ano;
    int media;
} tauluno;

typedef struct
{
    int codigo;
    int credito;
} tdisc;

void exibir(tauluno aluno[], int tamanho, tdisc disciplina[], int tamanho_disc);

void main()
{
}

void exibir(tauluno aluno[], int tamanho, tdisc disciplina[], int tamanho_disc)
{
    int i, cr = 0, soma_credito = 0, j;
    for (i = 0; i < tamanho; i++)
    {
        printf("%d,", aluno[i].codigo);
        printf("%d\n", aluno[i].media);
        for (j = 0; j < tamanho_disc; j++)
        {
            if (disciplina[j].codigo == aluno[i].codigo)
            {
                cr += aluno[i].media * disciplina[j].credito;
                soma_credito += disciplina[j].credito;
                break;
            }
        }
    }
    cr /= soma_credito;
    printf("coeficiente: %d", cr);
}