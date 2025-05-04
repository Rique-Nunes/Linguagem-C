/*
Suponha a existência de um vetor de tamanho
    TAM,
    cada posição armazenando o nome da
            pessoa e a sua data de
            aniversário(representada por um struct do tipo TData,contendo os campos dia e mes)
.Pede- se o desenvolvimento das seguintes funções :
- Determinar a quantidade de pessoas que
    fazem aniversário no mês M;
- Exibir os nomes de todas pessoas que fazem
    aniversário entre as datas d1 e d2,
    ambas do tipTdatao TData.
*/

#include "stdio.h"
#include "string.h"

typedef struct
{
    int dia;
    int mes;
} Tniver;
typedef struct
{
    char nome[20];
    Tniver aniversario;
} Tdados;
int qtd_aniversario(Tdados lista[], int tamanho, int mes);
void nomes_aniversario(Tdados lista[], int tamanho, int d1, int d2);
void main()
{
    Tdados lista[5] = {
        {"Ana", {12, 5}},
        {"Bruno", {23, 5}},
        {"Carlos", {15, 6}},
        {"Daniela", {8, 5}},
        {"Eduardo", {25, 7}}};

    int mes = 5;
    printf("Quantidade de aniversariantes no mes %d: %d\n", mes, qtd_aniversario(lista, 5, mes));

    Tniver data1 = {10, 5};
    Tniver data2 = {20, 6};
    printf("Aniversariantes entre 10 e 18\n");
    nomes_aniversario(lista, 5, 10, 18);

    
}

int qtd_aniversario(Tdados lista[], int tamanho, int mes)
{
    int contador = 0;
    for (int i = 0; i < tamanho; i++)
    {
        if (lista[i].aniversario.mes == mes)
        {
            contador++;
        }
    }
    return contador;
}
void nomes_aniversario(Tdados lista[], int tamanho, int d2, int d1)
{
    int contador = 0;

    for (int i = 0; i < tamanho; i++)
    {
        if (lista[i].aniversario.dia >= d2 && d1 >= lista[i].aniversario.dia )
        {
            printf("%s \n", lista[i].nome);
        }
    }
}