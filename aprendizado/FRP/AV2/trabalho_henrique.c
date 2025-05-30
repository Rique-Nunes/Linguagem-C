/*Trabalho AV2*/
/*os dados tem que ficar no arquivo e para manipular eles tem que abrir o arquivo e alocar em um vetor
quando sair tem que salvar os dados no arquivo de texto o IGC usa a mesma tabela do CPC continuo*/
/*o CPC é uma média ponderada porém quando se soma todos os pesos vai dar 1, por ser em porcentagem*/

/*while na main para ficar reptidindo até o usuário querer sair*/
/*cadastrar novos, não altera ou remove*/
/*
Todos os dados do arquivo devem ser lidos para
um vetor de structs, cada posição com os insumos
de um curso da instituição.
O programa deve permitir que o usuário opte pela
inclusão de novo(s) curso(s) no vetor ou processar
os seus dados. Neste último caso, deve exibir as
seguintes informações:
1) Para cada curso: código, CPC contínuo, CPC
faixa e a classificação deste (satisfatório ou
insatisfatório);
2) Para cada CPC faixa possível, exibir os cursos
que o obteve;
3) O IGC – Índice Geral de Cursos – da
instituição, contínuo e faixa (baseados na
mesma tabela de mapeamento apresentada
para o CPC), considerando que este é obtido a
partir de uma média ponderada de todos os
CPCs, onde o número de alunos matriculados
no curso representará o peso de seu CPC no
cálculo do IGC.
*/

#include "stdio.h"

typedef struct
{
    int codigo;
    float enade;
    float idd;
    float doutores;
    float mestres;
    float regime_trabalho;
    float organizacao_pedagogica;
    float infraestrutura;
    float opaap;
    int qtd_alunos;
} Tcurso;

int inicializar(int tamanho, Tcurso cursos[]);
int inserir_curso(int tamanho, Tcurso cursos[]);
void exibir_part1(int tamanho, Tcurso cursos[]);
void main()
{
    Tcurso cursos[100];
    int quantos;
    quantos = inicializar(100, cursos);
    printf("a quantidade de dados inicializados sao: %d", quantos);
}

int inicializar(int tamanho, Tcurso cursos[])
{
    FILE *arq;
    int contador = 0;
    float codigo, qtd_alunos;
    arq = fopen("dados.txt", "r");

    if (arq == NULL)
    {
        printf("erro ao abrir o arquivo");
        return 0;
    }
    while (fscanf(arq, "%f %f %f %f %f %f %f %f %f %f", &codigo, &cursos[contador].enade, &cursos[contador].idd, &cursos[contador].doutores, &cursos[contador].mestres,
                  &cursos[contador].regime_trabalho, &cursos[contador].organizacao_pedagogica, &cursos[contador].infraestrutura, &cursos[contador].opaap, &qtd_alunos) != EOF)
    {
        cursos[contador].codigo = (int)codigo;
        cursos[contador].qtd_alunos = (int)qtd_alunos;
        contador++;
    }
    fclose(arq);
    return contador;
}

int inserir_curso(int tamanho, Tcurso cursos[])
{
    printf("Iniciando processo para adicionar um novo curso: ");
    printf("codigo: ");
    scanf("%d", &cursos[tamanho].codigo);

    printf("enade: ");
    scanf("%f", &cursos[tamanho].enade);

    printf("idd: ");
    scanf("%f", &cursos[tamanho].idd);

    printf("doutores: ");
    scanf("%f", &cursos[tamanho].doutores);

    printf("mestres: ");
    scanf("%f", &cursos[tamanho].mestres);

    printf("regime_trabalho: ");
    scanf("%f", &cursos[tamanho].regime_trabalho);

    printf("organizacao_pedagogica: ");
    scanf("%f", &cursos[tamanho].organizacao_pedagogica);

    printf("infraestrutura: ");
    scanf("%f", &cursos[tamanho].infraestrutura);

    printf("opaap: ");
    scanf("%f", &cursos[tamanho].opaap);

    printf("qtd_alunos: ");
    scanf("%d", &cursos[tamanho].qtd_alunos);
}
/*
1) Para cada curso: código, CPC contínuo, CPC
faixa e a classificação deste (satisfatório ou
insatisfatório);
*/
void exibir_part1(int tamanho, Tcurso cursos[])
{
    int i, j, CPC_faixa;
    float CPC;
    int cursos_altos[tamanho];
    int cursos_baixos[tamanho];

    for (i = 0; i < tamanho; i++)
    {
        CPC = cursos[i].enade * 0.2 + cursos[i].idd * 0.35 + cursos[i].doutores * 0.15 + cursos[i].mestres * 0.075 + cursos[i].regime_trabalho * 0.075 + cursos[i].organizacao_pedagogica * 0.075 + cursos[i].infraestrutura * 0.05 + cursos[i].opaap * 0.025;
        if (CPC < 0.945)
        {
            CPC_faixa = 1;
        }
        else if (0.945 <= CPC < 1.945)
        {
            CPC_faixa = 2;
        }
        else if (1.945 <= CPC < 2.945)
        {
            CPC_faixa = 3;
        }
        else if (2.945 <= CPC < 3.945)
        {
            CPC_faixa = 4;
        }
        else if (CPC >= 3.945)
        {
            CPC_faixa = 5;
        }

        printf("%d", cursos[i].codigo);
        printf("%f", CPC);
        printf("%f", CPC_faixa);
        if (CPC_faixa < 3)
        {
            printf("CPC está insatisfatorio");
            cursos_baixos[j] = cursos[i].codigo;
        }
        else
        {
            printf("CPC está satisfatorio");
            cursos_altos[j] = cursos[i].codigo;
        }
        j++;
        
    }
}