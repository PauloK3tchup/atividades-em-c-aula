//-- Intervalo --
//
////Paulo Cesar Nicolau Padilha BSI5
//#include <stdio.h>
//
//int main()
//{
//    //Intervalo
//  
//    int primeiro;
//    int segundo;
//    
//    printf("\nDigite o primeiro número: ");
//    scanf("%d", &primeiro);
//    
//    printf("\nDigite o segundo número: ");
//    scanf("%d", &segundo);
//
//    if (primeiro < segundo) {
//        for(int n = primeiro; n <= segundo; ++n) {
//            printf("%d",n);
//            printf(" ");
//        };
//    } else if (segundo < primeiro){
//        for(int n = primeiro; n >= segundo; --n) {
//            printf("%d",n);
//            printf(" ");
//        };
//    } else {
//        printf("%d", primeiro);
//    };
//    return 0;
//}
//
//-- Vetor --
//
////Paulo Cesar Nicolau Padilha BSI5
//#include <stdio.h>
//
//int main()
//{
//    //Vetor
//    
//    int vetor[10];
//    
//    for(int n = 0; n < 10; ++n) {
//        scanf("%d", &vetor[n]);
//    }
//    for(int n = 0; n < 10; ++n) {
//        printf("%d", vetor[n]);
//        printf(" ");
//    }
//    
//    return 0;
//}
//
//-- Palavras --
////Paulo Cesar Nicolau Padilha BSI5
//#include <stdio.h>
//
//int main()
//{
//    //Palavra
//    
//    int tam = 10;
//    int qnts = 20;
//    char palavra[tam][qnts];
//    
//    for (int n = 0; n < tam; ++n){
//        printf("%d° Palavra: ",n+1);
//        scanf("%s", &palavra[n]);
//    }
//    for(int m = 0; m < tam; ++m) {
//        for(int n = 0; n < qnts; ++n) {
//            printf("%c ", palavra[m][n]);
//        }
//        printf("\n");
//    }
//    return 0;
//}
//
//-- Letras --
//
////Paulo Cesar Nicolau Padilha BSI5
//#include <stdio.h>
//
//int main()
//{
//    //Letras
//    
//    int tam = 20;
//    char letras[tam];
//
//    int n = 0;
//    int m = 0;
//
//    do {
//        ++n;
//        printf("%d° Letra: ",n);
//        scanf(" %c", &letras[n]);
//    } while (n < tam);
//    
//
//    while (m < tam) {
//        ++m;
//        printf("%c ", letras[m]);
//    }
//    
//    return 0;
//}
//
//-- Pares --
//
////Paulo Cesar Nicolau Padilha BSI5
//#include <stdio.h>
//
//int main()
//{
//    //Pares
//    
//    int verifica(int x) {
//        return (x%2) == 0;
//    }
//    
//    int tam = 3;
//    int nums[tam];
//    int atual = 0;
//    int i = 0;
//    
//    while (i < tam) {
//        printf("Digite um número par: ");
//        scanf("%d", &atual);
//        if (verifica(atual)){
//            nums[i] = atual;
//            ++i;
//        } else {
//            printf("Número ímpar!\n");
//        }
//    }
//    for (int n = 0; n < tam; ++n) {
//        printf("%d ", nums[n]);
//    }
//}
////Paulo Cesar Nicolau Padilha
//#include <stdio.h>
//
//int main()
//{
//    //Soma
//    
//    int soma(int x, int y) {
//        return x + y;
//    }
//    
//    int num1;
//    int num2;
//    int res;
//    
//    
//    printf("? + ? = ? ");
//    printf("\nDigite um número: ");
//    scanf("%d", &num1);
//    
//    printf("\n%d + ? = ? ", num1);
//    printf("\nDigite outro número: ");
//    scanf("%d", &num2);
//    
//    res = soma(num1,num2);
//    printf("\n%d + %d = ? ", num1, num2);
//    printf("\n%d + %d = %d ", num1, num2, res);
//}
//
////Paulo Cesar Nicolau Padilha
//#include <stdio.h>
//
//void troca(int *a, int *b) {
//    int temp = *a;
//    *a = *b;
//    *b = temp;
//    printf("\n\nTroca -> a = %d\n      -> b = %d",*a,*b);
//    return;
//}
//    
//int main()
//{
//    //Troca
//    
//    int a;
//    int b;
//
//    printf("a = ?\nb = ?");
//    printf("\nDigite um número: ");
//    scanf("%d", &a);
//    
//    printf("\na = %d\nb = ?",a);
//    printf("\nDigite outro número: ");
//    scanf("%d", &b);
//    
//    
//    printf("\na = %d\nb = %d",a,b);
//    
//    troca(&a,&b);
//    
//    printf("\n\na = %d\nb = %d",a,b);
//}
//
////Paulo Cesar Nicolau Padilha
//#include <stdio.h>
//int main()
//{
//    //Fatorial
//    
//    int a;
//
//    int fatorial(int n) {
//        if (n == 0 || n == 1) {
//            return 1;
//        } else if (n > 0) {
//            return n * fatorial(n - 1);
//        } else {
//            return 0;
//        }
//    }
//
//    printf("\nDigite um número: ");
//    scanf("%d", &a);
//    
//    printf("\nFatorial do número %d: %d", a, fatorial(a));
//}
//
////Paulo Cesar Nicolau Padilha
//#include <stdio.h>
//
//int main()
//{
//    //Struct
//    
//    int tam = 2;
//
//    struct lista {
//        char nome[100];
//        int dia;
//        int mes;
//        int ano;
//    } list_aniv[tam];
//
//
//    for (int n = 0; n < tam; ++n) {
//        printf("\nDigite o %d° nome: ", n+1);
//        scanf("%s", &list_aniv[n].nome);
//        printf("\nDigite o dia de nascimento: ");
//        scanf("%d", &list_aniv[n].dia);
//        printf("\nDigite o mês de nascimento: ");
//        scanf("%d", &list_aniv[n].mes);
//        printf("\nDigite o ano de nascimento: ");
//        scanf("%d", &list_aniv[n].ano);
//    }
//    
//    for (int n = 0; n < tam; ++n) {
//        printf("\n%d - Nome: %s\nData de Nascimento: %d/%d/%d\n",n+1,list_aniv[n].nome,list_aniv[n].dia,list_aniv[n].mes,list_aniv[n].ano);    
//        
//    }
//}
//// Atividade: fazer um programinha onde pode adicionar, editar, consultar e remover um elemento da lista!!!

