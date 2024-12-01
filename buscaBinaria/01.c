#include <stdio.h>

int encontradoMaiorDividirConquistar(int arr[], int inicio, int fim) {
  if(inicio == fim) {
    return arr[inicio];
  }
  int meio = (inicio + fim)/2;
  int maiorEsquerda = encontradoMaiorDividirConquistar(arr, inicio, meio);
  int maiorDireita = encontradoMaiorDividirConquistar(arr, meio + 1, fim);
  return (maiorEsquerda > maiorDireita) ? maiorEsquerda : maiorDireita;
}

int main() {
  int arr[] = {10, 324, 45, 90, 9808};
  int tamanho = sizeof(arr) / sizeof(arr[0]);
  int maior = encontradoMaiorDividirConquistar(arr, 0,tamanho-1);

  printf("Maior elemento (Divisao e conquista): %d\n",maior);
  return 0;
}