#include <stdio.h>

void troca(int *a, int *b) {
   int t = *a;
   *a = *b;
   *b = t;
}

int particiona(int vet[], int p, int r) {
   int i = p;
   int j = r + 1;
   while (1) {
      while (vet[++i] <= vet[p])
         if (i == r) break;
      while (vet[--j] > vet[p])
         if (j == p) break;
      if (i >= j) break;
      troca(&vet[i], &vet[j]);
   }
   troca(&vet[p], &vet[j]);
   return j;
}

void quick(int vet[], int p, int r) {
   if (p >= r) return;
   int j = particiona(vet, p, r);
   quick(vet, p, j - 1);
   quick(vet, j + 1, r);
}

void quickSort(int vet[], int t) {
   quick(vet, 0, t - 1);
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
   quickSort(vet, tam);
   exibir(vet, tam);

   return 0;
}