////Paulo Cesar Nicolau Padilha
//#include <stdio.h>

////Lista de Pessoas - ESTÁ BUGADO!!!

//int main()
//{
//    //Struct
//
//    int tam = 3;
//    int menu = 1;
//    int atual = 0;
//
//    struct lista {
//        char nome[100];
//        int dia;
//        int mes;
//        int ano;
//    } list_aniv[tam];
//
//    void include(int index) {
//        printf("\nDigite o nome da pessoa: ");
//        scanf("%s", &list_aniv[index].nome);
//        printf("\nDigite o dia de nascimento: ");
//        scanf("%d", &list_aniv[index].dia);
//        printf("\nDigite o mês de nascimento: ");
//        scanf("%d", &list_aniv[index].mes);
//        printf("\nDigite o ano de nascimento: ");
//        scanf("%d", &list_aniv[index].ano);
//        if (list_aniv[atual + 1].nome[0] == '\0') {
//            atual++;
//        }
//        return;
//    }
//
//    void limpa_lista() {
//        for (int n = 0; n < tam; ++n) {
//            list_aniv[n].nome[0] = '\0';
//            list_aniv[n].dia = 0;
//            list_aniv[n].mes = 0;
//            list_aniv[n].ano = 0;
//        }
//        atual = 0;
//    }
//
//    void listar() {
//        for (int n = 0; n < tam; ++n) {
//            if (list_aniv[n].nome[0] != '\0') {
//                printf("\n%d - Nome: %s\nData de Nascimento: %d/%d/%d\n",n+1,list_aniv[n].nome,list_aniv[n].dia,list_aniv[n].mes,list_aniv[n].ano);    
//            }
//        }
//    }
//
//    void consulta(char *nome) {
//        for (int n = 0; n < tam; ++n) {
//            if (strcmp(list_aniv[n].nome, nome) == 0) {
//                printf("\n%d - Nome: %s\nData de Nascimento: %d/%d/%d\n",n+1,list_aniv[n].nome,list_aniv[n].dia,list_aniv[n].mes,list_aniv[n].ano);
//                return;
//            }
//        }
//        printf("\n>>> Elemento não encontrado <<<\n");
//    }
//
//    void alterar(char *nome) {
//        int temp = -1;
//        for (int n = 0; n < tam; ++n) {
//            if (strcmp(list_aniv[n].nome, nome) == 0) {
//                temp = n;
//                break;
//            }
//        }
//        if (temp != -1) {
//            printf("\n%d - Nome: %s\nData de Nascimento: %d/%d/%d\n",temp+1,list_aniv[temp].nome,list_aniv[temp].dia,list_aniv[temp].mes,list_aniv[temp].ano);
//            printf("\nDigite o novo nome da pessoa: ");
//            scanf("%s", &list_aniv[temp].nome);
//            printf("\nDigite o novo dia de nascimento: ");
//            scanf("%d", &list_aniv[temp].dia);
//            printf("\nDigite o novo mês de nascimento: ");
//            scanf("%d", &list_aniv[temp].mes);
//            printf("\nDigite o novo ano de nascimento: ");
//            scanf("%d", &list_aniv[temp].ano);
//            return;
//        } else {
//            printf("\n>>> Elemento não encontrado <<<\n");
//        }
//    }
//
//    void remover(char *nome) {
//        int temp = -1;
//        for (int n = 0; n < tam; ++n) {
//            if (strcmp(list_aniv[n].nome, nome) == 0) {
//                temp = n;
//                break;
//            }
//        }
//        if (temp != -1) {
//            list_aniv[temp].nome[0] = '\0';
//            list_aniv[temp].dia = 0;
//            list_aniv[temp].mes = 0;
//            list_aniv[temp].ano = 0;
//            atual = temp;
//            printf("\n>>> Elemento removido <<<\n");
//        } else {
//            printf("\n>>> Elemento não encontrado <<<\n");
//        }
//    }
//
//    printf("\nSeja Bem-Vindo!\nTamanho Máximo da Lista: %d\n", tam);
//    limpa_lista();
//    while (menu != 0) {
//        printf("\nComandos: \n1 para adicionar um elemento\n2 para listar os elementos\n3 para consultar um elemento\n4 para alterar um elemento\n5 para remover um elemento\n0 para sair. \n\nDigite: ");
//        scanf("%d", &menu);
//        system("clear");
//        if (menu == 1) {
//            if (atual < tam) {
//                include(atual);
//            } else {
//                printf("\n>>> Lista cheia <<<\n");
//            }
//        }
//        if (menu == 2) {
//            listar();
//        }
//        if (menu == 3) {
//            char nome[100];
//            printf("\nDigite o nome da pessoa: ");
//            scanf("%s", nome);
//            consulta(nome);
//        }
//        if (menu == 4) {
//            char nome[100];
//            printf("\nDigite o nome da pessoa: ");
//            scanf("%s", nome);
//            alterar(nome);
//        }
//        if (menu == 5) {
//            char nome[100];
//            printf("\nDigite o nome da pessoa: ");
//            scanf("%s", nome);
////            remover(nome);
////        }
////    }
////    printf("\n>>> Programa encerrado <<<\n");
////}
//
////Paulo Cesar Nicolau Padilha
//
////Pilha de Pessoas - L.I.F.O.
//
//#include <stdio.h>
//#define MAX 5
//
//int main(){
//    int menu = 1;
//    int atual = 0;
//
//    struct lista {
//        char nome[50];
//        int idade;
//        float renda;
//        int prioritario;
//    } list_pessoas[MAX];
//
//    void include(int index) {
//        printf("\nDigite o nome da pessoa: ");
//        scanf("%s", &list_pessoas[index].nome);
//        printf("\nDigite a idade da pessoa: ");
//        scanf("%d", &list_pessoas[index].idade);
//        printf("\nDigite a renda da pessoa: ");
//        scanf("%f", &list_pessoas[index].renda);
//        printf("\nDigite 1 se a pessoa é prioritária, 0 caso contrário: ");
//        scanf("%d", &list_pessoas[index].prioritario);
//        atual++;
//        return;
//    }
//
//    void remover(int index) {
//        if (index >= 0) {
//            printf("\n>>> Pessoa \"%s\" removida <<<\n", list_pessoas[index].nome);
//            list_pessoas[index].nome[0] = '\0';
//            list_pessoas[index].idade = 0;
//            list_pessoas[index].renda = 0.0;
//            list_pessoas[index].prioritario = 0;
//            atual--;
//            return;
//        } else {
//            printf("\n>>> Lista vazia <<<\n");
//        }
//    }
//
//    while (menu != 0)
//    {
//        printf("\n>>> Pessoas na pilha: %d <<<\n\nComandos: \n\n0 para sair\n1 para adicionar um elemento\n2 para remover um elemento\n\nDigite: ", atual);
//        scanf("%d", &menu);
//        system("clear");
//        switch (menu)
//        {
//        case 1:
//            if (atual < MAX) {
//                include(atual);
//            } else {
//                printf("\n>>> Lista cheia <<<\n");
//            }
//            break;
//        case 2:
//            remover(atual-1);
//            break;
//        default:
//            printf("\n>>> Comando inválido <<<\n");
//            break;
//        }
//    }
//    printf("\n>>> Programa encerrado <<<\n");
//}



