#include <stdio.h>
#include "arvoreKD.h"

int main() {
    NoKD *raiz = NULL;
    int opc, ponto[2];

    do {
        printf("1 - Inserir\n");
        printf("2 - Buscar\n");
        printf("3 - Remover\n");
        printf("4 - Imprimir\n");
         printf("5 - vizinho\n");
        printf("0 - Sair\n");
        scanf("%d", &opc);

        switch (opc) {
            case 1:
                printf("Digite os valores de X Y: ");
                scanf("%d %d", &ponto[0], &ponto[1]);
                raiz = inserirKD(raiz, ponto, 0);
                break;

            case 2: {
                printf("X Y: ");
                scanf("%d %d", &ponto[0], &ponto[1]);
                NoKD *res = buscarKD(raiz, ponto, 0);
                printf(res ? "Encontrado!\n" : "Não encontrado.\n");
                break;
            }

            case 3:
                printf("Digite X Y para remover: ");
                scanf("%d %d", &ponto[0], &ponto[1]);
                raiz = removerKD(raiz, ponto, 0);
                break;

            case 4:
                imprimirKD(raiz);
                break;
                
            case 5:
                printf("Digite X Y: ");
                scanf("%d %d", &ponto[0], &ponto[1]);
                double md = 999999;
                NoKD *nn = vizinhoMaisProximo(raiz, ponto, 0, NULL, &md);
            if (nn)
                printf("Vizinho mais próximo: (%d,%d) distância=%.2lf\n",
                nn->ponto[0], nn->ponto[1], md);
                break;
    
        }
        
        
    

    } while (opc != 0);

    liberarKD(raiz);
    return 0;
}
