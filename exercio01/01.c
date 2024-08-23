#include <stdio.h>

float Maior(float num1 , float num2 ) {
  if(num1 > num2) {
    return  num1;
  } else {
    return num2;
  } 
}

int main() {
  float num1;
  float num2;
  scanf("%f", &num1);
  scanf("%f", &num2);
  float maiorNum = Maior(num1, num2);
  printf("maiorNum = %.2f\n", maiorNum);
  return 0; 
}
