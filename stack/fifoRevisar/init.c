#include "handlerFila.h"

int main() {
  Fila normal, prioridade;
  inicializar(&normal);
  inicializar(&prioridade);
  push(&normal, 'A');
  push(&prioridade, 'A');
  push(&prioridade, 'B');
  push(&prioridade,  'C');
  listarTudo(&normal);
  printf("\n");
  // printf('valor');
  listarTudo(&prioridade);

}
