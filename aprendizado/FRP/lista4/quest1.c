/*Implementar uma função que, dada uma string
s, determine a quantidade de caracteres
distintos em s.*/

#include <stdio.h>
#include <string.h>

int qtd_carecter(char string[]);

void main()
{
    char strang[10];
    int resultado;
    printf("Digite uma string: ");
    gets(strang);
    resultado = qtd_carecter(strang);
    printf("quantidade de caracteres e: %d\n", resultado);
}

int qtd_carecter(char string[])
{
    int i, cont = 0, tamanho = strlen(string);
    for (i = 0; i < tamanho; i++)
    {
        if (string[i] != '\0')
        {
            cont++;
            for (int j = i + 1; j < tamanho; j++)
            {
                if (string[j] == string[i])
                {
                    string[j] = '\0';
                }
            }
        }
    }
    return cont;
}

/*
#include <stdio.h>
#include <string.h>

int qtd_caracteres_sem_repeticao(char string[]) {
    int i, j, tamanho = strlen(string), cont = 0;

    for (i = 0; i < tamanho; i++) {
        int repetido = 0;

        for (j = 0; j < tamanho; j++) {
            if (i != j && string[i] == string[j]) {
                repetido = 1;
                break;
            }
        }

        if (!repetido) {
            cont++;
        }
    }
    return cont;
}

int main() {
    char string1[] = "abracadabra";
    char string2[] = "banana";
    char string3[] = "a";
    char string4[] = "";
    char string5[] = "aabbc";

    printf("'%s': %d caracteres sem repetição\n", string1, qtd_caracteres_sem_repeticao(string1)); // Saída: 5 (abrcd)
    printf("'%s': %d caracteres sem repetição\n", string2, qtd_caracteres_sem_repeticao(string2)); // Saída: 3 (ban)
    printf("'%s': %d caracteres sem repetição\n", string3, qtd_caracteres_sem_repeticao(string3)); // Saída: 1 (a)
    printf("'%s': %d caracteres sem repetição\n", string4, qtd_caracteres_sem_repeticao(string4)); // Saída: 0
    printf("'%s': %d caracteres sem repetição\n", string5, qtd_caracteres_sem_repeticao(string5)); // Saída: 3 (abc)

    return 0;
}
*/
