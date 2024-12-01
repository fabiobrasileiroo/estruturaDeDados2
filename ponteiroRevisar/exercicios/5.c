#include <stdio.h>
int order(int *a,int *b,int *c) {
  if(*a == *b && *a == *c && *b == *c ) {
    printf("sao todos iguais\n");
    return 0;
  } else {
    if( *a > *b) {
      int tmp = *a;
      *a = *b;
      *b = tmp;
    }
    if( a > c) {
      int tmp = *a;
      *a = *c;
      *c = tmp;
    }
    if(*b > *c) {
      int tmp = *b;
      *b = *c;
      *c = tmp;
    }
    return 1;
  }
}

void main() {
  int a,b,c;
  scanf("%d %d %d",&a,&b,&c);
  printf("Sem order: %d %d %d\n",a,b,c);
  int retorno = order(&a,&b,&c);
  printf("retorno: %d\n", retorno);

  printf("Com order: %d %d %d\n",a,b,c);

}