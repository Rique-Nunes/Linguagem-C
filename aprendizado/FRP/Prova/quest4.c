/*Dada uma string s, contendo apenas letras,
desenvolver uma função recursiva que desloque as
vogais de s para o seu início (e, consequentemente,
as consoantes para o seu final).
Exemplo:
s (inicialmente): ALGORITMOS
s (após a função): AOIOLGRTMS
Observação: a ordem das vogais e consoantes em s, ao
final, não precisa ser necessariamente a mesma da string
original.*/

#include "stdio.h"
#include "string.h"

void trocando_vogal(char string[], int i, int tamanho);

void main()
{
    char teste[11] = {'A', 'L', 'G', 'O', 'R', 'I', 'T', 'M', 'O', 'S', '\0'};
    printf("%s \n", teste);
    trocando_vogal(teste, 0, 11);
    printf("%s \n", teste);
}

void trocando_vogal(char string[], int i, int tamanho)
{
    if (i >= tamanho)
    {
        return;
    }
    if (string[i] != 'A' && string[i] != 'E' && string[i] != 'I' && string[i] != 'O' && string[i] != 'U')
    {
        for (int j = i + 1; j < tamanho; j++)
        {
            if (string[j] == 'A' || string[j] == 'E' || string[j] == 'I' || string[j] == 'O' || string[j] == 'U')
            {

                char temp = string[i];
                string[i] = string[j];
                string[j] = temp;
                break;
            }
        }
    }
    trocando_vogal(string, i + 1, tamanho);
}