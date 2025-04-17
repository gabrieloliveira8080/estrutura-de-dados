#include <stdio.h>
#include "TLDE.h"

int main(int argc, char *argv[]) {

    Lista* l = criar_lista();
    printf("\nTamanho da lista = %d",tamanho_lista(l));
    Produto P1;
    P1.codigo = 10;
    P1.preco = 100.99;
    P1.qtdEstoque = 100;
    Produto P2;
    P2.codigo = 11;
    P2.preco = 101.99;
    P2.qtdEstoque = 101;
    Produto P3;
    P3.codigo = 12;
    P3.preco = 102.99;
    P3.qtdEstoque = 102;


    insere_ordenado (l,&P1);
    insere_ordenado (l,&P3);
    insere_ordenado (l,&P2);

    //inserir_inicio(l,&P1);
    //inserir_inicio(l,&P2);
    //inserir_inicio(l,&P3);

    printf("\nTamanho da lista = %d",tamanho_lista(l));

    imprimir_ida_volta(l);

    if(retira(l,12)){
        printf("\nremovido com sucesso!");
    }
    imprimir_ida_volta(l);


    libera_lista(l);

    return 0;
}
