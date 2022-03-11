// .h eh uma API, desse modo, incluimos todas as interfaces dos programas, funcoes e procedimentos.
#ifndef deq_h
#define deq_h
#define MAX 550000 

// Pedro Henrique Bianco Schneider ra:800467

typedef struct{ // inicia a struct da deque 
    int filaDupla[MAX]; // o proprio vetor da deque
    int contador; // contador de elementos
    int inicio; // posicao do inicio
    int fim; // posicao do final
}deck; 


void inicializa(deck *d); // inicializa a deque
int vazio(deck *d); // confere se esta vazia
int cheio(deck *d, int n); // confere se esta cheia
void insereI(deck *d, int elemento, int n); // insere no comeco
void insereF(deck *d, int elemento, int n); // insere no final
int retiraI(deck *d, int n); // retira do comeco
int retiraF(deck *d, int n); // retira do final


#endif