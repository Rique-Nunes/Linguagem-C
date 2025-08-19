/*A Direção de uma Faculdade decidiu fazer uma pesquisa com uma amostra de X pessoas,
incluindo professores e funcionários.
Cada um informou se é professor (código 1) ou funcionário (código 2), idade, escolaridade
(I – fundamental incompleto,
F – fundamental completo, E – ensino médio, G – graduação, P – Especialização, M – Mestrado,
 D – Doutorado).
Desenvolver um programa que obtenha esses dados e, ao final, exiba:
a. Percentual de professores que são mestres ou doutores;
b. Quantidade de Especialistas;
c. Média de idade dos que não possuem o ensino fundamental completo.*/

#include "stdio.h"

void main()
{
    int profissao, idade, qtd_especialista = 0, qtd_incompleto = 0, qtd_professor = 0;
    float qtd_doutor = 0, media_idade = 0;
    char escolaridade = 'a', teste = 'N';

    while (teste == 'N')
    {
        printf("digite (1) para professor e (2) para funcionario: ");
        scanf("%d", &profissao);
        printf("digite a idade: ");
        scanf("%d", &idade);
        printf("digite a escolaridade (I) fundamental incompleto, (F)  fundamental completo, (E)  ensino medio, (G)  graduacao, (P)  Especializacao, (M)  Mestrado, (D)  Doutorado: ");
        scanf(" %c", &escolaridade);
        if (profissao == 1)
        {
            qtd_professor += 1;
        }

        if ((escolaridade == 'M') || (escolaridade == 'D'))
        {
            qtd_doutor += 1;
        }
        if (escolaridade == 'P')
        {
            qtd_especialista += 1;
        }
        if (escolaridade == 'I')
        {
            media_idade += idade;
            qtd_incompleto += 1;
        }
        printf("quer parar o programa? (S/N)");
        scanf(" %c", &teste);
    }
    printf("percentual de professores que sao mestres ou doutores: %.2f", (qtd_professor * 100) / qtd_doutor);
    printf("quantidade de especialistas: %d", qtd_especialista);
    printf("media de idade dos que nao possuem ensino fundamental completo: %.2f", media_idade / qtd_incompleto);
}