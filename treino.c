#include <stdio.h>

#define MAX_STACK 5
typedef struct {
  float value
} Data;

typedef struct {
  Data data[MAX_STACK];
  int front;
  int rear;
} Stack;

void initStack(Stack* stack) {
  stack->front = -1; 
  stack->rear = -1;
}

int isEmpty(Stack* stack) {
  return stack->front == stack->rear;
  // -1 == -1
}

int isFull(Stack* stack) {
  return stack->front +1 == MAX_STACK;
}

void display(Stack* stack) {
  if(isEmpty(stack)) {
    printf("Estar vazio\n") ;
    return;
  }
  printf("\nTodos os dados os %d itens.\n",stack->front+1);
  for(int i = 0; i< stack->front+1;i++) {
    printf("Valor[%d]: %.2f\n",i+1,stack->data[i].value);
  }
}
void peek(Stack* stack) {
  if(isEmpty(stack)) {
    printf("Esta vazio\n");
    return;
  }
  printf("No index: %d\nTem valor: %.2f",stack->front+1,stack->data[stack->front].value);
}
void pop(Stack* stack) {
  if(isEmpty(stack)) {
    printf("Estar Vazio\n");
    return;
  }
  stack->data[stack->front].value = 0;
  stack->front--;
  printf("Removido no index: %d\nValor: %.2f",stack->front,stack->data[stack->front].value);
}
void push(Stack* stack,float value) {
  if(isFull(stack)) {
    printf("Estar cheio\n");
    return;
  }
  stack->front++;
  stack->data[stack->front].value = value;
  printf("Adiciona no index: %d\nValor: %.2f",stack->front,stack->data[stack->front].value);
}
void main() {
  Stack stack;
  initStack(&stack);
  pop(&stack);
  push(&stack, 1);
  push(&stack, 2);
  push(&stack, 3);
  push(&stack, 4);
  push(&stack, 5);
  pop(&stack);
  display(&stack);
  peek(&stack);
  // push(&stack, 13);
  // push(&stack, 13);
  // display(&stack);
}