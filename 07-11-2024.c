#include <stdio.h>
#include <malloc.h>

typedef struct {
  char dado;
  struct NO *proxNO;
} NO;

typedef struct {
  NO * inicio;
  NO *fim;
  int qtdElementos;
} Fila;

Fila* inicializar() {
  Fila *f = (Fila*) malloc(sizeof(Fila));
  if(f != NULL) {
    f->inicio = NULL;
    f->fim = NULL;
    f->qtdElementos = 0;
  }
  return f;
}
int isEmpty(Fila* f) {
  // return f->inicio == NULL;
  // return f->fim == NULL;
  return f->qtdElementos == 0;
}



void inserir(Fila *f,char valor) {
  NO *novo = (NO*) malloc(sizeof(NO));// tem a parte dado e ponteiro

  if(novo == NULL) {
    printf("Error de alocacao. \n");
  } else {
    novo->dado = valor;
    novo->proxNO = NULL;
    if(isEmpty(f)) {
      f->inicio = novo;
    } else {
      f->fim->proxNO = novo;
    }

    f->fim = novo;
    f->qtdElementos++;
    printf("Inserindo com sucesso!\n");
  }

}
void remover(Fila *f) {
  if(isEmpty(f)) {
    printf("Fila está vazia. Não é possivel remover.\n");
  } else {
    NO *noRemovido = f->inicio;
    f->inicio = noRemovido->proxNO;
    printf("Removendo '%c' com sucesso!\n",noRemovido->dado);
    if(isEmpty(f)) {
      f->fim = NULL;
    }
    free(noRemovido);
    f->qtdElementos--;
  }
}
void exibir(Fila *f) {
  if(isEmpty(f)) {
    printf("Fila está vazia\n");
  } else {
    NO *temp = f->inicio;
    printf("Fila: \n");
    while(temp != NULL) {
      printf("%c", temp->dado);
      temp = temp->proxNO;
    }
  }
}

// void listarTudo(Fila *f) {
//   if(estaVazia(f)) {
//     printf("Fila esta vazia! \n");
//   } else {
//     NO *aux = f->inicio;
//     do {
//       printf("%c ", aux->dado);
//       aux = aux->proxNO;
//     } while(aux != NULL); 
//   }
// }

int main(){
  Fila* fila = inicializar();
  inserir(fila, 'A');
  inserir(fila, 'B');
  inserir(fila, 'C');
  printf('antes');
  exibir(fila);
  printf('depois');

  remover(fila);
  exibir(fila);

  remover(fila);
  exibir(fila);

  remover(fila);
  exibir(fila);
  return;


  return 0;

}