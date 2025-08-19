#include <stdio.h>
#include <math.h>

int main()
{
    int n1 = 0, n2, c;

    int p1 = 0, d1, p2 = 0, d2;

    do
    {
        printf("entre com um valor com 2 a 5 algarismos: ");
        scanf("%d", &n1);
    } while (n1 < 10 || n1 > 99999);

    if (n1 < 100)
    {
        c = 2;
    }
    else if (n1 < 1000)
    {
        c = 3;
    }
    else if (n1 < 10000)
    {
        c = 4;
    }
    else
    {
        c = 5;
    }

    d1 = n1 % 10;
    d2 = n1 % 10;
    n2 = 0; // Inicializa n2 com 0

    for (int i = c; i > 0; i--)
    {                                                 // Corrigido: Loop de c até 1
        int digito = (n1 / (int)pow(10, i - 1)) % 10; // Extrai o dígito na posição i

        if (digito > d1)
        {
            d1 = digito;
            p1 = i - 1;
        }
        if (digito < d2)
        {
            d2 = digito;
            p2 = i - 1;
        }
    }

    // Reconstruindo n2 dígito a dígito
    for (int i = c; i > 0; i--)
    {
        int digito = (n1 / (int)pow(10, i - 1)) % 10;
        if (i - 1 == p1)
        {
            n2 = n2 * 10 + d2; // Substitui o maior dígito pelo menor
        }
        else if (i - 1 == p2)
        {
            n2 = n2 * 10 + d1; // Substitui o menor dígito pelo maior
        }
        else
        {
            n2 = n2 * 10 + digito; // Mantém os outros dígitos
        }
    }

    printf("Número original (n1): %d\n", n1);
    printf("Número com dígitos trocados (n2): %d\n", n2);

    return 0;
}