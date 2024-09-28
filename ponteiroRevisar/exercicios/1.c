#include <stdio.h>

int main() {
  int value = 1;
  int *valueP = &value;

  float value2 = 2.0;
  float *value2P = &value2;

  char value3[3] = "32"; // Alterado para 3 bytes para incluir o caractere nulo
  char *value3P = value3; // Não precisa de & para um array, pois o nome do array já é um ponteiro

  printf("Ponteiro: %d - endereco: %p e seu valor original: %d\n", *valueP, &valueP, value);
  printf("Ponteiro: %f - endereco: %p e seu valor original: %f\n", *value2P, &value2P, value2);
  printf("Ponteiro: %s - endereco: %p e seu valor original: %s\n", value3P, &value3P, value3);

  return 0;
}
