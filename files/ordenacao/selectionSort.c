#include <stdio.h>

void troca(int *a, int *b) {
   int t = *a;
   *a = *b;
   *b = t;
}

void selectionSort(int vet[], int t) {
   int min;
   for (int i = 0; i < t - 1; ++i) {
      min = i;
      for (int j = i + 1; j < t; ++j)
         if (vet[j] < vet[min])
            min = j;
      troca(&vet[i], &vet[min]);
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
   selectionSort(vet, tam);
   exibir(vet, tam);

   return 0;
}
