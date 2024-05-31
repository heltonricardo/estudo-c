#include <stdio.h>

#define MAX 94

void fibonacci(short n, unsigned long long a, unsigned long long b) {
   if (n) {
      printf("%3d: %20llu\n", MAX - n + 1, a);
      fibonacci(n - 1, b, a + b);
   }
}

void fib(unsigned long long n) {
   fibonacci(n, 0, 1);
}

int main(void) {
   fib(MAX);
   return 0;
}
