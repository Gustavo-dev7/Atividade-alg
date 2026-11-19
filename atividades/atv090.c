#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ==================== Definições das Structs ====================

typedef struct ward {
    int id;
    char nome[100];
} Ward;

typedef struct no {
    Ward dado;
    struct no* prox;
} No;

typedef struct lista {
    No* inicio;
} Lista;

// ==================== Funções da Lista ====================

void inicializar_lista(Lista* l) {
    l->inicio = NULL;
}

void adicionar_ward(Lista* l, int id, char* nome) {
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
    
    printf("\nWard '%s' (ID %d) adicionado à sequência de proteção!\n", nome, id);
}

void deletar_apos(Lista* l, int id_referencia) {
    // Caso 1: Lista vazia
    if (l->inicio == NULL) {
        printf("\nERRO: Nenhum ward ativo! A lista está vazia.\n");
        return;
    }
    
    // Procura o ward de referência
    No* atual = l->inicio;
    
    while (atual != NULL) {
        if (atual->dado.id == id_referencia) {
            // Encontrou o ward de referência
            
            // Caso 2: O ward de referência é o último da lista
            if (atual->prox == NULL) {
                printf("\nERRO: O ward '%s' (ID %d) é o último da sequência!\n", 
                       atual->dado.nome, id_referencia);
                printf("Não há ward após ele para ser destruído.\n");
                return;
            }
            
            // Caso 3: Há um ward após o de referência - deleta o próximo
            No* remover = atual->prox;
            atual->prox = remover->prox;
            
            printf("\n--- WARD SHATTER LANÇADO! ---\n");
            printf("Ward '%s' (ID %d) foi destruído!\n", remover->dado.nome, remover->dado.id);
            printf("Ele estava logo após o ward '%s' (ID %d).\n", 
                   atual->dado.nome, id_referencia);
            
            free(remover);
            return;
        }
        atual = atual->prox;
    }
    
    // Caso 4: Ward de referência não encontrado
    printf("\nERRO: Ward com ID %d não encontrado na sequência!\n", id_referencia);
    printf("Verifique o ID e tente novamente.\n");
}

void mostrar_wards(Lista* l) {
    if (l->inicio == NULL) {
        printf("\n--- WARDS ATIVOS ---\n");
        printf("Nenhum ward ativo no momento.\n");
        printf("O personagem está sem proteção mágica!\n");
        return;
    }
    
    printf("\n--- WARDS ATIVOS ---\n");
    printf("Sequência de proteção (do mais antigo ao mais recente):\n");
    printf("============================================\n");
    
    No* atual = l->inicio;
    int posicao = 1;
    
    while (atual != NULL) {
        printf("Ward %d:\n", posicao);
        printf("  ID  : %d\n", atual->dado.id);
        printf("  Nome: %s\n", atual->dado.nome);
        
        if (atual->prox == NULL) {
            printf("  (ÚLTIMO WARD DA SEQUÊNCIA)\n");
        }
        printf("--------------------------------------------\n");
        atual = atual->prox;
        posicao++;
    }
}

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
    printf("   SISTEMA DE WARDS MÁGICOS\n");
    printf("========================================\n");
    printf("  1 - Adicionar Ward (no final)\n");
    printf("  2 - Lançar 'Ward Shatter' (deletar após)\n");
    printf("  3 - Mostrar Wards Ativos\n");
    printf("  4 - Sair\n");
    printf("========================================\n");
    printf("Escolha uma opção: ");
}

// ==================== main ====================

int main() {
    Lista wards;
    inicializar_lista(&wards);
    
    int opcao;
    
    printf("========================================\n");
    printf("   BEM-VINDO AO SISTEMA DE WARDS\n");
    printf("========================================\n");
    printf("Proteja seu personagem com barreiras mágicas!\n");
    printf("Use 'Ward Shatter' para destruir wards em cadeia.\n");
    
    do {
        exibir_menu();
        scanf("%d", &opcao);
        limpar_buffer();
        
        switch (opcao) {
            case 1: {
                int id;
                char nome[100];
                
                printf("\n--- ADICIONAR WARD ---\n");
                printf("Digite o ID do ward: ");
                scanf("%d", &id);
                limpar_buffer();
                
                printf("Digite o nome do ward: ");
                fgets(nome, 100, stdin);
                size_t len = strlen(nome);
                if (len > 0 && nome[len - 1] == '\n') {
                    nome[len - 1] = '\0';
                }
                
                adicionar_ward(&wards, id, nome);
                break;
            }
            case 2: {
                int id_referencia;
                
                printf("\n--- LANÇAR WARD SHATTER ---\n");
                printf("Digite o ID do ward de referência: ");
                scanf("%d", &id_referencia);
                limpar_buffer();
                
                deletar_apos(&wards, id_referencia);
                break;
            }
            case 3: {
                mostrar_wards(&wards);
                break;
            }
            case 4: {
                printf("\nSaindo do sistema de wards...\n");
                break;
            }
            default: {
                printf("\nOpção inválida! Tente novamente.\n");
            }
        }
    } while (opcao != 4);
    
    liberar_lista(&wards);
    printf("Programa finalizado. Que a magia esteja com você!\n");
    
    return 0;
}
