#include <stdio.h>

typedef struct elemento {
    char nome[31];
    struct elemento * proximo;
} elemento;

elemento * inicio = NULL;

void insert(elemento * novo) {
    novo->proximo = NULL;
    
    if (inicio == NULL || strcmp(novo->nome, inicio->nome) < 0) {
        novo->proximo = inicio;
        inicio = novo;
        return;
    }

    elemento * atual = inicio;
    while (atual->proximo != NULL && strcmp(atual->proximo->nome, novo->nome) < 0) {
        atual = atual->proximo;
    }
    
    novo->proximo = atual->proximo;
    atual->proximo = novo;
}

void excluir(elemento **cabeca, char *nome) {
    elemento *atual = *cabeca;
    elemento *anterior = NULL;

    while (atual != NULL && strcmp(atual->nome, nome) != 0) {
        anterior = atual;
        atual = atual->proximo;
    }

    if (atual == NULL) {
        printf("Nome '%s' nao encontrado.\n", nome);
        return;
    }

    if (anterior == NULL) {
        *cabeca = atual->proximo;
    } else {
        anterior->proximo = atual->proximo;
    }

    free(atual);
    printf("Nome '%s' removido.\n", nome);
}


void contar() {
    int count = 0;
    elemento * atual = inicio;
    while (atual != NULL) {
        count++;
        atual = atual->proximo;
    }
    printf("Total de elementos: %d\n", count);
}

void inicior() {
    if (inicio != NULL) {
        elemento * atual = inicio;
        while (atual != NULL) {
            printf("%s\n", atual->nome);
            atual = atual->proximo;
        }
    } else {
        printf("Lista vazia!\n");
    }
}

int main(){
    int menu = 1;
    elemento * novo;
    char nome[31];
    char buffer[31];
    
    while (menu != 0)
    {
        printf("\n\nComandos: \n\n0 para sair\n1 para adicionar um elemento\n2 para listar os elementos\n3 para remover um elemento\n4 para contar os elementos\n\nDigite: ");
        scanf("%d", &menu);
        system("clear");
        switch (menu) {
            case 0:
                break;
            case 1:
                novo = (elemento *)malloc(sizeof(elemento));
                printf("\nDigite o nome: ");
                scanf("%s", nome);
                strncpy(novo->nome, nome, 30);
                novo->nome[30] = '\0';
                insert(novo);
                break;
            case 2:
                inicior();
                break;
            case 3:
                printf("\nDigite o nome: ");
                scanf("%s", nome);
                strncpy(buffer, nome, 30);
                buffer[30] = '\0';
                excluir(&inicio, buffer);
                break;
            case 4:
                contar();
                break;
            default:
                printf("\n>>> Comando inválido <<<\n");
                break;
        }
    }
    printf("\n>>> Programa encerrado <<<\n");
}
