#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node {
   int v;
   struct node *a, *p;
} node;

node *novoNo(int v) {
   node *novo = (node *) malloc(sizeof(node));
   novo->v = v;
   novo->a = novo->p = 0;
   return novo;
}

node *inserirF(node *lista, int n) {
   node *novo = novoNo(n);
   while (lista->p) lista = lista->p;
   lista->p = novo;
   novo->a = lista;
   return novo;
}

node *inserirC(node *lista, int n) {
   node *novo = novoNo(n);
   while (lista->a) lista = lista->a;
   lista->a = novo;
   novo->p = lista;
   return novo;
}

void inserirO(node *lista, int n) {
   if (lista->p) {
      if (n < lista->p->v) {
         node *novo = novoNo(n);
         novo->p = lista->p;
         lista->p->a = novo;
         lista->p = novo;
         novo->a = lista;
      } else inserirO(lista->p, n);
   } else {
      node *novo = novoNo(n);
      lista->p = novo;
      novo->a = lista;
   }
}

void exibirCF(node *lista) {
   while (lista) {
      printf("%3d ", lista->v);
      lista = lista->p;
   }
   printf("\n");
}

void exibirFC(node *lista) {
   while (lista) {
      printf("%3d ", lista->v);
      lista = lista->a;
   }
}

void limpar(node *lista) {
   if (lista->p) limpar(lista->p);
   free(lista);
}

int main(void) {
   int i, n, r;
   node *cab, *cau;
   srand(time(0));

   printf("\n Insira o valor do inicio da lista: ");
   scanf("%d", &n);
   cab = cau = novoNo(n);


   printf("\n Quantidade de valores para gerar na lista: ");
   scanf("%d", &n);
   for (i = 0; i < n; ++i) {
      r = rand() % 1000;
      inserirO(cab, r);
      printf("%3d ", r);
   }
   printf("\n");

   exibirCF(cab);

   limpar(cab);
   return 0;
}

