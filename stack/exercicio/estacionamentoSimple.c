#include <stdio.h>
#include <string.h>

#define MAX_CARROS 10

// Estrutura para armazenar um carro com a placa e o número de manobras
typedef struct {
    char placa[8];
    int manobras;
} Carro;

// Função para buscar o índice do carro pela placa
int buscarCarro(Carro estacionamento[], int n, char placa[]) {
    for (int i = 0; i < n; i++) {
        if (strcmp(estacionamento[i].placa, placa) == 0) {
            return i;
        }
    }
    return -1;  // Carro não encontrado
}

int main() {
    Carro estacionamento[MAX_CARROS];  // Array para armazenar os carros no estacionamento
    int numCarros = 0;                 // Número de carros no estacionamento
    char operacao;
    char placa[8];
    
    // Loop para processar as entradas
    while (scanf(" %c %s", &operacao, placa) != EOF) {
        printf("\nDigite 'E' para entrada, 'S' para saída: ");
        if (operacao == 'E') {
            // Tentativa de entrada de um carro
            if (numCarros < MAX_CARROS) {
                // Adiciona o carro ao estacionamento
                strcpy(estacionamento[numCarros].placa, placa);
                estacionamento[numCarros].manobras = 0;
                numCarros++;
                printf("Carro %s entrou no estacionamento.\n", placa);
            } else {
                // Estacionamento cheio
                printf("Carro %s partiu sem entrar: estacionamento cheio.\n", placa);
            }
        } else if (operacao == 'S') {
            // Tentativa de saída de um carro
            int indice = buscarCarro(estacionamento, numCarros, placa);
            if (indice != -1) {
                // Conta as manobras
                for (int i = 0; i < indice; i++) {
                    estacionamento[i].manobras++;
                }

                // Remove o carro do estacionamento
                printf("Carro %s saiu do estacionamento após %d manobras.\n", estacionamento[indice].placa, estacionamento[indice].manobras);
                
                // Reorganiza o estacionamento
                for (int i = indice; i < numCarros - 1; i++) {
                    estacionamento[i] = estacionamento[i + 1];
                }
                numCarros--;
            } else {
                // Carro não está no estacionamento
                printf("Carro %s não encontrado no estacionamento.\n", placa);
            }
        }
    }

    return 0;
}
