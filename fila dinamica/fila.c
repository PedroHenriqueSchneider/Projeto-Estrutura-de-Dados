#include <stdio.h>
#include <malloc.h>
#include "fila.h"

void insereInicio(struct fila** head, int val)
{
    struct fila* new_fila = (struct fila*)malloc(sizeof(struct fila));
 
    new_fila->valor = val;
 
    new_fila->next = (*head);
    new_fila->before = NULL;
 
    if ((*head) != NULL)
        (*head)->before = new_fila;

    (*head) = new_fila;
}

void insereFim(struct fila** head, int val)
{
    struct fila* new_fila = (struct fila*)malloc(sizeof(struct fila));
 
    struct fila* last = *head;
 
    new_fila->valor = val;
 
    new_fila->next = NULL;

    if (*head == NULL) {
        new_fila->before = NULL;
        *head = new_fila;
        return;
    }
    while (last->next != NULL)
        last = last->next;
 
    last->next = new_fila;
 
    new_fila->before = last;
 
    return;
}
int tamanhofila(struct fila* fila)
{
    int tam = 0;
    while(fila != NULL)
    {
        fila = fila->next;
        tam++;
    }
    return tam;

}

void deleteLast(struct fila** head, struct fila* last)
{
    while (last->next != NULL) {
        last = last->next;
    }
    if (*head == last)
        *head = last->next;

    printf("%d\n", last->valor);

    if(last->before != NULL){
        last->before->next = NULL;
    }

    free(last);

}
void deleteInicio(struct fila** head, struct fila* home)
{
    if (*head == home)
        *head = home->next;
 
    if (home->next != NULL)
        home->next->before = home->before;

    if (home->before != NULL)
        home->before->next = home->next;

    printf("%d\n", home->valor);

    free(home);
    return;
}