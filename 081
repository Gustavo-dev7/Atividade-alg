#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ==================== Definições das Structs ====================

typedef struct movimento {
    int id;
    char nome[50];
} Movimento;

typedef struct no {
    Movimento dado;
    struct no* prox;
} No;

typedef struct lista {
    No* inicio;
} Lista;

// ==================== Funções da Lista ====================

void inicializar(Lista* l) {
    l->inicio = NULL;
}

void inserir_inicio(Lista* l, Movimento mov) {
    No* novo = (No*)malloc(sizeof(No));
    if (novo == NULL) {
        printf("Erro ao alocar memória!\n");
        return;
    }
    novo->dado = mov;
    novo->prox = l->inicio;
    l->inicio = novo;
    printf("Movimento '%s' (ID %d) inserido no início do combo!\n", mov.nome, mov.id);
}

void liberar_lista(Lista* l) {
    No* atual = l->inicio;
    while (atual != NULL) {
        No* temp = atual;
        atual = atual->prox;
        free(temp);
    }
    l->inicio = NULL;
}

// ==================== Funções Auxiliares ====================

void limpar_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

void ler_movimento(Movimento* mov) {
    printf("\n--- NOVO MOVIMENTO ---\n");
    
    printf("Digite o ID do movimento: ");
    scanf("%d", &mov->id);
    
    limpar_buffer();
    
    printf("Digite o nome do movimento (max 49 caracteres): ");
    fgets(mov->nome, 50, stdin);
    
    // Remove o '\n' do final da string
    size_t len = strlen(mov->nome);
    if (len > 0 && mov->nome[len - 1] == '\n') {
        mov->nome[len - 1] = '\0';
    }
}

void exibir_menu() {
    printf("\n========================================\n");
    printf("   SISTEMA DE COMBO - JOGO DE LUTA\n");
    printf("========================================\n");
    printf("  1 - Inserir novo movimento no combo\n");
    printf("  2 - Sair\n");
    printf("========================================\n");
    printf("Escolha uma opção: ");
}

// ==================== main ====================

int main() {
    Lista historico;
    inicializar(&historico);
    
    int opcao;
    
    printf("========================================\n");
    printf("   BEM-VINDO AO SISTEMA DE COMBOS\n");
    printf("========================================\n");
    
    do {
        exibir_menu();
        scanf("%d", &opcao);
        limpar_buffer();
        
        switch (opcao) {
            case 1: {
                Movimento novo_mov;
                ler_movimento(&novo_mov);
                inserir_inicio(&historico, novo_mov);
                break;
            }
            case 2:
                printf("\nSaindo do sistema...\n");
                break;
            default:
                printf("\nOpção inválida! Tente novamente.\n");
        }
    } while (opcao != 2);
    
    liberar_lista(&historico);
    printf("Histórico do combo liberado. Até logo!\n");
    
    return 0;
}
