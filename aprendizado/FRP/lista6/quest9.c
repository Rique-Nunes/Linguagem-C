/*Desenvolver uma função recursiva que, dado um vetor V com quant números inteiros,
determine se seus elementos estão dispostos
de maneira a representar uma progressão aritmética.
*/
#include <stdio.h>
#include <string.h>

int aritmetica(int quant, int vet[quant], int *testador, int resultado);

void main()
{
    int testador, resultado;
    int string[5] = {2,4,6,8,10}; // String de teste
    int tamanho = 5;
    testador = string[tamanho - 1] - string[tamanho - 2];
    resultado = aritmetica(tamanho - 1, string, &testador, 1);
}

int aritmetica(int quant, int vet[quant], int *testador, int resultado)
{
    if (quant < 1)
    {
        return 1;
    }
    resultado = aritmetica(quant, vet, *testador, resultado);
    if(resultado == 1){
    if (vet[quant] - vet[quant - 1] == *testador)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
    
}
