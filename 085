#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ==================== Definições das Structs ====================

typedef struct item {
    int id;
    char nome[50];
} Item;

typedef struct no {
    Item dado;
    struct no* prox;
} No;

typedef struct inventario {
    No* inicio;
} Inventario;

// ==================== Funções do Inventário ====================

void inicializar_inventario(Inventario* inv) {
    inv->inicio = NULL;
}

void inserir_inicio(Inventario* inv, int id, char* nome) {
    No* novo = (No*)malloc(sizeof(No));
    if (novo == NULL) {
        printf("Erro ao alocar memória!\n");
        return;
    }
    
    novo->dado.id = id;
    strcpy(novo->dado.nome, nome);
    novo->prox = inv->inicio;
    inv->inicio = novo;
    
    printf("\nItem '%s' (ID %d) inserido no INÍCIO do inventário!\n", nome, id);
}

void inserir_fim(Inventario* inv, int id, char* nome) {
    No* novo = (No*)malloc(sizeof(No));
    if (novo == NULL) {
        printf("Erro ao alocar memória!\n");
        return;
    }
    
    novo->dado.id = id;
    strcpy(novo->dado.nome, nome);
    novo->prox = NULL;
    
    // Se o inventário estiver vazio
    if (inv->inicio == NULL) {
        inv->inicio = novo;
    } else {
        // Percorre até o final
        No* atual = inv->inicio;
        while (atual->prox != NULL) {
            atual = atual->prox;
        }
        atual->prox = novo;
    }
    
    printf("\nItem '%s' (ID %d) inserido no FIM do inventário!\n", nome, id);
}

void inserir_apos_fragmento(Inventario* inv, int id_catalisador, char* nome_catalisador, int id_fragmento) {
    // Primeiro, procura o fragmento pelo ID
    No* atual = inv->inicio;
    No* fragmento_encontrado = NULL;
    
    while (atual != NULL) {
        if (atual->dado.id == id_fragmento) {
            fragmento_encontrado = atual;
            break;
        }
        atual = atual->prox;
    }
    
    // Se o fragmento não foi encontrado
    if (fragmento_encontrado == NULL) {
        printf("\nERRO: Fragmento com ID %d não encontrado no inventário!\n", id_fragmento);
        printf("O catalisador NÃO foi inserido.\n");
        return;
    }
    
    // Cria o novo nó para o catalisador
    No* novo = (No*)malloc(sizeof(No));
    if (novo == NULL) {
        printf("Erro ao alocar memória!\n");
        return;
    }
    
    novo->dado.id = id_catalisador;
    strcpy(novo->dado.nome, nome_catalisador);
    
    // Insere o catalisador APÓS o fragmento encontrado
    novo->prox = fragmento_encontrado->prox;
    fragmento_encontrado->prox = novo;
    
    printf("\nCatalisador '%s' (ID %d) inserido APÓS o fragmento (ID %d)!\n", 
           nome_catalisador, id_catalisador, id_fragmento);
}

void mostrar_inventario(Inventario* inv) {
    if (inv->inicio == NULL) {
        printf("\n--- INVENTÁRIO DE ITENS ---\n");
        printf("O inventário está vazio!\n");
        return;
    }
    
    printf("\n--- INVENTÁRIO DE ITENS ---\n");
    printf("============================================\n");
    
    No* atual = inv->inicio;
    int posicao = 1;
    
    while (atual != NULL) {
        printf("Item %d:\n", posicao);
        printf("  ID  : %d\n", atual->dado.id);
        printf("  Nome: %s\n", atual->dado.nome);
        printf("--------------------------------------------\n");
        atual = atual->prox;
        posicao++;
    }
}

void liberar_inventario(Inventario* inv) {
    No* atual = inv->inicio;
    while (atual != NULL) {
        No* temp = atual;
        atual = atual->prox;
        free(temp);
    }
    inv->inicio = NULL;
    printf("Memória do inventário liberada com sucesso!\n");
}

// ==================== Funções Auxiliares ====================

void limpar_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

void exibir_menu() {
    printf("\n========================================\n");
    printf("   INVENTÁRIO DE ITENS DE MISSÃO\n");
    printf("========================================\n");
    printf("  1 - Inserir item no INÍCIO\n");
    printf("  2 - Inserir item no FIM\n");
    printf("  3 - Inserir catalisador APÓS um fragmento\n");
    printf("  4 - Mostrar inventário\n");
    printf("  5 - Sair\n");
    printf("========================================\n");
    printf("Escolha uma opção: ");
}

void ler_dados_item(int* id, char* nome) {
    printf("Digite o ID do item: ");
    scanf("%d", id);
    limpar_buffer();
    
    printf("Digite o nome do item: ");
    fgets(nome, 50, stdin);
    size_t len = strlen(nome);
    if (len > 0 && nome[len - 1] == '\n') {
        nome[len - 1] = '\0';
    }
}

// ==================== main ====================

int main() {
    Inventario inventario;
    inicializar_inventario(&inventario);
    
    int opcao;
    
    printf("========================================\n");
    printf("   SISTEMA DE INVENTÁRIO DE MISSÃO\n");
    printf("========================================\n");
    printf("Colete fragmentos e catalisadores!\n");
    
    do {
        exibir_menu();
        scanf("%d", &opcao);
        limpar_buffer();
        
        switch (opcao) {
            case 1: {
                int id;
                char nome[50];
                
                printf("\n--- INSERIR ITEM NO INÍCIO ---\n");
                ler_dados_item(&id, nome);
                inserir_inicio(&inventario, id, nome);
                break;
            }
            case 2: {
                int id;
                char nome[50];
                
                printf("\n--- INSERIR ITEM NO FIM ---\n");
                ler_dados_item(&id, nome);
                inserir_fim(&inventario, id, nome);
                break;
            }
            case 3: {
                int id_catalisador, id_fragmento;
                char nome_catalisador[50];
                
                printf("\n--- INSERIR CATALISADOR APÓS FRAGMENTO ---\n");
                printf("Dados do Catalisador:\n");
                printf("Digite o ID do catalisador: ");
                scanf("%d", &id_catalisador);
                limpar_buffer();
                
                printf("Digite o nome do catalisador: ");
                fgets(nome_catalisador, 50, stdin);
                size_t len = strlen(nome_catalisador);
                if (len > 0 && nome_catalisador[len - 1] == '\n') {
                    nome_catalisador[len - 1] = '\0';
                }
                
                printf("\nDigite o ID do fragmento após o qual inserir: ");
                scanf("%d", &id_fragmento);
                limpar_buffer();
                
                inserir_apos_fragmento(&inventario, id_catalisador, nome_catalisador, id_fragmento);
                break;
            }
            case 4: {
                mostrar_inventario(&inventario);
                break;
            }
            case 5: {
                printf("\nSaindo do sistema...\n");
                break;
            }
            default: {
                printf("\nOpção inválida! Tente novamente.\n");
            }
        }
    } while (opcao != 5);
    
    liberar_inventario(&inventario);
    printf("Programa finalizado. Boa sorte na missão!\n");
    
    return 0;
}
