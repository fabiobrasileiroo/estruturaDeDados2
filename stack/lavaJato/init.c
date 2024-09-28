#include <stdio.h>
#include <string.h>

#define MAX_CARS 5

typedef struct {
  int tipoCarro; 
  char placa[10];
} Carro;

typedef struct  {
  Carro fila[MAX_CARS];
  int inicio;
  int fim;
  int totalCarrosLavados;
  float valorArrecadado;
} FilaLavaJato;

void inicializarFila(FilaLavaJato* fila) {
  fila->inicio = -1;
  fila->fim = 0;
  fila->totalCarrosLavados = 0;
  fila->valorArrecadado = 0.0;
}

int filaVazia(FilaLavaJato* fila) {
  return fila->inicio == fila->fim;
  // -1 == 0
}

int filaCheia(FilaLavaJato* fila) {
  return (fila->fim+ 1) % MAX_CARS == fila->inicio;
}

void inserirCarro(FilaLavaJato* fila, char* placa, int tipoCarro) {
  if(filaCheia(fila)) {
    printf("A fila está cheia! O carro não opde entrar.\n");
  } else {
    strcpy(fila->fila[fila->fim].placa, placa); // copia o array para dentro de placa
    fila->fila[fila->fim].tipoCarro = tipoCarro; // tipo da carro em cada array
    fila->fim = (fila->fim + 1) % MAX_CARS; // adicionar o index referente a ultima valor adicionado na fila
    printf("Carro de placa %s entrou na fila (Tipo %d).\n\n", placa, tipoCarro);
  }
}

void removerCarro(FilaLavaJato* fila) {
  if(filaVazia(fila)) {
    printf("Não há carros na fila para lavar.\n");
  } else {
    Carro carroAtual = fila->fila[fila->inicio];
    float valor = 0.0;

    switch (carroAtual.tipoCarro)
    {
    case 1:
      valor = 25.0;
      break;
    case 2:
       case 3:
      valor = 45.0;
    }
    fila->valorArrecadado += valor;
    fila->totalCarrosLavados++;
    fila->inicio = (fila->inicio + 1) % MAX_CARS;

    printf("Carro de placa %s foi lavado. (Total arrecadado: %.2f)\n\n", carroAtual.placa,valor);
  }
}

void exibirRelatorio(FilaLavaJato* fila) {
  printf("Foram lavados %d carros. Valor total arrecadado: R$ %.2f.\n",fila->totalCarrosLavados, fila->valorArrecadado);

}

int main() {
    FilaLavaJato fila;
    inicializarFila(&fila);

    // Inserir alguns carros na fila
    inserirCarro(&fila, "XYZ-1234", 2);
    inserirCarro(&fila, "ABC-5678", 1);
    inserirCarro(&fila, "QWE-9090", 3);

    // Lavar carros
    removerCarro(&fila);
    removerCarro(&fila);

    // Inserir mais um carro na fila
    inserirCarro(&fila, "ZZZ-9999", 1);

    // Lavar mais carros
    removerCarro(&fila);
    removerCarro(&fila);

    // Exibir o relatório final do dia
    exibirRelatorio(&fila);

    return 0;
}