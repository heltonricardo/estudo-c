#include <stdio.h>

int ePrimo(int *n) {
  int i, lim = sqrt(*n);
  if (*n != 2 && *n%2 == 0 || *n == 1)
    return 0;
  for (i = 3; i <= lim; i += 2)
    if (*n%i == 0) return 0;
  return 1;
}

int main(void) {
   int n = 6669983;

   printf("O numero %d ", n);
   if (!ePrimo(&n))
      printf("nao ");
   printf("e' primo!\n");

   return 0;
}
