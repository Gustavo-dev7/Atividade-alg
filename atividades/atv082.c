#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ==================== Definições das Structs ====================

typedef struct aventureiro {
    int id;
    char nome[50];
} Aventureiro;

typedef struct no {
    Aventureiro dado;
    struct no* prox;
} No;

typedef struct grupo {
    No* inicio;
} Grupo;

// ==================== Funções do Grupo ====================

void inicializar_grupo(Grupo* g) {
    g->inicio = NULL;
}

void adicionar_aventureiro(Grupo* g, int id, char* nome) {
    No* novo = (No*)malloc(sizeof(No));
    if (novo == NULL) {
        printf("Erro ao alocar memória!\n");
        return;
    }
    
    novo->dado.id = id;
    strcpy(novo->dado.nome, nome);
    novo->prox = g->inicio;
    g->inicio = novo;
    
    printf("\nAventureiro '%s' (ID %d) adicionado ao grupo!\n", nome, id);
}

void mostrar_grupo(Grupo* g) {
    if (g->inicio == NULL) {
        printf("\n--- GRUPO DE AVENTUREIROS ---\n");
        printf("O grupo está vazio! Nenhum aventureiro no momento.\n");
        return;
    }
    
    printf("\n--- GRUPO DE AVENTUREIROS ---\n");
    printf("Ordem: do mais recente ao mais antigo\n");
    printf("====================================\n");
    
    No* atual = g->inicio;
    int posicao = 1;
    
    while (atual != NULL) {
        printf("%dº Aventureiro:\n", posicao);
        printf("  ID  : %d\n", atual->dado.id);
        printf("  Nome: %s\n", atual->dado.nome);
        printf("------------------------------------\n");
        atual = atual->prox;
        posicao++;
    }
}

void liberar_grupo(Grupo* g) {
    No* atual = g->inicio;
    while (atual != NULL) {
        No* temp = atual;
        atual = atual->prox;
        free(temp);
    }
    g->inicio = NULL;
    printf("Memória do grupo liberada com sucesso!\n");
}

// ==================== Funções Auxiliares ====================

void limpar_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

void exibir_menu() {
    printf("\n========================================\n");
    printf("   GERENCIADOR DE GRUPO DE AVENTUREIROS\n");
    printf("========================================\n");
    printf("  1 - Adicionar Aventureiro\n");
    printf("  2 - Mostrar Grupo\n");
    printf("  3 - Sair\n");
    printf("========================================\n");
    printf("Escolha uma opção: ");
}

// ==================== main ====================

int main() {
    Grupo grupo;
    inicializar_grupo(&grupo);
    
    int opcao;
    
    printf("========================================\n");
    printf("   BEM-VINDO AO GERENCIADOR DE GRUPO\n");
    printf("========================================\n");
    
    do {
        exibir_menu();
        scanf("%d", &opcao);
        limpar_buffer();
        
        switch (opcao) {
            case 1: {
                int id;
                char nome[50];
                
                printf("\n--- NOVO AVENTUREIRO ---\n");
                printf("Digite o ID do aventureiro: ");
                scanf("%d", &id);
                limpar_buffer();
                
                printf("Digite o nome do aventureiro: ");
                fgets(nome, 50, stdin);
                
                // Remove o '\n' do final da string
                size_t len = strlen(nome);
                if (len > 0 && nome[len - 1] == '\n') {
                    nome[len - 1] = '\0';
                }
                
                adicionar_aventureiro(&grupo, id, nome);
                break;
            }
            case 2: {
                mostrar_grupo(&grupo);
                break;
            }
            case 3: {
                printf("\nSaindo do sistema...\n");
                break;
            }
            default: {
                printf("\nOpção inválida! Tente novamente.\n");
            }
        }
    } while (opcao != 3);
    
    liberar_grupo(&grupo);
    printf("Programa finalizado. Até logo!\n");
    
    return 0;
}
