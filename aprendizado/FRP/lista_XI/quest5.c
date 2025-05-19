/*O histórico de um aluno é representado por um
vetor de structs onde cada posição armazena o
código da disciplina cursada, semestre e ano
que a cumpriu e a média final na disciplina.
Implementar uma função que exiba o histórico
do aluno com o seguinte formato:
NomeDisciplina1 (código1) MédiaDisciplina1
NomeDisciplina2 (código2) MédiaDisciplina2
.
.
.
NomeDisciplinaN (códigoN) MédiaDisciplinaN
Coeficiente de rendimento: CR
Observações:
1. Para obter os dados da disciplina, um outro
vetor de structs deve ser consultado. Este,
por sua vez, armazena para cada disciplina
do curso as seguintes informações: código,
nome e número de créditos;
2. O coeficiente de rendimento consiste em
uma média ponderada de todos os graus
atribuídos às disciplinas cursadas, onde os
pesos são representados pelo número de
créditos da disciplina;
3. Todos os dados em negrito apresentados no
formato do histórico devem ser obtidos a
partir dos vetores.*/

typedef struct
{
    int codigo;
    int semestre;
    int ano;
    float media;
} Taluno;

typedef struct
{
    int codigo;
    char nome[30];
    int creditos;
} Tdisciplina;

#include "stdio.h"
#include "string.h"

void exibirhistorico(Taluno aluno[], int tamanho, Tdisciplina disciplinas[], int tamanho_disc);
void main()
{
    Taluno aluno[] = {
        {101, 1, 2023, 8.5},
        {102, 2, 2023, 7.0}};

    Tdisciplina disciplinas[] = {
        {101, "Matematica", 4},
        {102, "Fisica", 3}};

    exibirhistorico(aluno, 2, disciplinas, 2);
}

void exibirhistorico(Taluno aluno[], int tamanho, Tdisciplina disciplinas[], int tamanho_disc)
{
    int codigos, j;
    float mediana = 0, cont = 0;
    for (int i = 0; i < tamanho; i++)
    {
        codigos = aluno[i].codigo;
        for (j = 0; j < tamanho_disc; j++)
        {
            if (codigos == disciplinas[j].codigo)
            {
                break;
            }
        }
        printf("%s (%d) %.2f\n", disciplinas[j].nome, codigos, aluno[i].media);

        mediana += aluno[i].media * disciplinas[j].creditos;
        cont += disciplinas[j].creditos;
    }
    printf("\n a media e: %.2f, %f", mediana / cont, cont);
}