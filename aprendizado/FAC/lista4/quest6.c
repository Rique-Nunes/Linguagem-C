#include <stdio.h>
#include <stdlib.h>

void main()
{
    int num, i, teste, digito1, digito2;

    printf("Digite um numero: ");
    scanf("%d", &num);

    if (num <= 18)
    {
        for (i = 1; i <= 99; i++)
        {
            digito1 = i / 10;
            digito2 = i % 10;
            teste = digito1 + digito2;

            if (teste == num)
            {
                printf("%d\n", i);
            }
        }
    }
    else
    {
        printf("Numero errado\n");
    }
}