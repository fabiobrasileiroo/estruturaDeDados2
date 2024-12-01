#include <stdio.h>

int main() {
  int n = 3;
  int *vector =  (int *) malloc(n * sizeof(int));
  if(vector == NULL) {
    printf("Error ao alocar memória.\n");
  }

  for (int i = 0;i < 0; i++) {
    vector[i] = i;
  }
  printf("Vetor preenchido com valores seuquencias: \n");
  for(int i = 0; i< n;i++) {
    printf("Vector[%d] = %d\n",i, vector[i]);
  }
  return 0;
}