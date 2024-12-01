#include <stdio.h>
#include <stdlib.h>

// Estrutura que representa cada elemento da pilha
typedef struct Elemento {
    int num;
    struct Elemento *prox;
} Elemento;

// Estrutura do tipo Pilha contendo um ponteiro "topo" para controlar a pilha
typedef struct Pilha {
    struct Elemento *topo;
} Pilha;

// Função para criar a pilha
Pilha* cria_pilha() {
    Pilha* pilha = (Pilha*) malloc(sizeof(Pilha));
    if (pilha != NULL) {
        pilha->topo = NULL; // A pilha inicia-se vazia
    }
    return pilha;
}

// Função para inserir elemento na pilha
void insere_elemento(Pilha *pilha) {
    Elemento *novo = (Elemento*) malloc(sizeof(Elemento));
    if (novo == NULL) {
        printf("Erro ao alocar memória!\n");
        return;
    }

    printf("\nDigite o número a ser inserido na pilha: ");
    scanf("%d", &novo->num);
    novo->prox = pilha->topo;
    pilha->topo = novo;
    printf("Número inserido na pilha: %d\n", pilha->topo->num);
}

// Função para consultar os elementos da pilha
void consulta_pilha(Pilha *pilha) {
    if (pilha->topo == NULL) {
        printf("\nPilha Vazia!!\n");
    } else {
        Elemento *aux = pilha->topo;
        printf("\nElementos na pilha: ");
        while (aux != NULL) {
            printf("%d ", aux->num);
            aux = aux->prox;
        }
        printf("\n");
    }
}

// Função para remover elemento do topo da pilha
void remove_elemento_pilha(Pilha *pilha) {
    if (pilha->topo == NULL) {
        printf("\nPilha Vazia\n");
    } else {
        Elemento *aux = pilha->topo;
        printf("\n%d removido!\n", pilha->topo->num);
        pilha->topo = pilha->topo->prox;
        free(aux);
    }
}

int main() {
    Pilha *pilha = cria_pilha();
    int opcao;

    do {
        printf("\n1 - Inserir elemento na pilha");
        printf("\n2 - Consultar pilha");
        printf("\n3 - Remover elemento da pilha");
        printf("\n4 - Sair");
        printf("\nEscolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                insere_elemento(pilha);
                break;
            case 2:
                consulta_pilha(pilha);
                break;
            case 3:
                remove_elemento_pilha(pilha);
                break;
            case 4:
                printf("\nSaindo...\n");
                break;
            default:
                printf("\nOpção inválida!\n");
        }
    } while (opcao != 4);

    return 0;
}
