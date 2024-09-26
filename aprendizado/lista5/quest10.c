/*
Foi feita uma pesquisa entre os habitantes
de uma região e coletados os dados de
altura e gênero das pessoas. Faça um
programa que leia as informações de 50
pessoas e informe:
 a maior e a menor alturas
encontradas;
 a média de altura das mulheres;
 a média de altura da população;
 o percentual de homens na população.*/
#include "stdio.h"
#include "stdlib.h"

void main()
{
    float altura, cont_mulher = 0, media_mulher = 0, media_populacao = 0, percetual_homens = 0;
    char sexo = 'a';

    for (int i = 1; i <= 5; i++)
    {
        printf("digite o sexo: (f/m)");
        scanf("%s", &sexo);
        printf("digite a altura: ");
        scanf("%f", &altura);

        if (sexo == 'f')
        {
            cont_mulher += 1;
            media_mulher += altura;
        }
        else
        {
            percetual_homens += 1;
        }
        media_populacao += altura;
    }
    printf("media das mulheres: %.2f\n", media_mulher / cont_mulher);
    printf("media da populacao: %.2f\n", media_populacao / (cont_mulher + percetual_homens));
    printf("o percentual de homens %.2f", ((cont_mulher + percetual_homens) / 100) * percetual_homens);
}