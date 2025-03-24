// Implementar uma função que, dadas duas
// strings s1 e s2, crie uma nova string – s3 –
// contendo todos os caracteres de s1 que não estejam em s2.
// Nota :em s3, não devem existir caracteres repetidos.

#include <stdio.h>
#include <string.h>

void transformador(char s1[], char s2[], char s3[]);
void formatador(char s1[]);
void resultado(char s1[]);

void main()
{
    char s1[100], s2[100], s3[100];
    printf("Digite a primeira string: ");
    gets(s1);
    printf("Digite a segunda string: ");
    gets(s2);
    transformador(s1, s2, s3);
    resultado(s3);
}

void formatador(char s1[])
{
    int i, tamanho = strlen(s1);
    for (i = 0; i < tamanho; i++)
    {
        if (s1[i] != '\0')
        {
            for (int j = i + 1; j < tamanho; j++)
            {
                if (s1[j] == s1[i])
                {
                    s1[j] = '\0';
                }
            }
        }
    }
}

void transformador(char s1[], char s2[], char s3[])
{
    int i, j, k, tamanho_s1 = strlen(s1), tamanho_s2 = strlen(s2);
    for (i = 0; i < tamanho_s1; i++)
    {
        for (j = 0; j < tamanho_s2; j++)
        {
            if (s1[i] == s2[j])
            {
                break;
            }
        }
        if (j == tamanho_s2 && s1[i] != '\0')
        {
            s3[k++] = s1[i];
        }
    }

    s3[k] = '\0';
    formatador(s3); 
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