//Paulo Cesar Nicolau Padilha
//
////FILA de Pessoas - F.I.F.O.
//
//#include <stdio.h>
//#define MAX 3
//
//int main(){
//    int menu = 1;
//    int atual = 0;
//    int atual_del = 0;
//
//    struct lista {
//        char nome[50];
//        int idade;
//        float renda;
//        int prioritario;
//    } list_pessoas[MAX];
//
//    void limpa_lista() {
//        for (int n = 0; n < MAX; ++n) {
//            list_pessoas[n].nome[0] = '\0';
//            list_pessoas[n].idade = 0;
//            list_pessoas[n].renda = 0.0;
//            list_pessoas[n].prioritario = 0;
//        }
//        atual = 0;
//    }
//
//    void listar() {
//        printf("\n>>> Pessoas na fila <<<\n");
//        for (int i = 0; i < MAX; i++) {
//            if (list_pessoas[i].nome[0] != '\0') {
//                printf("Nome: %s, Idade: %d, Renda: %.2f, Prioritário: %d\n", list_pessoas[i].nome, list_pessoas[i].idade, list_pessoas[i].renda, list_pessoas[i].prioritario);
//            }
//        }
//    }
//
//    void include(int index) {
//        printf("\nDigite o nome da pessoa: ");
//        scanf("%s", &list_pessoas[index].nome);
//        printf("\nDigite a idade da pessoa: ");
//        scanf("%d", &list_pessoas[index].idade);
//        printf("\nDigite a renda da pessoa: ");
//        scanf("%f", &list_pessoas[index].renda);
//        printf("\nDigite 1 se a pessoa é prioritária, 0 caso contrário: ");
//        scanf("%d", &list_pessoas[index].prioritario);
//        atual++;
//        return;
//    }
//
//    void remover(int index) {
//        printf("\n>>> Pessoa \"%s\" removida <<<\n", list_pessoas[index].nome);
//        list_pessoas[index].nome[0] = '\0';
//        list_pessoas[index].idade = 0;
//        list_pessoas[index].renda = 0.0;
//        list_pessoas[index].prioritario = 0;
//        atual_del++;
//    }
//
//    limpa_lista();
//    while (menu != 0)
//    {
//        printf("\nComandos: \n\n0 para sair\n1 para adicionar um elemento\n2 para remover um elemento\n\nDigite: ", atual);
//        scanf("%d", &menu);
//        system("clear");
//        switch (menu)
//        {
//        case 1:
//            for (int i = 0; i < MAX; i++) {
//                if (list_pessoas[i].nome[0] == '\0') {
//                    atual = i;
//                    break;
//                }
//            }
//            if (list_pessoas[atual].nome[0] == '\0') {
//                if (atual < MAX) {
//                    include(atual);
//                } else {
//                    atual = 0;
//                    include(atual);
//                }
//            } else {
//                printf("\n>>> Lista cheia <<<\n");
//            }
//            break;
//        case 2:
//            for (int i = 0; i < MAX; i++) {
//                if (list_pessoas[i].nome[0] != '\0') {
//                    atual_del = i;
//                    break;
//                }
//            }
//            if (list_pessoas[atual_del].nome[0] != '\0') {
//                if (atual_del < MAX) {
//                    remover(atual_del);
//                } else {
//                    atual_del = 0;
//                    remover(atual_del);
//                }
//            } else {
//                printf("\n>>> Lista Vazia <<<\n");
//            }
//            break;
//        case 3:
//            listar();
//            break;
//        default:
//            printf("\n>>> Comando inválido <<<\n");
//            break;
//        }
//    }
//    printf("\n>>> Programa encerrado <<<\n");
//}