#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// --- Definição das Estruturas ---
typedef struct {
    int id;
    char nome[50];
} Heroi;

typedef struct no {
    Heroi heroi;
    struct no *prox;
} No;

typedef struct {
    No *inicio;
} Lista;

// --- Protótipos das Funções ---
void inicializar_lista(Lista *lista);
void adicionar_heroi(Lista *lista, Heroi h);
void dispensar_heroi(Lista *lista, int id);
void mostrar_guilda(Lista *lista);
void menu();

// --- Função Principal ---
int main() {
    Lista guilda;
    inicializar_lista(&guilda);
    int opcao, id_heroi;
    Heroi novo_heroi;

    do {
        menu();
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                printf("\nDigite o ID do novo heroi: ");
                scanf("%d", &novo_heroi.id);
                printf("Digite o nome do novo heroi: ");
                scanf("%49s", novo_heroi.nome);
                adicionar_heroi(&guilda, novo_heroi);
                break;
            case 2:
                mostrar_guilda(&guilda);
                break;
            case 3:
                printf("\nDigite o ID do heroi a ser dispensado: ");
                scanf("%d", &id_heroi);
                dispensar_heroi(&guilda, id_heroi);
                printf("\n--- Roster da Guilda Atualizado ---\n");
                mostrar_guilda(&guilda);
                break;
            case 4:
                printf("\nSaindo do gerenciador da guilda...\n");
                break;
            default:
                printf("\nOpcao invalida!\n");
        }
    } while(opcao != 4);

    // Liberar memória restante (boa prática)
    while(guilda.inicio != NULL) {
        No *temp = guilda.inicio;
        guilda.inicio = guilda.inicio->prox;
        free(temp);
    }

    return 0;
}

// --- Implementação das Funções Auxiliares ---
void inicializar_lista(Lista *lista) {
    lista->inicio = NULL;
}

// Insere um novo herói no final da lista.
void adicionar_heroi(Lista *lista, Heroi h) {
    No *novo = (No*) malloc(sizeof(No));
    if (novo) {
        novo->heroi = h;
        novo->prox = NULL;

        if (lista->inicio == NULL) {
            lista->inicio = novo;
        } else {
            No *aux = lista->inicio;
            while (aux->prox != NULL) {
                aux = aux->prox;
            }
            aux->prox = novo;
        }
    } else {
        printf("Erro de alocacao de memoria!\n");
    }
}

void mostrar_guilda(Lista *lista) {
    printf("\n--- Roster da Guilda ---\n");
    if (lista->inicio == NULL) {
        printf("A guilda esta vazia.\n");
    } else {
        No *aux = lista->inicio;
        while (aux != NULL) {
            printf("ID: %d, Nome: %s\n", aux->heroi.id, aux->heroi.nome);
            aux = aux->prox;
        }
    }
    printf("------------------------\n");
}

void menu() {
    printf("\nGerenciador de Guilda:\n");
    printf("1. Adicionar Heroi\n");
    printf("2. Mostrar Guilda\n");
    printf("3. Dispensar Heroi por ID\n");
    printf("4. Sair\n");
    printf("Escolha uma opcao: ");
}

// Função para deletar um nó baseado no ID do herói.
void dispensar_heroi(Lista *lista, int id) {
    // Caso 1: Lista vazia
    if (lista->inicio == NULL) {
        printf("\nERRO: A guilda esta vazia! Nenhum heroi para dispensar.\n");
        return;
    }
    
    // Caso 2: Remover o primeiro herói da lista
    if (lista->inicio->heroi.id == id) {
        No *remover = lista->inicio;
        lista->inicio = lista->inicio->prox;
        printf("\nHeroi '%s' (ID %d) dispensado com sucesso!\n", remover->heroi.nome, id);
        free(remover);
        return;
    }
    
    // Caso 3: Remover herói do meio ou do final da lista
    No *anterior = lista->inicio;
    No *atual = lista->inicio->prox;
    
    while (atual != NULL) {
        if (atual->heroi.id == id) {
            // Encontrou o herói a ser removido
            anterior->prox = atual->prox;
            printf("\nHeroi '%s' (ID %d) dispensado com sucesso!\n", atual->heroi.nome, id);
            free(atual);
            return;
        }
        anterior = atual;
        atual = atual->prox;
    }
    
    // Caso 4: Herói com ID não encontrado
    printf("\nERRO: Heroi com ID %d nao encontrado na guilda!\n", id);
    printf("Verifique o ID e tente novamente.\n");
}
