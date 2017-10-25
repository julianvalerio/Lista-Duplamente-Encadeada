#ifndef LISTADUPLAENCADEADA_H_INCLUDED
#define LISTADUPLAENCADEADA_H_INCLUDED
typedef struct elemento Elemento;
Elemento* cria_lista();
void libera_lista(Elemento* li);
int consulta_lista_pos(Elemento* li, int pos);
int consulta_lista_val(Elemento* li, int valor);
Elemento* insere_lista_final(Elemento* li, int valor);
Elemento* insere_lista_inicio(Elemento* li, int valor);
Elemento* insere_lista_ordenada(Elemento* li, int valor);
Elemento* remove_lista(Elemento* li, int valor);
Elemento* remove_lista_inicio(Elemento* li);
Elemento* remove_lista_final(Elemento* li);
int tamanho_lista(Elemento* li);
int lista_vazia(Elemento* li);
void imprime_lista(Elemento* li);
#endif // LISTADUPLAENCADEADA_H_INCLUDED
