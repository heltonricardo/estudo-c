#include <stdio.h>
#include <stdlib.h>

#define inserir(lista, v) inserir2(lista, lista, v)
#define exibir(lista)     exibir2(lista, lista)
#define resetar(lista)    resetar2(lista, lista)

typedef struct node {
   short v;
   struct node *p;
} node;

node *novo(short v) {
   node *tmp = (node *) malloc(sizeof(node));
   tmp->p = tmp;
   tmp->v = v;
   return tmp;
}

void resetar2(node *cab, node *lista) {
   if (lista->p != cab)
      resetar2(cab, lista->p);
   free(lista);
}

void inserir2(node *cab, node *lista, short v) {
   if (lista->p != cab)
      inserir2(cab, lista->p, v);
   else {
      lista->p = novo(v);
      lista->p->p = cab;
   }
}

void exibir2(node *cab, node *lista) {
   printf("%hd ", lista->v);
   if (lista->p != cab)
      exibir2(cab, lista->p);
   else printf("\n");
}

int main(void) {
   int i;
   node *lista = novo(1);

   for (i = 2; i <= 10; ++i)
      inserir(lista, i);
   exibir(lista);
   resetar(lista);

   return 0;
}

