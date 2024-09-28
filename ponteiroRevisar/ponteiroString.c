#include <stdio.h>

void main() {
  char nome[100] = "Fabio Brasileiroa";
  char *pNome;

  pNome = nome;

  printf("\nEnreco da 1a posicao = %d\n", pNome);
  printf("\nValor da 1a posicao = %c\n",*pNome);

  while(*pNome != NULL) {
    // putchar(*pNome);
    printf("%c",*pNome);
    pNome++;
  }

  printf("\nEndereco da ultima posicao = %d\n", pNome);

}