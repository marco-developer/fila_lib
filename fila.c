#include "stdio.h"
#include "stdlib.h"
#include <string.h> 
#include "fila_privada.h"

fila* criar(int tamanho_dados, int *resultado){

    fila *f = (fila*)malloc(sizeof(fila));
    
    if (!f) {
        printf("Erro ao criar fila!!\n");
        // *resultado = 1;
        exit(1);
    }
    f->inicio=NULL;
    f->fim=NULL;
    f->tamanho_dados = tamanho_dados;
    printf("Valor de f-tamdados: %d\n", f->tamanho_dados);
    return f;
    
}

void enfileirar(fila *f, void *elemento, int *resultado){
    
    if(f==NULL) {
        printf("Fila nao alocada!\n");
        // *resultado=1;
        exit(1);
    }

    printf("Alocando noFila el!\n");
    noFila *el = malloc(sizeof(noFila));
    printf("Alocando dados do noFila el!\n");
    el->dados = (void*) malloc(f->tamanho_dados);

    if(el==NULL) {
        printf("Falha na alocacao do elemento\n");
        // *resultado=1;
        exit(1);
    }

    printf("Definindo dados noFila el como elemento!\n");
    el->dados = elemento;
    printf("definindo ponteiro prox para el!\n");
    el->prox = el;
    
    if(f->fim==NULL){
        f->inicio=el;
    } else { 
        f->fim->prox=el;
        
    }
    f->fim=el;
    printf("\nValor no inicio da fila: %s\n", f->inicio);
    printf("\nValor no fim da fila: %s\n", f->fim);
    // *resultado = 0;

}

void desefileirar(fila *f, void *item, int *resultado){
    
    noFila *el = malloc(sizeof(noFila));
    el->dados = (void*) malloc(f->tamanho_dados);
    // item = (void*) malloc(f->tamanho_dados);

    if(f==NULL) {
        // *resultado=1;
        return;
    }
    if(f->inicio==NULL){
        // *resultado=1;
        return;
    }

    el = f->inicio;
    // item = el;

    memcpy(item, f->inicio, f->tamanho_dados);
    f->inicio = f->inicio->prox;
    
    if(f->inicio==NULL) f->fim=NULL;

    // printf("\nValor removido: %s\n", el->dados);
    printf("\nValor no inicio da fila: %s\n", f->inicio);
    printf("\nValor no fim da fila: %s\n", f->fim);

    free(el);
    // *resultado=0;

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

void consultarpontas (fila *f, void *inicio, void *fim, int *resultado){
        
    // inicio = (noFila*) malloc(sizeof(noFila*));
    // fim = (noFila*) malloc(sizeof(noFila*));



    if(f==NULL) {
        printf("Fila nao alocada!\n");
        // *resultado=1;
        return;
    }

    if(f->fim==NULL){
        printf("Fila vazia!\n");
    } else {    
        memcpy(inicio, f->inicio, f->tamanho_dados);
        memcpy(fim, f->fim, f->tamanho_dados);

    }
    // *resultado = 0;


}