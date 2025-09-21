#include "lista.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/* Em seguida, um tipo para a lista */ 
struct tipo_lista 
{ 
int* vnos; 
int qtnos; 
int maximo; 
int ehclassificada; // 1: classificada 0: não classificada 
int temrepeticao; // 1: com repetição 0: sem repetição 
}; 

/*cria lista vazia*/ 
tLista * lista_cria_vazia(int maximo,int classif, int repet) {
    tLista *pl = (tLista*) malloc(sizeof(tLista));
	pl->vnos=(int*)malloc (sizeof(int)* maximo);
	pl->qtnos = 0; 
    pl->maximo= maximo; 
    pl->ehclassificada=classif; 
    pl->temrepeticao=repet; 
    return pl;
} 
//lista está vazia? 
int lista_vazia( const tLista *pl){ 
return ( pl->qtnos == 0); 
}
//lista está cheia? 
int lista_cheia( const tLista *pl){ 
return ( pl->qtnos == pl->maximo); 
} 
//lista com repetição? 
int lista_repet( const tLista *pl){ 
return ( pl->temrepeticao == 1); 
} 
//lista classificada? 
int lista_classif( const tLista *pl){ 
return ( pl->ehclassificada == 1); 
} 
//percorre a lista 
void lista_percorre(const tLista *pl) { 
    int i; 
    for(i = 0; i < pl->qtnos; i++) 
        printf("\n%d", pl->vnos[i]); 
} 

int lista_inclui(tLista *pl, int novo) {
    //Verifica se a lista está cheia
    if (lista_cheia(pl)) {
        return 0; 
    }

    int pos;
    int achou;

    // Lista classificada e sem repetição ---
    if (lista_classif(pl) && !lista_repet(pl)) {
        achou = busca_bin(pl, novo, &pos);
        if (achou) {
            return 0; 
        }
        chegaparala(pl, pos);
        pl->vnos[pos] = novo;
    }
    // Lista classificada e com repetição ---
    else if (lista_classif(pl) && lista_repet(pl)) {
        busca_bin(pl, novo, &pos);
        chegaparala(pl, pos);
        pl->vnos[pos] = novo;
    }
    // Lista não classificada e sem repetição ---
    else if (!lista_classif(pl) && !lista_repet(pl)) {
        achou = busca_des_srep(pl, novo, &pos);
        if (achou) {
            return 0; 
        }
        pl->vnos[pl->qtnos] = novo;
    }
    // Lista não classifica e com repetição
    else { 
        pl->vnos[pl->qtnos] = novo;
    }
    pl->qtnos++;

    return 1; 
}

int lista_exclui(tLista*pl,int no){
    int posRet,achou,qt=1;
    if (lista_vazia(pl))
        return 0;

    if (lista_repet(pl) && ! lista_classif(pl))
        return 1;
        //return retira_varios(pl,no);
        
    if(lista_classif(pl))
        achou=busca_bin(pl,no, &posRet);
    else
        achou=busca_des_srep(pl,no,&posRet);
        
    if (!achou)
        return -1; // exlusão de inexistente
    
    if (lista_repet(pl)){
       
        printf("\nantes %d %d", posRet,qt);
        encontra_posInicEqt(pl,&posRet, &qt,no);
        printf("\ndepois %d %d", posRet,qt);
        }
    
    chegaparacaMC(pl, posRet, qt);
    printf("\n\n%d %d ",qt, pl->qtnos);
    pl->qtnos-=qt;
    printf("\n%d %d ",qt, pl->qtnos);
    return 1;
}
    

// FUNÇÕES AUXILARES

//Busca DESORDENADA sem repetição 
int busca_des_srep(tLista *pl,int chave,int *pos){ 
    int i; 
    for(i=0; (i<pl->qtnos)&&(pl->vnos[i]!=chave); i++); 
    (*pos) = i; 
    return(i < pl->qtnos); 
    } 
//Busca BINÁRIA 
int busca_bin(tLista *pl, int chave, int *pos) {
    int inicio = 0, meio, fim = pl->qtnos-1, achou = 0; 
    while((inicio <= fim) && (!achou)) { 
        meio = (inicio + fim) /2;
        if(pl->vnos[meio] == chave) 
            achou = 1; 
        else if(pl->vnos[meio] > chave) 
            fim = meio-1; 
        else 
            inicio = meio+1; 
    } 
    if(achou) 
        (*pos) = meio; 
    
    else 
        (*pos) = inicio; 
    return achou; 
} 

void encontra_posInicEqt(tLista*pl,int * posRet, int *qt, int valor){
    int inic, fim;
    printf("oi");
    (*qt)=1;
    inic=*posRet-1;
    fim=*posRet+1;
    while (inic >=0 && pl->vnos[inic]==valor){
        (*qt)++;
        inic--;
        (*posRet)--;
    }
    while (fim < pl->qtnos && pl->vnos[fim]==valor){
        (*qt)++;
        fim++;
    }
    
}
    

//CHEGA PARA CÁ  ==> TRANSFORMAR PARA  memcpy
void chegaparaca(tLista *pl, int pos, int qt) { 
    int i; 
    for(i = pos; i <= pl->qtnos - qt; i++) 
        pl->vnos[i] = pl->vnos[i+qt]; 
} 


// CHEGA PARA LÁ ==> TRANSFORMAR PARA  memcpy

void chegaparala(tLista *pl, int pos){ 
    int i; 
    for(i = pl->qtnos; i > pos; i--) 
        pl->vnos[i] = pl->vnos[i-1]; 
}

void chegaparacaMC(tLista *pl, int posRet, int qt){ 
    memcpy(pl->vnos+posRet, pl->vnos+posRet+qt, sizeof(int) * (pl->qtnos - (posRet+qt)));
}

void chegaparalaMC(tLista *pl, int pos, int qt){ 
    memcpy(pl->vnos+pos+1, pl->vnos+pos, sizeof(int) * (pl->qtnos - pos));
}


