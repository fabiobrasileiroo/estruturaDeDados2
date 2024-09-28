``` c
#include <stdio.h>
#include <string.h>

#define MAX_CARS 5

// Definição da estrutura para armazenar os dados dos carros
typedef struct {
    int tipoCarro;  // 1: Pequeno, 2: Médio, 3: Grande
    char placa[10]; // Placa do carro
} Carro;

// Definição da estrutura da fila estática
typedef struct {
    Carro fila[MAX_CARS];
    int inicio;
    int fim;
    int totalCarrosLavados;
    float valorArrecadado;
} FilaLavaJato;

// Inicializa a fila
void inicializarFila(FilaLavaJato* fila) {
    fila->inicio = 0;
    fila->fim = 0;
    fila->totalCarrosLavados = 0;
    fila->valorArrecadado = 0.0;
}

// Verifica se a fila está vazia
int filaVazia(FilaLavaJato* fila) {
    return fila->inicio == fila->fim;
}

// Verifica se a fila está cheia
int filaCheia(FilaLavaJato* fila) {
    return (fila->fim + 1) % MAX_CARS == fila->inicio;
}

// Insere um carro na fila
void inserirCarro(FilaLavaJato* fila, char* placa, int tipoCarro) {
    if (filaCheia(fila)) {
        printf("A fila está cheia! O carro não pode entrar.\n");
    } else {
        strcpy(fila->fila[fila->fim].placa, placa);
        fila->fila[fila->fim].tipoCarro = tipoCarro;
        fila->fim = (fila->fim + 1) % MAX_CARS;
        printf("Carro de placa %s entrou na fila (Tipo %d).\n", placa, tipoCarro);
    }
}

// Remove um carro da fila e atualiza o valor arrecadado
void removerCarro(FilaLavaJato* fila) {
    if (filaVazia(fila)) {
        printf("Não há carros na fila para lavar.\n");
    } else {
        Carro carroAtual = fila->fila[fila->inicio];
        float valor = 0.0;

        switch (carroAtual.tipoCarro) {
            case 1:
                valor = 25.0;
                break;
            case 2:
                valor = 35.0;
                break;
            case 3:
                valor = 45.0;
                break;
        }

        fila->valorArrecadado += valor;
        fila->totalCarrosLavados++;
        fila->inicio = (fila->inicio + 1) % MAX_CARS;

        printf("Carro de placa %s foi lavado. (Total arrecadado: R$ %.2f)\n", carroAtual.placa, valor);
    }
}

// Exibe o relatório final do dia
void exibirRelatorio(FilaLavaJato* fila) {
    printf("Foram lavados %d carros. Valor total arrecadado: R$ %.2f.\n", fila->totalCarrosLavados, fila->valorArrecadado);
}

int main() {
    FilaLavaJato fila;
    inicializarFila(&fila);

    // Inserir alguns carros na fila
    inserirCarro(&fila, "XYZ-1234", 2);
    inserirCarro(&fila, "ABC-5678", 1);
    inserirCarro(&fila, "QWE-9090", 3);

    // Lavar carros
    removerCarro(&fila);
    removerCarro(&fila);

    // Inserir mais um carro na fila
    inserirCarro(&fila, "ZZZ-9999", 1);

    // Lavar mais carros
    removerCarro(&fila);
    removerCarro(&fila);

    // Exibir o relatório final do dia
    exibirRelatorio(&fila);

    return 0;
}
``` 