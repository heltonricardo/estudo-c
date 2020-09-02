#include <stdio.h>
#include <stdlib.h>


typedef struct node {
  int v;
  struct node *p;
} node;


node *criarNo(int v) {

  node *novo = (node *) malloc(sizeof(node));

  if (novo) {
    novo->v = v;
    novo->p = 0;
  }

  return novo;
}


void inserir(node **lista, int v) {

  node *novo = criarNo(v);
  if (!novo) return;

  node *aux = *lista;
  if (aux->v > v) {
    novo->p = *lista;
    *lista = novo;
    return;
  }

  while (aux->p && aux->p->v < v)
    aux = aux->p;

  novo->p = aux->p;
  aux->p = novo;
}


void exibir(node *lista) {

  if (lista) {
    printf("%d ", lista->v);
    exibir(lista->p);
  }

  else
    printf("\n");
}


void liberar(node *lista) {

  if (lista->p)
    liberar(lista->p);

  free(lista);
}


int main(void) {

  node *lista = criarNo(13);
  if (!lista) return 1;

  int valores[] = {27, 18, 14, 28, 27,  0, 30, 36, 19,  1, 19, 27, 22, 11,
                   30, 22, 17, 11, 14, 45, 39,  3, 50, 44, 25, 49, 31, 24, 30};
  int tamanho = sizeof(valores) / sizeof(int);

  for (int i = 0; i < tamanho; ++i)
    inserir(&lista, valores[i]);

  exibir(lista);

  free(lista);
  return 0;
}

