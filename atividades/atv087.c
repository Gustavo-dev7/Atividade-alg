#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ==================== Definições das Structs ====================

typedef struct jogador {
    int id;
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

void adicionar_jogador(Fila* f, int id, char* nome) {
    No* novo = (No*)malloc(sizeof(No));
    if (novo == NULL) {
        printf("Erro ao alocar memória!\n");
        return;
    }
    
    novo->dado.id = id;
    strcpy(novo->dado.nome, nome);
    novo->prox = NULL;
    
    // Se a fila estiver vazia
    if (fila_vazia(f)) {
        f->inicio = novo;
        f->fim = novo;
    } else {
        // Adiciona no final
        f->fim->prox = novo;
        f->fim = novo;
    }
    
    printf("\nJogador '%s' (ID %d) entrou na fila de espera!\n", nome, id);
}

void iniciar_partida(Fila* f) {
    // Verifica se a fila está vazia
    if (fila_vazia(f)) {
        printf("\nERRO: Não há jogadores na fila de espera!\n");
        printf("A partida não pode ser iniciada.\n");
        return;
    }
    
    // Remove o primeiro jogador da fila
    No* removido = f->inicio;
    Jogador jogador_saindo = removido->dado;
    
    // Atualiza o início da fila
    f->inicio = f->inicio->prox;
    
    // Se a fila ficou vazia, o fim também deve ser NULL
    if (f->inicio == NULL) {
        f->fim = NULL;
    }
    
    // Libera a memória do nó removido
    free(removido);
    
    printf("\n--- PARTIDA INICIADA! ---\n");
    printf("Jogador '%s' (ID %d) foi removido da fila e entrou na partida!\n", 
           jogador_saindo.nome, jogador_saindo.id);
    
    if (!fila_vazia(f)) {
        printf("Ainda há %d jogador(es) na fila de espera.\n", contar_jogadores(f));
    } else {
        printf("A fila de espera agora está vazia.\n");
    }
}

int contar_jogadores(Fila* f) {
    int count = 0;
    No* atual = f->inicio;
    while (atual != NULL) {
        count++;
        atual = atual->prox;
    }
    return count;
}

void mostrar_fila(Fila* f) {
    if (fila_vazia(f)) {
        printf("\n--- FILA DE MATCHMAKING ---\n");
        printf("A fila de espera está vazia!\n");
        printf("Nenhum jogador aguardando partida.\n");
        return;
    }
    
    printf("\n--- FILA DE MATCHMAKING ---\n");
    printf("Ordem: do primeiro (mais antigo) ao último (mais recente)\n");
    printf("Total de jogadores na fila: %d\n", contar_jogadores(f));
    printf("============================================\n");
    
    No* atual = f->inicio;
    int posicao = 1;
    
    while (atual != NULL) {
        printf("%dº Jogador:\n", posicao);
        printf("  ID  : %d\n", atual->dado.id);
        printf("  Nome: %s\n", atual->dado.nome);
        
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
    printf("   SISTEMA DE MATCHMAKING MULTIPLAYER\n");
    printf("========================================\n");
    printf("  1 - Adicionar jogador ao fim da fila\n");
    printf("  2 - Iniciar partida (remover primeiro)\n");
    printf("  3 - Mostrar fila de espera\n");
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
    printf("Gerenciando jogadores para partidas multiplayer!\n");
    printf("FIFO (First-In, First-Out): o primeiro a entrar,\n");
    printf("é o primeiro a ser atendido.\n");
    
    do {
        exibir_menu();
        scanf("%d", &opcao);
        limpar_buffer();
        
        switch (opcao) {
            case 1: {
                int id;
                char nome[50];
                
                printf("\n--- ADICIONAR JOGADOR NA FILA ---\n");
                printf("Digite o ID do jogador: ");
                scanf("%d", &id);
                limpar_buffer();
                
                printf("Digite o nome do jogador: ");
                fgets(nome, 50, stdin);
                size_t len = strlen(nome);
                if (len > 0 && nome[len - 1] == '\n') {
                    nome[len - 1] = '\0';
                }
                
                adicionar_jogador(&fila, id, nome);
                break;
            }
            case 2: {
                iniciar_partida(&fila);
                break;
            }
            case 3: {
                mostrar_fila(&fila);
                break;
            }
            case 4: {
                printf("\nSaindo do sistema de matchmaking...\n");
                break;
            }
            default: {
                printf("\nOpção inválida! Tente novamente.\n");
            }
        }
    } while (opcao != 4);
    
    liberar_fila(&fila);
    printf("Programa finalizado. Boas partidas!\n");
    
    return 0;
}
