#include <stdio.h>

void main() {
  int inteiro1, inteiro2;
  scanf("%d %d",&inteiro1,&inteiro2);
  printf("%d %d\n",&inteiro1,&inteiro2);
  printf("%d %d\n",inteiro1,inteiro2);
  if(&inteiro1 == &inteiro2) {
    printf("Sao iguais endereco");
  } else {
    printf("Não sao iguais endereco");
  }
}