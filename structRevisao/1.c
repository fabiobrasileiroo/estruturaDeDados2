#include <stdio.h>

typedef struct 
{
  char nome[50];
  char matricula[20];
  float media;
} DadosAluno;

int main() {
  int qtdAluno, qtdAvaliacoes;

  printf("Digite a quantidade de alunos a serem cadastrados e de avaliações:\n");
  scanf("%d %d", &qtdAluno, &qtdAvaliacoes);

  DadosAluno Alunos[qtdAluno];

  for (int i = 0; i < qtdAluno; i++) {
    printf("Digite o nome do aluno:\n");
    scanf("%s", Alunos[i].nome);

    printf("Digite a matrícula do aluno:\n");
    scanf("%s", Alunos[i].matricula);

    float somaNotas = 0.0;

    for (int n = 0; n < qtdAvaliacoes; n++) {
      float nota;
      printf("Digite a nota [%d]:\n", n + 1);
      scanf("%f", &nota);
      somaNotas += nota;
    }

    Alunos[i].media = somaNotas / qtdAvaliacoes;
  }

  // for (int i = 0; i < qtdAluno; i++) {
  //   printf("Aluno[%d] e seus respectivos dados:\n", i);
  //   printf("Nome: %s\n", Alunos[i].nome);
  //   printf("Matrícula: %s\n", Alunos[i].matricula);
  //   printf("Média: %.2f\n", Alunos[i].media);
  //   printf("------------------------------------\n");
  // }
    // Abrir o arquivo para gravação
  FILE *arquivo = fopen("dados_alunos.txt", "w");
  if (arquivo == NULL) {
    printf("Erro ao abrir o arquivo!\n");
    return 1;
  }

  // Escrever os dados no arquivo
  for (int i = 0; i < qtdAluno; i++) {
    fprintf(arquivo, "Aluno[%d] e seus respectivos dados:\n", i);
    fprintf(arquivo, "Nome: %s\n", Alunos[i].nome);
    fprintf(arquivo, "Matrícula: %s\n", Alunos[i].matricula);
    fprintf(arquivo, "Média: %.2f\n", Alunos[i].media);
    fprintf(arquivo, "------------------------------------\n");
  }

  // Fechar o arquivo
  fclose(arquivo);

  printf("Dados dos alunos foram armazenados em 'dados_alunos.txt'.\n");


  return 0;
}


