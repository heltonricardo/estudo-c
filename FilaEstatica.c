#include <stdio.h>
#define TAM 5

typedef struct fila{
   int elem[TAM];
   int cabecalho, ultimo;
}FILA;

void inicializar(FILA *fila) {
   fila->ultimo = 0;
   fila->cabecalho = fila->ultimo;
}

int filaVazia(FILA *fila) {
   return(fila->ultimo == fila->cabecalho);
}

int filaCheia(FILA *fila) {
   int proxi =(fila->ultimo+1) %TAM;
   return(proxi == fila->cabecalho);
}

int enfileirar(FILA* fila, int elemento) {
   int proxi;
   if(filaCheia(fila)) {
      printf("\nFila Cheia!");
      return 0;
   }
   proxi =(fila->ultimo+1) %TAM;
   fila->elem[proxi] = elemento;
   fila->ultimo = proxi;
   return 1;
}

int desenfileirar(FILA *fila) {
   int removido = -1;

   if(filaVazia(fila)) {
      printf("\nFila Vazia!");
      return removido;
   }

   fila->cabecalho =(fila->cabecalho+1) %TAM;
   removido = fila->elem[fila->cabecalho];
   return removido;
}

void imprimir(FILA* fila) {
   if(filaVazia(fila)) {
      printf("Fila Vazia!\n");
      return;
   }

   while (!filaVazia(fila))
      printf("%d ", desenfileirar(fila));
   printf("\n");
}

int main() {
   FILA fila;

   inicializar(&fila);

   imprimir(&fila);

   enfileirar(&fila, 2);
   enfileirar(&fila, 5);
   enfileirar(&fila, 7);
   imprimir(&fila);

   imprimir(&fila);

   return 0;
}
