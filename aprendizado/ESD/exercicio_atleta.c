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
    int resposta=0, n;
do{

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
        indices[i] = &vetor[i];
        indices_nome[i] = &vetor[i];
        indices_ranking[i] = &vetor[i];
    }

    // Ordenar por nome
    int trocou = 1;
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

    // Ordenar por ranking
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;

        for (int j = i + 1; j < n; j++)
        {
            if (indices_ranking[j]->tempo < indices_ranking[min]->tempo)
            {
                min = j;
            }
            if (min != i)
            {
                vAtletas *temp = indices_ranking[i];
                indices_ranking[i] = indices_ranking[min];
                indices_ranking[min] = temp;
            }
        }
    }
    printf("Bem-vindo ao sistemas");
    scanf("%d", &resposta);

    switch (resposta)
    {
    case 0:
        printf("quantos usuarios ira cadastrar");
        scanf("%d", &n);
        vAtletas *vetor = alocar_struct(n);
    case 1:
       printf("\n--- Ordem Original ---\n");
       for (int i = 0; i < n; i++)
       {
        printf("Nome: %s, Matricula: %d, tempo:  %d\n", indices[i]->nome, indices[i]->matricula, indices[i]->tempo);
        }
        break;
    case 2:
        printf("\n--- Ordem Ranking ---\n");
    for (int i = 0; i < n; i++)
    {
        printf("Nome: %s, Matricula: %d, tempo:  %d\n", indices_ranking[i]->nome, indices_ranking[i]->matricula, indices_ranking[i]->tempo);
    }
    break;
    case 3:
        printf("\n--- Ordem Nome ---\n");
    for (int i = 0; i < n; i++)
    {
        printf("Nome: %s, Matricula: %d, tempo:  %d\n", indices_nome[i]->nome, indices_nome[i]->matricula, indices_nome[i]->tempo);
    }
    break;
    case 4:
        /*
    Filtrar atletas com tempo superior a um limite:
     O usuário informa um tempo limite em minutos.
    */
    int tempo_limite;
    printf("\nDigite o tempo limite em minutos: ");
    scanf("%d", &tempo_limite);

    printf("\n--- Atletas com tempo superior a %d minutos ---\n", tempo_limite);

    for (int j = 0; j < n; j++)
    {
        if (indices_ranking[j]->tempo < tempo_limite)
        {
            printf("Nome: %s, Matricula: %d, tempo:  %d\n", indices_ranking[j]->nome, indices_ranking[j]->matricula, indices_ranking[j]->tempo);
        }
    }
    break;
    case 5: 

    for (int i = 0; i < n; i++)
    {
        free(vetor[i].nome);
    }
    free(vetor);
    free(indices);
    free(indices_ranking);
    free(indices_nome);
    printf("saindo...");
    }

}while(resposta == 5);

return 1;
}

vAtletas* alocar_struct(int n){
    
    vAtletas *vetor = (vAtletas *)malloc(n * sizeof(vAtletas)); // Para os dados
    if (!vetor)
    {
        printf("erro");
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

    return vetor;
}
vAtletas** alocar_struct_atletas(int n, vAtletas *vetor){
    
    vAtletas **indices = (vAtletas **)malloc(n * sizeof(vAtletas *)); // para os ponteiros
    if (!indices)
    {
        free(vetor);
        return 0;
    }
    return **indices;
}
