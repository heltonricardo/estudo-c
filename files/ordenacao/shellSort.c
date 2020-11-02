#include <stdio.h>

void shellSort(int vet[], int t) {
   int i, j, h = 1, value;
   do h = 3 * h + 1;
   while (h < t);
   do {
      h /= 3;
      for (i = h; i < t; ++i) {
         value = vet[i];
         j = i - h;
         while (j >= 0 && value < vet[j]) {
            vet[j + h] = vet[j];
            j -= h;
         }
         vet[j + h] = value;
      }
   } while (h > 1);
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
   shellSort(vet, tam);
   exibir(vet, tam);

   return 0;
}
