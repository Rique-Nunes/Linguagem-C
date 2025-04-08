/*Desenvolver uma função recursiva que, dado um vetor V com quant números inteiros,
determine se seus elementos estão dispostos
de maneira a representar uma progressãoaritmética.
*/
#include <stdio.h>
#include <string.h>

void aritmetica(int quant, int vet[quant], int *testador);

void main()
{
    int testador;
    char string[] = "avenida"; // String de teste
    int tamanho = strlen(string);
    inverte_string(string, tamanho - 1);
}

void aritmetica(int quant, int vet[quant], int *testador)
{
    if (quant < 1)
    {
        return 0;
    }
    aritmetica(quant - 1, vet, *testador);
    if (vet[quant] - vet[quant - 1] == *testador)
    {
        *testador = 1;
    }
    else
    {
        
    }
    
}
