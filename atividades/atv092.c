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

void contratar_mercenario(Lista* l, int id, char* nome) {
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

void exibir_companhia(Lista* l) {
    if (l->inicio == NULL) {
        printf("\n--- COMPANHIA DE MERCENÁRIOS ---\n");
        printf("A companhia está vazia! Nenhum mercenário contratado.\n");
        return;
    }
    
    printf("\n--- COMPANHIA DE MERCENÁRIOS ---\n");
    printf("Total de mercenários: %d\n", contar_mercenarios(l));
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

int contar_mercenarios(Lista* l) {
    int count = 0;
    No* atual = l->inicio;
    while (atual != NULL) {
        count++;
        atual = atual->prox;
    }
    return count;
}

void demitir_todos_mercenarios(Lista* l) {
    // Verifica se a lista já está vazia
    if (l->inicio == NULL) {
        printf("\nA companhia já está vazia! Nenhum mercenário para demitir.\n");
        return;
    }
    
    printf("\n--- DECLARANDO FALÊNCIA ---\n");
    printf("Demitindo todos os mercenários...\n");
    
    int contador = 0;
    No* atual = l->inicio;
    
    // Percorre a lista liberando cada nó
    while (atual != NULL) {
        No* temp = atual;
        atual = atual->prox;
        printf("Demitindo: %s (ID %d)\n", temp->dado.nome, temp->dado.id);
        free(temp);
        contador++;
    }
    
    // Atualiza o ponteiro de início para NULL
    l->inicio = NULL;
    
    printf("\n%d mercenários foram demitidos!\n", contador);
    printf("A companhia foi dissolvida. Todos os mercenários foram liberados.\n");
}

// ==================== Funções Auxiliares ====================

void limpar_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

void exibir_menu() {
    printf("\n========================================\n");
    printf("   COMPANHIA DE MERCENÁRIOS\n");
    printf("========================================\n");
    printf("  1 - Contratar mercenário (inserir no fim)\n");
    printf("  2 - Exibir companhia\n");
    printf("  3 - Declarar falência (deletar lista inteira)\n");
    printf("  4 - Sair\n");
    printf("========================================\n");
    printf("Escolha uma opção: ");
}

// ==================== main ====================

int main() {
    Lista companhia;
    inicializar_lista(&companhia);
    
    int opcao;
    
    printf("========================================\n");
    printf("   BEM-VINDO À COMPANHIA DE MERCENÁRIOS\n");
    printf("========================================\n");
    printf("Gerencie seus mercenários com sabedoria!\n");
    printf("Cuidado com a falência...\n");
    
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
                
                contratar_mercenario(&companhia, id, nome);
                break;
            }
            case 2: {
                exibir_companhia(&companhia);
                break;
            }
            case 3: {
                demitir_todos_mercenarios(&companhia);
                break;
            }
            case 4: {
                printf("\nSaindo do sistema...\n");
                // Libera a memória restante antes de sair (segurança)
                demitir_todos_mercenarios(&companhia);
                break;
            }
            default: {
                printf("\nOpção inválida! Tente novamente.\n");
            }
        }
    } while (opcao != 4);
    
    printf("Programa finalizado. Até a próxima aventura!\n");
    
    return 0;
}
