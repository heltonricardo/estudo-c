#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define NUM rand() % 9999 + 1

struct node {
   int v;
   struct node *p;
};

struct node *novoNo(int n) {
   struct node *node = (struct node *) malloc(sizeof(struct node));
   node->v = n;
   node->p = 0;
   return node;
}

void inserirInicio(struct node **node, int n) {
   struct node *novo = novoNo(n);
   novo->p = *node;
   *node = novo;
}

void inserirFinal(struct node *node, int n) {
   if (node->p) inserirFinal(node->p, n);
   else node->p = novoNo(n);
}

void exibirLista(struct node *node) {
   if (node) {
      printf("(%4d) -> ", node->v);
      exibirLista(node->p);
   }
   else printf("[NULL]\n");
}

void removerLista(struct node *node) {
   if (node->p) removerLista(node->p);
   free(node);
}

void pesquisar(struct node *node, int p, int *i) {
   ++*i;
   if (node->v == p) return;
   else if (node->p) pesquisar(node->p, p, i);
   else *i = 0;
}

int main(void) {
   int i, t, p;
   struct node *node;
   srand(time(0));

   printf("\n LISTA ENCADEADA (DINAMICA)\n\n");
   do {
      printf(" Insira o valor para ser o inicio da lista (0 < n) ...............: ");
      scanf("%d", &i);
   } while (i < 1);
   node = novoNo(i);

   printf("\n");

   do {
      printf(" Insira a quantidade de elementos para gerar no inicio (0 <= n) ..: ");
      scanf("%d", &t);
   } while (t < 0);
   for (i = 0; i < t; ++i)
      inserirInicio(&node, NUM);

   printf("\n Lista atual:\n ");
   exibirLista(node);

   printf("\n");

   do {
      printf(" Insira a quantidade de elementos para gerar no final (0 <= n) ...: ");
      scanf("%d", &t);
   } while (t < 0);
   for (i = 0; i < t; ++i)
      inserirFinal(node, NUM);

   printf("\n Lista atual:\n ");
   exibirLista(node);

   do {
      printf("\n Insira um valor para pesquisar (n < 1 para sair): ");
      scanf("%d", &p);
      if (p > 0) {
         i = 0;
         pesquisar(node, p, &i);
         if (i) printf(" Valor %d ncontrado na posicao %d\n", p, i);
         else printf(" Valor %d nao encontrado\n", p);
      }
   } while (p > 0);

   removerLista(node);
   while (getchar() != '\n');
   printf("\n Pressione <Enter> para sair... ");
   getchar();
   return 0;
}
