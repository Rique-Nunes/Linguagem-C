/*biblioteca*/

#include <stdio.h>
#include <string.h>

typedef struct
{
    char ISBN[30];
    char titulo[30];
    char autor[30];
    int ano_publicacao;
    int num_copias;
} Tbiblioteca;

int emprestar(Tbiblioteca biblioteca[], int tamanho, char ISBN[30]);
void buscar_autor(Tbiblioteca biblioteca[], int tamanho, char nomeautor[]);
void ordenar_ano(Tbiblioteca biblioteca[], int tamanho, int ano);

void main()
{

    Tbiblioteca acervo[5] = {
        {"978-8535902775", "Dom Casmurro", "Machado de Assis", 1999, 5},
        {"978-8571645889", "Cem Anos de Solidao", "Gabriel Garcia Marquez", 1967, 3},
        {"978-0747532743", "Harry Potter e a Pedra F.", "J.K. Rowling", 1997, 0},
        {"978-8522005230", "1984", "George Orwell", 1949, 8},
        {"978-8535914846", "Grande Sertao: Veredas", "Joao Guimaraes Rosa", 1956, 2}};

    printf("%d", emprestar(acervo, 5, "978-8535902775"));
    printf("\n");
    printf("\n");
    buscar_autor(acervo, 5, "Machado de Assis");
    printf("\n");
    printf("\n");
    ordenar_ano(acervo, 5, 1970);
}

int emprestar(Tbiblioteca biblioteca[], int tamanho, char ISBN[30])
{
    int i;
    for (i = 0; i < tamanho; i++)
    {
        if (strcmp(biblioteca[i].ISBN, ISBN) == 0)
        {
            break;
        }
    }
    if (biblioteca[i].num_copias > 0)
    {
        printf("quantidade disponivel para retirada");
        biblioteca[i].num_copias -= 1;
        return 1;
    }
    else
    {
        printf("quantidade indisponivel para retirada");
        return 0;
    }
}

void buscar_autor(Tbiblioteca biblioteca[], int tamanho, char nomeautor[])
{
    int i;
    for (i = 0; i < tamanho; i++)
    {
        if (strcmp(biblioteca[i].autor, nomeautor) == 0)
        {
            break;
        }
    }
    printf("%s\n", biblioteca[i].titulo);
    printf("%d", biblioteca[i].ano_publicacao);
}

void ordenar_ano(Tbiblioteca biblioteca[], int tamanho, int ano)
{
    int i, j;
    Tbiblioteca aux;

    for (i = 0; i < tamanho - 1; i++)
    {
        for (j = 0; j < tamanho - i - 1; j++)
        {
            // Compara o ano do livro atual com o do próximo
            if (biblioteca[j].ano_publicacao > biblioteca[j + 1].ano_publicacao)
            {
                // Se estiver fora de ordem, troca os livros de posição
                aux = biblioteca[j];
                biblioteca[j] = biblioteca[j + 1];
                biblioteca[j + 1] = aux;
            }
        }
    }
    for (i = 0; i < tamanho; i++)
    {
        printf("%d\n", biblioteca[i].ano_publicacao);
    }
}

// O laço continua enquanto os ponteiros não se cruzarem
while (esquerda < direita)
{
    // 1. Move o ponteiro da esquerda para a direita enquanto encontra livros que já estão no lugar certo
    // (publicados ANTES do ano_corte)
    while (biblioteca[esquerda].ano_publicacao < ano_corte && esquerda < direita)
    {
        esquerda++;
    }

    // 2. Move o ponteiro da direita para a esquerda enquanto encontra livros que já estão no lugar certo
    // (publicados NO ou DEPOIS do ano_corte)
    while (biblioteca[direita].ano_publicacao >= ano_corte && esquerda < direita)
    {
        direita--;
    }

    // 3. Se 'esquerda' ainda for menor que 'direita', significa que encontramos dois livros
    // em posições trocadas. Então, realizamos a troca.
    if (esquerda < direita)
    {
        aux = biblioteca[esquerda];
        biblioteca[esquerda] = biblioteca[direita];
        biblioteca[direita] = aux;

        // Move os ponteiros após a troca para evitar laço infinito
        esquerda++;
        direita--;
    }
}
}