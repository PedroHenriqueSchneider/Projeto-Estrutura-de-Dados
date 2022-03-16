#ifndef LISTA_H // conferir se é com letra maiúscula!
#define LISTA_H 

struct node{
    char data; // elemento dentro do struct. Observar se vai ser do tipo char ou int ou float
    struct node *prox, *anterior; // ponteiro que aponta para o elemento da frente e de trás
};

typedef struct{
    struct node *sentinela; // ponteiro do sentinela
    unsigned quantidadeElements; // quantidade de elementos armazenados
}listaEncadeada;



#endif