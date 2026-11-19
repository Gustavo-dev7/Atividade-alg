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
    
    if (l->inicio == NULL) {
        l->inicio = novo;
    } else {
        No* atual = l->inicio;
        while (atual->prox != NULL) {
            atual = atual->prox;
        }
        atual->prox = novo;
    }
    
    printf("\nMembro '%s' (ID %d) adicionado à guilda!\n", nome, id);
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

// ============================================================
// FUNÇÃO SALVAR_GUILD_ARQUIVO - IMPLEMENTE AQUI
// ============================================================
void salvar_guild_arquivo(Lista lista) {
    // Abre o arquivo em modo de escrita binária
    FILE* arquivo = fopen("guild_roster.bin", "wb");
    if (arquivo == NULL) {
        printf("\nERRO: Não foi possível abrir o arquivo para salvar!\n");
        return;
    }
    
    // Verifica se a lista está vazia
    if (lista.inicio == NULL) {
        printf("\nA guilda está vazia! Nada para salvar.\n");
        fclose(arquivo);
        return;
    }
    
    printf("\n--- SALVANDO GUILDA ---\n");
    printf("Salvando membros em 'guild_roster.bin'...\n");
    
    int contador = 0;
    No* atual = lista.inicio;
    
    // Percorre a lista do início ao fim
    while (atual != NULL) {
        // Escreve apenas os dados do membro (não o ponteiro prox)
        size_t escritos = fwrite(&atual->dado, sizeof(Membro), 1, arquivo);
        if (escritos != 1) {
            printf("Erro ao salvar o membro ID %d!\n", atual->dado.id);
        } else {
            contador++;
        }
        atual = atual->prox;
    }
    
    // Fecha o arquivo
    fclose(arquivo);
    
    printf("%d membros salvos com sucesso em 'guild_roster.bin'!\n", contador);
}
// ============================================================

void liberar_lista(Lista* l) {
    No* atual = l->inicio;
    while (atual != NULL) {
        No* temp = atual;
        atual = atual->prox;
        free(temp);
    }
    l->inicio = NULL;
}

// ==================== Funções Auxiliares ====================

void limpar_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

void exibir_menu() {
    printf("\n========================================\n");
    printf("   GERENCIADOR DE GUILDA - MMORPG\n");
    printf("========================================\n");
    printf("  1 - Adicionar membro\n");
    printf("  2 - Mostrar guilda\n");
    printf("  3 - Salvar guilda em arquivo binário\n");
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
    printf("Não se esqueça de salvar antes de sair!\n");
    
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
                salvar_guild_arquivo(guilda);
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
