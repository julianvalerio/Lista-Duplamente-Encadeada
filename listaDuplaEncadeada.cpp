#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "listaDuplaEncadeada.h"
using namespace std;
//função para verificar se lista foi criada
struct elemento{
    int valor;
    struct elemento *ant;
    struct elemento *prox;
};

Elemento* cria_lista(){
    return NULL;
}

void libera_lista(Elemento* li){
    if(li != NULL){
        Elemento* aux = li;
        Elemento* rmv;
        while(aux != NULL){
            rmv = aux->prox; //guarda ref para prox elemento
            free(aux); //libera memória
            aux=rmv;
        }
    }
}

int consulta_lista_pos(Elemento* li, int pos){
    if(li == NULL || pos <= 0)
        return 0;
    Elemento* aux = li;
    int i = 1;
    while(aux != NULL && i < pos){
        aux = aux->prox;
        i++;
    }
    if(aux == NULL){
        cout<<"Elemento não encontrado!"<<endl;
        return 0;
    }
    else{
        cout<<"Elemento encontrado:"<< endl;
        cout<< "Valor = " << aux->valor<<endl;
        return 1;
    }
}

int consulta_lista_val(Elemento* li, int val){
    if(li == NULL)
        return 0;
    Elemento* aux = li;
    while(aux != NULL && aux->valor != val){
        aux = aux->prox;
    }
    if(aux == NULL){//cheguei ao final da lista e não encontrei
        cout<<"Elemento não encontrado!"<<endl;
        return 0;
    }
    else{
        cout<<"Elemento encontrado: " << aux->valor << endl; ;
        return 1;
    }
}

Elemento* insere_lista_final(Elemento* li, int val){
    Elemento *novo;
    novo = (Elemento*) malloc(sizeof(Elemento));
    if(novo == NULL)
        return li;//alocacao nao deu certo
    novo->valor = val;
    novo->prox = NULL;
    if(li == NULL){//lista vazia: insere início
        novo->ant = NULL;
        li = novo;
    }else{
        Elemento *aux;
        aux = li;
        while(aux->prox != NULL){
            aux = aux->prox;
        }
        aux->prox = novo;
        novo->ant = aux;
    }
    return li;
}

Elemento* insere_lista_inicio(Elemento* li, int val){
    Elemento* novo;
    novo = (Elemento*) malloc(sizeof(Elemento));
    if(novo == NULL)
        return li;
    novo->valor = val;
    novo->prox = li;
    novo->ant = NULL;
    if(li != NULL){//lista não vazia: apontar para o anterior!
        li->ant = novo;
    }
    li = novo;
    return li;
}

Elemento* insere_lista_ordenada(Elemento* li, int val){
    Elemento *novo = (Elemento*) malloc(sizeof(Elemento));
    if(novo == NULL)
        return li;
    novo->valor = val;
    if(li == NULL){//lista vazia: insere início
        novo->prox = NULL;
        novo->ant = NULL;
        li = novo;
        return li;
    }else{
        Elemento *aux, *atual = li;
        while(atual != NULL && atual->valor < val){
            aux = atual;
            atual = atual->prox;
        }
        if(atual == li){//insere início
            novo->ant = NULL;
            li->ant = novo;
            novo->prox = li;
            li = novo;
        }else{
            novo->prox = aux->prox;
            novo->ant = aux;
            aux->prox = novo;
            if(atual != NULL)
                atual->ant = novo;
        }
        return li;
    }
}

Elemento* remove_lista(Elemento* li, int val){//TERMINAR
    Elemento *aux = li;
    while(aux != NULL && aux->valor != val){
        aux = aux->prox;
    }
    if(aux == NULL){//não encontrado
        cout<<"Elemento não encontrado!"<<endl;
        return li;
    }
    if(aux->ant == NULL)//remover o primeiro?
        li = aux->prox;
    else
        aux->ant->prox = aux->prox;
    if(aux->prox != NULL)//não é o último?
        aux->prox->ant = aux->ant;
    free(aux);
    return li;
}


Elemento* remove_lista_inicio(Elemento* li){
    if(li == NULL){
        cout<< "Lista Vazia";
        return li;
    }
    Elemento *no = li;
    li = no->prox;
    if(no->prox != NULL)
        no->prox->ant = NULL;

    free(no);
    return li;
}

Elemento* remove_lista_final(Elemento* li){
    if(li == NULL){
        cout<< "Lista Vazia";
        return li;
    }
    Elemento *aux = li;
    while(aux->prox != NULL)
        aux = aux->prox;

    if(aux->ant == NULL)//remover o primeiro e único
        li = aux->prox;
    else
        aux->ant->prox = NULL;

    free(aux);
    return li;
}

int tamanho_lista(Elemento* li){
    int cont = 0;
    Elemento* aux = li;
    while(aux != NULL){
        cont++;
        aux = aux->prox;
    }
    return cont;
}

int lista_vazia(Elemento* li){
    if(li == NULL)
        return 1;
    return 0;
}

void imprime_lista(Elemento* li){
    if(li == NULL)
        cout<<"lista vazia"<< endl;
    Elemento* aux = li;
    while(aux != NULL){
        cout<< "Valor= " << aux->valor << endl;
        aux = aux->prox;
    }
}
