#include "TLDE.h"
#include <stdlib.h>

typedef struct no{
	Produto info;
	struct no* ant;
	struct no* prox;
}No;

struct lista{
	int qtd;
	No* prim;
};

Lista* criar_lista(){
	Lista* l = (Lista*) malloc(sizeof(Lista));
	if(!l) exit(1); //Erro de memoria
	l->qtd = 0;
	l->prim = NULL;
	return l;
}

int tamanho_lista(Lista* l){
	return l->qtd;
}

void inserir_inicio(Lista* l, Produto* prod){
	No* no = (No*) malloc(sizeof(No));
	if(!no) exit(1); //Erro de memoria
	no->ant = NULL;
	no->info.codigo = prod->codigo;
	no->info.preco = prod->preco;
	no->info.qtdEstoque = prod->qtdEstoque;
	no->prox = l->prim;
	if(l->prim)
		l->prim->ant = no;
	l->prim = no;
	l->qtd++;
}

void insere_ordenado (Lista* l, Produto* prod){

   No* no = (No*) malloc(sizeof(No));
   if(!no) exit(1); //Erro de memoria

   no->info.codigo = prod->codigo;
   no->info.preco = prod->preco;
   no->info.qtdEstoque = prod->qtdEstoque;


   No* p = l->prim;
   No *ant = NULL;
   while((p)&&(p->info.codigo<prod->codigo)){
   		ant=p;
		p=p->prox;
   }
   if(!ant){
   		no->ant = NULL;
	  	no->prox = l->prim;
	  	if(l->prim)
			l->prim->ant = no;
		l->prim = no;
   }else{
   		ant->prox = no;
   		no->prox = p;
   		no->ant = ant;
   		if(p) //tratar inser  o no final
			p->ant = no;
   }
   l->qtd++;

}

int retira (Lista* l, int cod) {

   No* q = l->prim;
   // procura elemento na lista, guardando anterior
   while ((q != NULL) && (q->info.codigo != cod)) {
      q = q->prox;
   }

   //verifica se achou elemento
   if (q == NULL) // O Elemento n o foi encontrado na lista
      return 0; //0   insucesso na remo  o

   /* Retira elemento */

   if (q->ant == NULL) { /* retira elemento do inicio */
      l->prim = q->prox; //reapontar o in cio (prim) para o pr ximo n  do elemento que ser  retirado
      l->prim->ant = NULL; //apontar o "ant" do novo primeiro para NULL
   }
   else { /* retira elemento do meio/fim da lista */
      q->ant->prox = q->prox; // apontar o n  anterior do que ser  exclu do para o posterior do que ser  exclu do
      if(q->prox != NULL)
        q->prox->ant = q->ant; // apontar o n  a seguir do que ser  removido para o anterior
   }
   free(q); //liberar o espa o de mem ria do n  exclu do da lista
   l->qtd--; //decrementar a quantidade de elementos da lista.
   return 1; // 1   sucesso na remo  o
}


void imprimir_ida_volta(Lista* l){
	No* pAux;
	No* fim;
	for(pAux = l->prim; pAux!=NULL; pAux=pAux->prox){
		printf("\nCODIGO = %d",pAux->info.codigo);
		printf("\nPRECO = %.2f",pAux->info.preco);
		printf("\nQTD_ESTOQUE = %d",pAux->info.qtdEstoque);
		if(pAux->prox == NULL)
			fim = pAux;
	}
	//printf("\n%d",fim);

	for(pAux = fim; pAux!=NULL; pAux=pAux->ant){
		printf("\nCODIGO = %d",pAux->info.codigo);
		printf("\nPRECO = %.2f",pAux->info.preco);
		printf("\nQTD_ESTOQUE = %d",pAux->info.qtdEstoque);
	}
}

void libera_lista(Lista* l){
	No* pAux = l->prim;
	while(pAux){
		No* tAux = pAux;
		pAux = pAux->prox;
		free(tAux);
	}
}








