#include <stdio.h>
#include <malloc.h>
#include "fila.h"

// Alocação dinâmica e sequencial já feita.
// Necessário a documentar o código.

void insereInicio(struct fila** head, int val)
{
    /*Recebe um valor e um ponteiro para Head
    aloca espaço e insere
    */
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
    /* Recebe um valor e ponteiro pra Head
       itera até o fim do deque
       aloca espaço e insere o valor 
    */
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
    //itera sobre os valores do deque e retorna seu tamanho
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
    /* Pega o ponteiro na Head
    itera ate o fim e desaloca o espaço utilizado
    */
    while (last->next != NULL) {
        last = last->next;
    }
    if (*head == last)
        *head = last->next;
    // printf("%d\n", last->valor);
    if(last->before != NULL){
        last->before->next = NULL;
    }
    free(last);
}
void deleteInicio(struct fila** head, struct fila* home)
{
    /*Pega o ponteiro na Head
    e desaloca o espaço utilizado*/
    if (*head == home)
        *head = home->next;
 
    if (home->next != NULL)
        home->next->before = home->before;

    if (home->before != NULL)
        home->before->next = home->next;

    // printf("%d\n", home->valor);

    free(home);
    return;
}