#include <stdio.h>
#define TAMANHO 5

typedef struct {
  int dado[TAMANHO];
  int topo;
} Stack;

void initStack(Stack* stack) {
  stack->topo = -1;
}

int isEmpty(Stack* stack) {
  return stack->topo == -1;
}

int isFull(Stack* stack) {
  return stack->topo + 1 == TAMANHO;
}

void push(Stack* stack, int value) {
  if(isFull(stack)) {
    printf("Stack estar cheia\n");
    return;
  }
  stack->dado[stack->topo +1] = value;
  stack->topo++;
  printf("Foi adicionador: %d\n",stack->dado[stack->topo]);
  return;
}

void pop(Stack* stack) {
  if(isEmpty(stack)) {
    printf("Estar vazio\n");
    return;
  }
  printf("Removido %d",stack->dado[stack->topo]);
  // stack->dado[stack->topo] = 0; //zera
  stack->topo--;
}

void peek(Stack* stack) {
  if(isEmpty(stack)) {
    printf("Estar vazia\n");
    return;
  }
  printf("Valor topo %d\n",stack->dado[stack->topo]);
}

void display(Stack* stack) {
  if(isEmpty(stack)) {
    printf("Estar vazio\n");
    return;
  }
  for(int i = 0; i < stack->topo +1;i++) {
    printf("Dado[%d]: %d\n",i,stack->dado[i]);
  }
}


int main() {
  Stack stack;
  initStack(&stack);
  push(&stack, 10);
  push(&stack, 20);
  push(&stack, 25);
  push(&stack, 25);
  push(&stack, 55);
  pop(&stack);
  printf("\n%d\n\n",stack.dado[4]);
  peek(&stack);
  display(&stack);
  return 0;
}