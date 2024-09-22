#include <stdio.h>
#include <string.h>

#define MAX_CARS 10
#define PLACA_LEN 10 // Tamanho máximo da placa

// Estrutura para representar o estacionamento
typedef struct {
    char stack[MAX_CARS][PLACA_LEN]; // pilha que armazena as placas (agora como strings)
    int top; // índice do topo da pilha
} Estacionamento;

// Inicializa o estacionamento
void initEstacionamento(Estacionamento* est) {
    est->top = -1;
}

// Verifica se o estacionamento está cheio
int isFull(Estacionamento* est) {
    return est->top == MAX_CARS - 1;
}

// Verifica se o estacionamento está vazio
int isEmpty(Estacionamento* est) {
    return est->top == -1;
}

// Exibe o estado atual do estacionamento
void mostrarEstacionamento(Estacionamento* est) {
    if (isEmpty(est)) {
        printf("Estacionamento vazio.\n");
    } else {
        printf("Estacionamento atualmente ocupado por %d carro(s):\n", est->top + 1);
        for (int i = 0; i <= est->top; i++) {
            printf("Vaga %d: Placa %s\n", i + 1, est->stack[i]);
        }
    }
    printf("Vagas disponíveis: %d\n", MAX_CARS - (est->top + 1));
}

// Entrada de carro no estacionamento
void entradaCarro(Estacionamento* est, char placa[]) {
    if (isFull(est)) {
        printf("Estacionamento cheio. Carro de placa %s não pode entrar.\n", placa);
    } else {
        strcpy(est->stack[++(est->top)], placa);
        printf("Carro de placa %s entrou no estacionamento.\n", placa);
    }
    mostrarEstacionamento(est);
}

// Saída de carro do estacionamento
void saidaCarro(Estacionamento* est, char placa[]) {
    if (isEmpty(est)) {
        printf("Estacionamento vazio. Nenhum carro para sair.\n");
        return;
    }

    // Contador de manobras
    int manobras = 0;
    Estacionamento aux; // Pilha auxiliar para armazenar os carros manobrados
    initEstacionamento(&aux);

    // Encontrar o carro com a placa desejada
    while (!isEmpty(est) && strcmp(est->stack[est->top], placa) != 0) {
        entradaCarro(&aux, est->stack[est->top--]);
        manobras++;
    }

    // Se o carro foi encontrado
    if (!isEmpty(est) && strcmp(est->stack[est->top], placa) == 0) {
        printf("Carro de placa %s saiu do estacionamento após %d manobras.\n", placa, manobras);
        est->top--; // Remover o carro
    } else {
        printf("Carro de placa %s não está no estacionamento.\n", placa);
    }

    // Colocar os carros de volta no estacionamento
    while (!isEmpty(&aux)) {
        entradaCarro(est, aux.stack[aux.top--]);
    }

    mostrarEstacionamento(est);
}

int main() {
    Estacionamento est;
    initEstacionamento(&est);

    char operacao;
    char placa[PLACA_LEN];

    // Loop para aceitar múltiplas entradas do usuário
    while (1) {
        printf("\nDigite 'E' para entrada, 'S' para saída, ou 'Q' para sair do programa: ");
        scanf(" %c", &operacao);  // Espaço antes de %c para ignorar novos caracteres

        // Se o usuário quiser sair do programa
        if (operacao == 'Q' || operacao == 'q') {
            printf("Saindo do programa...\n");
            break;
        }

        // Entrada ou saída de carro
        if (operacao == 'E' || operacao == 'e') {
            printf("Digite o número da placa do carro: ");
            scanf("%s", placa); // Lendo a placa como string
            entradaCarro(&est, placa);
        } else if (operacao == 'S' || operacao == 's') {
            printf("Digite o número da placa do carro: ");
            scanf("%s", placa); // Lendo a placa como string
            saidaCarro(&est, placa);
        } else {
            printf("Operação inválida. Tente novamente.\n");
        }
    }

    return 0;
}
