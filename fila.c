#include "stdio.h"
#include "stdlib.h"
#include <string.h> 
#include "fila_privada.h"

fila* criar(int tamanho_dados, int *resultado){

    fila *f = (fila*)malloc(sizeof(fila));
    
    if (!f) {
        printf("Erro ao criar fila!!\n");
        *resultado = 1;
        return;
    }
    f->inicio=NULL;
    f->fim=NULL;
    f->tamanho_dados = tamanho_dados;
    printf("Valor de f-tamdados: %d\n", f->tamanho_dados);
    *resultado = 0;
    return f;
    
}

void enfileirar(fila *f, void *elemento, int *resultado){
    
    if(f==NULL) {
        printf("Fila nao alocada!\n");
        *resultado=1;
        return;
    }

    printf("Alocando noFila el!\n");
    noFila *el = malloc(sizeof(noFila));
    printf("Alocando dados do noFila el!\n");
    el->dados = (void*) malloc(f->tamanho_dados);

    if(el==NULL) {
        printf("Falha na alocacao do elemento\n");
        *resultado=1;
        return;
    }

    printf("Definindo dados elemento novo como elemento passado!\n");
    el->dados = elemento;
    printf("Definindo ponteiro prox do elemento novo para NULL!\n");
    el->prox = NULL;
    
    if(f->inicio==NULL){
        printf("inicio eh null, entao inicio eh elemento novo");
        f->inicio=el;
    } else { 
        printf("inicio nao e null, entao fim-prox = elemento novo");
        f->fim->prox=el;
        
    }
    printf("Fim da fila vira novo elemento\n");
    f->fim=el;
    printf("\nValor no inicio da fila: %s\n", f->inicio);
    printf("Valor no fim da fila: %s\n\n", f->fim);
    *resultado = 0;

}

void desefileirar(fila *f, int *resultado){
    
    noFila *el = malloc(sizeof(noFila));
    // item = malloc(sizeof(noFila));
    // el->dados = (void*) malloc(f->tamanho_dados);

    if(f==NULL) {
        printf("Fila nao alocada!\n");
        *resultado=1;
        return;
    }
    if(vazia(f)==0){
        *resultado=1;
        printf("Fila vazia!\n");
        return;
    }

    printf("Valor de f-inicio: %s\n", f->inicio);
    el = f->inicio;

    printf("Valor de el: %s\n", el);

    printf("Valor de f-inicio-prox: %s\n", f->inicio->prox);        
    if(f->inicio->prox==NULL) {
        
        f->inicio=NULL;
        f->fim=NULL; 

    } else f->inicio = f->inicio->prox;

    printf("\nValor removido: %s\n", el);
    free(el);
    *resultado=0;

}

void destruir (fila *f, int *resultado){

    printf("Valor de f-inicio %s\n", f->inicio);

    while(f->inicio!=NULL) {
        
        printf("desenfileirando...\n");
        noFila *apagar = malloc(sizeof(noFila));
        apagar = f->inicio;
        f->inicio = f->inicio->prox;
        free(apagar);
    }
    free(f);
    *resultado = 0;
}

int cheia(fila *f){

}

int vazia(fila *f){

    if(f->inicio==NULL) return 0; else return 1;

}

void consultarpontas (fila *f, void *inicio, void *fim, int *resultado){
        
    // inicio = (noFila*) malloc(sizeof(noFila*));
    // fim = (noFila*) malloc(sizeof(noFila*));



    if(f==NULL) {
        printf("Fila nao alocada!\n");
        *resultado=1;
        return;
    }

    if(vazia(f)==0){
        printf("Fila vazia!\n");
    } else {    
        memcpy(inicio, f->inicio, f->tamanho_dados);
        memcpy(fim, f->fim, f->tamanho_dados);

    }
    *resultado = 0;


}