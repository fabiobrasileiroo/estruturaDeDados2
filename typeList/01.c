#include <stdio.h>
#include <malloc.h>


// interface No = {
//   dado
// }
typedef struct NO {
  char dado;
  struct NO *prox;
} NO;

typedef struct {
  struct NO *inicio;
  int qtde;
} Lista;

Lista* inicializa() {
  // criar lista com tipo Lista usando tamanho dela com malloc
  Lista * lista = (Lista*) malloc(sizeof(Lista));
  if(lista != NULL) {
    lista -> inicio = NULL;
    lista->qtde = 0;
  }
  return lista;
}

int estarVazia(Lista *lista) {
  return lista->qtde ==0;
}

void inserir(Lista *lista,char valor) {
  NO *novo = (NO*) malloc(sizeof(NO));
  if(novo != NULL) {
    novo->dado = valor;
    novo->prox = lista->inicio;
    lista->inicio = novo;
    lista->qtde++;
  }
  printf("Erro ao alocar a memoria!\n");
}

NO* alocaNO() {
  return (NO*) malloc(sizeof(NO));
}

void inserirMeio(Lista *lista, char valor, char valorProcurado) {
  NO *novo = alocaNO();
  if(novo != NULL) {
    novo->dado = valor;
    if(estarVazia) {
      novo->prox = lista->inicio;
      lista->inicio = novo;
    } else {
      NO *atual = lista->inicio;
      while (atual->dado != valorProcurado && atual->prox->prox != NULL) {
        atual = atual->prox;
      }
      novo->prox = atual->prox;
      atual->prox = novo;
      lista->qtde++;
      printf("Elemento inserido com sucesso!\n");
    }
  }
}

void remover(Lista *lista, char valor, char valorProcurado) {
  NO *novo = alocaNO();
  if(novo != NULL) {
    novo->dado = valor;
    if(estarVazia) {
      novo->prox = lista->inicio;
      lista->inicio = novo;
    } else {
      NO *atual = lista->inicio;
      while (atual->dado != valorProcurado && atual->prox->prox != NULL) {
        atual = atual->prox;
      }
      novo->prox = atua->prox;
      atual->prox = novo;
      lista->qtde++;
      printf("Elemento inserido com sucesso!\n");
    }
  }
}



ultimoElemento(Lista * lista) {

}

inserirFinal(Lista *lista,char valor) {
   NO *novo = alocaNO();
  if(novo != NULL) {
    novo->dado = valor;
    if(estarVazia) {
      novo->prox = lista->inicio;
      lista->inicio = novo;
    } else {
      NO *atual = lista->inicio;
      while (atual->prox->prox != NULL) {
        atual = atual->prox;
      }
      novo->prox = atual->prox;
      atual->prox = novo;
      lista->qtde++;
      printf("Elemento inserido com sucesso!\n");
    }
  }
}



int main() {


  // NO *novo = (NO*) malloc(sizeof(NO));
  // printf("%d",novo);

  return 0;
}