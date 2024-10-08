/*A prefeitura de uma cidade
fez uma pesquisa com 300 de seus
habitantes, coletando dados sobre o
salário e número de filhos. A prefeitura
deseja saber:
a) média do salário da população;
b) média do número de filhos;
c) maior salário;
d) percentual de pessoas com salário até
R$ 1.000,00. */

#include <stdio.h>

void main()
{
    float salario, media_salario = 0, media_filho = 0, maior_salario = 0, qtd_pessoas, qtd_pessoas_mil;
    int qtd_filho;

    for (int i = 1; i <= 5; i++)
    {
        printf("digite o seu salario: ");
        scanf("%f", &salario);
        printf("digite o numero de filhos: ");
        scanf("%d", &qtd_filho);

        media_salario += salario;
        media_filho += qtd_filho;
        qtd_pessoas += 1;
        if (salario > maior_salario)
        {
            maior_salario = salario;
        }
        if (salario <= 1000)
        {
            qtd_pessoas_mil += 1;
        }
    }
    printf("media de salario: %.2f\n", media_salario / qtd_pessoas);
    printf("media de numero de filhos %.2f\n", media_filho / qtd_pessoas);
    printf("maior salario %.2f\n", maior_salario);
    printf("percentual de pessoas com salario ate mil: %.2f", (qtd_pessoas_mil / qtd_pessoas) * 100);
}