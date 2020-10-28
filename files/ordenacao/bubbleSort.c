#include <stdio.h>

void trocar(int *a, int *b) {
   int t = *a;
   *a = *b;
   *b = t;
}

void bubbleSort(int vet[], int t) {
   int memoria, troca = 1;
   for (int i = t - 1; i >= 1 && troca == 1; --i) {
      troca = 0;
      for (int j = 0; j < i; ++j)
         if (vet[j] > vet[j + 1]) {
            trocar(&vet[j], &vet[j + 1]);
            troca = 1;
         }
   }
}

void exibir(int vet[], int t) {
   for (int i = 0; i < t; ++i)
      printf(" %d", vet[i]);
   printf("\n");
}

int main(void) {
   int vet[] = {61, 51, 6, 50, 78, 40, 87, 88, 36, 7, 9, 53, 2, 9, 25};
   int tam = sizeof(vet) / sizeof(vet[0]);

   exibir(vet, tam);
   bubbleSort(vet, tam);
   exibir(vet, tam);

   return 0;
}
