#include <stdio.h>

int main() {
  int inteiro = 5;
  int *pInteiro = &inteiro;

  printf("Endereço do apontador: %d\n",pInteiro);
  printf("Endereço do apontador: %d\n",*pInteiro);

  *pInteiro = 15;

  printf("Endereço do apontador: %d\n",pInteiro);
  printf("Endereço do apontador: %d\n",*pInteiro);


}