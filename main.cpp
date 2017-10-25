#include <iostream>
#include "listaDuplaEncadeada.h"

using namespace std;

int main()
{
    Elemento* l;
    l = cria_lista();
    l = insere_lista_final(l, 23);
    l = insere_lista_final(l, 45);
    l = insere_lista_final(l, 50);
    l = insere_lista_ordenada(l, 30);
    l = insere_lista_final(l, 10);
    l = insere_lista_inicio(l, 15);

    cout<<"primeira impressao"<<endl;
    imprime_lista(l);
    l = remove_lista(l, 45);//buscar valor a ser removido

    cout<<"segunda impressao"<<endl;
    imprime_lista(l);
    l = remove_lista_inicio(l);

    cout<<"terceira impressao"<<endl;
    l = remove_lista(l, 45);//elemento nao encontrado
    imprime_lista(l);

    //busca por indice
    cout<<"Busca por indice: ";
    consulta_lista_pos(l, 2);
    cout<<"\n Busca por valor: ";
    consulta_lista_val(l, 10);

    //remocao no final
    l = remove_lista_final(l);
    cout<<"5 impressão"<<endl;
    imprime_lista(l);

    l = remove_lista_final(l);
    cout<< "6 impressao:"<<endl;
    imprime_lista(l);

    libera_lista(l);

    return 0;
}
