// Arquivo: ListaEncadeada.h

// O nó contém o dado e um ponteiro para o próximo nó
struct no
{
    int dado;
    struct no *proximo;
};

typedef struct no No; // Apelido para a struct no

// A lista é um ponteiro para o primeiro nó
typedef No *ListaEncadeada;

void exibe_lista_encadeada(ListaEncadeada *li);

int insere_lista_encadeada_inicio(ListaEncadeada *li, int valor);

void libera_lista_encadeada(ListaEncadeada *li);

ListaEncadeada *cria_lista_encadeada();