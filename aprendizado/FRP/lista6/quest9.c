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
    int string[5] = {2, 3, 6, 8, 10}; // String de teste
    int tamanho = 5; //o tamanho real é 6 ai que bugou tudo
    testador = string[tamanho - 1] - string[tamanho - 2];
    resultado = aritmetica(tamanho - 1, string, &testador, 1);
    printf("%d", resultado);
}

int aritmetica(int quant, int vet[quant], int *testador, int resultado)
{
    if (quant < 1)
    {
        return 1;
    }
    resultado = aritmetica(quant - 1, vet, testador, resultado); //testador aqui é variavel e não ponteiro
    if (resultado == 1)
    {
        if (vet[quant] - vet[quant - 1] == *testador)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else //else para quando o primeiro return de 0 acontecer nem precisa testar os outros
    {
        return 0;
    }
}
