//
// Created by Pichau on 08/06/2025.
//
#include <stdio.h>
#include <stdlib.h>
#include "ArvBin.h" //inclui os Prottipos

struct NO{
    int info;
    struct NO *esq;
    struct NO *dir;
};

ArvBin* cria_ArvBin(){
    ArvBin* raiz = (ArvBin*) malloc(sizeof(ArvBin));
    if(raiz != NULL)
        *raiz = NULL;
    return raiz;
}

void libera_NO(struct NO* no){
    if(no == NULL)
        return;
    libera_NO(no->esq);
    libera_NO(no->dir);
    free(no);
    no = NULL;
}

void libera_ArvBin(ArvBin* raiz){
    if(raiz == NULL)
        return;
    libera_NO(*raiz);//libera cada nó
    free(raiz);//libera a raiz
}

int insere_ArvBin(ArvBin* raiz, int valor){
    if(raiz == NULL) // Verifica se a arvore existe
        return 0;
    struct NO* novo;
    novo = (struct NO*) malloc(sizeof(struct NO)); //Cria um novo elemento
    if(novo == NULL) // Verifica se o novo elemento existe
        return 0;
    novo->info = valor; // Atribui o vlor ao novo elemento
    novo->dir = NULL; // Define os ponteiros como NULL
    novo->esq = NULL;

    if(*raiz == NULL) // Se a arvora ainda não possui elementos,
        *raiz = novo; // então o novo elemento se torna a Raiz principal e encerra a função
    else{
        struct NO* atual = *raiz; // Cria um elemento para o nó atual e um para o nó anterior
        struct NO* ant = NULL;
        while(atual != NULL){
            ant = atual;
            if(valor == atual->info){ //Se o elemento já existir, então cancela a criação do novo elemento
                free(novo);
                return 0; //elemento já existe
            }

            if(valor > atual->info) // Se o valor do elemento for maior que o do atual, vai para a direita
                atual = atual->dir;
            else
                atual = atual->esq; // Se for menor, vai para a esquerda
        }
        // Quando o elemento Atual chegou no NULL
        if(valor > ant->info) //Verifica se é maior ou menor que o anterior e adiciona para o respectivo lado.
            ant->dir = novo;
        else
            ant->esq = novo;
    }
    return 1;
}
// A função, de forma geral, serve para organizar de uma forma que facilite a procurá dos elementos depois,
// pois os elementos a esquerda sempre são menores que os elementos a direita da raiz.

int remove_ArvBin(ArvBin *raiz, int valor){
    if(raiz == NULL) // Verifica se a árvore existe
        return 0;
    struct NO* ant = NULL; // Cria o elemento anterior e o atual para percorrer a arvore.
    struct NO* atual = *raiz;
    while(atual != NULL){
        if(valor == atual->info){ // Se o valor a ser removido está no elemento atual
            if(atual == *raiz) // Se o atual for o principal da raiz
                *raiz = remove_atual(atual);
            else{
                if(ant->dir == atual) // Ajusta o ponteiro do nó pai para o novo nó filho
                    ant->dir = remove_atual(atual);
                else
                    ant->esq = remove_atual(atual);
            }
            return 1;
        }
        ant = atual;
        if(valor > atual->info) // Mantem a busca, considerando os lados para maior e menor valor
            atual = atual->dir;
        else
            atual = atual->esq;
    }
    return 0; // Valor nao foi encontrado
}


struct NO* remove_atual(struct NO* atual) {
    struct NO *no1, *no2;
    if(atual->esq == NULL){ // No nao tem filho a esquerda
        no2 = atual->dir; // Pega o filho direito
        free(atual); // Libera o no Atual
        return no2; // Retorna o filho direito para substituir o nó atual que foi removido
    }
    no1 = atual; // Nó tem coisa a esquerda
    no2 = atual->esq;
    while(no2->dir != NULL){ // Encontra o maior valor da subarvore a direita
        no1 = no2;
        no2 = no2->dir;
    }
    if(no1 != atual){ // Ajusta a ordenação caso o no2 nao seja o logo a esquerda do atual
        no1->dir = no2->esq; // Ajusta para o no pai apontar para a esquerda no no filho, mantendo a organização
        no2->esq = atual->esq; // Coloca o no filho apontando para onde o no atual apontava, pois ele o substituirá
    }
    no2->dir = atual->dir; // Mantém o no2 apontando para a direita da onde o no atual aponta.
    free(atual);
    return no2; // Retorna o no2 para atualizar o valor do no atual
}
// As funções de remove servem para manter a organização ao remover o elemento, o que elas fazem é procurar o elemento
// Cujo valor sirva para substituir o atual a ser removido e ainda sim manter a organização da árvore com os menores elemento
// Sempre a esquerda da raíz, e os maiores a direita.

void preOrdem_ArvBin(ArvBin *raiz){
    if(raiz == NULL)
        return;
    if(*raiz != NULL){
        printf("%d\n",(*raiz)->info);
        preOrdem_ArvBin(&((*raiz)->esq));
        preOrdem_ArvBin(&((*raiz)->dir));
    }
}

