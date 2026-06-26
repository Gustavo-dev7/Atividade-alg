#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ==================== Definições das Structs ====================

typedef struct membro {
    int id;
    char nome[100];
} Membro;

typedef struct no {
    Membro dado;
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
    
    printf("\nMembro '%s' (ID %d) adicionado à guilda!\n", nome, id);
}

No* pesquisar(Lista* l, int id) {
    No* atual = l->inicio;
    
    while (atual != NULL) {
        if (atual->dado.id == id) {
            return atual; // Encontrou o membro
        }
        atual = atual->prox;
    }
    
    return NULL; // Membro não encontrado
}

void alterar_nome(Lista* l, int id, char* novo_nome) {
    // Busca o membro pelo ID
    No* encontrado = pesquisar(l, id);
    
    if (encontrado == NULL) {
        printf("\nERRO: Membro com ID %d não encontrado na guilda!\n", id);
        printf("Verifique o ID e tente novamente.\n");
        return;
    }
    
    // Atualiza o nome do membro
    strcpy(encontrado->dado.nome, novo_nome);
    printf("\n--- NOME ATUALIZADO COM SUCESSO! ---\n");
    printf("O membro (ID %d) agora se chama: %s\n", id, novo_nome);
}

void mostrar_lista(Lista* l) {
    if (l->inicio == NULL) {
        printf("\n--- REGISTRO DA GUILDA ---\n");
        printf("A guilda está vazia! Nenhum membro registrado.\n");
        return;
    }
    
    printf("\n--- REGISTRO DA GUILDA ---\n");
    printf("Total de membros: %d\n", contar_membros(l));
    printf("============================================\n");
    
    No* atual = l->inicio;
    int posicao = 1;
    
    while (atual != NULL) {
        printf("Membro %d:\n", posicao);
        printf("  ID  : %d\n", atual->dado.id);
        printf("  Nome: %s\n", atual->dado.nome);
        printf("--------------------------------------------\n");
        atual = atual->prox;
        posicao++;
    }
}

int contar_membros(Lista* l) {
    int count = 0;
    No* atual = l->inicio;
    while (atual != NULL) {
        count++;
        atual = atual->prox;
    }
    return count;
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
    printf("   GERENCIADOR DE GUILDA - RPG\n");
    printf("========================================\n");
    printf("  1 - Adicionar membro (inserir no fim)\n");
    printf("  2 - Mostrar registro da guilda\n");
    printf("  3 - Alterar nome de um membro\n");
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
    printf("   BEM-VINDO AO GERENCIADOR DE GUILDA\n");
    printf("========================================\n");
    printf("Gerencie os membros da sua guilda!\n");
    printf("Você pode alterar o nome de qualquer membro.\n");
    
    do {
        exibir_menu();
        scanf("%d", &opcao);
        limpar_buffer();
        
        switch (opcao) {
            case 1: {
                int id;
                char nome[100];
                
                printf("\n--- ADICIONAR MEMBRO ---\n");
                printf("Digite o ID do membro: ");
                scanf("%d", &id);
                limpar_buffer();
                
                printf("Digite o nome do membro: ");
                fgets(nome, 100, stdin);
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
                int id;
                char novo_nome[100];
                
                printf("\n--- ALTERAR NOME DE MEMBRO ---\n");
                printf("Digite o ID do membro que deseja alterar: ");
                scanf("%d", &id);
                limpar_buffer();
                
                printf("Digite o novo nome: ");
                fgets(novo_nome, 100, stdin);
                size_t len = strlen(novo_nome);
                if (len > 0 && novo_nome[len - 1] == '\n') {
                    novo_nome[len - 1] = '\0';
                }
                
                alterar_nome(&guilda, id, novo_nome);
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
