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
    int qtd_zeros = numero, contador_zero = 0;

    // rodando pelo vetor inteiro
    for (int i = 0; i < tamanho; i++)
    {
        // quero procurar o zero correspondente a posição que o usuário escolheu
        // se ele digitar 1, vai mostrar o subconjunto anterior ao primeiro zero e assim por diante
        if (lista[i] == 0)
        {
            contador_zero += 1;
        }

        if (contador_zero == qtd_zeros)
        {
            // o I está na posição do zero, (3 por exemplo), mais queremos o subconjunto anterior a ele
            // então diminui 1 para iniciar a contagem, temos duas condições um para parar no zero e outra para
            // limitar o tamanho do sub_vetor, o J vai voltando posições até ele representar a posição do zero
            for (int j = i - 1; lista[j] == 0 || indice < 3; j--)
            {
                // isso foi para caso o subconjunto for menor e não incluir o zero
                if (lista[j] != 0)
                {
                    sub_vetor[indice] = lista[j];
                    indice++;
                }
                // sem essa parte se voce escolher o 3° subconjunto (ou outros) iria incluir numeros a mais
                if (lista[j] == 0)
                {
                    break;
                }
            }
            // isso é para não ler o resto da varredura da lista
            break;
        }
    }
    *sub_indice = indice;
    return 1;
}