#include "fila_publica.h"

typedef struct fila {

    noFila *inicio, *fim;
    int tamanho_dados;    

} fila;

typedef struct noFila {
    void *dados;
    noFila *ant;
} noFila;

int cheia(fila *f);
int vazia(fila *f);