#include <stdio.h>
#include <malloc.h>
#include "deque.h"

int vazia(deque* d)
{
    return (d->elementos == 0);
}

int cheia(deque* d)
{
    return (d->elementos == d->tam_total);
}

void inicializa(deque* d, int tam) //inicializa com o tamanho total do deque
{
    d->head = NULL;
    d->end = NULL;
    d->elementos = 0;
    d->tam_total = tam;
}
void insereInicio(deque* d, int val)
{
    if(cheia(d)){
        printf("cheia\n");
        return;
    }
    node* n = (node*)malloc(sizeof(node));
 
    n->valor = val;
    n->prev = NULL;
    if(d->head == NULL){ // se vazia o proximo aponta pra null
        n->next = NULL;
        d->end = n; // e o final aponta pro mesmo node
    }
    if (d->head != NULL){  // caso não vazia fazemos as ligacoes entre os nodes
        n->next = d->head;
        d->head->prev = n;
    }
    d->elementos++;
    d->head = n;
}

void insereFim(deque* d, int val)
{
    if(cheia(d)){
        printf("cheia\n");
        return;
    }
    node* n = (node*)malloc(sizeof(node));
 
 
    n->valor = val;
 
    n->next = NULL;

    if (d->end == NULL) { // caso deque vazio
        d->head = n;
        n->prev = NULL;
    }
    if(d->end != NULL){ // ligacao caso já exista nodes no deque
        d->end->next = n;
        n->prev = d->end;
    }
    d->end = n;
    d->elementos++;
    return;
}

void deleteLast(deque *d)
{
    if(vazia(d)){
        printf("vazia\n");
        return;
    }
    node *remove = d->end;
    d->end = d->end->prev; //o deque nao esta vazio entao pulamos para o proximo node e analisamos ele
    if(d->end == NULL) // caso o prox vazio reinicializamos o deque    
        d->head = NULL;
    
    if(d->end != NULL)
        d->end->next = NULL;
    
    printf("%d\n", remove->valor);
    d->elementos--;
    free(remove);

}
void deleteInicio(deque *d)
{
    if(vazia(d)){
        printf("vazia\n");
        return;
    }
    node *n = d->head;
    d->head = d->head->next;//o deque nao esta vazio entao pulamos para o proximo node e analisamos ele
    
    if (d->head == NULL){// deque estara vazio portanto reinicializamos
        d->end = NULL;
    }
    if(d->head != NULL){// deque não vazio realocamos ponteiros
        d->head->prev = NULL;
    }
    printf("%d\n", n->valor);
    d->elementos--;
    free(n);
    return;
}