#include <stdio.h>
#include "lista.h"
#include "fila.h"
int main()
{
    listaEncadeada i;
    inicializar(&i);
    insereF(&i, 10);
    insereF(&i, 9);
    insereI(&i, 8);
    insereI(&i, 7);
    insereI(&i, 6);
    iterador t;
    for( t = begin(&i); !acabou(t); t = proximo(t) )
    {
        if (elemento(t) == 6){
            insereAntes(&i, t, 111);
            insereDepois(&i, t, 340340);
            removePosicao(&i, t);
        }
        printf("%d\n",elemento(t));
    }
    return 0;
}