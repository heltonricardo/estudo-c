#include <stdio.h>
#include <stdlib.h>
#define MAX_TAM 10

typedef struct sLista {
  int elem[MAX_TAM];
  int ultimo;
} Lista;

void inicializarLista(Lista *lista) {
  lista->ultimo = -1;
}

int listaCheia(Lista *lista) {
  if (lista->ultimo == MAX_TAM - 1)
    return 1;
  return 0;
}

int listaVazia(Lista *lista) {
  if (lista->ultimo == -1)
    return 1;
  return 0;
}

int inserirFim(Lista *lista, int elemento) {
  if (!listaCheia(lista) && elemento) {
    lista->elem[lista->ultimo + 1] = elemento;
    ++(lista->ultimo);
    return 1;
  }
  return 0;
}

int modificarElemento(Lista *lista, int posicao, int elem) {
  if (0 <= posicao && posicao <= lista->ultimo && elem) {
    lista->elem[posicao] = elem;
    return 1;
  }
  return 0;
}

int removerElemento(Lista *lista, int posicao) {
  if (0 <= posicao && posicao <= lista->ultimo) {
    for (int i = posicao; i < lista->ultimo; ++i)
      lista->elem[i] = lista->elem[i + 1];
    --(lista->ultimo);
    return 1;
  }
  return 0;
}

int acessarElemento(Lista *lista, int posicao) {
  if (0 <= posicao && posicao <= lista->ultimo)
    return lista->elem[posicao];
  return 0;
}

int pesquisarElemento(Lista *lista, int elem) {
  for (int i = 0; i <= lista->ultimo; ++i)
    if (lista->elem[i] == elem)
      return i;
  return -1;
}

int tamanhoLista(Lista *lista) {
  return lista->ultimo + 1;
}

int imprimirLista(Lista *lista) {
  if (!listaVazia(lista)) {
    for (int i = 0; i <= lista->ultimo; ++i)
      printf("[%3d] ", lista->elem[i]);
    return 1;
  }
  return 0;
}

int inserirElemento(Lista *lista, int posicao, int elem) {
  if (!listaCheia(lista) && 0 <= posicao && posicao <= lista->ultimo && elem) {
    ++(lista->ultimo);
    for (int i = lista->ultimo; i > posicao; --i)
      lista->elem[i] = lista->elem[i - 1];
    lista->elem[posicao] = elem;
    return 1;
  }
  return 0;
}

int inverterLista(Lista *lista) {
  if (!listaVazia(lista)) {
    int troca, meio = lista->ultimo / 2;
    if (!lista->ultimo % 2) --meio;
    for (int i = 0; i <= meio; ++i) {
      troca = lista->elem[i];
      lista->elem[i] = lista->elem[lista->ultimo - i];
      lista->elem[lista->ultimo - i] = troca;
    }
    return 1;
  }
  return 0;
}

int ordenarLista(Lista *lista) {
  if (!listaVazia(lista)) {
    for (int i = 0; i < lista->ultimo; ++i)
      for (int j = i + 1; j <= lista->ultimo; ++j) {
        int troca;
        if (lista->elem[i] > lista->elem[j]) {
          troca = lista->elem[i];
          lista->elem[i] = lista->elem[j];
          lista->elem[j] = troca;
        }
      }
    return 1;
  }
  return 0;
}

void pause(void) {
  while(getchar() != '\n');
  getchar();
}

int menu(void) {
  int opcao;
  do {
    printf("\n MENU :: LISTA ESTATICA COM >INTEIROS<\n\n");
    printf(" [ 1] - Inicializar Lista\n");
    printf(" [ 2] - Verificar se lista esta cheia\n");
    printf(" [ 3] - Verificar se lista esta vazia\n");
    printf(" [ 4] - Inserir elemento no fim\n");
    printf(" [ 5] - Modificar elemento\n");
    printf(" [ 6] - Remover elemento\n");
    printf(" [ 7] - Acessar elemento\n");
    printf(" [ 8] - Pesquisar elemento\n");
    printf(" [ 9] - Tamanho da lista\n");
    printf(" [10] - Imprimir lista\n");
    printf(" [11] - Inserir elemento em posicao arbitraria\n");
    printf(" [12] - Inverter lista\n");
    printf(" [13] - Ordenar lista\n");

    printf("\n Entre a opcao: "); scanf("%d", &opcao);
  } while (opcao < 0 || 13 < opcao);
  return opcao;
}

int main(void) {
  int valor, posicao;
  Lista lista;
  inicializarLista(&lista);

  while (1)
    switch (menu()) {

      case 0:
        free(&lista);
        exit(0);

      case 1:
        inicializarLista(&lista);
        printf("\n ");
        printf("A lista foi inicializada! ");
        pause(); break;

      case 2:
        printf("\n ");
        printf(listaCheia(&lista) ? "A lista esta cheia! " : "A lista nao esta cheia! ");
        pause(); break;

      case 3:
        printf("\n ");
        printf(listaVazia(&lista) ? "A lista esta vazia! " : "A lista nao esta vazia! ");
        pause(); break;

      case 4:
        printf("\n ");
        printf("Elemento para inserir no final: "); scanf("%d", &valor);
        printf(inserirFim(&lista, valor) ? " Operacao realizada! " : " Ocorreu um erro! ");
        pause(); break;

      case 5:
        printf("\n ");
        printf("Modificar elemento na posicao: "); scanf("%d", &posicao);
        printf(" Novo valor: "); scanf("%d", &valor);
        printf(modificarElemento(&lista, posicao, valor) ? " Operacao realizada! " : " Ocorreu um erro! ");
        pause(); break;

      case 6:
        printf("\n ");
        printf("Remover elemento da posicao: "); scanf("%d", &posicao);
        printf(removerElemento(&lista, posicao) ? " Operacao realizada! " : " Ocorreu um erro! ");
        pause(); break;

      case 7:
        printf("\n ");
        printf("Acessar elemento da posicao: "); scanf("%d", &posicao);
        printf(" Valor na posicao %d: %d ", posicao, acessarElemento(&lista, posicao));
        pause(); break;

      case 8:
        printf("\n ");
        printf("Pesquisar elemento: "); scanf("%d", &valor);
        posicao = pesquisarElemento(&lista, valor);
        if (posicao != -1) printf(" O valor %d esta na posicao %d ", valor, posicao);
        else printf(" O valor %d nao foi encontrado ", valor);
        pause(); break;

      case 9:
        printf("\n ");
        printf("Tamanho atual da lista: %d ", tamanhoLista(&lista));
        pause(); break;

      case 10:
        printf("\n ");
        printf("Impressao da lista: ");
        valor = imprimirLista(&lista);
        if (!valor) printf("Lista vazia! ");
        pause(); break;

      case 11:
        printf("\n ");
        printf("Elemento para inserir: "); scanf("%d", &valor);
        printf(" Posicao para inserir: "); scanf("%d", &posicao);
        printf(inserirElemento(&lista, posicao, valor) ? " Operacao realizada! " : " Ocorreu um erro! ");
        pause(); break;

      case 12:
        printf("\n ");
        printf(inverterLista(&lista) ? "Operacao realizada! " : "Ocorreu um erro! ");
        pause(); break;

      case 13:
        printf("\n ");
        printf(ordenarLista(&lista) ? "Operacao realizada! " : "Ocorreu um erro! ");
        pause(); break;
    }

  return 0;
}
