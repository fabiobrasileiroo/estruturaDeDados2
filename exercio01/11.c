#include <stdio.h>

int somaDobro(int *value1, int *value2) {
  *value1 *= 2;
  *value2 *=  2;
  return *value1 + *value2;
}

int main() {
  int value1;  
  int value2;
  scanf("%d %d", &value1,&value2);
  int soma =somaDobro(&value1,&value2);
  printf("Valor 1: %d\n", value1);
  printf("Valor 2: %d\n", value2);
  printf("Soma: %d", soma);

  return 0;
}

