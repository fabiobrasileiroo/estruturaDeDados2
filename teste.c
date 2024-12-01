#include <stdio.h>
#include <malloc.h>
typedef struct {
  int matricula;
  float nota;
  char nome[50];
} Aluno;


int main() {
  // int *x = (int *) malloc(12);
  // int *x = (int *) calloc(3, sizeof(int));
  Aluno *x = (Aluno *) malloc(sizeof(Aluno));

  // if(x == NULL) {
  //   printf("é nulo");
  // } else {
  //   printf("nao é nulo");
  // }

  // printf("\n valor do ponteiro %d", x->matricula);
  printf("Matricular em bytes: %d\n",sizeof(x->matricula));
  printf("Nota em bytes: %d\n",sizeof(x->nota));
  printf("Nome em bytes: %d\n",sizeof(x->nome));
  printf("Tamanho em bytes total: %d\n",sizeof(Aluno));
  free(x);
  printf("Matricular em bytes: %d\n",sizeof(x->matricula));
  printf("Nota em bytes: %d\n",sizeof(x->nota));
  printf("Nome em bytes: %d\n",sizeof(x->nome));
  printf("Tamanho em bytes total: %d\n",sizeof(Aluno));
  // printf("\n valor do ponteiro %p", x);
  // printf("\n valor do ponteiro %d",*x);
  // printf("\n\n");


  return 0;
}