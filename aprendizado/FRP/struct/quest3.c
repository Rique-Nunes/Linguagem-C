#include "stdio.h"
#include "string.h"

typedef struct
{
    int matricula;
    char genero;
} talunos;

void main()
{
    talunos lista[3] = {{1,"m"}, {2,"m",}, {3, "f"}};
    
    
}

void ordenador(talunos alunos[], char genero, int tamanho)
{
    int i;
    char trocar;
    for (i = 0; i < tamanho; i++)
    {
        if (alunos[i].genero == genero)
        {
            for (int j = i + 1; j < tamanho; j++)
            {
                if (alunos[j].genero != genero)
                {
                    trocar = alunos[i].genero;
                    alunos[i].genero = alunos[j].genero;
                    alunos[j].genero = trocar;
                    break;
                }
            }
        }
    }
}
