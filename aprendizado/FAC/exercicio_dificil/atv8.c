/*Considere que um vetor de inteiros armazene o número 0 em algumas de suas posições objetivando “separar
subconjuntos de valores”, como no exemplo a seguir:

5 7 3 0 5 9 0 1 0 3 4 8
0 1 2 3 4 5 6 7 8 9 10 11

Desenvolver uma função que, dados um vetor como definido anteriormente e um número inteiro n, retorne um
vetor contendo o n-ésimo subconjunto do vetor.
Notas:
1. Caso exista o n-ésimo subconjunto, a função retornará, além do subconjunto, o valor 1; caso contrário,
retornará 0.
2. Apresentar a main chamando a função implementada.*/
#include <stdio.h>
int vetorial(int lista[], int numero, int tamanho, int sub_vetor[], int *sub_indice);

void main()
{
    // variaveis
    int sub, i, numeros[13] = {5, 7, 3, 0, 5, 9, 0, 1, 0, 3, 4, 8, 0}, sub_vetor[3];

    // digitando qual subconjunto ele quer
    printf("digite qual subconjunto voce quer: ");
    scanf("%d", &sub);

    /*função com parametros do vetor principal, o tamanho do vetor principal,
    o sub conjunto escolhido, e retorna o tamanho do sub conjunto como ponteiro*/
    vetorial(numeros, sub, 13, sub_vetor, &i);

    // o resultado
    printf("Sub-vetor:\n");
    for (int h = 0; h < i; h++)
    {
        printf("%d\n", sub_vetor[h]);
    }
}

int vetorial(int lista[], int numero, int tamanho, int sub_vetor[], int *sub_indice)
{
    int indice = 0;
    int contador_zero = 0;

    // rodando pelo vetor inteiro
    for (int i = 0; i < tamanho; i++)
    {
        /*basicamente só vai adicionar ao subvetor[] quando o contador_zero for
        menor ou igual ao número que a pessoa digitou -1, por exemplo se foi 1,
        o contador de zeros vai ser 0 até ele encontrar o primeiro zero e se tornar 1 e parar a condição*/
        if (lista[i] == 0)
        {
            contador_zero++;
        }

        if (contador_zero == numero)
        {
            break;
        }

        if (contador_zero >= numero - 1 && contador_zero < numero)
        {
            if (lista[i] != 0)
            {
                sub_vetor[indice++] = lista[i];
            }
        }
    }
    *sub_indice = indice;
    return 1;
}