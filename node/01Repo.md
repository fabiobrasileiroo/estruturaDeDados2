```c
#include <stdio.h>
#include <stdlib.h>

typedef struct NO {
  char dado;
  struct NO *prox;
} NO;

typedef struct {
  NO *topo;
} Pilha;

// Função para inicializar a pilha
Pilha* inicializar() {
  Pilha *p = (Pilha *) malloc(sizeof(Pilha));
  if (p != NULL) {
    p->topo = NULL;
  }
  return p;
}

// Função para inserir um elemento na pilha
void inserir(Pilha *p, char valor) {
  NO *novo = (NO *) malloc(sizeof(NO));
  if (novo == NULL) {
    printf("Erro de memoria.\n");
  } else {
    novo->dado = valor;
    novo->prox = p->topo;
    p->topo = novo;
    printf("Elemento '%c' inserido na pilha.\n", valor);
  }
}

// Função para remover o elemento do topo da pilha
char remover(Pilha *p) {
  if (p->topo == NULL) {
    printf("A pilha está vazia.\n");
    return '\0'; // Retorna '\0' para indicar que a pilha está vazia
  } else {
    NO *temp = p->topo;
    char valor = temp->dado;
    p->topo = temp->prox;
    free(temp);
    printf("Elemento '%c' removido da pilha.\n", valor);
    return valor;
  }
}

// Função para consultar o elemento no topo da pilha sem remover
char consultarTopo(Pilha *p) {
  if (p->topo == NULL) {
    printf("A pilha está vazia.\n");
    return '\0';
  } else {
    return p->topo->dado;
  }
}

// Função para exibir todos os elementos da pilha
void exibir(Pilha *p) {
  if (p->topo == NULL) {
    printf("A pilha está vazia.\n");
  } else {
    NO *temp = p->topo;
    printf("Pilha: ");
    while (temp != NULL) {
      printf("%c -> ", temp->dado);
      temp = temp->prox;
    }
    printf("NULL\n");
  }
}

// Função para liberar toda a memória da pilha
void liberar(Pilha *p) {
  NO *temp = p->topo;
  while (temp != NULL) {
    NO *prox = temp->prox;
    free(temp);
    temp = prox;
  }
  free(p);
  printf("Memória da pilha liberada.\n");
}

// Função principal para testar as operações da pilha
int main() {
  Pilha *p = inicializar();

  inserir(p, 'A');
  inserir(p, 'B');
  inserir(p, 'C');

  exibir(p); // Exibe todos os elementos da pilha

  printf("Elemento no topo: %c\n", consultarTopo(p));

  remover(p);
  exibir(p); // Exibe a pilha após remover um elemento

  liberar(p); // Libera a memória alocada pela pilha

  return 0;
}
``` 