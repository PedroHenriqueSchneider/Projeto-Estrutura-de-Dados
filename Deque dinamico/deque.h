#ifndef DEQUE_H
#define DEQUE_H

typedef struct node{
    int valor;
    struct node* prev;
    struct node* next;
}node;

typedef struct deque
{
    struct node* head;
    struct node* end;  
    int elementos;
    int tam_total;
}deque;

int vazia(deque* d);
int cheia(deque* d);
void inicializa(deque* d, int tam);
void insereInicio(deque* d, int val);
void insereFim(deque* d, int val);
void deleteInicio(deque *d);
void deleteLast(deque *d);

#endif