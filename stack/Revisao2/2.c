#include <stdio.h>
#include <stdlib.h>

#define TAMANHO 5

typedef struct {
  int* dado;
  int topo;
} Stack;

void initStack(Stack* stack) {
  stack->dado = malloc(TAMANHO * sizeof(int));
  stack->topo = -1;
}

int isEmpty(Stack* stack) { return stack->topo == -1; }
int isFull(Stack* stack) { return stack->topo + 1 == TAMANHO; }

void push(Stack* stack, int value) {
  if(isFull(stack)) return (void)printf("Stack está cheia\n");
  stack->dado[++stack->topo] = value;
  printf("Adicionado: %d\n", value);
}

void pop(Stack* stack) {
  if(isEmpty(stack)) return (void)printf("Está vazio\n");
  printf("Removido: %d\n", stack->dado[stack->topo--]);
}

void peek(Stack* stack) {
  if(isEmpty(stack)) return (void)printf("Está vazia\n");
  printf("Topo: %d\n", stack->dado[stack->topo]);
}

void display(Stack* stack) {
  if(isEmpty(stack)) return (void)printf("Está vazio\n");
  for(int i = 0; i <= stack->topo; i++) printf("Dado[%d]: %d\n", i, stack->dado[i]);
}

void freeStack(Stack* stack) { free(stack->dado); }

int main() {
  Stack stack;
  initStack(&stack);
  push(&stack, 10);
  push(&stack, 20);
  push(&stack, 25);
  push(&stack, 55);
  pop(&stack);
  printf("\n%d\n\n", stack.dado[4]);
  peek(&stack);
  display(&stack);
  freeStack(&stack);
  return 0;
}
