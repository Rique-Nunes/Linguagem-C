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

#include <stdio.h>

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

int inicializar(Tcurso cursos[]);
int inserir_curso(int tamanho, Tcurso cursos[]);
void exibir_part1(int tamanho, Tcurso cursos[]);
void salvar_arquivo(int tamanho, Tcurso cursos[]);
void printadora(int contador, int curso[]);

int main()
{
    Tcurso cursos[100];
    int tamanho = inicializar(cursos);
    int opcao;

    do
    {
        printf("\n--- MENU ---\n");
        printf("1 - Inserir novo curso\n");
        printf("2 - Processar dados (CPC/IGC)\n");
        printf("3 - Sair e salvar\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            if (tamanho < 100)
                tamanho = inserir_curso(tamanho, cursos);
            else
                printf("Limite de cursos atingido.\n");
            break;
        case 2:
            exibir_part1(tamanho, cursos);
            break;
        case 3:
            salvar_arquivo(tamanho, cursos);
            break;
        default:
            printf("Opcao invalida.\n");
        }
    } while (opcao != 3);

    return 0;
}

int inicializar(Tcurso cursos[])
{
    FILE *arq = fopen("dados.txt", "r");
    int contador = 0;
    float codigo, qtd_alunos;

    if (arq == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        return 0;
    }

    while (fscanf(arq, "%d %f %f %f %f %f %f %f %f %d", &cursos[contador].codigo, &cursos[contador].enade, &cursos[contador].idd,
                  &cursos[contador].doutores, &cursos[contador].mestres, &cursos[contador].regime_trabalho,
                  &cursos[contador].organizacao_pedagogica, &cursos[contador].infraestrutura,
                  &cursos[contador].opaap, &cursos[contador].qtd_alunos) != EOF)
    {
        contador++;
    }

    fclose(arq);
    return contador;
}

int inserir_curso(int tamanho, Tcurso cursos[])
{
    printf("Inserir novo curso:\n");

    printf("Codigo: ");
    scanf("%d", &cursos[tamanho].codigo);

    printf("ENADE: ");
    scanf("%f", &cursos[tamanho].enade);

    printf("IDD: ");
    scanf("%f", &cursos[tamanho].idd);

    printf("Doutores: ");
    scanf("%f", &cursos[tamanho].doutores);

    printf("Mestres: ");
    scanf("%f", &cursos[tamanho].mestres);

    printf("Regime de trabalho: ");
    scanf("%f", &cursos[tamanho].regime_trabalho);

    printf("Organizacao pedagogica: ");
    scanf("%f", &cursos[tamanho].organizacao_pedagogica);

    printf("Infraestrutura: ");
    scanf("%f", &cursos[tamanho].infraestrutura);

    printf("OPAAP: ");
    scanf("%f", &cursos[tamanho].opaap);

    printf("Quantidade de alunos: ");
    scanf("%d", &cursos[tamanho].qtd_alunos);

    return tamanho + 1;
}

