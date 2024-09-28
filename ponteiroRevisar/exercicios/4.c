#include <stdio.h>
#define MAX_MATRIZ 3
void main() {
  float matriz[MAX_MATRIZ][MAX_MATRIZ];

  for(int l = 0; l < MAX_MATRIZ;l++ ) {
    for(int c = 0; c < MAX_MATRIZ;c++ ) {
      scanf("%f",&matriz[l][c]);
    }
  }
  printf("\n");
  for(int l = 0; l < MAX_MATRIZ;l++ ) {
    for(int c = 0; c < MAX_MATRIZ;c++ ) {
      printf("value[%d][%d]: %f\n",l,c,matriz[l][c]);
    }
  }
  printf("\n");
  for(int l = 0; l < MAX_MATRIZ;l++ ) {
    for(int c = 0; c < MAX_MATRIZ;c++ ) {
      printf("Endreco[%d][%d]: %p\n",l,c,&matriz[l][c]);
    }
  }
}