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

int estaVazia(Fila* f) {
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
    
    if (estaVazia(f)) {
        f->inicio = novo;
        f->fim = novo;
    } else {
        f->fim->prox = novo;
        f->fim = novo;
    }
}

void mostrar(Fila* f) {
    if (estaVazia(f)) {
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

Jogador remover(Fila* f) {
    Jogador vazio;
    vazio.id = -1;
    strcpy(vazio.nickname, "");
    
    if (estaVazia(f)) {
        printf("\nERRO: A fila de matchmaking está vazia!\n");
        printf("Não há jogadores para remover.\n");
        return vazio;
    }
    
    No* removido = f->inicio;
    Jogador jogador_removido = removido->dado;
    
    f->inicio = f->inicio->prox;
    
    if (f->inicio == NULL) {
        f->fim = NULL;
    }
    
    free(removido);
    
    return jogador_removido;
}

Jogador verInicio(Fila* f) {
    Jogador vazio;
    vazio.id = -1;
    strcpy(vazio.nickname, "");
    
    if (estaVazia(f)) {
        printf("\nA fila de matchmaking está vazia!\n");
        printf("Não há jogador no início da fila.\n");
        return vazio;
    }
    
    return f->inicio->dado;
}

void salvarFila(Fila* f, const char* nomeArquivo) {
    if (estaVazia(f)) {
        printf("\nA fila de matchmaking está vazia!\n");
        printf("Não há jogadores para salvar.\n");
        return;
    }
    
    FILE* arquivo = fopen(nomeArquivo, "wb");
    if (arquivo == NULL) {
        printf("\nERRO: Não foi possível abrir o arquivo '%s' para salvar!\n", nomeArquivo);
        return;
    }
    
    printf("\n--- SALVANDO FILA EM ARQUIVO ---\n");
    printf("Arquivo: %s\n", nomeArquivo);
    
    int contador = 0;
    No* atual = f->inicio;
    
    while (atual != NULL) {
        size_t escritos = fwrite(&atual->dado, sizeof(Jogador), 1, arquivo);
        if (escritos != 1) {
            printf("Erro ao salvar o jogador '%s' (ID %d)!\n", 
                   atual->dado.nickname, atual->dado.id);
        } else {
            contador++;
        }
        atual = atual->prox;
    }
    
    fclose(arquivo);
    
    printf("%d jogador(es) salvos com sucesso em '%s'!\n", contador, nomeArquivo);
    printf("A fila foi persistida com sucesso.\n");
}

// ============================================================
// FUNÇÃO CARREGARFILA - IMPLEMENTE AQUI
// ============================================================
void carregarFila(Fila* f, const char* nomeArquivo) {
    // Tenta abrir o arquivo em modo de leitura binária
    FILE* arquivo = fopen(nomeArquivo, "rb");
    if (arquivo == NULL) {
        printf("\nNenhum arquivo de salvamento encontrado.\n");
        printf("Iniciando com uma fila vazia.\n");
        return;
    }
    
    printf("\n--- CARREGANDO FILA DO ARQUIVO ---\n");
    printf("Arquivo: %s\n", nomeArquivo);
    
    Jogador temp;
    int contador = 0;
    
    // Lê cada jogador do arquivo, um de cada vez
    while (fread(&temp, sizeof(Jogador), 1, arquivo) == 1) {
        // Insere o jogador lido na fila
        inserir(f, temp);
        contador++;
        printf("Jogador carregado: %s (ID %d)\n", temp.nickname, temp.id);
    }
    
    // Fecha o arquivo
    fclose(arquivo);
    
    printf("%d jogador(es) carregados com sucesso!\n", contador);
    if (contador > 0) {
        printf("A fila foi restaurada. O primeiro da fila é: %s\n", f->inicio->dado.nickname);
    }
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

int contar_jogadores(Fila* f) {
    int count = 0;
    No* atual = f->inicio;
    while (atual != NULL) {
        count++;
        atual = atual->prox;
    }
    return count;
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
    printf("  4 - Verificar se a Fila está Vazia\n");
    printf("  5 - Ver quem é o próximo da Fila\n");
    printf("  6 - Salvar Fila em Arquivo\n");
    printf("  7 - Sair\n");
    printf("========================================\n");
    printf("Escolha uma opção: ");
}

// ==================== main ====================

int main() {
    Fila fila;
    inicializar_fila(&fila);
    
    // ============================================================
    // CARREGA A FILA DO ARQUIVO AO INICIAR O PROGRAMA
    // ============================================================
    carregarFila(&fila, "matchmaking_queue.bin");
    
    int opcao;
    
    printf("\n========================================\n");
    printf("   BEM-VINDO AO SISTEMA DE MATCHMAKING\n");
    printf("========================================\n");
    printf("Entre na fila e aguarde sua partida!\n");
    printf("(FIFO - First-In, First-Out)\n");
    printf("O primeiro a entrar é o primeiro a sair!\n");
    printf("\nNÃO ESQUEÇA DE SALVAR A FILA!\n");
    
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
                printf("\nJogador '%s' (ID %d) entrou na fila de matchmaking!\n", j.nickname, j.id);
                break;
            }
            case 2: {
                mostrar(&fila);
                break;
            }
            case 3: {
                printf("\n--- INICIANDO PARTIDA ---\n");
                Jogador removido = remover(&fila);
                
                if (removido.id != -1) {
                    printf("O jogador '%s' (ID: %d) foi removido da fila e entrou em uma partida!\n", 
                           removido.nickname, removido.id);
                    if (!estaVazia(&fila)) {
                        printf("Ainda há jogadores aguardando na fila.\n");
                    } else {
                        printf("A fila de matchmaking agora está vazia.\n");
                    }
                }
                break;
            }
            case 4: {
                printf("\n--- VERIFICANDO SE A FILA ESTÁ VAZIA ---\n");
                if (estaVazia(&fila)) {
                    printf("SIM, a fila está vazia.\n");
                    printf("Nenhum jogador aguardando partida.\n");
                } else {
                    printf("NÃO, a fila contém jogadores.\n");
                    printf("Aguardando na fila: %d jogador(es).\n", contar_jogadores(&fila));
                }
                break;
            }
            case 5: {
                printf("\n--- VERIFICANDO PRÓXIMO JOGADOR ---\n");
                Jogador proximo = verInicio(&fila);
                
                if (proximo.id != -1) {
                    printf("O próximo jogador a entrar na partida é: %s (ID: %d)\n", 
                           proximo.nickname, proximo.id);
                    printf("Ele está na frente da fila aguardando!\n");
                }
                break;
            }
            case 6: {
                salvarFila(&fila, "matchmaking_queue.bin");
                break;
            }
            case 7: {
                printf("\nSaindo do sistema de matchmaking...\n");
                break;
            }
            default: {
                printf("\nOpção inválida! Tente novamente.\n");
            }
        }
    } while (opcao != 7);
    
    liberar_fila(&fila);
    printf("Programa finalizado. Boas partidas!\n");
    
    return 0;
}
