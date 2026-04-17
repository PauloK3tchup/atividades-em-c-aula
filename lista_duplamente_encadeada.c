#include <stdio.h>

typedef struct elemento {
    char nome[31];
    struct elemento * anterior;
    struct elemento * proximo;
    
} elemento;

elemento * inicio = NULL;

elemento * criarNo(char * nome) {
    elemento * novo = (elemento *)malloc(sizeof(elemento));
    if (novo) {
        strncpy(novo->nome, nome, 30);
        novo->nome[30] = '\0';
        novo->anterior = NULL;
        novo->proximo = NULL;
    }
    return novo;
}

void inserir(elemento **cabeca, char *nome) {
    elemento *novo = criarNo(nome);
    if (!novo) return;

    // Caso 1: Lista vazia ou nome deve vir antes do primeiro elemento
    if (*cabeca == NULL || strcmp(nome, (*cabeca)->nome) < 0) {
        novo->proximo = *cabeca;
        novo->anterior = NULL;
        *cabeca = novo;
    } else {
        // Caso 2: Procurar a posição correta no meio ou fim
        elemento *atual = *cabeca;
        while (atual->proximo != NULL && strcmp(nome, atual->proximo->nome) > 0) {
            atual = atual->proximo;
        }
        novo->proximo = atual->proximo;
        novo->anterior = atual;
        atual->proximo = novo;
    }
    printf("Nome '%s' inserido com sucesso!\n", nome);
}

void listar(elemento *cabeca) {
    if (cabeca == NULL) {
        printf("A lista esta vazia.\n");
        return;
    }
    printf("\n--- Lista de Nomes ---\n");
    while (cabeca != NULL) {
        printf("- %s\n", cabeca->nome);
        cabeca = cabeca->proximo;
    }
}

void listar_reverso(elemento *cabeca) {
    if (cabeca == NULL) {
        printf("A lista esta vazia.\n");
        return;
    }
    printf("\n--- Lista de Nomes (Reversa) ---\n");
    while (cabeca->proximo != NULL) {
        cabeca = cabeca->proximo;
    }
    while (cabeca != NULL) {
        printf("- %s\n", cabeca->nome);
        cabeca = cabeca->anterior;
    }
}

int main() {
    elemento *lista = NULL;
    int opcao;
    char buffer[31];

    do {
        printf("\n1. Inserir Nome\n2. Excluir Nome\n3. Listar Nomes\n4. Listar Nomes (Reverso)\n0. Sair\nEscolha: ");
        scanf("%d", &opcao);
        getchar();
        system("clear");

        switch(opcao) {
            case 1:
                printf("Digite o nome: ");
                fgets(buffer, 31, stdin);
                buffer[strcspn(buffer, "\n")] = '\0';
                inserir(&lista, buffer);
                break;
            case 2:
                //printf("Digite o nome para excluir: ");
                //fgets(buffer, 31, stdin);
                //buffer[strcspn(buffer, "\n")] = '\0';
                //excluir(&lista, buffer);
                //break;
            case 3:
                listar(lista);
                break;
            case 4:
                listar_reverso(lista);
                break;
        }
    } while (opcao != 0);

    return 0;
}
