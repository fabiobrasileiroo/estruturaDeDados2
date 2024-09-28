#include <stdio.h>
#define TAMANHO_FILA 5

typedef struct {
  char dados[TAMANHO_FILA];
  int inicio;
  int fim;
} Fila;


void inicializar(Fila* f) {
  f->inicio=0;
  f->fim=-1;
}

int estaVazia(Fila* f) {
  return f->fim == -1;
}

int estaCheia(Fila* f) {
  return f->fim == TAMANHO_FILA -1;
  // 0 == 4 is false
}

void push(Fila* f,int valor) {
  if (estaCheia(f)) {
    printf("Fila estar cheia! \n");
    return;
  } else {
    f->fim++;
    f->dados[f->fim] = valor;
  }
}

char pop(Fila* f) {
  char valorRemovido;
  if(estaVazia(f)) {
    printf("Falar estar vazia!\n");
  } else {
    valorRemovido = f->dados[f->inicio];
    for(int x= f->inicio;x < f->fim;x++) {
      f->dados[x] = f->dados[x+1];
    }
  }
  f->fim--;
  return valorRemovido;
}
void listarTudo(Fila* f) {
  if(estaVazia(f)) {
    printf("Fila vazia! \n");
  } else {
    for(int x = f->inicio; x <= f->fim;x++) {
      printf("%c, ", f->dados[x]);
    }
  }
}
void display(Fila* f) {
  if(estaVazia(f)) {
    printf("Fila vazia! \n");
    return;
  }
  printf("Fila: ");
  int i = f->inicio;
  while(1) {
    printf("%d ", f->dados[i]);
    if(i == f->fim) break;
    i = (i+1) % TAMANHO_FILA;
  }
  printf("\n");
}
