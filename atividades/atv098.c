#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ==================== Definições das Structs ====================

typedef struct membro {
    int id;
    char nome[100];
    int nivel;
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

void inserir_fim(Lista* l, Membro m) {
    No* novo = (No*)malloc(sizeof(No));
    if (novo == NULL) {
        printf("Erro ao alocar memória!\n");
        return;
    }
    
    novo->dado = m;
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
}

void mostrar_guilda(Lista* l) {
    if (l->inicio == NULL) {
        printf("\n--- GUILDA CARREGADA ---\n");
        printf("A guilda está vazia! Nenhum membro encontrado.\n");
        return;
    }
    
    printf("\n========================================\n");
    printf("   GUILDA CARREGADA COM SUCESSO!\n");
    printf("========================================\n");
    
    No* atual = l->inicio;
    int posicao = 1;
    
    while (atual != NULL) {
        printf("Membro %d:\n", posicao);
        printf("  ID    : %d\n", atual->dado.id);
        printf("  Nome  : %s\n", atual->dado.nome);
        printf("  Nível : %d\n", atual->dado.nivel);
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
}

// ============================================================
// FUNÇÃO SALVAR_GUILDA_TESTE - Cria arquivo de teste
// ============================================================
void salvar_guilda_teste() {
    // Cria uma lista com 3 membros fixos
    Membro membros[3] = {
        {101, "Arthur Pendragon", 50},
        {102, "Merlin, O Mago", 75},
        {103, "Lancelot du Lac", 45}
    };
    
    // Abre o arquivo em modo de escrita binária
    FILE* arquivo = fopen("guild_roster.b", "wb");
    if (arquivo == NULL) {
        printf("ERRO: Não foi possível criar o arquivo de teste!\n");
        return;
    }
    
    // Escreve cada membro no arquivo
    int escritos = fwrite(membros, sizeof(Membro), 3, arquivo);
    if (escritos != 3) {
        printf("ERRO: Não foi possível salvar todos os membros!\n");
    } else {
        printf("\nArquivo 'guild_roster.b' criado com 3 membros para teste!\n");
    }
    
    fclose(arquivo);
}

// ============================================================
// FUNÇÃO CARREGAR_GUILDA - IMPLEMENTE AQUI
// ============================================================
Lista carregar_guilda() {
    Lista nova_lista;
    inicializar_lista(&nova_lista);
    
    // Abre o arquivo em modo de leitura binária
    FILE* arquivo = fopen("guild_roster.b", "rb");
    if (arquivo == NULL) {
        printf("\nERRO: Não foi possível abrir o arquivo 'guild_roster.b'!\n");
        printf("Certifique-se de que o arquivo existe.\n");
        return nova_lista;
    }
    
    printf("\n--- CARREGANDO GUILDA ---\n");
    printf("Lendo membros do arquivo 'guild_roster.b'...\n");
    
    Membro temp;
    int contador = 0;
    
    // Lê cada membro do arquivo, um de cada vez
    while (fread(&temp, sizeof(Membro), 1, arquivo) == 1) {
        // Insere o membro lido no final da lista
        inserir_fim(&nova_lista, temp);
        contador++;
        printf("Membro lido: %s (ID %d, Nível %d)\n", temp.nome, temp.id, temp.nivel);
    }
    
    // Fecha o arquivo
    fclose(arquivo);
    
    printf("\n%d membros carregados com sucesso!\n", contador);
    return nova_lista;
}
// ============================================================

// ==================== Função Auxiliar ====================

void exibir_menu() {
    printf("\n========================================\n");
    printf("   GUILDA - SISTEMA DE CARREGAMENTO\n");
    printf("========================================\n");
    printf("  1 - Salvar guilda de teste\n");
    printf("  2 - Carregar guilda do arquivo\n");
    printf("  3 - Mostrar guilda carregada\n");
    printf("  4 - Sair\n");
    printf("========================================\n");
    printf("Escolha uma opção: ");
}

void limpar_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

// ==================== main ====================

int main() {
    Lista guilda;
    inicializar_lista(&guilda);
    
    int opcao;
    int guilda_carregada = 0;
    
    printf("========================================\n");
    printf("   BEM-VINDO AO SISTEMA DE GUILDA\n");
    printf("========================================\n");
    printf("Carregue sua guilda do arquivo de save!\n");
    printf("Arquivo esperado: 'guild_roster.b'\n");
    
    do {
        exibir_menu();
        scanf("%d", &opcao);
        limpar_buffer();
        
        switch (opcao) {
            case 1: {
                salvar_guilda_teste();
                break;
            }
            case 2: {
                // Libera a lista atual se existir
                liberar_lista(&guilda);
                inicializar_lista(&guilda);
                
                // Carrega a nova lista do arquivo
                guilda = carregar_guilda();
                guilda_carregada = 1;
                break;
            }
            case 3: {
                if (!guilda_carregada || guilda.inicio == NULL) {
                    printf("\nNenhuma guilda carregada ainda!\n");
                    printf("Use a opção 2 para carregar a guilda do arquivo.\n");
                } else {
                    mostrar_guilda(&guilda);
                }
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
