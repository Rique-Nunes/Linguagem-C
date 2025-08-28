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
vAtletas *cadastrar_atletas(int n);

int main()
{
    int opcao = 0, n = 0, trocou = 1;
    vAtletas *vetor = NULL;
    vAtletas **indices = NULL;
    vAtletas **indices_nome = NULL;
    vAtletas **indices_ranking = NULL;

    do
    {
        printf("\n===== MENU DE ATLETAS =====\n");
        printf("1. Cadastrar novos atletas\n");
        printf("2. Ver ordem de cadastro\n");
        printf("3. Ver ranking por tempo\n");
        printf("4. Ver ordem alfabetica\n");
        printf("5. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("Quantos atletas ira cadastrar? ");
            scanf("%d", &n);

            if (n > 0)
            {
                vetor = cadastrar_atletas(n);
                if (vetor == NULL)
                    return 0;

                indices_nome = (vAtletas **)malloc(n * sizeof(vAtletas *));
                indices_ranking = (vAtletas **)malloc(n * sizeof(vAtletas *));

                for (int i = 0; i < n; i++)
                {
                    indices_nome[i] = &vetor[i];
                    indices_ranking[i] = &vetor[i];
                }
            }
            break;

        case 2:
            printf("\n--- Ordem de Cadastro ---\n");
            for (int i = 0; i < n; i++)
            {
                printf("Nome: %s, Matricula: %d, tempo: %d\n", vetor[i].nome, vetor[i].matricula, vetor[i].tempo);
            }
            break;

        case 3:
            for (int i = 0; i < n - 1; i++)
            {
                int min = i;
                for (int j = i + 1; j < n; j++)
                {
                    if (indices_ranking[j]->tempo < indices_ranking[min]->tempo)
                    {
                        min = j;
                    }
                }
                if (min != i)
                {
                    vAtletas *temp = indices_ranking[i];
                    indices_ranking[i] = indices_ranking[min];
                    indices_ranking[min] = temp;
                }
            }
            printf("\n--- Ordem por Ranking (Tempo) ---\n");
            for (int i = 0; i < n; i++)
            {
                printf("Nome: %s, Matricula: %d, tempo: %d\n", indices_ranking[i]->nome, indices_ranking[i]->matricula, indices_ranking[i]->tempo);
            }
            break;

        case 4:
            while (trocou == 1)
            {
                trocou = 0;
                for (int i = 0; i < n - 1; i++)
                {
                    if (strcmp(indices_nome[i]->nome, indices_nome[i + 1]->nome) > 0)
                    {
                        vAtletas *temp = indices_nome[i];
                        indices_nome[i] = indices_nome[i + 1];
                        indices_nome[i + 1] = temp;
                        trocou = 1;
                    }
                }
            }
            printf("\n--- Ordem Alfabetica por Nome ---\n");
            for (int i = 0; i < n; i++)
            {
                printf("Nome: %s, Matricula: %d, tempo: %d\n", indices_nome[i]->nome, indices_nome[i]->matricula, indices_nome[i]->tempo);
            }
            break;

        case 5:
            printf("Saindo...\n");
            break;

        default:
            printf("\nOpcao invalida\n");
            break;
        }

    } while (opcao != 5);

    for (int i = 0; i < n; i++)
    {
        free(vetor[i].nome);
    }
    free(vetor);
    free(indices_ranking);
    free(indices_nome);

    printf("Programa finalizado.\n");
    return 1;
}

vAtletas *cadastrar_atletas(int n)
{
    vAtletas *vetor = (vAtletas *)malloc(n * sizeof(vAtletas));
    if (!vetor)
    {
        printf("Erro de alocação no vetor principal!\n");
        return NULL;
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
            for (int j = 0; j < i; j++)
                free(vetor[j].nome);
            free(vetor);
            return NULL;
        }
        strcpy(vetor[i].nome, nome_buffer);

        printf("Digite a matricula: ");
        scanf("%d", &vetor[i].matricula);

        printf("Digite o tempo: ");
        scanf("%d", &vetor[i].tempo);
    }
    return vetor;
}