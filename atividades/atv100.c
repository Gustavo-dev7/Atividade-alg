#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ==================== Definições das Structs ====================

typedef struct feitico {
    char nome[50];
    int custo_mana;
} Feitico;

typedef struct no {
    Feitico dado;
    struct no* prox;
} No;

typedef struct pilha {
    No* topo;
} Pilha;

// ==================== Funções da Pilha ====================

void inicializar_pilha(Pilha* p) {
    p->topo = NULL;
}

int pilha_vazia(Pilha* p) {
    return (p->topo == NULL);
}

void push(Pilha* p, char* nome, int custo_mana) {
    No* novo = (No*)malloc(sizeof(No));
    if (novo == NULL) {
        printf("Erro ao alocar memória!\n");
        return;
    }
    
    strcpy(novo->dado.nome, nome);
    novo->dado.custo_mana = custo_mana;
    novo->prox = p->topo;
    p->topo = novo;
    
    printf("\nFeitiço '%s' (Custo: %d mana) adicionado ao topo da pilha!\n", nome, custo_mana);
}

void mostrar_pilha(Pilha* p) {
    if (pilha_vazia(p)) {
        printf("\n--- PILHA DE COMANDOS ---\n");
        printf("Nenhum feitiço na pilha.\n");
        return;
    }
    
    printf("\n--- PILHA DE COMANDOS ---\n");
    printf("Ordem: do topo (último adicionado) para a base\n");
    printf("============================================\n");
    
    No* atual = p->topo;
    int posicao = 1;
    
    while (atual != NULL) {
        printf("Comando %d (TOPO):\n", posicao);
        printf("  Feitiço    : %s\n", atual->dado.nome);
        printf("  Custo Mana : %d\n", atual->dado.custo_mana);
        if (posicao == 1) {
            printf("  (PRÓXIMO A SER EXECUTADO)\n");
        }
        printf("--------------------------------------------\n");
        atual = atual->prox;
        posicao++;
    }
}

void liberar_pilha(Pilha* p) {
    No* atual = p->topo;
    int contador = 0;
    
    while (atual != NULL) {
        No* temp = atual;
        atual = atual->prox;
        free(temp);
        contador++;
    }
    
    p->topo = NULL;
    printf("\n%d feitiços removidos da pilha.\n", contador);
    printf("Memória da pilha liberada com sucesso!\n");
}

// ==================== Funções Auxiliares ====================

void limpar_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

void exibir_menu() {
    printf("\n========================================\n");
    printf("   PILHA DE COMANDOS - ARCANISTA\n");
    printf("========================================\n");
    printf("  1 - Adicionar feitiço à pilha (push)\n");
    printf("  2 - Finalizar sequência e sair\n");
    printf("========================================\n");
    printf("Escolha uma opção: ");
}

void exibir_status_pilha(Pilha* p) {
    printf("\nStatus atual da pilha: ");
    if (pilha_vazia(p)) {
        printf("VAZIA\n");
    } else {
        printf("%d feitiço(s) na pilha\n", contar_feiticos(p));
    }
}

int contar_feiticos(Pilha* p) {
    int count = 0;
    No* atual = p->topo;
    while (atual != NULL) {
        count++;
        atual = atual->prox;
    }
    return count;
}

// ==================== main ====================

int main() {
    Pilha comandos;
    inicializar_pilha(&comandos);
    
    int opcao;
    
    printf("========================================\n");
    printf("   BEM-VINDO AO SISTEMA DE COMANDOS\n");
    printf("========================================\n");
    printf("Gerencie a pilha de feitiços do Arcanista!\n");
    printf("O último feitiço adicionado será o primeiro\n");
    printf("a ser executado (LIFO - Last In, First Out).\n");
    
    do {
        exibir_menu();
        scanf("%d", &opcao);
        limpar_buffer();
        
        switch (opcao) {
            case 1: {
                char nome[50];
                int custo_mana;
                
                printf("\n--- ADICIONAR FEITIÇO ---\n");
                printf("Digite o nome do feitiço: ");
                fgets(nome, 50, stdin);
                size_t len = strlen(nome);
                if (len > 0 && nome[len - 1] == '\n') {
                    nome[len - 1] = '\0';
                }
                
                printf("Digite o custo de mana: ");
                scanf("%d", &custo_mana);
                limpar_buffer();
                
                push(&comandos, nome, custo_mana);
                exibir_status_pilha(&comandos);
                break;
            }
            case 2: {
                printf("\nFinalizando sequência de comandos...\n");
                if (!pilha_vazia(&comandos)) {
                    printf("A pilha contém %d feitiço(s) aguardando execução.\n", contar_feiticos(&comandos));
                    printf("(Em uma aula futura, aprenderemos a executá-los!)\n");
                }
                break;
            }
            default: {
                printf("\nOpção inválida! Tente novamente.\n");
            }
        }
    } while (opcao != 2);
    
    // Exibe a pilha final antes de liberar
    mostrar_pilha(&comandos);
    
    liberar_pilha(&comandos);
    printf("\nPrograma finalizado. Até a próxima aventura!\n");
    
    return 0;
}
