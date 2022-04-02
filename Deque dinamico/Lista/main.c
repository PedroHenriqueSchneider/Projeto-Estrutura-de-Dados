#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main(int argv, char *argc[]){
    listaEncadeada alunos;
    inicializar(&alunos);
    inserirFim(&alunos, "Pedro Henrique", 800863);
    inserirFim(&alunos, "Jimin do Bts", 855630);
    inserirFim(&alunos, "Pedro Henrique", 582638);
    alunosCadastrados(&alunos);

    for( iterador it = begin(&alunos);  !acabou(it); it = proximo(it))


    return 0;
}