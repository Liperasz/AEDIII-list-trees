#include <stdio.h>
#include <stdlib.h>
#include "ArvBin.h"

int main(){
    int N = 8, dados[8] = {50, 100, 30, 20, 40, 45, 35, 37};

    ArvBin* raiz = cria_ArvBin();

    for(int i = 0; i < N; i++)
        insere_ArvBin(raiz, dados[i]);

    printf("=== Pre-Ordem ===\n");
    preOrdem_ArvBin(raiz);

    printf("\n=== Em-Ordem ===\n");
    emOrdem_ArvBin(raiz);

    printf("\n=== Pos-Ordem ===\n");
    posOrdem_ArvBin(raiz);

    printf("\n=== Remoção do valor 50 ===\n");
    if(remove_ArvBin(raiz, 50)){
        printf("Removido com sucesso!\n");

        printf("\nPre-Ordem após remoção:\n");
        preOrdem_ArvBin(raiz);

        printf("\nEm-Ordem após remoção:\n");
        emOrdem_ArvBin(raiz);

        printf("\nPos-Ordem após remoção:\n");
        posOrdem_ArvBin(raiz);
    } else {
        printf("Valor 50 NÃO encontrado para remoção.\n");
    }

    libera_ArvBin(raiz);
    printf("\nFim!\n");
    return 0;
}
