#include "stdio.h"
#include "string.h"

typedef struct
{
    int matricula;
    char genero;
} talunos;

void ordenador(talunos alunos[], char genero, int tamanho);
void main()
{
    talunos lista[3] = {{1, 'm'}, {
                                      2,
                                      'm',
                                  },
                        {3, 'f'}};

    ordenador(lista, 'f', 3);
    for (int i = 0; i < 3; i++)
    {
        printf("%d", lista[i].matricula);
    }
}

void ordenador(talunos alunos[], char genero, int tamanho)
{
    int i;
    talunos trocar;
    for (i = 0; i < tamanho; i++)
    {
        if (alunos[i].genero == genero)
        {
            for (int j = 0; j < tamanho; j++)
            {
                if (alunos[j].genero != genero)
                {
                    trocar = alunos[i];
                    alunos[i] = alunos[j];
                    alunos[j] = trocar;
                    break;
                }
            }
        }
    }
}
