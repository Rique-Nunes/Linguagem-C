#include "stdio.h"
#include "stdlib.h"

void main()
{
    char genero, resposta;
    int porcent_masc, porcent_fem, quanti_sim = 0, quanti_nao = 0, quanti_masculino = 0, quanti_feminino = 0, x;
    printf("quantas pessoas participaram");
    scanf("%d", &x);

    for (int i = 1; i <= x; i++)
    {
        printf("Digite o genero: (M/F) ");
        scanf(" %c", &genero);
        printf("Digite a resposta: (G/N) ");
        scanf(" %c", &resposta);
        if (resposta == 'g')
        {
            quanti_sim += 1;
            if (genero == 'm')
            {
                quanti_masculino += 1;
            }
            else
            {
                quanti_feminino += 1;
            }
        }
        else if (resposta == 'n')
        {
            quanti_nao += 1;
        }
        else
        {
            printf("erro\n");
        }
    }
    printf("Numero de pessoas que gostaram: %d \n", quanti_sim);
    printf("Numero de pessoas que nao gostaram: %d \n", quanti_nao);
    porcent_masc = quanti_masculino / ((quanti_feminino + quanti_masculino)*100);
    porcent_fem = quanti_feminino/ ((quanti_masculino + quanti_feminino)*100);
    if (porcent_masc > porcent_fem)
    {
        printf("maior aceitacao do genero masculino");
    }
    else
    {
        printf("maior aceitacao do genero feminino");
    }
    printf("porcentagem masculina: %d", porcent_masc):
    printf("porcentagem feminina: %d", porcent_fem);
}