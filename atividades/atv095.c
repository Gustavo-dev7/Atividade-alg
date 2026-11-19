#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ==================== Definições das Structs ====================

typedef struct inimigo {
    int id;
    char tipo[50];
} Inimigo;

typedef struct no {
    Inimigo dado;
    struct no* prox;
} No;

typedef struct lista {
    No* inicio;
} Lista;

// ==================== Funções da Lista ====================

void inicializar_lista(Lista* l) {
    l->inicio = NULL;
}

void inserir_fim(Lista* l, int id, char* tipo) {
    No* novo = (No*)malloc(sizeof(No));
    if (novo == NULL) {
        printf("Erro ao alocar memória!\n");
        return;
    }
    
    novo->dado.id = id;
    strcpy(novo->dado.tipo, tipo);
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
}

void mostrar_lista(Lista* l) {
    if (l->inicio == NULL) {
        printf("\n--- INIMIGOS ATIVOS ---\n");
        printf("Nenhum inimigo ativo no momento.\n");
        return;
    }
    
    printf("\n--- INIMIGOS ATIVOS ---\n");
    printf("Total de inimigos: %d\n", tamanho(l));
    printf("============================================\n");
    
    No* atual = l->inicio;
    int posicao = 1;
    
    while (atual != NULL) {
        printf("Inimigo %d:\n", posicao);
        printf("  ID  : %d\n", atual->dado.id);
        printf("  Tipo: %s\n", atual->dado.tipo);
        printf("--------------------------------------------\n");
        atual = atual->prox;
        posicao++;
    }
}

int tamanho(Lista* l) {
    int contador = 0;
    No* atual = l->inicio;
    while (atual != NULL) {
        contador++;
        atual = atual->prox;
    }
    return contador;
}

// ============================================================
// FUNÇÃO CRIAR_LISTA - IMPLEMENTE AQUI
// ============================================================
Lista criar_lista(int n) {
    Lista nova_lista;
    inicializar_lista(&nova_lista);
    
    if (n <= 0) {
        printf("\nNúmero de inimigos inválido! Criando lista vazia.\n");
        return nova_lista;
    }
    
    printf("\n--- CRIANDO NOVA ONDA DE INIMIGOS ---\n");
    printf("Cadastre %d inimigos:\n\n", n);
    
    for (int i = 0; i < n; i++) {
        int id;
        char tipo[50];
        
        printf("Inimigo %d:\n", i + 1);
        printf("  Digite o ID: ");
        scanf("%d", &id);
        limpar_buffer();
        
        printf("  Digite o tipo (ex: Goblin, Orc, Troll, Dragão): ");
        fgets(tipo, 50, stdin);
        size_t len = strlen(tipo);
        if (len > 0 && tipo[len - 1] == '\n') {
            tipo[len - 1] = '\0';
        }
        
        inserir_fim(&nova_lista, id, tipo);
        printf("  Inimigo '%s' (ID %d) adicionado à onda!\n\n", tipo, id);
    }
    
    printf("Onda com %d inimigos criada com sucesso!\n", n);
    return nova_lista;
}
// ============================================================

void limpar_lista(Lista* l) {
    No* atual = l->inicio;
    while (atual != NULL) {
        No* temp = atual;
        atual = atual->prox;
        free(temp);
    }
    l->inicio = NULL;
}

void liberar_lista(Lista* l) {
    limpar_lista(l);
    printf("Memória da lista liberada com sucesso!\n");
}

// ==================== Funções Auxiliares ====================

void limpar_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

void exibir_menu() {
    printf("\n========================================\n");
    printf("   SISTEMA DE DEFESA DE TORRE\n");
    printf("========================================\n");
    printf("  1 - Adicionar inimigo individual (fim)\n");
    printf("  2 - Mostrar inimigos ativos\n");
    printf("  3 - Iniciar Nova Onda (criar lista)\n");
    printf("  4 - Sair\n");
    printf("========================================\n");
    printf("Escolha uma opção: ");
}

// ==================== main ====================

int main() {
    Lista inimigos;
    inicializar_lista(&inimigos);
    
    int opcao;
    
    printf("========================================\n");
    printf("   BEM-VINDO AO SISTEMA DE DEFESA\n");
    printf("========================================\n");
    printf("Gerencie as ondas de inimigos!\n");
    printf("Use 'Iniciar Nova Onda' para criar\n");
    printf("uma lista completa de inimigos.\n");
    
    do {
        exibir_menu();
        scanf("%d", &opcao);
        limpar_buffer();
        
        switch (opcao) {
            case 1: {
                int id;
                char tipo[50];
                
                printf("\n--- ADICIONAR INIMIGO ---\n");
                printf("Digite o ID do inimigo: ");
                scanf("%d", &id);
                limpar_buffer();
                
                printf("Digite o tipo do inimigo: ");
                fgets(tipo, 50, stdin);
                size_t len = strlen(tipo);
                if (len > 0 && tipo[len - 1] == '\n') {
                    tipo[len - 1] = '\0';
                }
                
                inserir_fim(&inimigos, id, tipo);
                printf("\nInimigo '%s' (ID %d) adicionado!\n", tipo, id);
                break;
            }
            case 2: {
                mostrar_lista(&inimigos);
                break;
            }
            case 3: {
                int quantidade;
                
                printf("\n--- INICIAR NOVA ONDA ---\n");
                printf("Quantos inimigos terá a nova onda? ");
                scanf("%d", &quantidade);
                limpar_buffer();
                
                // Limpa a lista anterior (inimigos da onda passada)
                limpar_lista(&inimigos);
                printf("\nOnda anterior descartada!\n");
                
                // Cria a nova lista e substitui a anterior
                inimigos = criar_lista(quantidade);
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
    
    liberar_lista(&inimigos);
    printf("Programa finalizado. Defenda suas torres!\n");
    
    return 0;
}
