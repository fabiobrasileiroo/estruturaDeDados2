#include <stdio.h>

int main() {
  float matriz[3][3]= { {1,2,3},{4,5,6},{7,8,9} };
  for(int l = 0;l < 3; l++)  {
    for(int c = 0;c < 3; c++)  {
      printf("Endereço de matriz[%d][%d]: %p\n", l, c, &matriz[l][c]);
    }
  }
  return 0;
}