#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
  int info;
  struct celula *next;
} celula;

void inicilizar(celula **pilha) {
  *pilha = NULL;
}

int pilhaVazia(celula **pilha) {
  if (*pilha == NULL) return 1;
  return 0;
}

int acessarTopo(celula **pilha) {
  if (!pilhaVazia(pilha)) return 0;
  return (*pilha)->info;
}

celula *criarCelula(int info) {
  celula *nova = (celula *) malloc(sizeof(celula));
  if (!nova) return 0;
  nova->info = info;
  nova->next = NULL;
  return nova;
}

int push(celula **pilha, int info) {
  celula *nova = criarCelula(info);
  if (!nova) return 0;
  nova->next = *pilha;
  *pilha = nova;
  return 1;
}

int pop(celula **pilha) {
  if (pilhaVazia(pilha)) return 0;
  int removido = (*pilha)->info;
  celula *removida = *pilha;
  *pilha = (*pilha)->next;
  free(removida);
  return removido;
}

int imprimirPilha(celula **pilha) {
  while (!pilhaVazia(pilha))
    printf("%d ", pop(pilha));
}

int main(void) {
  celula *pilha;
  inicilizar(&pilha);

  int vet[] = {2, 37, 3, 31, 5, 29, 7, 23, 11, 19, 13, 17};
  int tam = sizeof(vet) / sizeof(int);

  for (int i = 0; i < tam; ++i)
    push(&pilha, vet[i]);

  imprimirPilha(&pilha);
  return 0;
}

