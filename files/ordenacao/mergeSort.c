#include <stdio.h>
#include <stdlib.h>

void intercala(int vet[], int inicio, int meio, int fim) {
   int *w = (int *) malloc((fim - inicio) * sizeof(int));
   int i = inicio, j = meio, k = 0;

   while (i < meio && j < fim)
      if (vet[i] <= vet[j])
         w[k++] = vet[i++];
      else
         w[k++] = vet[j++];

   while (i < meio)
      w[k++] = vet[i++];
   while (j < fim)
      w[k++] = vet[j++];
   for (i = inicio; i < fim; ++i)
      vet[i] = w[i - inicio];

   free(w);
}

void sort(int vet[], int p, int r) {
   if (p < r - 1) {
      int q = (p + r) / 2;
      sort(vet, p, q);
      sort(vet, q, r);
      intercala(vet, p, q, r);
   }
}

void mergeSort(int vet[], int t) {
   sort(vet, 0, t);
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
   mergeSort(vet, tam);
   exibir(vet, tam);

   return 0;
}
