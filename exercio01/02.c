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
    if (num > 0) {
        return 1;
    } else if(num < 0){
        return -1;
    }
    return 0;
}