#include <stdio.h>
#include <string.h>

#define TAMANHO_FILA 5

typedef struct {
  int tipo;
  char placa[8];
} Carro;

typedef struct {
  Carro carros[TAMANHO_FILA];
  int inicio;
  int fim;
  int totalLavados;
  float totalArrecadado;
} Fila;

void inicializarFila(Fila *fila) {
  fila->inicio = 0;
  fila->fim = 0;
  fila->totalLavados =0;
  fila->totalArrecadado = 0;
}

int filaCheia(Fila *fila) {
  return (fila->fim == TAMANHO_FILA);
}

int filaVazia(Fila *fila) {
  return (fila->fim ==  fila->inicio);
}

void inserirCarro(Fila *fila, int tipo, char placa[]) {
  if(filaCheia(fila)) {
    printf("Fila cheia! O carro não pode entrarr na fila.\n");
  } else {
    fila->carros[fila->fim].tipo = tipo;
    strcpy(fila->carros[fila->fim].placa, placa);
    fila->fim++;
    printf("Carro de placa %s entrou na fila (Tipo %d).\n",placa, tipo);
  }
}

void lavarCarro(Fila *fila) {
  if(filaVazia(fila)) {
    printf("Fila vazia! Não há carros para lavar.\n");
  } else {
    Carro carroLavado = fila->carros[fila->inicio];
    float valor = 0;
    switch(carroLavado.tipo) {
      case 1: valor = 2500; break;
      case 2: valor = 3500; break;
      case 3: valor = 4500; break;
    }
    fila->totalLavados++;
    fila->totalArrecadado +=valor;
    printf("Carro de placa %s foi lavado. (Total arrecadado: R$ %.2f).\n",carroLavado.placa,valor);

    fila->inicio++;
  }

}

void exibirResumo(Fila *fila) {
  printf("Foram lavados %d carros. Valor arrecadado: R$ %2.f.\n",fila->totalLavados, fila->totalArrecadado);
}

// Função principal
int main() {
    Fila fila;
    inicializarFila(&fila);

    // Exemplo de operações
    inserirCarro(&fila, 2, "XYZ-1234");  // Tipo Médio
    inserirCarro(&fila, 3, "ABC-5678");  // Tipo Grande
    lavarCarro(&fila);
    inserirCarro(&fila, 1, "QWE-9090");  // Tipo Pequeno
    lavarCarro(&fila);
    lavarCarro(&fila);

    // Exibir resumo do dia
    exibirResumo(&fila);

    return 0;
}
