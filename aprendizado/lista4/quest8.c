#include "stdio.h"
#include "stdlib.h"

void main()
{
    float salario, salario_homem;
    int matricula, matricula_novo = 0, matricula_antigo = 0, idade, idade_novo = 150, idade_antigo = 0, tempo, idade21 = 0, genero_fem = 0, genero_masc = 0;
    char genero;

    for (int i = 0; i <= 1; i++)
    {
        printf("Comecando o cadastro, digite sua matricula: ");
        scanf("%d", &matricula);
        printf("digite seu genero (m/f): ");
        scanf(" %c", &genero);
        printf("digite sua idade: ");
        scanf("%d", &idade);
        printf("digite o salario: ");
        scanf("%f", &salario);
        printf("tempo na empresa em anos: ");
        scanf("%d", &tempo);

        if (idade < 21)
        {
            idade21 += 1;
        }
        if (genero == 'f')
        {
            genero_fem += 1;
        }
        else
        {
            salario_homem += salario;
            genero_masc += 1;
        }
        if (idade > idade_antigo)
        {
            matricula_antigo = matricula;
            idade_antigo = idade;
        }
        if (idade < idade_novo)
        {
            matricula_novo = matricula;
            idade_novo = idade;
        }
    }
    printf("\nquantidade com menos de 21 anos: %d\n", idade21);
    printf("quantidade do genero feminino: %d\n", genero_fem);
    printf("media salarial dos homens: %.2f\n", salario_homem / genero_masc);
    printf("matricula do mais novo: %d, matricula do mais antigo: %d\n", matricula_novo, matricula_antigo);
}