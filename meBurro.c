#include <stdio.h>
#define MAX 5
#define INICIO -1
typedef struct {
  int dados[MAX];
  int topo;
} Pilha;

void inicializarDados(Pilha *pilha) {
  pilha->topo = -1;
  // pilha.topo = -1;
}
int estarVazio(Pilha *pilha) {
  // printf("Estar vazio: %d\n",pilha->topo  == -1);

  return pilha->topo == INICIO;
  // -1 == -1 = true
}

int estarCheio(Pilha *pilha) {
  // printf("Estar cheio:%d\n",pilha->topo +1 == MAX);
  return pilha->topo + 1 == MAX;
  // pilha.topo == 5
  // 0 == 5
}
void adicionarDados(Pilha *pilha, int valor) {
  if(estarCheio(pilha)) {
    printf("Estar cheio\n");
    return;
  }  
  pilha->topo++;
  pilha->dados[pilha->topo]= valor;
  // printf("--------------------------\n");
  printf("Index: %d - Valor: %d\n",pilha->topo ,pilha->dados[pilha->topo]);
  //   pilha->dados[0]     =  10 
}

void desempilharDados(Pilha *pilha) {
  if(estarVazio(pilha)) {
    printf("Estar vazio\n");
    return;
  }
  printf("Index removido: %d\nValor: %d",pilha->topo,pilha->dados[pilha->topo]);
  pilha->dados[pilha->topo] = 0;
  pilha->topo--;
}

void todosDados(Stack *stack) {
  if(stack) {
    []
  }
}




void main() {
  Pilha pilha;
  inicializarDados(&pilha);
  estarVazio(&pilha);
  estarCheio(&pilha);
  adicionarDados(&pilha, 10);
  adicionarDados(&pilha, 19);
  adicionarDados(&pilha, 15);
  adicionarDados(&pilha, 21);
  adicionarDados(&pilha, 15);
  adicionarDados(&pilha, 15);
  // desempilharDados(&pilha);
}