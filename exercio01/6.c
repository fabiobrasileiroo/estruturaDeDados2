#include <stdio.h>

float calcular_nota(float nota[], char letra) {
    float soma = 0;

    if(letra == 'A' || letra == 'a') {
        for(int i = 0; i < 3; i++) {
            soma += nota[i];
        }
        soma = soma / 3; 
    } 
    else if(letra == 'P' ||  letra == 'p' ) {
        soma = (nota[0] * 5 + nota[1] * 3 + nota[2] * 2) / 10;
    }

    return soma;
}

int main() {
    float nota[3];
    char letra;

    for(int i = 0; i < 3; i++) {
        scanf("%f", &nota[i]);
    }

    scanf(" %c", &letra); // Note the space before %c to consume the newline character

    float result = calcular_nota(nota, letra);
    printf("result: %f\n", result);

    return 0;
}
