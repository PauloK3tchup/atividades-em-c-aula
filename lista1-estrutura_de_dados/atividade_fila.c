//Paulo Cesar Nicolau Padilha - BSI5

//FILA de Pessoas - F.I.F.O.

#include <stdio.h>
#define MAX 3

int inicio = 0;
int fim = 0;
int tamanho = 0;

struct lista {
    char nome[50];
    int idade;
    float renda;
    int prioritario;
} list_pessoas[MAX];

void limpa_lista() {
    for (int n = 0; n < MAX; ++n) {
        list_pessoas[n].nome[0] = '\0';
        list_pessoas[n].idade = 0;
        list_pessoas[n].renda = 0.0;
        list_pessoas[n].prioritario = 0;
    }
}

void include() {
    if (tamanho == MAX) {
        printf("\n>>> Fila cheia! Aguarde alguém sair. <<<\n");
        return;
    }
    printf("\nDigite o nome da pessoa: ");
    scanf("%s", &list_pessoas[fim].nome);
    printf("Digite a idade da pessoa: ");
    scanf("%d", &list_pessoas[fim].idade);
    printf("Digite a renda da pessoa: ");
    scanf("%f", &list_pessoas[fim].renda);
    printf("Digite 1 se a pessoa é prioritária, 0 caso contrário: ");
    scanf("%d", &list_pessoas[fim].prioritario);
    fim = (fim + 1) % MAX;
    tamanho++;
    printf("\n>>> Pessoa adicionada com sucesso! <<<\n");
}

void remover() {
    if (tamanho == 0) {
        printf("\n>>> Fila Vazia! <<<\n");
        return;
    }
    printf("\n>>> Pessoa \"%s\" removida da fila <<<\n", list_pessoas[inicio].nome);
    list_pessoas[inicio].nome[0] = '\0';
    list_pessoas[inicio].idade = 0;
    list_pessoas[inicio].renda = 0.0;
    list_pessoas[inicio].prioritario = 0;
    inicio = (inicio + 1) % MAX;
    tamanho--;
}

int main() {
    int menu = 1;
    limpa_lista();
    while (menu != 0) {
        printf("\n\nComandos: \n\n0 para sair\n1 para adicionar um elemento\n2 para remover um elemento\n\nDigite: ");
        scanf("%d", &menu);
        system("clear");
        switch (menu) {
            case 0:
                break;
            case 1:
                include();
                break;
            case 2:
                remover();
                break;
            default:
                printf("\n>>> Comando inválido <<<\n");
                break;
        }
    }
    printf("\n>>> Programa encerrado <<<\n");
    return 0;
}