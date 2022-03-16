// O sentinela fica no início e no fim da lista, ou seja, o sentinela aponta para o primeiro elemento da lista e o ultimo elemento da lista aponta para o sentinela..
// Na lista duplamente encadeada circular possuimos apenas um sentinela.
// Necessário ainda colocar os iteradores para colocar e remover elementos do meio da lista.

#include "lista.h"

// função que inicializa           
void inicializar(listaEncadeada *p){
    struct node *n = (struct node*) malloc (sizeof(struct node));
    n->prox = n->anterior = p->sentinela = n;
    p->quantidadeElements = 0;
}


void fechar(listaEncadeada *p){
    while(!vazia(p)){
        removerInit(p);
    }
    free(p->sentinela);
}


int vazia(listaEncadeada *p){
    return p->sentinela->prox == p->sentinela; 
}


void inserirInit(listaEncadeada *p, char data){
    struct node *n = (struct node*)malloc(sizeof(struct node)); // aloca memória 
    n->data = data; // coloca dentro do elemento da struct ponteiro o elemento de quando chama a funcao
    n->prox = p->sentinela->prox; // coloca dentro do ponteiro que aponta para o proximo elemento o ponteiro da sentinela 
    n->anterior = p->sentinela; // coloca dentro do ponteiro que aponta para o elemento anterior o sentinela
    p->sentinela->prox = n; // colocando dentro do sentinela que aponta para o proximo o struct n
    n->prox->anterior = n; 
    p->quantidadeElements++; // aumenta dentro do struct o número de elementos
}


void removeFim(listaEncadeada *p){
    struct node *n = p->sentinela->anterior;
        if( n != p->sentinela ) { // lista vazia
        n->prox->anterior = n->anterior;
        n->anterior->prox = n->prox;
        free(n);
        p->quantidadeElements--;
    }
}