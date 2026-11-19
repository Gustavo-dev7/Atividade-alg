#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ==================== Definições das Structs ====================

typedef struct jogador {
    int id;
    char nickname[50];
} Jogador;

typedef struct no {
    Jogador dado;
    struct no* prox;
} No;

typedef struct fila {
    No* inicio;
    No* fim;
} Fila;

// ==================== Funções da Fila ====================

void inicializar_fila(Fila* f) {
    f->inicio = NULL;
    f->fim = NULL;
}

int fila_vazia(Fila* f) {
    return (f->inicio == NULL);
}

// ============================================================
// FUNÇÃO INSERIR - IMPLEMENTE AQUI
// ============================================================
void inserir(Fila* f, Jogador j) {
    // Aloca memória para o novo nó
    No* novo = (No*)malloc(sizeof(No));
    if (novo == NULL) {
        printf("Erro ao alocar memória!\n");
        return;
    }
    
    // Armazena os dados do jogador no nó
    novo->dado = j;
    novo->prox = NULL;
    
    // Caso 1: Fila vazia
    if (fila_vazia(f)) {
        f->inicio = novo;
        f->fim = novo;
    } 
    // Caso 2: Fila não vazia
    else {
        f->fim->prox = novo;
        f->fim = novo;
    }
    
    printf("\nJogador '%s' (ID %d) entrou na fila de matchmaking!\n", j.nickname, j.id);
}
// ============================================================

void mostrar_fila(Fila* f) {
    if (fila_vazia(f)) {
        printf("\n--- FILA DE MATCHMAKING ---\n");
        printf("A fila está vazia! Nenhum jogador aguardando.\n");
        return;
    }
    
    printf("\n--- FILA DE MATCHMAKING ---\n");
    printf("Ordem: do primeiro (início) ao último (fim)\n");
    printf("============================================\n");
    
    No* atual = f->inicio;
    int posicao = 1;
    
    while (atual != NULL) {
        printf("%dº Jogador:\n", posicao);
        printf("  ID      : %d\n", atual->dado.id);
        printf("  Nickname: %s\n", atual->dado.nickname);
        if (posicao == 1) {
            printf("  (PRÓXIMO A ENTRAR NA PARTIDA)\n");
        }
        printf("--------------------------------------------\n");
        atual = atual->prox;
        posicao++;
    }
}

void liberar_fila(Fila* f) {
    No* atual = f->inicio;
    while (atual != NULL) {
        No* temp = atual;
        atual = atual->prox;
        free(temp);
    }
    f->inicio = NULL;
    f->fim = NULL;
    printf("Memória da fila liberada com sucesso!\n");
}

// ==================== Funções Auxiliares ====================

void limpar_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

void exibir_menu() {
    printf("\n========================================\n");
    printf("   SISTEMA DE MATCHMAKING - MOBA\n");
    printf("========================================\n");
    printf("  1 - Entrar na fila (inserir)\n");
    printf("  2 - Mostrar fila de espera\n");
    printf("  3 - Sair\n");
    printf("========================================\n");
    printf("Escolha uma opção: ");
}

// ==================== main ====================

int main() {
    Fila fila;
    inicializar_fila(&fila);
    
    int opcao;
    
    printf("========================================\n");
    printf("   BEM-VINDO AO SISTEMA DE MATCHMAKING\n");
    printf("========================================\n");
    printf("Entre na fila e aguarde sua partida!\n");
    printf("(FIFO - First-In, First-Out)\n");
    printf("O primeiro a entrar é o primeiro a sair!\n");
    
    do {
        exibir_menu();
        scanf("%d", &opcao);
        limpar_buffer();
        
        switch (opcao) {
            case 1: {
                Jogador j;
                
                printf("\n--- ENTRAR NA FILA ---\n");
                printf("Digite o ID do jogador: ");
                scanf("%d", &j.id);
                limpar_buffer();
                
                printf("Digite o nickname do jogador: ");
                fgets(j.nickname, 50, stdin);
                size_t len = strlen(j.nickname);
                if (len > 0 && j.nickname[len - 1] == '\n') {
                    j.nickname[len - 1] = '\0';
                }
                
                inserir(&fila, j);
                break;
            }
            case 2: {
                mostrar_fila(&fila);
                break;
            }
            case 3: {
                printf("\nSaindo do sistema de matchmaking...\n");
                break;
            }
            default: {
                printf("\nOpção inválida! Tente novamente.\n");
            }
        }
    } while (opcao != 3);
    
    liberar_fila(&fila);
    printf("Programa finalizado. Boas partidas!\n");
    
    return 0;
}
