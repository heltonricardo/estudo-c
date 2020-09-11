#include <stdio.h>
#include <stdlib.h>

typedef struct node {
   int valor;
   struct node *anterior;
   struct node *proximo;
} node;

typedef struct Deque {
   node *inicio;
   node *fim;
} Deque;

void inicializar(Deque **deque) {
   *deque = (Deque *) malloc(sizeof(Deque));
   if (*deque)
      (*deque)->inicio = (*deque)->fim = NULL;
   else printf("\nERRO DE MEMORIA\n");
}

int dequeVazio(Deque *deque) {
   return !deque->inicio;
}

node *novoNo(int valor) {
   node *novo = (node *) malloc(sizeof(node));
   if (novo) {
      novo->valor = valor;
      novo->anterior = novo->proximo = NULL;
   }
   else printf("\nERRO DE MEMORIA\n");
   return novo;
}

int inserirInicio(Deque *deque, int valor) {
   node *novo = novoNo(valor);
   if (!novo) return 0;
   if (!dequeVazio(deque)) {
      deque->inicio->anterior = novo;
      novo->proximo = deque->inicio;
   }
   else deque->fim = novo;
   deque->inicio = novo;
   return 1;
}

int inserirFim(Deque *deque, int valor) {
   node *novo = novoNo(valor);
   if (!novo) return 0;
   if (!dequeVazio(deque)) {
      deque->fim->proximo = novo;
      novo->anterior = deque->fim;
   }
   else deque->inicio = novo;
   deque->fim = novo;
   return 1;
}

int removerInicio(Deque *deque) {
   if (dequeVazio(deque)) return 0;
   int valor = deque->inicio->valor;
   node *rmv = deque->inicio;
   deque->inicio = deque->inicio->proximo;
   if (!deque->inicio) deque->fim = NULL;
   free(rmv);
   return valor;
}

int removerFim(Deque *deque) {
   if (dequeVazio(deque)) return 0;
   int valor = deque->fim->valor;
   node *rmv = deque->fim;
   deque->fim = deque->fim->anterior;
   if (!deque->fim) deque->inicio = NULL;
   free(rmv);
   return valor;
}

void imprimirDeque(Deque *deque, int sentido) {
   if (dequeVazio(deque))
      printf("\nDeque Vazio!");
   else if (sentido)
      while (!dequeVazio(deque))
         printf("%d ", removerFim(deque));
   else
      while (!dequeVazio(deque))
         printf("%d ", removerInicio(deque));
   printf("\n");
}

void limparDeque(Deque *deque) {
   while (!dequeVazio(deque))
      removerInicio(deque);
}

int main(void) {
   Deque *deque;
   inicializar(&deque);

   if (deque) {
      inserirInicio(deque, 55);
      imprimirDeque(deque, 0);

      inserirFim(deque, 44);
      imprimirDeque(deque, 1);

      inserirFim(deque, 888);
      inserirInicio(deque, 999);
      limparDeque(deque);

      inserirInicio(deque, 55);
      inserirFim(deque, 66);
      inserirInicio(deque, 44);
      inserirFim(deque, 77);
      inserirInicio(deque, 33);
      inserirFim(deque, 88);
      inserirInicio(deque, 22);
      inserirFim(deque, 99);
      inserirInicio(deque, 11);
      imprimirDeque(deque, 0);

      imprimirDeque(deque, 0);

      free(deque);
   }

   return 0;
}

