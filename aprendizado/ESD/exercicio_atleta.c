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

vAtletas *cadastrar_atletas_inicial(int n);
void preencher_novos_atletas(vAtletas *vetor, int inicio, int fim);

int main()
{
    int opcao = 0, n_total = 0, trocou = 1;
    vAtletas *vetor = NULL;
    vAtletas **indices_nome = NULL;
    vAtletas **indices_ranking = NULL;

    do
    {
        printf("\n1. Cadastrar/Adicionar atletas\n");
        printf("2. Ver ordem de cadastro\n");
        printf("3. Ver ranking por tempo\n");
        printf("4. Ver ordem alfabetica\n");
        printf("5. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
        {
            int n_adicionar;
            printf("Quantos atletas deseja adicionado? ");
            scanf("%d", &n_adicionar);

            if (n_adicionar <= 0)
                break;

            int novo_tamanho_total = n_total + n_adicionar;

            if (n_total == 0)
            {
                vetor = cadastrar_atletas_inicial(n_adicionar);
                if (vetor == NULL)
                    return 1;
            }
            else
            {
                vAtletas *temp_vetor = realloc(vetor, novo_tamanho_total * sizeof(vAtletas));
                if (temp_vetor == NULL)
                {
                    printf("Erro ao realocar o vetor de atletas!\n");
                    break;
                }
                vetor = temp_vetor;

                preencher_novos_atletas(vetor, n_total, novo_tamanho_total);
            }

            vAtletas **temp_nome = realloc(indices_nome, novo_tamanho_total * sizeof(vAtletas *));
            vAtletas **temp_ranking = realloc(indices_ranking, novo_tamanho_total * sizeof(vAtletas *));

            if (temp_nome == NULL || temp_ranking == NULL)
            {
                printf("Erro ao realocar os vetores de indices!\n");
                break;
            }
            indices_nome = temp_nome;
            indices_ranking = temp_ranking;

            n_total = novo_tamanho_total;

            for (int i = 0; i < n_total; i++)
            {
                indices_nome[i] = &vetor[i];
                indices_ranking[i] = &vetor[i];
            }
            printf("%d atletas adicionados com sucesso.\n", n_adicionar);
            break;
        }

        case 2:
            printf("\n--- Ordem de Cadastro ---\n");
            for (int i = 0; i < n_total; i++)
            {
                printf("Nome: %s, Matricula: %d, tempo: %d\n", vetor[i].nome, vetor[i].matricula, vetor[i].tempo);
            }
            break;
        case 3:
            for (int i = 0; i < n_total - 1; i++)
            {
                int min = i;
                for (int j = i + 1; j < n_total; j++)
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
            for (int i = 0; i < n_total; i++)
            {
                printf("Nome: %s, Matricula: %d, tempo: %d\n", indices_ranking[i]->nome, indices_ranking[i]->matricula, indices_ranking[i]->tempo);
            }
            break;

        case 4:
            while (trocou == 1)
            {
                trocou = 0;
                for (int i = 0; i < n_total - 1; i++)
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
            for (int i = 0; i < n_total; i++)
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

    if (vetor != NULL)
    {
        for (int i = 0; i < n_total; i++)
        {
            free(vetor[i].nome);
        }
        free(vetor);
        free(indices_ranking);
        free(indices_nome);
    }

    printf("Programa finalizado.\n");
    return 0;
}

vAtletas *cadastrar_atletas_inicial(int n)
{
    vAtletas *vetor = (vAtletas *)malloc(n * sizeof(vAtletas));
    if (!vetor)
        return NULL;

    for (int i = 0; i < n; i++)
    {
        char nome_buffer[100];
        printf("\n--- Atleta %d ---\n", i + 1);
        printf("Digite o nome: ");
        scanf("%s", nome_buffer);
        vetor[i].nome = (char *)malloc((strlen(nome_buffer) + 1) * sizeof(char));
        strcpy(vetor[i].nome, nome_buffer);
        printf("Digite a matricula: ");
        scanf("%d", &vetor[i].matricula);
        printf("Digite o tempo: ");
        scanf("%d", &vetor[i].tempo);
    }
    return vetor;
}

void preencher_novos_atletas(vAtletas *vetor, int inicio, int fim)
{
    for (int i = inicio; i < fim; i++)
    {
        char nome_buffer[100];
        printf("\n--- Atleta %d ---\n", i + 1);
        printf("Digite o nome: ");
        scanf("%s", nome_buffer);
        vetor[i].nome = (char *)malloc((strlen(nome_buffer) + 1) * sizeof(char));
        strcpy(vetor[i].nome, nome_buffer);
        printf("Digite a matricula: ");
        scanf("%d", &vetor[i].matricula);
        printf("Digite o tempo: ");
        scanf("%d", &vetor[i].tempo);
    }
}