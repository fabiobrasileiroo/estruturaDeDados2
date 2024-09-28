#include <stdio.h>

int somaDobro(int *a,int *b) {
  *a = *a *2;
  *b = *b *2;
  return *a + *b;
}

void main() {
  int a,b;
  scanf("%d %d",&a,&b);
  printf("Antes da funcao a= %d b= %d\n",a,b);
  int final = somaDobro(&a,&b);
  printf("Soma do dobro: %d\n",final);
  printf("Depois da funcao a= %d b = %d\n",a,b);
}