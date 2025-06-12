#include <stdio.h>
#include <stdlib.h>
// main
void main()
{
    // declara��o de vari�veis
    int **m;

    m = (int **)malloc(3 * sizeof(int *));

    for (int i = 0; i < 5; i++)
    {
        m[i] = (int *)malloc(3 * sizeof(int));
    }
}