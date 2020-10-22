#include <stdio.h>
#include <stdlib.h>

typedef struct node {
   int valor;
   struct node *esq;
   struct node *dir;
} node;

void inicializar(node **arvore) {
   *arvore = NULL;
}

int arvoreVazia(node *arvore) {
   return !arvore;
}

node *novoNo(int valor) {
   node *novo = (node *) malloc(sizeof(node));
   if (novo) {
      novo->valor = valor;
      novo->esq = novo->dir = NULL;
   } else printf("\nERRO DE MEMORIA\n");
   return novo;
}

node *menorElemento(node *arvore) {
   if (arvore && arvore->esq)
      return menorElemento(arvore->esq);
   else
      return arvore;
}

void menorValor(node *arvore) {
   if (!arvoreVazia(arvore))
      printf("\nMenor valor: %d", menorElemento(arvore)->valor);
   else
      printf("\nArvore vazia!");
}

node *maiorElemento(node *arvore) {
   if (arvore && arvore->dir)
      return maiorElemento(arvore->dir);
   else
      return arvore;
}

void maiorValor(node *arvore) {
   if (!arvoreVazia(arvore))
      printf("\nMaior Valor: %d", maiorElemento(arvore)->valor);
   else
      printf("\nArvore vazia!");
}

node *pesquisar(node *arvore, int valor) {
   if (arvore) {
      if (arvore->valor == valor)
         return arvore;
      if (valor < arvore->valor)
         return pesquisar(arvore->esq, valor);
      else
         return pesquisar(arvore->dir, valor);
   } else return NULL;

}

void pesquisa(node *arvore, int valor) {
   printf("\nO valor %d ", valor);
   if (!pesquisar(arvore, valor)) printf("nao ");
   printf("existe na arvore!");
}

void *inserir(node **arvore, int valor) {
   if (arvoreVazia(*arvore))
      *arvore = novoNo(valor);
   else if ((*arvore)->valor < valor)
      inserir(&(*arvore)->dir, valor);
   else
      inserir(&(*arvore)->esq, valor);
}

int retirarMaior(node **arvore) {
   if ((*arvore)->dir)
      return retirarMaior(&(*arvore)->dir);
   node *maior = *arvore;
   int valor = maior->valor;
   *arvore = (*arvore)->esq;
   free(maior);
   return valor;
}

void remover(node **arvore, int valor) {
   if (*arvore) {
      if ((*arvore)->valor == valor) {

         int classif = (*arvore)->esq ? 1 : 0;
         classif = (*arvore)->dir ? classif ? 3 : 2 : classif;

         if (classif == 0) { // Sem filhos
            free(*arvore);
            *arvore = NULL;
         } else if (classif == 1) { // Um filho (à esquerda)
            node *rmv = *arvore;
            *arvore = (*arvore)->esq;
            free(rmv);
         } else if (classif == 2) { // Um filho (à direita)
            node *rmv = *arvore;
            *arvore = (*arvore)->dir;
            free(rmv);
         } else if (classif == 3) // Dois filhos
            (*arvore)->valor = retirarMaior(&(*arvore)->esq);
      }
      else if (valor < (*arvore)->valor)
         remover(&(*arvore)->esq, valor);
      else remover(&(*arvore)->dir, valor);
   }
}

void imprimir(node *arvore) {
   if (arvore) {
      imprimir(arvore->esq);
      printf("%d ", arvore->valor);
      imprimir(arvore->dir);
   }
}

void limpar(node *arvore) {
   if (arvore) {
      limpar(arvore->esq);
      limpar(arvore->dir);
      free(arvore);
   }
}

int main(void) {
   node *arvore;
   inicializar(&arvore);

   inserir(&arvore, 11);
   inserir(&arvore, 6);
   inserir(&arvore, 19);
   inserir(&arvore, 43);
   inserir(&arvore, 17);
   inserir(&arvore, 8);
   inserir(&arvore, 4);
   inserir(&arvore, 5);
   inserir(&arvore, 10);
   inserir(&arvore, 31);
   inserir(&arvore, 49);
   inserir(&arvore, 3);

   imprimir(arvore);
   printf("\n\nRAIZ: %d", arvore->valor);
   menorValor(arvore);
   maiorValor(arvore);
   printf("\n");

   pesquisa(arvore, 11);
   pesquisa(arvore, 6);
   pesquisa(arvore, 17);
   pesquisa(arvore, 19);
   pesquisa(arvore, 8);

   pesquisa(arvore, 3);
   pesquisa(arvore, 23);
   pesquisa(arvore, 61);

   printf("\n\nRemovendo a raiz\n\n");
   remover(&arvore, 11);
   imprimir(arvore);
   printf("\n\nRAIZ: %d", arvore->valor);

   limpar(arvore);
   printf("\n");
   return 0;
}
