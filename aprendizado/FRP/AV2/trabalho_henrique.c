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

int inicializar(int tamanho, Tcurso cursos[]);
int inserir_curso(int tamanho, Tcurso cursos[]);
void main() {
    Tcurso cursos[100];
    int quantos;
    quantos = inicializar(100, cursos);
    printf("a quantidade de dados inicializados sao: %d", quantos);

}


int inicializar(int tamanho, Tcurso cursos[]){
    FILE *arq;
    int contador=0;
    float codigo, qtd_alunos;
    arq = fopen("dados.txt", "r");
    
    if(arq == NULL){
        printf("erro ao abrir o arquivo");
        return 0;
    }
    while(fscanf(arq,"%f %f %f %f %f %f %f %f %f %f", &codigo, &cursos[contador].enade, &cursos[contador].idd, &cursos[contador].doutores, &cursos[contador].mestres,
         &cursos[contador].regime_trabalho, &cursos[contador].organizacao_pedagogica, &cursos[contador].infraestrutura, &cursos[contador].opaap, &qtd_alunos) != EOF){
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
