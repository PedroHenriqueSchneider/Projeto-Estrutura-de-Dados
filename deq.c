#include <stdio.h>
#include "deque.h"

// Pedro Henrique Bianco Schneider ra:800467

void inicializa(deck *d){ // inicializa o deque 
    d->inicio = -1;
    d->fim = -1;
    d->contador = 0;
}

int vazio(deck *d){ // confere se o deque esta vazio
    
    if(d->contador == 0){
        return 1; // quer dizer que esta vazio
    } 
    else{
        return 0; // nao esta vazio
    }
}

int cheio(deck *d, int n){ // confere se o deque esta cheio
    if(d->contador == n){
        return 1; // retorna que esta cheio
    }
    else{
        return 0; // retorna que nao esta cheio
    }
}

void insereI(deck *d, int elemento, int n){ // insere o elemento no inicio do deque
    if(cheio(d,n)){ // se o deque estiver cheio
        return 0; // retorna 0 se estiver cheio
    }
    else{
        if(vazio(d) == 1){   // se o deque estiver vazio ele reinicia as posicoes com 0
        d->inicio = 0;
        d->fim = 0;
        }
        else{ // se o deque nao estiver vazio, mas o inicio for 0, ele coloca o inicio como a posicao 
            if(d->inicio == 0){
                d->inicio = n-1;
            }
            else{ // se o inicio nao estiver valendo 0
                d->inicio = d->inicio -1;
            }
        }
        d->contador++; // aumenta o contador pra saber se esta cheio
        d->filaDupla[d->inicio] = elemento; // adiciona o elemento no inicio da fila
        
    }
}

void insereF(deck *d,int elemento ,int n){ // insere no final da fila
    if(cheio(d, n)){
        return 0; // se esta cheio retorna 0 
    }
    else{
        if(vazio(d)){ // se ele estiver vazio, valendo -1, ele coloca 0 para os dois
            d->inicio = 0;
            d->fim = 0;
        }
        else{
            if(d->fim == n-1){
                d->fim = 0;
            }
            else{
                d->fim = d->fim+1;
            }
        }
        d->contador++; // aumenta o contador para saber se esta cheio
        d->filaDupla[d->fim] = elemento; // insere o elemento no final
    }
}

int retiraI(deck *d, int n){ // retira do inicio
    if(vazio(d)){ // se a deque esta vazia
        return 0;
    }
    else{
        int valor = d->filaDupla[d->inicio]; // guarda o valor do inicio
        d->filaDupla[d->inicio] = 0;
        if(d->inicio == d->fim){
            d->inicio = -1;
            d->fim = -1;
        }
        else{
                if(d->inicio == n-1){
                d->inicio = 0;
            }
            else{
                d->inicio = d->inicio+1;
            }
        }
        d->contador--; // diminui o contador pois retirou um elemento
        return valor;
    }
}

int retiraF(deck *d, int n){ // retira do final
    
    if(vazio(d)){
        return 0;
    }
    else{
        int valor = d->filaDupla[d->fim]; // salva o elemento do final na int valor
        d->filaDupla[d->fim] = 0;
        if(d->inicio == d->fim){
            d->inicio = -1;
            d->fim = -1;
        }
        else{
            if(d->fim == 0){
                d->fim = n-1;
            }
            else{
                d->fim = d->fim-1;
            }
        }
        d->contador--; // quando retira um elemento o contador diminui
        return valor;
    }
}