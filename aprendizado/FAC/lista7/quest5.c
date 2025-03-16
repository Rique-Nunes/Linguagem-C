/*Uma pesquisa foi feita
coletando informações (idade, altura e
peso) de um grupo de pessoas.
Pede-se a implementação de um programa
que proceda com a leitura de tais
informações (até que o usuário opte por
concluir a entrada de dados) e calcule:
 A quantidade de pessoas com idade
superior a 50 anos;
 A média de altura das pessoas com mais de
80 kg;
 O maior peso dentre as pessoas acima de
1.65 m de altura e com idade inferior a 30
anos.*/

#include <stdio.h>

void main()
{
    int idade, idade_50, qtd_peso;
    float altura, peso, altura_media, maior_peso;
    char teste = 'n';
    do
    {
        printf("digite a sua idade: ");
        scanf("%d", &idade);
        printf("digite a altura: ");
        scanf("%f", &altura);
        printf("digite o peso: ");
        scanf("%f", &peso);

        if (idade > 50)
        {
            idade_50 += 1;
        }
        if (peso > 80)
        {
            altura_media += altura;
            qtd_peso += 1;
        }

        if (altura > 1.65 && idade < 30 && peso > maior_peso)
        {
            maior_peso = peso;
        }
        printf("quer parar: ");
        scanf(" %c", &teste);
    } while (teste == 'n');

    printf("A quantidade de pessoas com idade superior a 50 anos %d", idade_50);
    printf("A média de altura das pessoas com mais de 80 kg %f", altura_media / qtd_peso);
    printf("O maior peso dentre as pessoas acima de 1.65 m de altura e com idade inferior a 30 anos. %f", maior_peso);
}