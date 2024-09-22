#include <stdio.h>

#define MATRIZTAMANHO 3
int main() {
  printf("Input\n");
  float matriz[MATRIZTAMANHO][MATRIZTAMANHO];
  for(int l =0; l < MATRIZTAMANHO; l++) {
    for(int c =0;c < MATRIZTAMANHO;c++) {
      scanf("%f", &matriz[l][c]);
    }
  }


  printf("Output e seu endereco\n");
  for(int l =0; l < MATRIZTAMANHO; l++) {
    for(int c =0;c < MATRIZTAMANHO;c++) {
          printf("%.2f -> %p\n", matriz[l][c], (void*)&matriz[l][c]);
    }
  }

  return 0;
}