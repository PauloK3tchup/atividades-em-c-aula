#include <stdio.h>

typedef struct elemento {
    char nome[31];
    struct elemento * anterior;
    struct elemento * proximo;
} elemento;

elemento * criarNo(char * nome) {
    elemento * novo = (elemento *)malloc(sizeof(elemento));
    if (novo) {
        strncpy(novo->nome, nome, 30);
        novo->nome[30] = '\0';
        novo->anterior = novo;
        novo->proximo = novo;  
    }
    return novo;
}

void inserir(elemento **cabeca, char *nome) {
    elemento *novo = criarNo(nome);
    if (!novo) return;

    if (*cabeca == NULL) {
        *cabeca = novo;
        novo->proximo = novo;
        novo->anterior = novo;
    } else {
        elemento *atual = *cabeca;
        
        if (strcmp(nome, atual->nome) < 0) {
            elemento *ultimo = (*cabeca)->anterior;
            
            novo->proximo = *cabeca;
            novo->anterior = ultimo;
            ultimo->proximo = novo;
            (*cabeca)->anterior = novo;
            *cabeca = novo;
        } else {
            while (atual->proximo != *cabeca && strcmp(nome, atual->proximo->nome) > 0) {
                atual = atual->proximo;
            }
            
            novo->proximo = atual->proximo;
            novo->anterior = atual;
            atual->proximo->anterior = novo;
            atual->proximo = novo;
        }
    }
    printf("Nome '%s' inserido na lista circular!\n", nome);
}

void navegar(elemento *cabeca) {
    if (cabeca == NULL) {
        printf("A lista esta vazia.\n");
        return;
    }

    elemento *atual = cabeca;
    char comando;

    do {
        printf("\n--- Navegador Circular ---\n");
        printf("Anterior: [%s] | ATUAL: << %s >> | Proximo: [%s]\n", 
                atual->anterior->nome, atual->nome, atual->proximo->nome);
        printf("[1] Proximo | [2] Anterior | [0] Sair\nEscolha: ");
        scanf(" %c", &comando);

        if (comando == '1') {
            atual = atual->proximo;
        } else if (comando == '2') {
            atual = atual->anterior;
        }
    } while (comando != '0');
}

void listar(elemento *cabeca) {
    if (cabeca == NULL) {
        printf("A lista esta vazia.\n");
        return;
    }
    elemento *temp = cabeca;
    printf("\n--- Lista Completa ---\n");
    do {
        printf("- %s\n", temp->nome);
        temp = temp->proximo;
    } while (temp != cabeca);
}

int main() {
    elemento *lista = NULL;
    int menu;
    char buffer[31];

    while (menu != 0) {
        printf("\n\nComandos: \n\n0 para sair\n1 para adicionar um elemento\n2 para listar os elementos\n3 para navegar pelos elementos\n\nDigite: ");
        scanf("%d", &menu);
        system("clear");

        switch(menu) {
            case 1:
                printf("Digite o nome: ");
                fgets(buffer, 31, stdin);
                buffer[strcspn(buffer, "\n")] = '\0';
                inserir(&lista, buffer);
                break;
            case 2:
                listar(lista);
                break;
            case 3:
                navegar(lista);
                break;
        }
    }

    return 0;
}