void exibir_part1(int tamanho, Tcurso cursos[])
{
    int i, CPC_faixa, IGC_faixa, soma_aluno = 0;
    float CPC, IGC = 0;
    int curso_1[100], curso_2[100], curso_3[100], curso_4[100], curso_5[100];
    int cont_1 = 0, cont_2 = 0, cont_3 = 0, cont_4 = 0, cont_5 = 0;

    for (i = 0; i < tamanho; i++)
    {
        CPC = cursos[i].enade * 0.2 + cursos[i].idd * 0.35 + cursos[i].doutores * 0.15 +
              cursos[i].mestres * 0.075 + cursos[i].regime_trabalho * 0.075 +
              cursos[i].organizacao_pedagogica * 0.075 + cursos[i].infraestrutura * 0.05 +
              cursos[i].opaap * 0.025;

        if (CPC < 0.945)
        {
            CPC_faixa = 1;
            curso_1[cont_1++] = cursos[i].codigo;
        }
        else if (CPC < 1.945)
        {
            CPC_faixa = 2;
            curso_2[cont_2++] = cursos[i].codigo;
        }
        else if (CPC < 2.945)
        {
            CPC_faixa = 3;
            curso_3[cont_3++] = cursos[i].codigo;
        }
        else if (CPC < 3.945)
        {
            CPC_faixa = 4;
            curso_4[cont_4++] = cursos[i].codigo;
        }
        else
        {
            CPC_faixa = 5;
            curso_5[cont_5++] = cursos[i].codigo;
        }

        IGC += CPC * cursos[i].qtd_alunos;
        soma_aluno += cursos[i].qtd_alunos;

        printf("\nCurso: %d\n", cursos[i].codigo);
        printf("CPC continuo: %.2f\n", CPC);
        printf("CPC faixa: %d\n", CPC_faixa);
        printf("Classificacao: %s\n", CPC_faixa < 3 ? "Insatisfatorio" : "Satisfatorio");
        printf("<------------------------->");
    }

    printf("\nCursos por faixa:\n");
    printf("Faixa 1: ");
    printadora(cont_1, curso_1);
    printf("\n");
    printf("Faixa 2: ");
    printadora(cont_2, curso_2);
    printf("\n");
    printf("Faixa 3: ");
    printadora(cont_3, curso_3);
    printf("\n");
    printf("Faixa 4: ");
    printadora(cont_4, curso_4);
    printf("\n");
    printf("Faixa 5: ");
    printadora(cont_5, curso_5);
    printf("\n");
    printf("<------------------------->");

    if (soma_aluno > 0)
        IGC /= soma_aluno;
    else
        IGC = 0;

    if (IGC < 0.945)
        IGC_faixa = 1;
    else if (IGC < 1.945)
        IGC_faixa = 2;
    else if (IGC < 2.945)
        IGC_faixa = 3;
    else if (IGC < 3.945)
        IGC_faixa = 4;
    else
        IGC_faixa = 5;

    printf("\nIGC continuo da instituicao: %.2f\n", IGC);
    printf("IGC faixa da instituicao: %d\n", IGC_faixa);
    printf("Classificacao Geral: %s\n", IGC_faixa < 3 ? "Insatisfatorio" : "Satisfatorio");
}
/* Expectativa de separar o calculo de CPC para essa função
void calcula_CPC(int tamanho, Tcurso cursos[], float *IGC, int *soma_aluno, int *cont_1, int *cont_2, cont_3 = 0, cont_4 = 0, cont_5 = 0;)
{
    int i, CPC_faixa;
    float CPC;
    for (i = 0; i < tamanho; i++)
    {
        CPC = cursos[i].enade * 0.2 + cursos[i].idd * 0.35 + cursos[i].doutores * 0.15 +
              cursos[i].mestres * 0.075 + cursos[i].regime_trabalho * 0.075 +
              cursos[i].organizacao_pedagogica * 0.075 + cursos[i].infraestrutura * 0.05 +
              cursos[i].opaap * 0.025;

        if (CPC < 0.945)
        {
            CPC_faixa = 1;
            curso_1[cont_1++] = cursos[i].codigo;
        }
        else if (CPC < 1.945)
        {
            CPC_faixa = 2;
            curso_2[cont_2++] = cursos[i].codigo;
        }
        else if (CPC < 2.945)
        {
            CPC_faixa = 3;
            curso_3[cont_3++] = cursos[i].codigo;
        }
        else if (CPC < 3.945)
        {
            CPC_faixa = 4;
            curso_4[cont_4++] = cursos[i].codigo;
        }
        else
        {
            CPC_faixa = 5;
            curso_5[cont_5++] = cursos[i].codigo;
        }

        IGC += CPC * cursos[i].qtd_alunos;
        soma_aluno += cursos[i].qtd_alunos;

        printf("\nCurso: %d\n", cursos[i].codigo);
        printf("CPC continuo: %.2f\n", CPC);
        printf("CPC faixa: %d\n", CPC_faixa);
        printf("Classificacao: %s\n", CPC_faixa < 3 ? "Insatisfatorio" : "Satisfatorio");
    }
}
*/
void printadora(int contador, int curso[])
{
    if (contador == 0)
    {
        printf("Nenhum");
        return;
    }

    for (int j = 0; j < contador; j++)
    {
        printf("%d", curso[j]);
        if (j < contador - 1)
            printf(", ");
    }
}

void salvar_arquivo(int tamanho, Tcurso cursos[])
{
    FILE *arq = fopen("dados.txt", "w");
    if (arq == NULL)
    {
        printf("Erro ao abrir o arquivo para escrita.\n");
        return;
    }

    for (int i = 0; i < tamanho; i++)
    {
        fprintf(arq, "%d %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %d\n",
                cursos[i].codigo, cursos[i].enade, cursos[i].idd, cursos[i].doutores,
                cursos[i].mestres, cursos[i].regime_trabalho, cursos[i].organizacao_pedagogica,
                cursos[i].infraestrutura, cursos[i].opaap, cursos[i].qtd_alunos);
    }

    fclose(arq);
    printf("Dados salvos com sucesso no arquivo.\n");
}