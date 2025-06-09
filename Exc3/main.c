#include <stdio.h>
#include <stdlib.h>
#include "ArvBin.h"

int main() {

    ArvBin *arvore = cria_ArvBin();

    insere_ArvBin(arvore, 1);
    insere_ArvBin(arvore, 4);
    insere_ArvBin(arvore, -5);
    insere_ArvBin(arvore, 3);
    insere_ArvBin(arvore, 7);


    printf("Tamanho: %d", TotalNO_Arvore(arvore));


    libera_ArvBin(arvore);
    return 0;
}
