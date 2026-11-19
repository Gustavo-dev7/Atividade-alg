#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ==================== Definições das Structs ====================

typedef struct heroi {
    int id;
    char nome[50];
} Heroi;

typedef struct no {
    Heroi dado;
    struct no* prox;
} No;

typedef struct formacao {
    No* inicio;
} Formacao;

// ==================== Funções da Formação ====================

void inicializar_formacao(Formacao* f) {
    f->inicio = NULL;
}

void adicionar_fim(Formacao* f, int id, char* nome) {
    No* novo = (No*)malloc(sizeof(No));
    if (novo == NULL) {
        printf("Erro ao alocar memória!\n");
        return;
    }
    
    novo->dado.id = id;
    strcpy(novo->dado.nome, nome);
    novo->prox = NULL;
    
    // Se a formação estiver vazia
    if (f->inicio == NULL) {
        f->inicio = novo;
    } else {
        // Percorre até o final
        No* atual = f->inicio;
        while (atual->prox != NULL) {
            atual = atual->prox;
        }
        atual->prox = novo;
    }
    
    printf("\nHerói '%s' (ID %d) adicionado ao FINAL da formação!\n", nome, id);
}

void inserir_antes(Formacao* f, int id_guarda, char* nome_guarda, int id_vip) {
    // Caso 1: Lista vazia
    if (f->inicio == NULL) {
        printf("\nERRO: Formação vazia! Não é possível inserir antes de um VIP inexistente.\n");
        return;
    }
    
    // Caso 2: VIP é o primeiro da lista
    if (f->inicio->dado.id == id_vip) {
        // Cria o novo nó (guarda-costas)
        No* novo = (No*)malloc(sizeof(No));
        if (novo == NULL) {
            printf("Erro ao alocar memória!\n");
            return;
        }
        novo->dado.id = id_guarda;
        strcpy(novo->dado.nome, nome_guarda);
        novo->prox = f->inicio;
        f->inicio = novo;
        
        printf("\nGuarda-costas '%s' (ID %d) inserido ANTES do VIP (ID %d) no INÍCIO da formação!\n",
               nome_guarda, id_guarda, id_vip);
        return;
    }
    
    // Caso 3: VIP está no meio ou no final da lista
    No* anterior = f->inicio;
    No* atual = f->inicio->prox;
    
    while (atual != NULL) {
        if (atual->dado.id == id_vip) {
            // Encontrou o VIP, insere o guarda-costas entre anterior e atual
            No* novo = (No*)malloc(sizeof(No));
            if (novo == NULL) {
                printf("Erro ao alocar memória!\n");
                return;
            }
            novo->dado.id = id_guarda;
            strcpy(novo->dado.nome, nome_guarda);
            novo->prox = atual;
            anterior->prox = novo;
            
            printf("\nGuarda-costas '%s' (ID %d) inserido ANTES do VIP (ID %d)!\n",
                   nome_guarda, id_guarda, id_vip);
            return;
        }
        anterior = atual;
        atual = atual->prox;
    }
    
    // Caso 4: VIP não encontrado
    printf("\nERRO: VIP com ID %d não encontrado na formação!\n", id_vip);
    printf("O guarda-costas NÃO foi inserido.\n");
}

void mostrar_formacao(Formacao* f) {
    if (f->inicio == NULL) {
        printf("\n--- FORMAÇÃO DE BATALHA ---\n");
        printf("A formação está vazia! Nenhum herói na equipe.\n");
        return;
    }
    
    printf("\n--- FORMAÇÃO DE BATALHA ---\n");
    printf("Ordem: da FRENTE (posição 1) para TRÁS\n");
    printf("============================================\n");
    
    No* atual = f->inicio;
    int posicao = 1;
    
    while (atual != NULL) {
        printf("Posição %d:\n", posicao);
        printf("  ID  : %d\n", atual->dado.id);
        printf("  Nome: %s\n", atual->dado.nome);
        
        // Marca o VIP com um indicador visual (opcional)
        if (posicao == 1) {
            printf("  (FRENTE DA FORMAÇÃO)\n");
        }
        printf("--------------------------------------------\n");
        atual = atual->prox;
        posicao++;
    }
}

void liberar_formacao(Formacao* f) {
    No* atual = f->inicio;
    while (atual != NULL) {
        No* temp = atual;
        atual = atual->prox;
        free(temp);
    }
    f->inicio = NULL;
    printf("Memória da formação liberada com sucesso!\n");
}

// ==================== Funções Auxiliares ====================

void limpar_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

void exibir_menu() {
    printf("\n========================================\n");
    printf("   FORMAÇÃO DE BATALHA - RPG TÁTICO\n");
    printf("========================================\n");
    printf("  1 - Adicionar Herói no FIM da Formação\n");
    printf("  2 - Adicionar Guarda-Costas (Inserir Antes)\n");
    printf("  3 - Mostrar Formação\n");
    printf("  4 - Sair\n");
    printf("========================================\n");
    printf("Escolha uma opção: ");
}

void ler_dados_heroi(int* id, char* nome) {
    printf("Digite o ID do herói: ");
    scanf("%d", id);
    limpar_buffer();
    
    printf("Digite o nome do herói: ");
    fgets(nome, 50, stdin);
    size_t len = strlen(nome);
    if (len > 0 && nome[len - 1] == '\n') {
        nome[len - 1] = '\0';
    }
}

// ==================== main ====================

int main() {
    Formacao formacao;
    inicializar_formacao(&formacao);
    
    int opcao;
    
    printf("========================================\n");
    printf("   SISTEMA DE FORMAÇÃO DE BATALHA\n");
    printf("========================================\n");
    printf("Posicione seus heróis estrategicamente!\n");
    printf("Use Guarda-Costas para proteger o VIP!\n");
    
    do {
        exibir_menu();
        scanf("%d", &opcao);
        limpar_buffer();
        
        switch (opcao) {
            case 1: {
                int id;
                char nome[50];
                
                printf("\n--- ADICIONAR HERÓI NO FIM ---\n");
                ler_dados_heroi(&id, nome);
                adicionar_fim(&formacao, id, nome);
                break;
            }
            case 2: {
                int id_guarda, id_vip;
                char nome_guarda[50];
                
                printf("\n--- ADICIONAR GUARDA-COSTAS (INSERIR ANTES) ---\n");
                printf("Dados do Guarda-Costas:\n");
                printf("Digite o ID do guarda-costas: ");
                scanf("%d", &id_guarda);
                limpar_buffer();
                
                printf("Digite o nome do guarda-costas: ");
                fgets(nome_guarda, 50, stdin);
                size_t len = strlen(nome_guarda);
                if (len > 0 && nome_guarda[len - 1] == '\n') {
                    nome_guarda[len - 1] = '\0';
                }
                
                printf("\nDigite o ID do VIP (herói a ser protegido): ");
                scanf("%d", &id_vip);
                limpar_buffer();
                
                inserir_antes(&formacao, id_guarda, nome_guarda, id_vip);
                break;
            }
            case 3: {
                mostrar_formacao(&formacao);
                break;
            }
            case 4: {
                printf("\nSaindo do sistema de formação...\n");
                break;
            }
            default: {
                printf("\nOpção inválida! Tente novamente.\n");
            }
        }
    } while (opcao != 4);
    
    liberar_formacao(&formacao);
    printf("Programa finalizado. Boa batalha!\n");
    
    return 0;
}
