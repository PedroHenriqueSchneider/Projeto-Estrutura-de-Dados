#ifndef fila_H
#define fila_H

// link :: https://panda.ime.usp.br/panda/static/pythonds_pt/03-EDBasicos/02-EstruturasLineares.html
// link :: https://libcheck.github.io/check/
// link :: https://panda.ime.usp.br/panda/static/pythonds_pt/03-EDBasicos/10-Filas.html

struct fila
{
    int valor;
    struct fila* before;
    struct fila* next;  
};

void insereInicio(struct fila** head, int val);
void insereFim(struct fila** head, int val);
int tamanhofila(struct fila* fila);
void deleteInicio(struct fila** head, struct fila* home);
void deleteLast(struct fila** head, struct fila* last);

#endif