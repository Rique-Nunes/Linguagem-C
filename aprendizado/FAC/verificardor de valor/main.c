#include <stdio.h>
#include <stdlib.h>
#include "fatorial.h"

int main()
{
    int x, y;
    printf("digite um numero para criar seu fatorial: \n");
    scanf("%d", &x);
    if (x > 0)
    {
        printf("%d, e positivo \n", x);
        y = fatorial(x);
        printf("%d, e seu fatorial \n", y);
    }
    else
    {
        if (x < 0)
        {
            printf("%d e negativo \n", x);
        }
        else
        {
            printf("E zero otário\n");
        }
    }
    system("pause");
    return 0;
}