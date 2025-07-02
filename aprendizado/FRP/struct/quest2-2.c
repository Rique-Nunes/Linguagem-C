// codigo, matricula, nome, turno, ordenar por codigo e se for igual ordenar por

#include <stdio.h>
#include <string.h>

typedef struct
{
    int codigo;
    int matricula;
    char nome[30];
    char turno[30];
} taluno;
void ordenado(taluno alunos[], int tamanho);
void main()
{
    // Usar 'int main()' é o padrão em C

    // Vetor de exemplo com casos de teste (códigos iguais, nomes diferentes)
    taluno turma[5] = {
        {102, 5001, "Carlos", "Manha"},
        {101, 5002, "Beatriz", "Tarde"},
        {102, 5003, "Ana", "Manha"}, // Mesmo código de Carlos, nome vem antes
        {104, 5004, "Daniel", "Noite"},
        {101, 5005, "Fabio", "Tarde"} // Mesmo código de Beatriz, nome vem depois
    };

    int tamanho = 5;

    // Chama a função para ordenar o vetor
    ordenado(turma, tamanho);
    for (int i = 0; i < 5; i++)
    {
        printf("%d\n", turma[i].codigo);
    }
}

void ordenado(taluno alunos[], int tamanho)
{
    int i, j, min;
    taluno aux;

    for (i = 0; i < tamanho - 1; i++)
    {
        min = i;
        for (j = i + 1; j < tamanho; j++)
        {
            if (alunos[j].codigo < alunos[min].codigo)
            {
                min = j;
            }
            else if (alunos[j].codigo == alunos[min].codigo)
            {
                if (strcmp(alunos[j].nome, alunos[min].nome) < 0)
                {
                    min = j;
                }
            }
        }
        if (min != i)
        {
            aux = alunos[i];
            alunos[i] = alunos[min];
            alunos[min] = aux;
        }
    }
    printf("ordenado!");
}
