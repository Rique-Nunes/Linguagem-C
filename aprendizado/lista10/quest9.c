/*Implementar a função de inserção de
determinado elemento em um vetor ordenado
crescentemente (dica: utilizar a função do item
08 para auxiliar).
*/
#include <stdio.h>
void inserir(float lista[], float lista_nova[], int tamanho, float numero);

void main()
{
    float lista[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9}, lista_nova[9 + 1], num;

    printf("digite o numero: ");
    scanf("%f", &num);

    inserir(lista, lista_nova, 9, num);

    for (int i = 0; i < 10; i++)
    {
        printf("%.2f\n", lista_nova[i]);
    }
}

void inserir(float lista[], float lista_nova[], int tamanho, float numero)
{
    int i, j;
    for (i = 0; i < tamanho && lista[i] < numero; i++)
    {
        // 0 1 2 3     4 5
        // 0 1 2 3 3.5 4 5
        lista_nova[i] = lista[i];
    }
    lista_nova[i] = numero;
    
    for (j = i; j < tamanho; j++)
    {
        lista_nova[j + 1] = lista[j];
    }
}