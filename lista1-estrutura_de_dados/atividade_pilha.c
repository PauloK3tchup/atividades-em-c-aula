//Paulo Cesar Nicolau Padilha - BSI5

//Pilha de Pessoas - L.I.F.O.

#include <stdio.h>
#define MAX 3

int atual = 0;

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
    atual = 0;
}

void include(int index) {
    printf("\nDigite o nome da pessoa: ");
    scanf("%s", &list_pessoas[index].nome);
    printf("\nDigite a idade da pessoa: ");
    scanf("%d", &list_pessoas[index].idade);
    printf("\nDigite a renda da pessoa: ");
    scanf("%f", &list_pessoas[index].renda);
    printf("\nDigite 1 se a pessoa é prioritária, 0 caso contrário: ");
    scanf("%d", &list_pessoas[index].prioritario);
    atual++;
    return;
}

void remover(int index) {
    if (index >= 0) {
        printf("\n>>> Pessoa \"%s\" removida <<<\n", list_pessoas[index].nome);
        list_pessoas[index].nome[0] = '\0';
        list_pessoas[index].idade = 0;
        list_pessoas[index].renda = 0.0;
        list_pessoas[index].prioritario = 0;
        atual--;
        return;
    } else {
        printf("\n>>> Lista vazia <<<\n");
    }
}

int main(){
    int menu = 1;
    limpa_lista();
    
    while (menu != 0)
    {
        printf("\n\nComandos: \n\n0 para sair\n1 para adicionar um elemento\n2 para remover um elemento\n\nDigite: ");
        scanf("%d", &menu);
        system("clear");
        switch (menu) {
            case 0:
                break;
            case 1:
                if (atual < MAX) {
                    include(atual);
                } else {
                    printf("\n>>> Lista cheia <<<\n");
                }
                break;
            case 2:
                remover(atual-1);
                break;
            default:
                printf("\n>>> Comando inválido <<<\n");
                break;
        }
    }
    printf("\n>>> Programa encerrado <<<\n");
}