#include <stdlib.h>
#include <stdio.h>

struct arvgen {
    int info;
    struct arvgen *prim;
    struct arvgen *prox;
};
typedef struct arvgen arvGen;

arvGen* cria_arvore (int c);
void insere_arvore (arvGen* a, arvGen* sa);
void imprime_arvore (arvGen* a);

int main (){
    /* criando nodes da arvore */
    arvGen*     node1 = cria_arvore(6);
    arvGen*     node2 = cria_arvore(8);
    arvGen*     node3 = cria_arvore(7);
    arvGen*     node4 = cria_arvore(10);
    arvGen*     node5 = cria_arvore(22);

    /* montando hierarquia */
    insere_arvore(node1, node2);
    insere_arvore(node2, node3);
    insere_arvore(node1, node4);

    imprime_arvore(node1);

    return 0;
}

arvGen* cria_arvore (int c){
    arvGen *node = (arvGen *) malloc(sizeof(arvGen));
    
    node->info = c;    
    node->prim = NULL;
    node->prox = NULL;

    return node;
}

void insere_arvore (arvGen* a, arvGen* sa){
    sa->prox = a->prim;
    a->prim = sa;    
}

void imprime_arvore (arvGen* a){
    arvGen* p;
    
    printf("<%d\n", a->info);

    for(p = a->prim; p != NULL; p = p->prox){
        imprime_arvore(p);
    }
    
    printf(">");
}
