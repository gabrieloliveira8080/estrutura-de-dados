#include <stdio.h>
#include <stdlib.h>

typedef struct lista {
	int info; //4 bytes - conteC:do C:til
	struct lista *prox; // 4 bytes - ponteiro para o prC3ximo nC3
	struct lista *ant; // 4 bytes - ponteiro para o nC3 anterior
} TLDE; //Tipo Lista Duplamente encadeada

/* Sofreu alteraC'C5es quando comparado com a TLSE */
TLDE*insere_ini(TLDE* l, int valor) {
	TLDE* novoNo = (TLDE*) malloc(sizeof(TLDE));
	novoNo->info = valor;
	novoNo->ant = NULL;
	novoNo->prox = l;
	if(l)
		l->ant = novoNo;
	return novoNo;
}

/*Mesma implementaC'C#o da TLSE*/
void imprimir_lista_while(TLDE* l) { //WHILE
	TLDE* pAux = l;
	while(pAux != NULL) {
		printf("\nValor: %d",pAux->info);
		pAux = pAux->prox;
	}
}

/*Mesma implementaC'C#o da TLSE*/
void imprimir_lista_for(TLDE* l) { //FOR
	TLDE* pAux;
	for(pAux = l; pAux != NULL; pAux = pAux->prox) {
		printf("\nValor: %d",pAux->info);

	}
}

void imprimir_ida_volta(TLDE* l) {
	TLDE* pAuxIda = l;
	TLDE* pAuxVolta = NULL;
	while(pAuxIda) {
		printf("\nValor: %d",pAuxIda->info);
		if(!pAuxIda->prox) //Chegou no ultimo - guardar ponteiro para voltar
			pAuxVolta = pAuxIda;
		pAuxIda = pAuxIda->prox;
	}

	while(pAuxVolta) {
		printf("\nValor: %d",pAuxVolta->info);
		pAuxVolta = pAuxVolta->ant;
	}

}

/*Mesma implementaC'C#o da TLSE*/
void imprimir_lista_recursivo(TLDE* l) {
	if(l->prox!=NULL) {
		imprimir_lista_recursivo(l->prox);
	}
	printf("\nValor: %d",l->info);
}

/*Mesma implementaC'C#o da TLSE*/
TLDE* inicializa_lista() {
	return NULL;
}

/*Mesma implementaC'C#o da TLSE*/
int vazia(TLDE* l) {
	return (l==NULL);
}

/*Mesma implementaC'C#o da TLSE*/
TLDE* liberar_lista_it(TLDE* l) {
	TLDE* pAux = l;
	while(pAux!=NULL) {
		TLDE*t = pAux;
		pAux = pAux->prox;
		free(t);
	}
	return NULL;
}

/*Mesma implementaC'C#o da TLSE*/
TLDE* liberar_lista_rec(TLDE* l) {
	if(l->prox!=NULL) {
		liberar_lista_rec(l->prox);
	}
	free(l);
	return NULL;
}

int main()
{
	TLDE* l = inicializa_lista();
	printf("\nEh vazia? %d",vazia(l));
	l = insere_ini(l, 10);
	l = insere_ini(l, 3);
	printf("\nEh vazia? %d",vazia(l));
	l = insere_ini(l, 9);
	//imprimir_lista_while(l);
	//imprimir_lista_for(l);
	//imprimir_lista_recursivo(l);

	imprimir_ida_volta(l);

	//printf("\nValor: %d",l->prox->prox->ant->ant->info);

	//l = liberar_lista_it(l);

	l = liberar_lista_rec(l);

	printf("\nEh vazia? %d",vazia(l));
	return 0;
}