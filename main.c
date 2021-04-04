#include <stdio.h>
#include <stdlib.h>
#include <curses.h>
#include <string.h>
#include "fila_publica.h"

void main() {

    int menu, nroElementos, tamanho, tela;
    
    fila *f;
    void *insere;
    // noFila *remove;
    void *ini, *fim;
    void *top;
    int resultado;

    tela = 1;
    // P = NULL;

    // f = (fila*) malloc (sizeof(fila*));
    
    ini = (noFila*) malloc(sizeof(noFila*));
    fim = (noFila*) malloc(sizeof(noFila*));
    // remove = (noFila*) malloc(sizeof(noFila*));


    do {
        printf("\n\n\n\n\n*---------------------------------------------------------------------------------------------------------------------------*\n");
        printf ("Escolha o comando: \n(1)-Criar fila\n(2)-Adicionar elemento\n(3)-Remover elemento\n(4)-Ver pontas\n(5)-Limpar fila\n(6)-Desalocar fila \n(7)-Sair\n");
        scanf ("%d", &menu);
        printf("\n*---------------------------------------------------------------------------------------------------------------------------*\n");
            
        switch (menu) {
            case 1:
                printf ("Informe o tamanho dos elementos: \n");
                scanf ("%d", &tamanho);
                printf ("Preparando para criar fila...\n");
                f = criar(tamanho, &resultado);
                if(resultado!=0) {
                    printf("Falha ao criar fila!\n"); 
                    exit(1);
                } else printf ("Fila criada.\n");
            break;

            case 2:
                printf ("Iniciando empilhamento...\n\n");
                printf ("Digite o valor a inserir: \n");
                scanf ("%s", &insere);
                enfileirar(f, insere, &resultado);   
                printf ("Resultado da operacao: %d\n", resultado);
                if(resultado==0) printf("Elemento enfileirado com sucesso!\n"); else printf("Falha ao enfileirar elemento!\n");
            break;

            case 3:
                printf ("Removendo item da fila...\n");
                desefileirar(f, &resultado);
                printf ("Resultado da operacao: %d\n", resultado);
            break;

            case 4:
                consultarpontas(f, ini, fim, &resultado);
                if(resultado==0) {
                    printf ("Item no inicio: %s\n", ini);
                    printf ("Item no fim: %s\n", fim);
                } else printf("Falha ao consultar fila!\n");                
            break;

            case 5:
                // limpa(f);
            break;

            case 6:
                destruir(f, &resultado);
                if(resultado==0) {
                    printf ("Fila destruida com sucesso! \n");
                } else printf("Falha ao destruir fila!\n");    
            break;

            case 7:
                exit(1);
        }
    // printf("Nro. de elementos max da pilha %d\n", nroElementos);
    } while(tela);
}