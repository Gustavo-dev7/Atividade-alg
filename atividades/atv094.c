#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ==================== Definições das Structs ====================

typedef struct mercenario {
    int id;
    char nome[50];
} Mercenario;

typedef struct no {
    Mercenario dado;
    struct no* prox;
} No;

typedef struct lista {
    No* inicio;
} Lista;

// ==================== Funções da Lista ====================

void inicializar_lista(Lista* l) {
    l->inicio = NULL;
}

void inserir_fim(Lista* l, int id, char* nome) {
    No* novo = (No*)malloc(sizeof(No));
    if (novo == NULL) {
        printf("Erro ao alocar memória!\n");
        return;
    }
    
    novo->dado.id = id;
    strcpy(novo->dado.nome, nome);
    novo->prox = NULL;
    
    // Se a lista estiver vazia
    if (l->inicio == NULL) {
        l->inicio = novo;
    } else {
        // Percorre até o final
        No* atual = l->inicio;
        while (atual->prox != NULL) {
            atual = atual->prox;
        }
        atual->prox = novo;
    }
    
    printf("\nMercenário '%s' (ID %d) contratado com sucesso!\n", nome, id);
}

void mostrar_lista(Lista* l) {
    if (l->inicio == NULL) {
        printf("\n--- REGISTRO DA GUILDA ---\n");
        printf("A guilda está vazia! Nenhum mercenário registrado.\n");
        return;
    }
    
    printf("\n--- REGISTRO DA GUILDA ---\n");
    printf("============================================\n");
    
    No* atual = l->inicio;
    int posicao = 1;
    
    while (atual != NULL) {
        printf("Mercenário %d:\n", posicao);
        printf("  ID  : %d\n", atual->dado.id);
        printf("  Nome: %s\n", atual->dado.nome);
        printf("--------------------------------------------\n");
        atual = atual->prox;
        posicao++;
    }
}

// ============================================================
// FUNÇÃO TAMANHO - IMPLEMENTE AQUI
// ============================================================
int tamanho(Lista* l) {
    int contador = 0;
    No* atual = l->inicio;
    
    // Percorre a lista do início ao fim
    while (atual != NULL) {
        contador++;          // Incrementa o contador para cada nó
        atual = atual->prox; // Avança para o próximo nó
    }
    
    return contador; // Retorna o número total de nós
}
// ============================================================

void liberar_lista(Lista* l) {
    No* atual = l->inicio;
    while (atual != NULL) {
        No* temp = atual;
        atual = atual->prox;
        free(temp);
    }
    l->inicio = NULL;
    printf("Memória da lista liberada com sucesso!\n");
}

// ==================== Funções Auxiliares ====================

void limpar_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

void exibir_menu() {
    printf("\n========================================\n");
    printf("   GUILDA DE MERCENÁRIOS\n");
    printf("========================================\n");
    printf("  1 - Contratar mercenário (inserir no fim)\n");
    printf("  2 - Mostrar registro da guilda\n");
    printf("  3 - Ver tamanho da guilda (Censo)\n");
    printf("  4 - Sair\n");
    printf("========================================\n");
    printf("Escolha uma opção: ");
}

// ==================== main ====================

int main() {
    Lista guilda;
    inicializar_lista(&guilda);
    
    int opcao;
    
    printf("========================================\n");
    printf("   BEM-VINDO À GUILDA DE MERCENÁRIOS\n");
    printf("========================================\n");
    printf("Gerencie seus mercenários e saiba\n");
    printf("quantos estão sob seu comando!\n");
    
    do {
        exibir_menu();
        scanf("%d", &opcao);
        limpar_buffer();
        
        switch (opcao) {
            case 1: {
                int id;
                char nome[50];
                
                printf("\n--- CONTRATAR MERCENÁRIO ---\n");
                printf("Digite o ID do mercenário: ");
                scanf("%d", &id);
                limpar_buffer();
                
                printf("Digite o nome do mercenário: ");
                fgets(nome, 50, stdin);
                size_t len = strlen(nome);
                if (len > 0 && nome[len - 1] == '\n') {
                    nome[len - 1] = '\0';
                }
                
                inserir_fim(&guilda, id, nome);
                break;
            }
            case 2: {
                mostrar_lista(&guilda);
                break;
            }
            case 3: {
                int total = tamanho(&guilda);
                printf("\n--- CENSO DA GUILDA ---\n");
                printf("Total de mercenários na guilda: %d\n", total);
                if (total == 0) {
                    printf("A guilda está vazia! Recrute novos mercenários.\n");
                } else if (total < 3) {
                    printf("A guilda é pequena. Considere recrutar mais mercenários.\n");
                } else if (total < 6) {
                    printf("A guilda tem um tamanho razoável. Continue expandindo!\n");
                } else {
                    printf("A guilda é grande! Vocês estão prontos para grandes contratos!\n");
                }
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
    
    liberar_lista(&guilda);
    printf("Programa finalizado. Até a próxima aventura!\n");
    
    return 0;
}
