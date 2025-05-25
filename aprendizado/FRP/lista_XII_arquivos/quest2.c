/*Desenvolver uma função que, dado um arquivo
texto, verifique o número de vezes que um
determinado caracter aparece no arquivo.*/

#include <stdio.h>

int verificador(char text[], char caractere);

void main()
{
    printf("%d", verificador("teste.txt", '1'));
}
int verificador(char text[], char caractere)
{
    FILE *arq;
    char c;
    int cont = 0;
    arq = fopen(text, "r");

    if (arq == NULL)
    {
        fclose(arq);
        return -1;
    }
    while (fscanf(arq, "%c\n", &c) != EOF)
    {
        if (c == caractere)
        {
            cont++;
        }
    }
    fclose(arq);
    return cont;
}