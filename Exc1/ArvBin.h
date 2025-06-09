//
// Created by Pichau on 08/06/2025.
//

#ifndef ARVBIN_H
#define ARVBIN_H

typedef struct NO* ArvBin;

ArvBin* cria_ArvBin();
void libera_ArvBin(ArvBin *raiz);
int insere_ArvBin(ArvBin* raiz, int valor);
int remove_ArvBin(ArvBin *raiz, int valor);
struct NO* remove_atual(struct NO* atual);
void preOrdem_ArvBin(ArvBin *raiz);

#endif //ARVBIN_H
