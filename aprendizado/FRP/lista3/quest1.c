/*
    FAETERJ-Rio
    Fundamentos de Programação - FPR
    Turno: Manhã

    Data: 19/03/2025

    Lista de Exercícios VII (Strings)

    Questão 01:
    Suponha que não existissem as funções strlen, strcpy, strcat
    e strcmp. Pede-se, então, a implementação de funções que
    tenham o mesmo objetivo daquelas.
*/

// importação de bibliotecas
#include <stdio.h>

// protótipos das funções
int strTamanho(char str[]);
void strCopia(char str1[], char str2[]);
void strConcatenacao(char str1[], char str2[]);
int strComparacao(char str1[], char str2[]);

// main
void main()
{
    // declaração de variáveis
    char string[30], nova[30];

    // lendo a string
    printf("Entre com uma string: ");
    gets(string);

    // chamando a função 'strTamanho'
    printf("\n\nTamanho da string %s: %d\n\n", string, strTamanho(string));

    // copiando 'string' para 'nova'
    strCopia(nova, string);

    // exibindo as duas strings
    printf("\n\nstring: %s    nova: %s\n\n", string, nova);

    // concatenando duas strings
    strConcatenacao(nova, "ALGORITMO");

    // exibindo as duas strings após a concatenação
    printf("\n\nstring: %s    nova: %s\n\n", string, nova);
}

// implementação das funções
/*int strTamanho (char str[])
{
    //declaração de variáveis
    int i, cont=0;

    //percorrendo a string
    for (i=0;str[i]!='\0';i++)
    {
        cont++;
    }

    //retornando a quantidade de caracteres
    return cont;
}*/

int strTamanho(char str[])
{
    // declaração de variáveis
    int i;

    // percorrendo a string
    for (i = 0; str[i] != '\0'; i++)
        ;

    // retornando a quantidade de caracteres
    return i;
}

void strCopia(char str1[], char str2[])
{
    // declaração de variáveis
    int i;

    // percorrendo a string 'str2'
    for (i = 0; str2[i] != '\0'; i++)
    {
        str1[i] = str2[i];
    }

    // finalizando 'str1'
    str1[i] = '\0';
}

void strConcatenacao(char str1[], char str2[])
{
    // declaração de variáveis
    int i, j;

    // percorrendo a string 'str2'
    for (i = 0, j = strTamanho(str1); str2[i] != '\0'; i++, j++)
    {
        str1[j] = str2[i];
    }

    // finalizando 'str1'
    str1[j] = '\0';
}

int strComparacao(char str1[], char str2[])
{
    // declaração de variáveis
    int i;

    // comparando os caracteres das duas strings
    // for (i=0;(str1[i]==str2[i]) && (str1[i] != '\0') && (str2[i] != '\0'));i++)
    for (i = 0; (str1[i] == str2[i]) && (str1[i]) && (str2[i]); i++);

    return str1[i] - str2[i];
}