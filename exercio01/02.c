#include <stdio.h>

int testNumber(float num); 

int main() {
    float num;
    scanf("%f", &num);
    int result = testNumber(num);
    printf("%d", result);
    return 0;
}

int testNumber(float num) {
    return num > 0 ? 1: (num < 0) ? -1: 0;
}