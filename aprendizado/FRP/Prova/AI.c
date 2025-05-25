#include <stdio.h>

int main()
{
    int mat[3][3];
    int i, j, num = 1;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            mat[i][j] = num++;
        }
    }

    for (i = 0; i < 3; i++)
    {
        int linha = 0;
        for (j = 0; j < 3; j++)
        {
            linha += mat[i][j];
        }
        printf("Linha %d: %d\n", i, linha);
    }
    return 0;
}