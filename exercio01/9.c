#include <stdio.h>
void trocar(int *value1, float *value2,char *character[]) {
    int *pvalue1 = &value1;
    float *pvalue2 = &value2;
    char *pcharacter = character; // Corrected pointer assignment
}

int main() {
    int value1 = 1;
    float value2 = 2; // Corrected float value
    char character[] = "Relandro"; // Corrected character array initialization

    printf("Valor 1 sem ponteiro: %d\n", value1);

    printf("Valor 2 sem ponteiro: %f\n", value2);

    printf("Caracter sem ponteiro: %s\n", character);

    // Pointers
    trocar(value1, value2, character[])
    printf("Valor 1 sem ponteiro: %d\n", value1);

    printf("Valor 2 sem ponteiro: %f\n", value2);

    printf("Caracter sem ponteiro: %s\n", character);

    return 0;
}