#include "stdio.h"
#include "stdlib.h"

void main()
{
    int positivo, negativo;

    for (int i = 1; i <= 50; i++)
    {
        if (i % 2 == 0)
        {
            printf("%d\n", i * -1);
        }
        else
        {
            printf("%d\n", i);
        }
    }
}