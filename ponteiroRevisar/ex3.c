#include <stdio.h>

void imprimeMatriz(int *p1) {
  int i;
  for(i=0;i<5;i++) {
    printf("\nConteudo da Matriz na posição antes %d=%d",i,*p1);
    (*p1)++;
    printf("\nConteudo da matriz na posicao depois %d=%d",i,*p1);
    printf("\nEndereço de memoria = %d",p1);
    printf("\n");
    p1++;
  }
}

main() {
  int matriz[5] = {6,7,8,9,10};
  imprimeMatriz(matriz);
}