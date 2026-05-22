// *Carregar os dados em uma árvore binária (ordenada)
// *Cada nó deve ter uma letra (identificador) e um conteúdo numérico (inteiro)
// * Carregue o alfabeto, depois faça uma busca de caractere e retorne o inteiro correspondente.

#include <stdio.h>
#include <string.h>

typedef struct node {
    char letra;
    int valor;
    struct node * pai;
    struct node * esquerda;
    struct node * direita;
} node;

node * raiz = NULL;

void adicionar(char letra, int valor) {
    node * novo = (node *)malloc(sizeof(node));
    novo->letra = letra;
    novo->valor = valor;
    novo->pai = NULL;
    novo->esquerda = NULL;
    novo->direita = NULL;

    if (raiz == NULL) {
        raiz = novo;
    } else {
        node * atual = raiz;
        while (1) {
            if (letra < atual->letra) {
                if (atual->esquerda == NULL) {
                    atual->esquerda = novo;
                    novo->pai = atual;
                    break;
                } else {
                    atual = atual->esquerda;
                }
            } else {
                if (atual->direita == NULL) {
                    atual->direita = novo;
                    novo->pai = atual;
                    break;
                } else {
                    atual = atual->direita;
                }
            }
        }
    }
}

void exibir() {
    
}

int main() {
    adicionar('A', 1);
    adicionar('B', 2);
    adicionar('C', 3);
    adicionar('D', 4);
    adicionar('E', 5);
    return 0;
}