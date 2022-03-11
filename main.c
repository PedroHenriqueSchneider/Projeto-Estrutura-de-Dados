#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "deq.h"

// Pedro Henrique Bianco Schneider ra:800467

int main(int argv, char *argc[])
{
    //deck d;
    deck d;      // instancia o deque
    int n, m;    // numero de comandos e numero maximo de elementos respectivamente
    char o[80]; // opcoes
    int elemento;

    inicializa(&d);

    scanf("%d%d", &n, &m);

    for (int i = 0; i < n; i++)
    {
        scanf("%s", o);
        if (strcmp(o,"insereI") == 0) // string compare com o que foi inserido para fazer certa operacao
        {
            scanf("%d", &elemento);
            insereI(&d,elemento , m); 
        }
        else if (strcmp(o,"insereF") == 0)
        {
            scanf("%d", &elemento);
            insereF(&d, elemento, m);
        }
        else if (strcmp(o,"removeI") == 0)
        {
            retiraI(&d, m);
        }
        else if (strcmp(o,"removeF") == 0)
        {
            retiraF(&d, m);
        }
        else
        {
            continue;
        }
    }
    return 0;
}