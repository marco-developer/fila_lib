# Biblioteca de filas

# Introdução

Para usar, acrescente #include "fila_publica.h" na aplicação.  

# Funções disponíveis
Todas as funções retornam 0 em caso de sucesso e 1 em caso de falha.  
Para estar de acordo com o definido em aula, existe a função cheia, que verifica se a fila está cheia. Para isso, está definido em fila.c a quantidade máxima de elementos da fila (qtdmax).  

pfila* criar(int tamanho_dados, int * resultado);  
Cria fila com tamanho especificado.
Ex.: f = criar(10, resultado);  

void enfileirar(pfila * f, void * elemento, int * resultado);  
Enfilera elemento na fila f.

void* desenfileirar(pfila * f, int * resultado);  
Desenfilera elemento da fila f, retornando-o.
Ex: el = desenfileirar(f, resultado);

void destruir (pfila * f, int * resultado);  
Desaloca os elementos e, em seguida, a fila.  

void consultarpontas (pfila * f, void * inicio, void * fim, int * resultado);  
Retorna o elementos no ínicio e o elemento no fim da fila.  
Ex: consultarpontas(f, inicio, fim, resultado);  

int consultaqtd(pfila * f);  
Consulta e retorna a quantidade de elementos em uso e o total da fila.  

int cheia(pfila * f); 
Percorre os elementos da fila, contabiliza e verifica se a fila está cheia.  

int vazia(pfila  f);  
Verifica se a fila está vazia.
