#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n1, n2, temp, digito, maior, menor, pos_maior, pos_menor;

    do
    {
        printf("Digite um número inteiro não negativo (2 a 5 algarismos): ");
        scanf("%d", &n1);

        if (n1 < 10 || n1 > 99999)
        {
            printf("Número inválido! Digite um número entre 10 e 99999.\n");
        }
    } while (n1 < 10 || n1 > 99999);
    //determina o maior e o menor
    temp = n1;
    maior = temp % 10;
    menor = temp % 10;
    pos_maior = 0;
    pos_menor = 0;
    int pos = 0;

    while (temp > 0)
    {
        //vai testando ate achar o maior e o menor
        digito = temp % 10;
        if (digito > maior)
        {
            maior = digito;
            //posicao do digito maior
            pos_maior = pos;
        }
        if (digito < menor)
        {
            menor = digito;
            // posicao do digito menor
            pos_menor = pos;
        }
        temp /= 10;
        //posicoes total
        pos++;
    }

    
    n2 = 0;
    temp = n1;
    for (int i = pos - 1; i >= 0; i--)
    {
        digito = temp % 10;
        //se ele for a posicao maior usa o digito menor
        if (i == pos_maior)
        {
            n2 = n2 * 10 + menor;
        }
        //se ele for da posicao menor usa o digito maior
        else if (i == pos_menor)
        {
            n2 = n2 * 10 + maior;
        }
        //senao só coloca ele na posicao
        else
        {
            n2 = n2 * 10 + digito;
        }
        temp /= 10;
    }

    printf("Número original (n1): %d\n", n1);
    printf("Número com dígitos trocados (n2): %d\n", n2);

    return 0;
}