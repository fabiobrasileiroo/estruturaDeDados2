#include <stdio.h>

void trocar(int *a, int *b) {
    int aux = *a;
    *a = *b;
    *b = aux;
}

int main() {
    int a = 5;
    int b = 10;

    printf("Before swapping: a = %d, b = %d\n", a, b);

    trocar(&a, &b);

    printf("After swapping: a = %d, b = %d\n", a, b);

    return 0;
}