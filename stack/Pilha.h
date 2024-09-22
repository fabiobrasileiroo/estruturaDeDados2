#include <stdio.h>
#define MAX 5 

typedef struct {
  int items[MAX];
  int front;
  int rear;
} Fila;

void initFila(Fila* fila) {
  fila->front = -1;
  fila->rear = -1;
}

int isfull(Fila* fila) {
  return (fila->rear + 1) % MAX == fila->front;
}

int isEmpty(Fila* fila) {
  printf("Aqui: %d \n", fila->front);
  return fila->front == -1;
}
// adicionar
void enqueue(Fila* fila, int value) {
  if(isfull(fila)) {
    printf("Fila cheia! Não é possivel adicionar elemento %d.\n",value);
    return;
  }
  if(isEmpty(fila)) {
    fila->front = 0;
  }
  fila->rear = (fila->rear + 1) % MAX;
  fila->items[fila->rear] = value;
  printf("Elemento %d adicionar á fila \n", value);
}
// remover
int dequeue(Fila* fila) {
  if(isEmpty(fila)) {
    printf("Fila vazia! Nao é possivel remover um elemento\n");
    return -1;
  }
  int item = fila->items[fila->front];
  if(fila->front == fila->rear) {
    fila->front = -1;
    fila->rear = -1;
  } else {
    fila->front = (fila->front +1) % MAX;
    return item;
  }
}

void display(Fila* fila) {
  if(isEmpty(fila)) {
    printf("Fila vazia!\n");
    return;
  }
  printf("Fila: ");
  int i = fila->front;
  while (1) {
    printf("%d ", fila->items[i]);
    if(i ==fila->rear) break;
    i = (i + 1) % MAX;
  }
  printf("\n");
}
