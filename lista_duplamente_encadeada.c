#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
typedef struct elemento {
    char nome[31];
    struct elemento * anterior;
    struct elemento * proximo;
} elemento;

elemento *inicio = NULL;

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
    struct termios oldt, newt;
    int ch;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);

    if (cabeca == NULL) {
        printf("A lista esta vazia.\n");
        return;
    }

    elemento *atual = cabeca;

    while (1) {
        system("clear");
        printf("%s\n\n%s \n\n%s\n", 
                atual->anterior->nome, atual->nome, atual->proximo->nome);
        printf("\n\n[<-] Anterior | [->] Próximo | [ESC] Sair");

        ch = getchar();
        if (ch == 27) {
            int seq1 = getchar();
            int seq2 = getchar();
            if (seq1 == '[') {
                if (seq2 == 'C') {
                    atual = atual->proximo;
                } else if (seq2 == 'D') {
                    atual = atual->anterior;
                } else {
                    break;
                }
            } else {
                break;
            }
        }
    }
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
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


void excluir(elemento **cabeca, char *nome) {
    if (*cabeca == NULL) {
        printf("A lista esta vazia.\n");
        return;
    }

    elemento *atual = *cabeca;
    elemento *alvo = NULL;

    do {
        if (strcmp(atual->nome, nome) == 0) {
            alvo = atual;
            break;
        }
        atual = atual->proximo;
    } while (atual != *cabeca);

    if (alvo == NULL) {
        printf("Nome '%s' nao encontrado.\n", nome);
        return;
    }

    if (alvo->proximo == alvo) {
        *cabeca = NULL;
    } else {
        alvo->anterior->proximo = alvo->proximo;
        alvo->proximo->anterior = alvo->anterior;
        if (alvo == *cabeca) {
            *cabeca = alvo->proximo;
        }
    }

    free(alvo);
    printf("Nome '%s' removido.\n", nome);
}

void contar() {
    if (inicio == NULL) {
        printf("Total de elementos: 0\n");
        return;
    }
    int count = 0;
    elemento * atual = inicio;
    do {
        count++;
        atual = atual->proximo;
    } while (atual != inicio);
    printf("Total de elementos: %d\n", count);
}

int main() {
    int menu = 1;
    elemento * novo;
    char nome[31];
    char buffer[31];

    while (menu != 0) {
        printf("\n\nComandos: \n\n0 para sair\n1 para adicionar um elemento\n2 para listar os elementos\n3 para navegar pelos elementos\n4 para remover um elemento\n5 para contar os elementos\n\nDigite: ");
        scanf("%d", &menu);
        system("clear");

        switch(menu) {
            case 1:
                printf("\nDigite o nome: ");
                scanf("%s", buffer);
                strncpy(nome, buffer, 30);
                nome[30] = '\0';
                inserir(&inicio, nome);
                break;
            case 2:
                listar(inicio);
                break;
            case 3:
                navegar(inicio);
                break;
            case 4:
                printf("\nDigite o nome: ");
                scanf("%s", nome);
                strncpy(buffer, nome, 30);
                buffer[30] = '\0';
                excluir(&inicio, buffer);
                break;
            case 5:
                contar();
                break;
        }
    }

    return 0;
}