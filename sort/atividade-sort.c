#include <stdio.h>
#include <string.h>
#define MAX 100

struct lista {
    int codigo;
    char nome[50];
} lista[MAX];

int total;

int ler_nomes(const char *arquivo) {
    FILE *fp = fopen(arquivo, "r");
    if (fp == NULL) {
        perror("Erro ao abrir arquivo");
        return 0;
    }

    char linha[128];
    total = 0;

    while (total < MAX && fgets(linha, sizeof(linha), fp)) {
        if (sscanf(linha, " %d , %49[^\n]", &lista[total].codigo, lista[total].nome) == 2) {
            size_t len = strlen(lista[total].nome);
            if (len > 0 && lista[total].nome[len - 1] == '\r') {
                lista[total].nome[len - 1] = '\0';
            }
            total++;
        }
    }

    fclose(fp);
    return total;
}

void ordenar_codigo() {
    int trocas = 0;
    for (int i = 0; i < total - 1; i++) {
        for (int j = 0; j < total - i - 1; j++) {
            if (lista[j].codigo > lista[j + 1].codigo) {
                struct lista temp = lista[j];
                lista[j] = lista[j + 1];
                lista[j + 1] = temp;
                trocas++;
            }
        }
    }
    printf("Número de trocas realizadas: %d\n", trocas);
}

void ordenar_nome() {
    int trocas = 0;
    for (int i = 0; i < total - 1; i++) {
        for (int j = 0; j < total - i - 1; j++) {
            if (strcmp(lista[j].nome, lista[j + 1].nome) > 0) {
                trocas++;
                struct lista temp = lista[j];
                lista[j] = lista[j + 1];
                lista[j + 1] = temp;
            }
        }
    }
    printf("Número de trocas realizadas: %d\n", trocas);
}

int main() {
    const char *arquivo = "nomes.txt";
    total = ler_nomes(arquivo);

    int menu = 1;

    while (menu) {
        printf("\nEscolha uma opção:\n");
        printf("1. Listar \n");
        printf("2. Ordenar por nome \n");
        printf("3. Ordenar por código \n");
        printf("0. Sair\n");
        printf("Opção: ");
        scanf("%d", &menu);

        switch (menu) {
            case 1:
                for (int i = 0; i < total; i++) {
                    printf("Código: %d - Nome: %s\n", lista[i].codigo, lista[i].nome);
                }
                break;
            case 2:
                ordenar_nome();
                break;
            case 3:
                ordenar_codigo();
                break;
            case 0:
                break;
            default:
                printf("Opção inválida!\n");
        }
    }
}
