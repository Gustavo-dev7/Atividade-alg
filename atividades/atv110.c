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

void inserir(Fila* f, Jogador j) {
    No* novo = (No*)malloc(sizeof(No));
    if (novo == NULL) {
        printf("Erro ao alocar memória!\n");
        return;
    }
    
    novo->dado = j;
    novo->prox = NULL;
    
    if (fila_vazia(f)) {
        f->inicio = novo;
        f->fim = novo;
    } else {
        f->fim->prox = novo;
        f->fim = novo;
    }
    
    printf("\nJogador '%s' (ID %d) entrou na fila de matchmaking!\n", j.nickname, j.id);
}

void mostrar(Fila* f) {
    if (fila_vazia(f)) {
        printf("\n--- FILA DE MATCHMAKING ---\n");
        printf("A fila de matchmaking está vazia.\n");
        printf("Nenhum jogador aguardando partida.\n");
        return;
    }
    
    printf("\n--- FILA DE MATCHMAKING ---\n");
    printf("Ordem: do primeiro (início) ao último (fim)\n");
    printf("============================================\n");
    
    No* aux = f->inicio;
    int posicao = 1;
    
    while (aux != NULL) {
        printf("%dº Jogador:\n", posicao);
        printf("  ID      : %d\n", aux->dado.id);
        printf("  Nickname: %s\n", aux->dado.nickname);
        if (posicao == 1) {
            printf("  (PRÓXIMO A ENTRAR NA PARTIDA)\n");
        }
        printf("--------------------------------------------\n");
        aux = aux->prox;
        posicao++;
    }
}

// ============================================================
// FUNÇÃO REMOVER - IMPLEMENTE AQUI
// ============================================================
Jogador remover(Fila* f) {
    Jogador vazio;
    vazio.id = -1;
    strcpy(vazio.nickname, "");
    
    // Caso 1: Fila vazia
    if (fila_vazia(f)) {
        printf("\nERRO: A fila de matchmaking está vazia!\n");
        printf("Não há jogadores para remover.\n");
        return vazio;
    }
    
    // Guarda os dados do primeiro jogador e o ponteiro para o nó
    No* removido = f->inicio;
    Jogador jogador_removido = removido->dado;
    
    // Atualiza o início da fila para o segundo elemento
    f->inicio = f->inicio->prox;
    
    // Caso 2: A fila tinha apenas um elemento
    if (f->inicio == NULL) {
        f->fim = NULL;
    }
    
    // Libera a memória do nó removido
    free(removido);
    
    return jogador_removido;
}
// ============================================================

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
    printf("  1 - Adicionar Jogador na Fila\n");
    printf("  2 - Mostrar Fila\n");
    printf("  3 - Iniciar Partida (remover primeiro)\n");
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
                
                printf("\n--- ADICIONAR JOGADOR NA FILA ---\n");
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
                mostrar(&fila);
                break;
            }
            case 3: {
                printf("\n--- INICIANDO PARTIDA ---\n");
                Jogador removido = remover(&fila);
                
                // Verifica se a remoção foi bem-sucedida
                if (removido.id != -1) {
                    printf("O jogador '%s' (ID: %d) foi removido da fila e entrou em uma partida!\n", 
                           removido.nickname, removido.id);
                    if (!fila_vazia(&fila)) {
                        printf("Ainda há jogadores aguardando na fila.\n");
                    } else {
                        printf("A fila de matchmaking agora está vazia.\n");
                    }
                }
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
