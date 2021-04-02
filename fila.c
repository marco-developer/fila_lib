#include "stdio.h"
#include "stdlib.h"
#include <string.h> 
#include "fila_privada.h"

fila* criar(fila *f, int tamanho_dados, int *resultado){
    
    f->inicio=NULL;
    f->fim=NULL;
    f->tamanho_dados = tamanho_dados;
    
}

void enfileirar(fila *f, void *elemento, int *resultado){
    
    noFila *el;

    if(f==NULL) {
        resultado=1;
        return;
    }

    el = (noFila*) malloc(sizeof(noFila));
    el->dados = (void*) malloc(f->tamanho_dados);

    if(el==NULL) {
        resultado=1;
        return;
    }

    el->dados = elemento;
    el->prox = el;
    
    if(f->fim==NULL){
        f->inicio=el;
    } else { 
        f->fim->prox=el;
        f->fim=el;
    }
    resultado = 0;

}

void desefileirar(fila *f, int *resultado){
    
    noFila *el;

    if(f==NULL) {
        resultado=1;
        return;
    }
    if(f->inicio==NULL){
        resultado=1;
        return;
    }

    el = f->inicio;
    f->inicio = f->inicio->prox;

    if(f->inicio==NULL) f->fim=NULL;

    free(el);
    resultado=0;

}

void destruir (fila **f, int *resultado){

    if((*f)!=NULL){
        noFila *el;
        while((*f)->inicio!=NULL) {
            el = (*f)->inicio;
            (*f)->inicio = (*f)->inicio->prox;
            free(el);
        }
    free(f);
    }
}

int cheia(fila *f){

}

int vazia(fila *f){

    if(f->fim==NULL) return 0; else return 1;
    
}