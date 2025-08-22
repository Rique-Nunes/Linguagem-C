#include "stdio.h"
#include "string.h"
#include  "stdlib.h"

struct al
{
    int matr;
    char *nome;
};

typedef struct al tAL;

int main(){
    int x,y;
    tAL aliA;
    tAL Vali[3];

    aliA.matr=1010;
    aliA.nome = (char*) malloc(5 * sizeof(char));

    strcpy(aliA.nome, "Lili");

    Vali[0]=aliA;
    //Vali[0].nome[3] = "#";



    tAL *vALD;

    vALD = (tAL*) malloc(3*sizeof(tAL));
    return 0;
}

