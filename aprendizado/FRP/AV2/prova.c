#include <stdio.h>
#include <string.h>

// Sua struct
typedef struct
{
    int status;
    char curso[30];
    char periodo[20];
} tsalas;

int exibir(int qtd_andar, int qtd_salas, int qtd_turno, tsalas salas[qtd_andar][qtd_salas][qtd_turno]);

void main()
{
    tsalas salas[10][8][3];
    int i, j, k;

    printf("--- Populando dados de exemplo ---\n");
    for (i = 0; i < 10; i++) // Andares
    {
        for (j = 0; j < 8; j++) // Salas
        {
            // Turno Manhã (k=0)
            salas[i][j][0].status = 1;
            strcpy(salas[i][j][0].curso, "Engenharia de Software");
            strcpy(salas[i][j][0].periodo, "Manha");

            // Turno Tarde (k=1)
            salas[i][j][1].status = 0;
            strcpy(salas[i][j][1].curso, "Ciencia da Computacao");
            strcpy(salas[i][j][1].periodo, "Tarde");

            // Turno Noite (k=2)
            salas[i][j][2].status = 1;
            strcpy(salas[i][j][2].curso, "Analise de Sistemas");
            strcpy(salas[i][j][2].periodo, "Noite");
        }
    }
    printf("Dados populados com sucesso!\n\n");

    printf("--- Testando a funcao exibir --- %d\n", exibir(10, 8, 3, salas));
}

int exibir(int qtd_andar, int qtd_salas, int qtd_turno, tsalas salas[qtd_andar][qtd_salas][qtd_turno])
{
    int i, j, k;

    for (i = 0; i < qtd_andar; i++)
    {
        for (j = 0; j < qtd_salas; j++)
        {
            for (k = 0; k < qtd_turno; k++)
            {
                printf("sala: %d, %d andar, turno: %s\n", j, i, salas[i][j][k].periodo);
            }
        }
    }
    return 1;
}