#include <stdio.h>
#include <stdlib.h>

typedef struct node {
   int valor;
   struct node *prox;
} node;

typedef struct Fila {
   node *inicio;
   node *fim;
} Fila;

void inicializar(Fila **fila) {
   *fila = (Fila *) malloc(sizeof(Fila));
   if (fila)
      (*fila)->inicio = (*fila)->fim = NULL;
   else
      printf("\nERRO DE MEMORIA\n");
}

node *novoNo(int valor) {
   node *novo = (node *) malloc(sizeof(node));
   if (novo) {
      novo->valor = valor;
      novo->prox = NULL;
   }
   else printf("\nERRO DE MEMORIA\n");
   return novo;
}

int filaVazia(Fila *fila) {
   if (!fila->inicio) return 1;
   return 0;
}

int enfileirar(Fila *fila, int valor) {
   node *novo = novoNo(valor);
   if (!novo) return 0;

   if (filaVazia(fila))
      fila->inicio = novo;
   else
      fila->fim->prox = novo;

   fila->fim = novo;
   return 1;
}

int desenfileirar(Fila *fila) {
   if (filaVazia(fila)) return 0;

   int valor = fila->inicio->valor;
   Fila *rmv = fila->inicio;
   fila->inicio = fila->inicio->prox;

   free(rmv);
   return valor;
}

void imprimir(Fila *fila) {
   if (filaVazia(fila))
      printf("\nFila Vazia!");

   while (!filaVazia(fila))
      printf("%d ", desenfileirar(fila));

   printf("\n");
}

int main(void) {
   Fila *fila;
   inicializar(&fila);

   if (fila) {
      for (int i = 1; i <= 20; ++i)
         enfileirar(fila, i);

      imprimir(fila);
      imprimir(fila);

      free(fila);
   }

   return 0;
}
