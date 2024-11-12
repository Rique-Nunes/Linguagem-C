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
int vetorial(int lista[], int numero, int tamanho);

void main()
{

    int numeros[12] = {5, 7, 3, 0, 5, 9, 0, 1, 0, 3, 4, 8};
    vetorial(numeros, 2, 12);
}

int vetorial(int lista[], int numero, int tamanho)
{
    int sub_vetor[3], indice = 0;
    int qtd_zeros = numero, contador_zero = 0;
    for (int i = 0; i < tamanho; i++)
    {
        if (lista[i] == 0)
        {
            contador_zero += 1;
        }
        if (contador_zero == qtd_zeros)
        {
            for (int j = i - 1; lista[j] == 0 || indice <= 2; j--)
            {
                if (lista[j] != 0)
                {
                    sub_vetor[indice] = lista[j];
                    indice++;
                }
                if (lista[j] == 0)
                {
                    break;
                }
            }
            break;
        }
    }
    printf("Sub-vetor:\n");
    for (int h = 0; h < indice; h++)
    {
        printf("%d\n", sub_vetor[h]);
    }
    /*
    for (int i = 0; i <= 2; i++) {
        lista[i] = sub_vetor[i];
    }
    */
    return 1;
}