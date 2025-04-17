#ifndef TLDE_H
#define TLDE_H

#endif //TLDE_H

typedef struct produto{
    int codigo;
    float preco;
    int qtdEstoque;
}Produto;

typedef struct lista Lista;

/*
 Nome: criar_lista
 Objetivo: criar o struct decritor da lista duplamente encadeada.
 parâmetro de entrada: nenhum.
 parâmetro de entrada: o ponteiro para o struct primeiro byte do
 struct descritor.
*/
Lista* criar_lista(); //OK

void inserir_inicio(Lista* l, Produto* prod); //OK

void inserir_fim(Lista* l, Produto* prod); //Não implementado

void inserir_ordenado(Lista* l, Produto* prod);

int retira(Lista* l, int cod);

int tamanho_lista(Lista* l); //OK

void imprimir_ida_volta(Lista* l);//OK

void libera_lista(Lista* l);//OK






