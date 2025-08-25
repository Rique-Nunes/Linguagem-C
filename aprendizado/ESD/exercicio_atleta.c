#include <string.h>
#include <stdio.h>
#include <stdlib.h>

struct atleta
{
    char *nome;
    int matricula;
    int tempo;
};

typedef struct atleta vAtletas;

int main()
{
    int n;
    printf("Bem-vindo quantos usuarios ira cadastrar");
    scanf("%d", &n);

    vAtletas *vetor = (vAtletas *)malloc(n * sizeof(vAtletas)); // Para os dados
    if (!vetor)
    {
        return 0;
    }
    vAtletas **indices = (vAtletas **)malloc(n * sizeof(vAtletas *)); // para os ponteiros
    if (!indices)
    {
        free(vetor);
        return 0;
    }
    vAtletas **indices_nome = (vAtletas **)malloc(n * sizeof(vAtletas *)); // para os ponteiros ordenados por nome
    if (!indices_nome)
    {
        free(vetor);
        return 0;
    }
    vAtletas **indices_ranking = (vAtletas **)malloc(n * sizeof(vAtletas *)); // para os ponteiros ordenados por tempo
    if (!indices_ranking)
    {
        free(vetor);
        return 0;
    }

    for (int i = 0; i < n; i++)
    {
        char nome_buffer[100];
        printf("\n--- Atleta %d ---\n", i + 1);
        printf("Digite o nome: ");
        scanf("%s", nome_buffer);

        vetor[i].nome = (char *)malloc((strlen(nome_buffer) + 1) * sizeof(char));
        if (!vetor[i].nome)
        {
            return 1;
        }

        strcpy(vetor[i].nome, nome_buffer);

        printf("Digite a matricula: ");
        scanf("%d", &vetor[i].matricula);

        printf("Digite o tempo: ");
        scanf("%d", &vetor[i].tempo);
    }

    for (int i = 0; i < n; i++)
    {
        indices[i] = &vetor[i];
        indices_nome[i] = &vetor[i];
        indices_ranking[i] = &vetor[i];
    }

    // comparar pelo nome - ainda não testado
    /*
    for (int i = 0; i < n - 1; i++)
    {
        if (strcmp(indices_nome[i + 1]->nome, indices_nome[i]->nome) == -1)
        {
            vAtletas *temp = indices_nome[i + 1];
            indices_nome[i + 1] = indices_nome[i];
            indices_nome[i] = temp;
        }
        else if (strcmp(indices_nome[i + 1]->nome, indices_nome[i]->nome) == 0)
        {
            if (indices_nome[i + 1]->matricula > indices_nome[i]->matricula)
            {

                vAtletas *temp = indices_nome[i + 1];
                indices_nome[i + 1] = indices_nome[i];
                indices_nome[i] = temp;
            }
        }
    }
    */
    /*
        for (i = 0; i < tamanho - 1; i++)
        {
            min = i;
            for (j = i + 1; j < tamanho; j++)
            {
                if (valores[j] < valores[min])
                {
                    min = j;
                    aux = valores[i];
                    valores[i] = valores[min];
                    valores[min] = aux;
                }
            }

        }


         */

    // Ordenar por ranking
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;

        for (int j = i + 1; j < n; j++)
        {
            if (indices_ranking[j]->matricula < indices_ranking[min]->matricula)
            {
                min = j;
            }
            vAtletas *temp = indices_ranking[i];
            indices_ranking[i] = indices_ranking[min];
            indices_ranking[min] = temp;
        }
    }

    printf("\n--- Ordem Original ---\n");
    for (int i = 0; i < n; i++)
    {
        printf("Nome: %s, Matricula: %d, tempo:  %d\n", indices[i]->nome, indices[i]->matricula, indices[i]->tempo);
    }

    printf("\n--- Ordem Ranking ---\n");
    for (int i = 0; i < n; i++)
    {
        printf("Nome: %s, Matricula: %d, tempo:  %d\n", indices_ranking[i]->nome, indices_ranking[i]->matricula, indices_ranking[i]->tempo);
    }

    for (int i = 0; i < n; i++)
    {
        free(vetor[i].nome);
    }
    free(vetor);
    free(indices);
    free(indices_ranking);
    free(indices_nome);
    return 1;
}