/*Desenvolver uma função que, dado um arquivo
texto, verifique o número de letras existentes
no mesmo (entendendo que no arquivo podem
existir letras, algarismos e símbolos).*/

/*
   FAETERJ-Rio
   Fundamentos de Programação - FPR - Manhã
   Professor Leonardo Vianna
   Data: 29/05/2025

   Lista de Exercícios XII:

   Questão 03:
   Desenvolver uma função que, dado um arquivo texto, verifique o
   número de letras existentes no mesmo (entendendo que no arquivo
   podem existir letras, algarismos e símbolos).
*/

// importação de bibliotecas
#include <stdio.h>

// Protótipos das funções
int numLetras(char nomeArq[]);

// main
void main()
{
    // declaração de variáveis
    int resultado;
    char nomeArquivo[30];

    // lendo o nome do arquivo
    printf("Nome do arquivo: ");
    gets(nomeArquivo);

    // chamando a função
    resultado = numLetras(nomeArquivo);

    // exibindo o resultado
    switch (resultado)
    {
    case -1:
        printf("\n\nErro na abertura do arquivo!\n");
        break;

    case 0:
        printf("\n\nArquivo vazio!\n");
        break;

    default:
        printf("\n\nForam encontradas %d letras no arquivo %s\n", resultado, nomeArquivo);
    }
}

// implementação das funções
int numLetras(char nomeArq[])
{
    // declaração de variáveis
    int cont = 0;
    char caracter;
    FILE *arq;

    // abrindo o arquivo
    arq = fopen(nomeArq, "r");

    // verificando se houve erro na abertura do arquivo
    if (!arq) // ou   if (arq == NULL)
    {
        return -1;
    }
    else
    {
        while (fscanf(arq, "%c", &caracter) != EOF)
        {
            // verificando se o caracter lido é uma letra
            caracter = toupper(caracter);
            if ((caracter >= 'A') && (caracter <= 'Z'))
            {
                cont++;
            }
        }

        // fechando o arquivo
        fclose(arq);

        // retornando a quantidade de caracteres
        return cont;
    }
}