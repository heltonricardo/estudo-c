#include <stdio.h>
#define TAM 5

typedef struct PILHA {
   int elem[TAM];
   int topo;
} PILHA;

void inicializar(PILHA *pilha) {
   pilha->topo = -1;
}

int pilhaVazia(PILHA *pilha) {
   if (pilha->topo == -1)
      return 1;
   return 0;
}

int pilhaCheia(PILHA *pilha) {
   if (pilha->topo == TAM - 1)
      return 1;
   return 0;
}

int push(PILHA *pilha, int elemento) {
   if (pilhaCheia(pilha)) {
      printf("\nERRO! Pilha Cheia.");
      return 0;
   }
   pilha->elem[pilha->topo+1] = elemento;
   pilha->topo++;
   return 1;
}

int pop(PILHA *pilha) {
   int removido = -1;
   if (pilhaVazia (pilha)) {
      printf("Nao ha elemento para remover.");
      return removido;
   }
   removido = pilha->elem[pilha->topo];
   pilha->topo--;
   return removido;
}

int topoEl(PILHA *pilha) {
   int topo = -1;
   if (pilhaVazia (pilha)) {
      printf ("Nao ha elemento.");
      return topo;
   }
   topo = pilha->elem[pilha->topo];
   return topo;
}

int main() {
   PILHA p;

   inicializar (&p);
   push(&p, 5);
   printf("\n%d", topoEl(&p));
   push(&p, 15);
   printf("\n%d", topoEl(&p));
   push(&p, 2);
   printf("\n%d", topoEl(&p));
   pop (&p);
   printf("\n%d", topoEl(&p));

   return 0;
}
