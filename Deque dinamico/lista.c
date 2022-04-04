// O sentinela fica no início e no fim da lista, ou seja, o sentinela aponta para o primeiro elemento da lista e o ultimo elemento da lista aponta para o sentinela..
// Na lista duplamente encadeada circular possuimos apenas um sentinela.
// Necessário ainda colocar os iteradores para colocar e remover elementos do meio da lista.

#include "lista.h"
// função que inicializa o sentinela
void inicializar(listaEncadeada *p)
{
    node *n = (node *)malloc(sizeof(node));
    n->prox = n->anterior = p->sentinela = n;
    p->quantidadeElements = 0;
}

// destroi a lista e o sentinela
void destroyL(listaEncadeada *p)
{
    while (!vaziaL(p))
    {
        removeI(p);
    }
    free(p->sentinela);
}

int vaziaL(listaEncadeada *p)
{
    return p->sentinela->prox == p->sentinela;
}

int insereI(listaEncadeada *p, int ra)
{
    node *n = (node *)malloc(sizeof(node)); // aloca memória
                                            // coloca dentro do elemento da struct ponteiro o elemento de quando chama a funcao

    n->ra = ra;

    n->prox = p->sentinela->prox; // coloca dentro do ponteiro que aponta para o proximo elemento o ponteiro da sentinela
    n->anterior = p->sentinela;   // coloca dentro do ponteiro que aponta para o elemento anterior o sentinela
    p->sentinela->prox = n;       // colocando dentro do sentinela que aponta para o proximo o struct n
    n->prox->anterior = n;
    p->quantidadeElements++; // aumenta dentro do struct o número de elementos

    return n->ra;
}

int insereF(listaEncadeada *p, int ra)
{
    node *n = (node *)malloc(sizeof(node));

    n->ra = ra;

    n->prox = p->sentinela;
    n->anterior = p->sentinela->anterior;
    p->sentinela->anterior = n;
    n->anterior->prox = n;
    p->quantidadeElements++;

    return n->ra;
}

int removeF(listaEncadeada *p)
{
    node *n = p->sentinela->anterior;
    if (n != p->sentinela)
    { // lista vazia
        n->prox->anterior = n->anterior;
        n->anterior->prox = n->prox;
        int x = n->ra;
        free(n);
        p->quantidadeElements--;
        return x;
    }
    return -1;
}

int removeI(listaEncadeada *p)
{
    node *n = p->sentinela->prox;
    if (n != p->sentinela)
    { // lista vazia
        n->anterior->prox = n->prox;
        n->prox->anterior = n->anterior;
        int x = n->ra;
        free(n);
        p->quantidadeElements--;
        return x;
    }
    return -1;
}

// iterador begin(listaEncadeada *p)
// {
//     iterador i;
//     i.posicao = p->sentinela->prox;
//     i.estrutura = p;
//     return i;
// }
// iterador end(listaEncadeada *p)
// {
//     iterador i;
//     i.posicao = p->sentinela->anterior;
//     i.estrutura = p;
//     return i;
// }

// char elemento(iterador i)
// {
//     return i.posicao->data;
// }

// int acabou(iterador i)
// {
//     return i.posicao == i.estrutura->sentinela;
// }

// int proximo( iterador* i)
// {
//     if(!acabou(i))
//     {
//         i->posicao = i->posicao->prox;
//         return 1;
//     }
//     return 0;
// }

// void alunosCadastrados(listaEncadeada *p)
// {
//     node *n = p->sentinela->prox;
//     while (n != p->sentinela)
//     {
//         n = n->prox;
//     }
//     return;
// }