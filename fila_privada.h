#include "fila_publica.h"

typedef struct fila {

    noFila *inicio, *fim;
    int tamanho_dados;    

} pfila;

typedef struct noFila {
    void *dados;
    noFila *prox;
} noFila;

int cheia(pfila *f);
int vazia(pfila *f);
