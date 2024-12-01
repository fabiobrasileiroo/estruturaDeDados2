#include <stdio.h>
#include <stdlib.h> // use stdlib.h ao invés de malloc.h para alocação de memória

typedef struct NO {
  char dado;
  struct NO *proxNO;
} NO;

typedef struct {
  NO *inico;
  NO *fim;
  int qtdElementos;
} Fila;

// Função para inicializar a fila
Fila* inicializar() {
  Fila *f = (Fila*) malloc(sizeof(Fila));
  if (f != NULL) {
    f->inico = NULL;
    f->fim = NULL;
    f->qtdElementos = 0;
  }
  return f;
}

// Função para verificar se a fila está vazia
int isEmpty(Fila* f) {
  return f->qtdElementos == 0;
}

// Função para inserir um elemento na fila
void inserir(Fila *f, char valor) {
  NO *novo = (NO*) malloc(sizeof(NO));

  if (novo == NULL) {
    printf("Erro de alocação. \n");
  } else {
    novo->dado = valor;
    novo->proxNO = NULL;
    if (isEmpty(f)) {
      f->inico = novo;
    } else {
      f->fim->proxNO = novo;
    }

    f->fim = novo;
    f->qtdElementos++;
    printf("Inserindo '%c' com sucesso!\n", valor);
  }
}

// Função para remover um elemento da fila
void remover(Fila *f) {
  if (isEmpty(f)) {
    printf("Fila está vazia. Não é possível remover.\n");
  } else {
    NO *temp = f->inico;
    f->inico = f->inico->proxNO;
    if (f->inico == NULL) {
      f->fim = NULL; // Se a fila ficar vazia, atualizamos fim também
    }
    printf("Removendo '%c' com sucesso!\n", temp->dado);
    free(temp);
    f->qtdElementos--;
  }
}

// Função para exibir todos os elementos da fila
void exibir(Fila *f) {
  if (isEmpty(f)) {
    printf("Fila está vazia.\n");
  } else {
    NO *temp = f->inico;
    printf("Fila: ");
    while (temp != NULL) {
      printf("%c ", temp->dado);
      temp = temp->proxNO;
    }
    printf("\n");
  }
}

// Função principal para teste
int main() {
  Fila* fila = inicializar();

  inserir(fila, 'A');
  inserir(fila, 'B');
  inserir(fila, 'C');
  exibir(fila);

  remover(fila);
  exibir(fila);

  remover(fila);
  exibir(fila);

  remover(fila);
  exibir(fila);

  free(fila); // Libera a memória alocada para a fila
  return 0;
}
