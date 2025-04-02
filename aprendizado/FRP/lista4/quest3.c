// Desenvolver uma função, em C, que, dada uma string s e dada uma posição p desta string,
// crie duas novas strings : s1 com os caracteres de s das posições 0 a p - 1;
// e s2 com os caracteres de s da posição p à última.
// Nota : Caso p seja uma posição inválida,
//  a função deverá retornar o valor 0; caso contrário,
//  procederá com a criação das duas strings e retornará o valor 1.


#include <stdio.h>
#include <string.h>

int criar_strings(char string[], char s2[], char s3[], int p);
void resultado(char s1[]);

void main()
{
    char s1[100], s2[100], s3[100];
    int p, teste;
    printf("Digite a primeira string: ");
    gets(s1);
    printf("digite a posicao");
    scanf("%d", &p);
    teste = criar_strings(s1, s2, s3, p);
    if (teste == 0)
    {
        printf("erro");
    }
    else
    {
        resultado(s2);
        resultado(s3);
    }
}
int criar_strings(char string[], char s2[], char s3[], int p)
{
    int i, j = 0, tamanho = strlen(string);
    if (p > tamanho - 1)
    {
        return 0;
    }
    for (i = 0; i < tamanho; i++)
    {
        if (i < p)
        {
            s2[i] = string[i];
        }
        else
        {
            s3[j++] = string[i];
        }
    }
}

void resultado(char s1[])
{
    int j;
    for (j = 0; j < strlen(s1); j++)
    {
        printf("%c ", s1[j]);
    }
    printf("\n");
}
