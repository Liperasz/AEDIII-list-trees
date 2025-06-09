#include <stdio.h>
#include <stdlib.h>
#include "ArvBin.h"

int main() {

    ArvBin *arvore = cria_ArvBin();

    insere_ArvBin(arvore, 1);
    insere_ArvBin(arvore, 4);
    insere_ArvBin(arvore, -5);
    insere_ArvBin(arvore, 3);

    preOrdem_ArvBin(arvore);
    printf("\n\n");

    remove_ArvBin(arvore, 4);

    preOrdem_ArvBin(arvore);
    printf("\n\n");


    libera_ArvBin(arvore);
    return 0;
}
