#include "Pilha.h"

int main() {
  Fila fila;
  //display(&fila);
  initFila(&fila);
  display(&fila);
  enqueue(&fila, 10);
  enqueue(&fila, 11);
  display(&fila);
  dequeue(&fila);
  display(&fila);
  return 0;
}