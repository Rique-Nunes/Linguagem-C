/*a. Captura os valores do teclado e armazenando-os em um vetor
b. Mostre o produto interno dos dois vetores. Esta função deve preencher dois
vetores X e Y com os dados do teclado.
a. Exemplo para vetores que possuem 4 elementos
Exemplo:
X = (1,2,3,4) Y = (4,3,2,1) ⇨ X.Y = 1*4 + 2*3 + 3*2 + 4*1 = 20
c. Exiba um vetor recebido na ordem inversa
d. Exiba os elementos de um vetor recebido das posições pares seguidos das
posições ímpares
e. Recebe um vetor, perguntar ao usuário o número de posição desejada e exibir o
valor da posição. Término: valor de posição inválida
f. Mostrar o maior valor armazenado de um vetor recebido
g. Somar os elementos de um vetor recebido
h. Contar quantos números ímpares tem em um vetor recebido
i. Mostra quais valores são menores que o valor armazenado na última posição do
vetor recebido
j. Mostrar a média dos valores armazenados no vetor recebido
k. Mostrar quantos valores do vetor recebido são menores que a média
l. Mostrar quais valores do vetor recebido são maiores que a média
m. Retornar o número da posição do vetor recebido que armazena um valor rambém recebido*/
#include <stdio.h>

int main()
{
    int *meuvetor;

    meuvetor = criavetor(5);
}

// Captura os valores do teclado e armazenando-os em um vetor
int *criavetor(int quantidade)
{
    int *vetor = (int *)malloc(quantidade * sizeof(int));

    if (vetor == NULL)
    {
        printf("erro");
        return 1;
    }

    return vetor;
}

/* b. Mostre o produto interno dos dois vetores. Esta função deve preencher dois
    vetores X e Y com os dados do teclado.
Exemplo para vetores que possuem 4 elementos
Exemplo : X = (1, 2, 3, 4)Y = (4, 3, 2, 1) ⇨ X.Y = 1 * 4 + 2 * 3 + 3 * 2 + 4 * 1 = 20
*/

void multiplica(int quantidade)
{
    int *vetor1 = (int *)malloc(quantidade * sizeof(int));
    int *vetor2 = (int *)malloc(quantidade * sizeof(int));
    int soma = 0;
    for (int i = 0; i < quantidade; i++)
    {
        printf("preencha vetor1 %d: ", i);
        scanf("%d", vetor1[i]);
    }
    for (int i = 0; i < quantidade; i++)
    {
        printf("preencha vetor2 %d: ", i);
        scanf("%d", vetor2[i]);
    }
    for (int i = 0; i < quantidade; i++)
    {
        printf("multiplicando e somando vetor1 e vetor2 %d: ", i);
        soma += vetor1[i] * vetor2[i];
    }

    printf("resultado: %d", soma);
}

// c.Exiba um vetor recebido na ordem inversa
void vetorinverso(int vetor[], int tamanho)
{
    for (int i = tamanho; i > 0; i--)
    {
        printf("resultado: %d : %d", i, vetor[i]);
    }
}
