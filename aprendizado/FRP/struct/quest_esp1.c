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
        {"978-8535902775", "Dom Casmurro", "Machado de Assis", 1899, 5},
        {"978-8571645889", "Cem Anos de Solidao", "Gabriel Garcia Marquez", 1967, 3},
        {"978-0747532743", "Harry Potter e a Pedra F.", "J.K. Rowling", 1997, 0},
        {"978-8522005230", "1984", "George Orwell", 1949, 8},
        {"978-8535914846", "Grande Sertao: Veredas", "Joao Guimaraes Rosa", 1956, 2}};

    printf("%d", emprestar(acervo, 5, "978-8535902775"));
    printf("\n");
    printf("\n");
    buscar_autor(acervo, 5, "Dom Casmurro");
    printf("\n");
    printf("\n");
    ordenar_ano(acervo, 5, 1965);
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
    printf(" %s", biblioteca[i].titulo);
    printf("%d", biblioteca[i].ano_publicacao);
}

void ordenar_ano(Tbiblioteca biblioteca[], int tamanho, int ano)
{
    int i, j, aux;

    for (i = 0; i < tamanho; i++)
    {
        if (biblioteca[i].ano_publicacao > ano)
        {
            for (j = i; j < tamanho; j++)
            {
                if (biblioteca[i].ano_publicacao < ano)
                {
                    aux = biblioteca[i].ano_publicacao;
                    biblioteca[i].ano_publicacao = biblioteca[j].ano_publicacao;
                    biblioteca[j].ano_publicacao = aux;
                }
            }
        }
    }
    for (i = 0; i < tamanho; i++)
    {
        printf("%d\n", biblioteca[i].ano_publicacao);
    }
}
