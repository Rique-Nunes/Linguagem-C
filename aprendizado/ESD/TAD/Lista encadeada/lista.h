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