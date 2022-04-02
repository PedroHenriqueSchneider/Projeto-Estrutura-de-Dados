#ifndef LISTA_H // conferir se é com letra maiúscula!
#define LISTA_H 
#include <stdio.h>
#include <malloc.h>
#include <string.h>
typedef struct node{
    char data[50]; // elemento dentro do struct. Observar se vai ser do tipo char ou int ou float
    int ra;
    struct node *prox, *anterior; // ponteiro que aponta para o elemento da frente e de trás
}node;

typedef struct{
    node *sentinela; // ponteiro do sentinela
    unsigned quantidadeElements; // quantidade de elementos armazenados
}listaEncadeada;

typedef struct{
    struct node *posicao;
    listaEncadeada *estrutura;
}iterador;


void inicializar(listaEncadeada *p);
void fechar(listaEncadeada *p);
int vazia(listaEncadeada *p);
void inserirInit(listaEncadeada *p, char data[], int ra);
void inserirFim(listaEncadeada *p, char data[], int ra);
int removeFim(listaEncadeada *p);
int removeIni(listaEncadeada *p);
void alunosCadastrados(listaEncadeada *p);

iterador procuraP(listaEncadeada* p, char data[], int ra);
iterador procuraD(iterador i, char data[], int ra);
iterador procuraPosition(listaEncadeada* p, unsigned position);

#endif
