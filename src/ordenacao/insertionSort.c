#include <stdio.h>

void troca(int *a, int *b) {
   int t = *a;
   *a = *b;
   *b = t;
}

void insertionSort(int vet[], int t) {
   for (int i = 0; i < t; ++i)
      for (int j = i; j > 0; --j)
         if (vet[j] < vet[j - 1])
            troca(&vet[j], &vet[j - 1]);
         else break;
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
   insertionSort(vet, tam);
   exibir(vet, tam);

   return 0;
}
