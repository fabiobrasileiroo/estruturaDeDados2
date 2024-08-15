#include <stdio.h>
int exPotencia(int num1, int num2);

int main() {
  int base,expoente;
  scanf("%d %d",&base, &expoente);
  int result = exPotencia(base, expoente);
  printf("Resultado %d^%d = %d",base,expoente, result);
  return 0;
}

int exPotencia(int base,int expoente) {
  int cal = 1;  // Inicializa o resultado com 1, pois qualquer número elevado a 0 é 1
  for(int i = 0; i < expoente; i++) {
    cal *= base;
  }
  return cal;
}