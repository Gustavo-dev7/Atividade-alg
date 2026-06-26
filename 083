#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ==================== Definições das Structs ====================

typedef struct jogador {
    int matricula;
    char nome[50];
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

void adicionar_inicio(Fila* f, int matricula, char* nome) {
    No* novo = (No*)malloc(sizeof(No));
    if (novo == NULL) {
        printf("Erro ao alocar memória!\n");
        return;
    }
    
    novo->dado.matricula = matricula;
    strcpy(novo->dado.nome, nome);
    novo->prox = f->inicio;
    f->inicio = novo;
    
    // Se a fila estava vazia, o fim também deve apontar para o novo nó
    if (f->fim == NULL) {
        f->fim = novo;
    }
    
    printf("\nJogador '%s' (Matrícula %d) adicionado no INÍCIO da fila!\n", nome, matricula);
}

void adicionar_fim(Fila* f, int matricula, char* nome) {
    No* novo = (No*)malloc(sizeof(No));
    if (novo == NULL) {
        printf("Erro ao alocar memória!\n");
        return;
    }
    
    novo->dado.matricula = matricula;
    strcpy(novo->dado.nome, nome);
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
    
    printf("\nJogador '%s' (Matrícula %d) adicionado no FIM da fila!\n", nome, matricula);
}

void mostrar_fila(Fila* f) {
    if (fila_vazia(f)) {
        printf("\n--- FILA DE BATALHA ---\n");
        printf("A fila está vazia! Nenhum jogador aguardando.\n");
        return;
    }
    
    printf("\n--- FILA DE BATALHA ---\n");
    printf("Ordem: do primeiro (início) ao último (fim)\n");
    printf("============================================\n");
    
    No* atual = f->inicio;
    int posicao = 1;
    
    while (atual != NULL) {
        printf("%dº Jogador:\n", posicao);
        printf("  Matrícula: %d\n", atual->dado.matricula);
        printf("  Nome     : %s\n", atual->dado.nome);
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
    printf("   GERENCIADOR DE FILA DE BATALHA\n");
    printf("========================================\n");
    printf("  1 - Adicionar jogador no INÍCIO (prioridade)\n");
    printf("  2 - Adicionar jogador no FIM (normal)\n");
    printf("  3 - Mostrar fila\n");
    printf("  4 - Sair\n");
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
    printf("Os jogadores entram na fila em ordem de chegada.\n");
    printf("O primeiro a entrar é o primeiro a ser atendido!\n");
    
    do {
        exibir_menu();
        scanf("%d", &opcao);
        limpar_buffer();
        
        switch (opcao) {
            case 1: {
                int matricula;
                char nome[50];
                
                printf("\n--- ADICIONAR JOGADOR (INÍCIO) ---\n");
                printf("Digite a matrícula do jogador: ");
                scanf("%d", &matricula);
                limpar_buffer();
                
                printf("Digite o nome do jogador: ");
                fgets(nome, 50, stdin);
                
                size_t len = strlen(nome);
                if (len > 0 && nome[len - 1] == '\n') {
                    nome[len - 1] = '\0';
                }
                
                adicionar_inicio(&fila, matricula, nome);
                break;
            }
            case 2: {
                int matricula;
                char nome[50];
                
                printf("\n--- ADICIONAR JOGADOR (FIM) ---\n");
                printf("Digite a matrícula do jogador: ");
                scanf("%d", &matricula);
                limpar_buffer();
                
                printf("Digite o nome do jogador: ");
                fgets(nome, 50, stdin);
                
                size_t len = strlen(nome);
                if (len > 0 && nome[len - 1] == '\n') {
                    nome[len - 1] = '\0';
                }
                
                adicionar_fim(&fila, matricula, nome);
                break;
            }
            case 3: {
                mostrar_fila(&fila);
                break;
            }
            case 4: {
                printf("\nSaindo do sistema...\n");
                break;
            }
            default: {
                printf("\nOpção inválida! Tente novamente.\n");
            }
        }
    } while (opcao != 4);
    
    liberar_fila(&fila);
    printf("Programa finalizado. Até logo!\n");
    
    return 0;
}
