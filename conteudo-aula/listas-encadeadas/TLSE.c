#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
    int info; //4 bytes - conteúdo útil
    struct lista *prox; // 4 bytes - ponteiro para o próximo nó da lista
}TLSE; //Tipo Lista Simplesmente encadeada

TLSE*inserir_ini(TLSE* l, int valor){
    TLSE* novoNo = (TLSE*) malloc(sizeof(TLSE));
    novoNo->info = valor;
    novoNo->prox = l;
    return novoNo;
}

void imprimir_lista_while(TLSE* l){ //WHILE
    TLSE* pAux = l;
    while(pAux != NULL){
        printf("\nValor: %d",pAux->info);
        pAux = pAux->prox;
    }
}

void imprimir_lista_for(TLSE* l){ //WHILE
    TLSE* pAux;
    for(pAux = l; pAux != NULL; pAux = pAux->prox){
        printf("\nValor: %d",pAux->info);

    }
}

void imprimir_lista_recursivo(TLSE* l){
    if(l->prox!=NULL){
        imprimir_lista_recursivo(l->prox);
    }
    printf("\nValor: %d",l->info);
}

TLSE* inicializa_lista(){
    return NULL;
}

int vazia(TLSE* l){
    return (l==NULL);
}

TLSE* liberar_lista_it(TLSE* l){
    TLSE* pAux = l;
    while(pAux!=NULL){
        TLSE*t = pAux;
        pAux = pAux->prox;
        free(t);
    }
    return NULL;

}

TLSE* liberar_lista_rec(TLSE* l){
    if(l->prox!=NULL){
        liberar_lista_rec(l->prox);
    }
    free(l);
    return NULL;
}

int main()
{
    TLSE* l = inicializa_lista();
    printf("\nEh vazia? %d",vazia(l));
    l = inserir_ini(l, 10);
    l = inserir_ini(l, 3);
    printf("\nEh vazia? %d",vazia(l));
    l = inserir_ini(l, 9);
    imprimir_lista_while(l);
    imprimir_lista_for(l);
    imprimir_lista_recursivo(l);

    //l = liberar_lista_it(l);
    l = liberar_lista_rec(l);

    printf("\nEh vazia? %d",vazia(l));

    return 0;
}