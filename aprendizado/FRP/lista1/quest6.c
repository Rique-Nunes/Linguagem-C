// Considere uma loja que mantém em uma
// matriz o total vendido por cada funcionário
// pelos diversos meses do ano. Ou seja, uma
// matriz de 12 linhas (uma por mês) e 10 colunas
//(10 funcionários). Pede-se o desenvolvimento de uma função para cada item abaixo:
// a. Calcular o total vendido durante o ano;
// b. Dado um mês fornecido pelo usuário, determinar o total vendido nesse mês;
// c. Dado um funcionário fornecido pelo usuário, determinar o total vendido por ele durante o ano;
// d. Determinar o mês com maior índice de vendas;
// e. Determinar o funcionário que menos vendeu durante o ano.
#include <stdio.h>

int total_ano(int linhas, int colunas, int matA[linhas][colunas]);
int total_mes(int linhas, int colunas, int matA[linhas][colunas], int mes);
int total_funcionario(int linhas, int colunas, int matA[linhas][colunas], int func);
int maior_mes(int linhas, int colunas, int matA[linhas][colunas]);
int menor_func(int linhas, int colunas, int matA[linhas][colunas]);

void main()
{
    int total_anual, mes_atual, func_resultado, maior_meses, menor_funcio;
    int matA[12][10] = {
        {1, 2, 3, 4, 5, 6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15, 16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25, 26, 27, 28, 29, 30},
        {31, 32, 33, 34, 35, 36, 37, 38, 39, 40},
        {41, 42, 43, 44, 45, 46, 47, 48, 49, 50},
        {51, 52, 53, 54, 55, 56, 57, 58, 59, 60},
        {61, 62, 63, 64, 65, 66, 67, 68, 69, 70},
        {71, 72, 73, 74, 75, 76, 77, 78, 79, 80},
        {81, 82, 83, 84, 85, 86, 87, 88, 89, 90},
        {91, 92, 93, 94, 95, 96, 97, 98, 99, 100},
        {101, 102, 103, 104, 105, 106, 107, 108, 109, 110},
        {111, 112, 113, 114, 115, 116, 117, 118, 119, 120}};
    total_anual = total_ano(12, 10, matA);
    printf("%d de total no ano\n", total_anual);
    mes_atual = total_mes(12, 10, matA, 0);
    printf("%d no mes de janeiro\n", mes_atual);
    func_resultado = total_funcionario(12, 10, matA, 0);
    printf("%d, resultado do funcionario escolhido\n", func_resultado);
    maior_meses = maior_mes(12, 10, matA);
    printf("%d, resultado do maior mes\n", maior_meses);
    menor_funcio = menor_func(12, 10, matA);
    printf("%d funcionario com o menor desempenho\n", menor_funcio);
}
// a. Calcular o total vendido durante o ano;
int total_ano(int linhas, int colunas, int matA[linhas][colunas])
{
    int i, j, soma_total = 0;
    for (i = 0; i < linhas; i++)
    {
        for (j = 0; j < colunas; j++)
        {
            soma_total += matA[i][j];
        }
    }
    return soma_total;
}
// b. Dado um mês fornecido pelo usuário, determinar o total vendido nesse mês;
int total_mes(int linhas, int colunas, int matA[linhas][colunas], int mes)
{
    int j, soma_mes = 0;
    mes--;

    for (j = 0; j < colunas; j++)
    {
        soma_mes += matA[mes][j];
    }
    return soma_mes;
}
// c. Dado um funcionário fornecido pelo usuário, determinar o total vendido por ele durante o ano;
int total_funcionario(int linhas, int colunas, int matA[linhas][colunas], int func)
{
    int i, j, soma_func = 0;

    for (j = 0; j < linhas; j++)
    {
        soma_func += matA[j][func];
    }
    return soma_func;
}
// d. Determinar o mês com maior índice de vendas;
int maior_mes(int linhas, int colunas, int matA[linhas][colunas])
{
    int i, j, maior_mes = 0, contador, mes;
    for (i = 0; i < linhas; i++)
    {
        contador = total_mes(linhas, colunas, matA, i);
        if (contador > maior_mes)
        {
            maior_mes = contador;
            mes = i;
        }
    }
    return maior_mes;
}
// e. Determinar o funcionário que menos vendeu durante o ano.
int menor_func(int linhas, int colunas, int matA[linhas][colunas])
{
    int i, j, menor_valor = 500000, func;
    for (i = 0; i < linhas; i++)
    {
        for (j = 0; j < colunas; j++)
        {
            if (matA[i][j] < menor_valor)
            {
                menor_valor = matA[i][j];
                func = j;
            }
        }
    }
    return func;
}

void resultado(int linha, int coluna, int matA[linha][coluna])
{
    int i, j;
    for (i = 0; i < linha; i++)
    {
        for (j = 0; j < coluna; j++)
        {
            // printf("%d", matA[i][j]);
        }
    }
}
