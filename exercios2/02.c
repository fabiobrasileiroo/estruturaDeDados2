#include <stdio.h>
#define VALUELENGTH 3

// Função para verificar se os valores são iguais e ordená-los
int Order(int values[]) {
  // Ordena os valores usando Bubble Sort
  for (int i = 0; i < VALUELENGTH - 1; i++) {
    for (int j = 0; j < VALUELENGTH - i - 1; j++) {
      if (values[j] > values[j + 1]) {
        // Troca os valores
        int temp = values[j];
        values[j] = values[j + 1];
        values[j + 1] = temp;
      }
    }
  }

  // Verifica se todos os valores são iguais
  if (values[0] == values[1] && values[1] == values[2]) {
    return 1; // Retorna 1 se todos os valores forem iguais
  } else {
    return 0; // Retorna 0 se os valores forem diferentes
  }
}

int main() {
  int values[VALUELENGTH]; // Declara o array

  // Leitura dos valores
  printf("Digite 3 valores inteiros:\n");
  for (int i = 0; i < VALUELENGTH; i++) {
    scanf("%d", &values[i]);
  }

  // Chama a função Order e imprime o resultado
  int result = Order(values);
  
  // Imprime os valores ordenados
  printf("Valores ordenados: ");
  for (int i = 0; i < VALUELENGTH; i++) {
    printf("%d ", values[i]);
  }
  printf("\n");

  if (result == 1) {
    printf("Todos os valores são iguais.\n");
  } else {
    printf("Os valores são diferentes.\n");
  }

  return 0;
}
