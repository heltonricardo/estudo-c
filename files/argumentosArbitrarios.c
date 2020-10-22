#include <stdio.h>
#include <stdarg.h>

int sum(int quantidade, ...) {
   va_list argumentos;
   int i, sumr = 0;
   va_start(argumentos, quantidade);
   for (i = 0; i < quantidade; ++i)
      sumr += va_arg(argumentos, int);
   va_end(argumentos);
   return sumr;
}

int main(void) {
   printf("Soma: %d\n", sum(3,  1, 2, 3));
   getchar();
   return 0;
}
