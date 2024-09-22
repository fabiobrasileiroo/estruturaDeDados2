#include <stdio.h>

#define MAX_SIZE 100

// Estrutura para armazenar elementos da pilha
struct Stack {
    int destination[MAX_SIZE];
    int weight[MAX_SIZE];
    int top;  // Índice do topo da pilha
};

// Inicializa a pilha
void initializeStack(struct Stack *s) {
    s->top = -1;  // Define o topo como vazio
}

// Função para adicionar um elemento (push) no topo da pilha
int push(struct Stack *s, int destination, int weight) {
    if (s->top >= MAX_SIZE - 1) {
        printf("Stack overflow, não é possível adicionar mais elementos.\n");
        return 1;
    } else {
        s->top++;
        s->destination[s->top] = destination;
        s->weight[s->top] = weight;
        return 0;
    }
}

// Função que remove um elemento (pop) do topo da pilha
// Retorna 0 se a remoção for bem-sucedida, e 1 caso contrário
int pop(struct Stack *s) {
    if (s->top < 0) {
        printf("Stack underflow, não há elementos para remover.\n");
        return 1;
    } else {
        s->top--;  // Simplesmente decrementa o índice do topo
        return 0;
    }
}

// Função para imprimir o estado atual da pilha
void printStack(struct Stack s) {
    if (s.top < 0) {
        printf("A pilha está vazia.\n");
    } else {
        for (int i = 0; i <= s.top; i++) {
            printf("Destino: %d, Peso: %d\n", s.destination[i], s.weight[i]);
        }
    }
}

int main() {
    struct Stack stack;  // Declara a pilha
    initializeStack(&stack);  // Inicializa a pilha

    // Adiciona alguns elementos
    push(&stack, 5, 10);
    push(&stack, 3, 15);
    push(&stack, 7, 20);

    // Imprime a pilha atual
    printf("Pilha após inserções:\n");
    printStack(stack);

    // Remove o elemento do topo
    pop(&stack);

    // Imprime a pilha após remoção
    printf("\nPilha após remoção:\n");
    printStack(stack);

    return 0;
}
