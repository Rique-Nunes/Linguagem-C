/*Trabalho AV2*/
/*os dados tem que ficar no arquivo e para manipular eles tem que abrir o arquivo e alocar em um vetor
quando sair tem que salvar os dados no arquivo de texto o IGC usa a mesma tabela do CPC continuo*/
/*o CPC é uma média ponderada porém quando se soma todos os pesos vai dar 1, por ser em porcentagem*/

/*while na main para ficar reptidindo até o usuário querer sair*/
/*cadastrar novos, não altera ou remove*/

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

int inserir_curso(int tamanho, Tcurso cursos[]);
void main() {}

int inserir_curso(int tamanho, Tcurso cursos[])
{
    printf("Iniciando processo para adicionar um novo curso: ");
    printf("codigo: ");
    scanf("%d", &cursos[tamanho].codigo);

    printf("enade: ");
    scanf("%f", &cursos[tamanho].enade);

    printf("idd: ");
    scanf("%f", &cursos[tamanho].idd);
    

}