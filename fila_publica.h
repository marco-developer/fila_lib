typedef struct fila fila;
typedef struct noFila noFila;

fila* criar(int tamanho_dados, int *resultado);
void enfileirar(fila *f, void *elemento, int *resultado);
void* desenfileirar(fila *f, int *resultado);
void destruir (fila *f, int *resultado);
void consultarpontas (fila *f, void *inicio, void *fim, int *resultado);
