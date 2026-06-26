#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ==================== Definições das Structs ====================

typedef struct monstro {
    int id;          // Nível de Ameaça
    char nome[50];
} Monstro;

typedef struct no {
    Monstro dado;
    struct no* prox;
} No;

typedef struct lista {
    No* inicio;
} Lista;

// ==================== Funções da Lista ====================

void inicializar_lista(Lista* l) {
    l->inicio = NULL;
}

void adicionar_monstro(Lista* l, int id, char* nome) {
    No* novo = (No*)malloc(sizeof(No));
    if (novo == NULL) {
        printf("Erro ao alocar memória!\n");
        return;
    }
    
    novo->dado.id = id;
    strcpy(novo->dado.nome, nome);
    novo->prox = NULL;
    
    // Insere no final da lista
    if (l->inicio == NULL) {
        l->inicio = novo;
    } else {
        No* atual = l->inicio;
        while (atual->prox != NULL) {
            atual = atual->prox;
        }
        atual->prox = novo;
    }
    
    printf("\nMonstro '%s' (Nível %d) adicionado ao bestiário!\n", nome, id);
}

// ============================================================
// FUNÇÃO ORDENAR_BESTIARIO - IMPLEMENTE AQUI
// ============================================================
void ordenar_bestiario(Lista* l) {
    if (l->inicio == NULL || l->inicio->prox == NULL) {
        printf("\nBestiário vazio ou com apenas um monstro. Não há necessidade de ordenar.\n");
        return;
    }
    
    printf("\n--- ORDENANDO BESTIÁRIO ---\n");
    printf("Ordenando por Nível de Ameaça (crescente)...\n");
    
    int trocou;
    No* pfim = NULL;
    
    do {
        trocou = 0;
        No* atual = l->inicio;
        
        while (atual->prox != pfim) {
            // Compara o ID do nó atual com o próximo
            if (atual->dado.id > atual->prox->dado.id) {
                // Troca os dados dos nós (não os ponteiros)
                Monstro temp = atual->dado;
                atual->dado = atual->prox->dado;
                atual->prox->dado = temp;
                trocou = 1;
            }
            atual = atual->prox;
        }
        pfim = atual;
        
    } while (trocou);
    
    printf("Bestiário ordenado com sucesso!\n");
}
// ============================================================

void mostrar_bestiario(Lista* l) {
    if (l->inicio == NULL) {
        printf("\n--- BESTIÁRIO ---\n");
        printf("O bestiário está vazio! Nenhum monstro registrado.\n");
        return;
    }
    
    printf("\n--- BESTIÁRIO ---\n");
    printf("Monstros registrados (ordenados por Nível de Ameaça):\n");
    printf("============================================\n");
    
    No* atual = l->inicio;
    int posicao = 1;
    
    while (atual != NULL) {
        printf("Monstro %d:\n", posicao);
        printf("  Nível de Ameaça: %d\n", atual->dado.id);
        printf("  Nome           : %s\n", atual->dado.nome);
        printf("--------------------------------------------\n");
        atual = atual->prox;
        posicao++;
    }
}

int contar_monstros(Lista* l) {
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
    printf("Memória do bestiário liberada com sucesso!\n");
}

// ==================== Funções Auxiliares ====================

void limpar_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

void exibir_menu() {
    printf("\n========================================\n");
    printf("   BESTIÁRIO DO RPG\n");
    printf("========================================\n");
    printf("  1 - Adicionar Monstro\n");
    printf("  2 - Ordenar Bestiário (por Nível de Ameaça)\n");
    printf("  3 - Mostrar Bestiário\n");
    printf("  4 - Sair\n");
    printf("========================================\n");
    printf("Escolha uma opção: ");
}

void exibir_nivel_ameaca(int nivel) {
    if (nivel <= 3) {
        printf("  (Nível Baixo - Inofensivo)\n");
    } else if (nivel <= 6) {
        printf("  (Nível Médio - Cuidado)\n");
    } else if (nivel <= 9) {
        printf("  (Nível Alto - Perigoso)\n");
    } else {
        printf("  (Nível Extremo - Lendário!)\n");
    }
}

// ==================== main ====================

int main() {
    Lista bestiario;
    inicializar_lista(&bestiario);
    
    int opcao;
    
    printf("========================================\n");
    printf("   BEM-VINDO AO BESTIÁRIO DO RPG\n");
    printf("========================================\n");
    printf("Registre os monstros que você derrotou!\n");
    printf("Organize-os pelo Nível de Ameaça.\n");
    
    do {
        exibir_menu();
        scanf("%d", &opcao);
        limpar_buffer();
        
        switch (opcao) {
            case 1: {
                int id;
                char nome[50];
                
                printf("\n--- ADICIONAR MONSTRO ---\n");
                printf("Digite o Nível de Ameaça do monstro (1-10): ");
                scanf("%d", &id);
                limpar_buffer();
                
                if (id < 1 || id > 10) {
                    printf("Nível de ameaça inválido! Use valores entre 1 e 10.\n");
                    break;
                }
                
                printf("Digite o nome do monstro: ");
                fgets(nome, 50, stdin);
                size_t len = strlen(nome);
                if (len > 0 && nome[len - 1] == '\n') {
                    nome[len - 1] = '\0';
                }
                
                adicionar_monstro(&bestiario, id, nome);
                break;
            }
            case 2: {
                ordenar_bestiario(&bestiario);
                break;
            }
            case 3: {
                mostrar_bestiario(&bestiario);
                break;
            }
            case 4: {
                printf("\nSaindo do bestiário...\n");
                break;
            }
            default: {
                printf("\nOpção inválida! Tente novamente.\n");
            }
        }
    } while (opcao != 4);
    
    liberar_lista(&bestiario);
    printf("Programa finalizado. Que a caçada continue!\n");
    
    return 0;
}
