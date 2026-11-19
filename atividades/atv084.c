#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ==================== Definições das Structs ====================

typedef struct missao {
    int id;
    char titulo[100];
    char status[20];
} Missao;

typedef struct no {
    Missao dado;
    struct no* prox;
} No;

typedef struct diario {
    No* inicio;
} Diario;

// ==================== Funções do Diário ====================

void inicializar_diario(Diario* d) {
    d->inicio = NULL;
}

void adicionar_missao(Diario* d, int id, char* titulo, char* status) {
    No* novo = (No*)malloc(sizeof(No));
    if (novo == NULL) {
        printf("Erro ao alocar memória!\n");
        return;
    }
    
    novo->dado.id = id;
    strcpy(novo->dado.titulo, titulo);
    strcpy(novo->dado.status, status);
    novo->prox = NULL;
    
    // Se a lista estiver vazia
    if (d->inicio == NULL) {
        d->inicio = novo;
    } else {
        // Percorre até o final
        No* atual = d->inicio;
        while (atual->prox != NULL) {
            atual = atual->prox;
        }
        atual->prox = novo;
    }
    
    printf("\nMissão '%s' (ID %d) adicionada com sucesso!\n", titulo, id);
}

void mostrar_missoes(Diario* d) {
    if (d->inicio == NULL) {
        printf("\n--- DIÁRIO DE MISSÕES ---\n");
        printf("O diário está vazio! Nenhuma missão cadastrada.\n");
        return;
    }
    
    printf("\n--- DIÁRIO DE MISSÕES ---\n");
    printf("============================================\n");
    
    No* atual = d->inicio;
    int contador = 1;
    
    while (atual != NULL) {
        printf("Missão %d:\n", contador);
        printf("  ID     : %d\n", atual->dado.id);
        printf("  Título : %s\n", atual->dado.titulo);
        printf("  Status : %s\n", atual->dado.status);
        printf("--------------------------------------------\n");
        atual = atual->prox;
        contador++;
    }
}

No* pesquisar_missao(Diario* d, int id) {
    No* atual = d->inicio;
    
    while (atual != NULL) {
        if (atual->dado.id == id) {
            return atual;  // Missão encontrada
        }
        atual = atual->prox;
    }
    
    return NULL;  // Missão não encontrada
}

void liberar_diario(Diario* d) {
    No* atual = d->inicio;
    while (atual != NULL) {
        No* temp = atual;
        atual = atual->prox;
        free(temp);
    }
    d->inicio = NULL;
    printf("Memória do diário liberada com sucesso!\n");
}

// ==================== Funções Auxiliares ====================

void limpar_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

void exibir_menu() {
    printf("\n========================================\n");
    printf("   DIÁRIO DE MISSÕES - RPG\n");
    printf("========================================\n");
    printf("  1 - Adicionar Missão\n");
    printf("  2 - Mostrar Missões\n");
    printf("  3 - Buscar Missão por ID\n");
    printf("  4 - Sair\n");
    printf("========================================\n");
    printf("Escolha uma opção: ");
}

void exibir_detalhes_missao(No* no) {
    printf("\n--- MISSÃO ENCONTRADA ---\n");
    printf("  ID     : %d\n", no->dado.id);
    printf("  Título : %s\n", no->dado.titulo);
    printf("  Status : %s\n", no->dado.status);
    printf("==========================\n");
}

// ==================== main ====================

int main() {
    Diario diario;
    inicializar_diario(&diario);
    
    int opcao;
    
    printf("========================================\n");
    printf("   BEM-VINDO AO DIÁRIO DE MISSÕES\n");
    printf("========================================\n");
    printf("Gerencie suas missões de forma fácil!\n");
    
    do {
        exibir_menu();
        scanf("%d", &opcao);
        limpar_buffer();
        
        switch (opcao) {
            case 1: {
                int id;
                char titulo[100];
                char status[20];
                
                printf("\n--- ADICIONAR NOVA MISSÃO ---\n");
                
                printf("Digite o ID da missão: ");
                scanf("%d", &id);
                limpar_buffer();
                
                printf("Digite o título da missão: ");
                fgets(titulo, 100, stdin);
                size_t len = strlen(titulo);
                if (len > 0 && titulo[len - 1] == '\n') {
                    titulo[len - 1] = '\0';
                }
                
                printf("Digite o status da missão (Ativa/Concluída/Pendente): ");
                fgets(status, 20, stdin);
                len = strlen(status);
                if (len > 0 && status[len - 1] == '\n') {
                    status[len - 1] = '\0';
                }
                
                adicionar_missao(&diario, id, titulo, status);
                break;
            }
            case 2: {
                mostrar_missoes(&diario);
                break;
            }
            case 3: {
                int id_busca;
                
                printf("\n--- BUSCAR MISSÃO POR ID ---\n");
                printf("Digite o ID da missão: ");
                scanf("%d", &id_busca);
                limpar_buffer();
                
                No* resultado = pesquisar_missao(&diario, id_busca);
                
                if (resultado != NULL) {
                    exibir_detalhes_missao(resultado);
                } else {
                    printf("\nMissão não encontrada!\n");
                    printf("Verifique se o ID está correto.\n");
                }
                break;
            }
            case 4: {
                printf("\nSaindo do diário de missões...\n");
                break;
            }
            default: {
                printf("\nOpção inválida! Tente novamente.\n");
            }
        }
    } while (opcao != 4);
    
    liberar_diario(&diario);
    printf("Programa finalizado. Até a próxima aventura!\n");
    
    return 0;
}
