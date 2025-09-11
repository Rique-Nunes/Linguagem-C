#include "stdio.h"
#define max 100;

typedef struct lista Tlista;

Tlista *criaLista();

void liberaLista(Tlista *lista);

void insereLista(Tlista *lista, int valor);

void exibe_lista_sequencial(Tlista *lista);

void insereLista2(Tlista *lista, int valor);
