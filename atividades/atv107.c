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

int vazia(Pilha* p) {
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
}

void push_feitico(Pilha* p, Feitico f) {
    No* novo = (No*)malloc(sizeof(No));
    if (novo == NULL) {
        printf("Erro ao alocar memória!\n");
        return;
    }
    
    novo->dado = f;
    novo->prox = p->topo;
    p->topo = novo;
}

void mostrar_pilha(Pilha* p) {
    if (vazia(p)) {
        printf("\n--- PILHA DE COMANDOS ---\n");
        printf("A pilha de comandos está vazia.\n");
        return;
    }
    
    printf("\n--- PILHA DE COMANDOS ---\n");
    printf("Ordem de execução (do topo para a base - LIFO):\n");
    printf("============================================\n");
    
    No* atual = p->topo;
    int posicao = 1;
    
    while (atual != NULL) {
        printf("%dº Feitiço (TOPO):\n", posicao);
        printf("  Nome      : %s\n", atual->dado.nome);
        printf("  Custo Mana: %d\n", atual->dado.custo_mana);
        if (posicao == 1) {
            printf("  (PRÓXIMO A SER EXECUTADO)\n");
        }
        printf("--------------------------------------------\n");
        atual = atual->prox;
        posicao++;
    }
}

Feitico top(Pilha* p) {
    Feitico vazio = {"", -1};
    
    if (vazia(p)) {
        printf("\nERRO: A pilha de comandos está vazia!\n");
        printf("Não há feitiço para consultar.\n");
        return vazio;
    }
    
    return p->topo->dado;
}

Feitico pop(Pilha* p) {
    Feitico vazio = {"", -1};
    
    if (vazia(p)) {
        printf("\nERRO: A pilha de comandos está vazia!\n");
        printf("Não há feitiços para lançar.\n");
        return vazio;
    }
    
    No* removido = p->topo;
    Feitico feitico_lancado = removido->dado;
    
    p->topo = removido->prox;
    free(removido);
    
    return feitico_lancado;
}

void inverter_pilha(Pilha* p) {
    if (vazia(p)) {
        return;
    }
    
    Pilha auxiliar;
    inicializar_pilha(&auxiliar);
    
    while (!vazia(p)) {
        Feitico f = pop(p);
        push_feitico(&auxiliar, f);
    }
    
    p->topo = auxiliar.topo;
}

void salvar_pilha_em_arquivo(Pilha* p, const char* nome_arquivo) {
    if (vazia(p)) {
        printf("\nA pilha de comandos está vazia!\n");
        printf("Não há feitiços para salvar no grimório.\n");
        return;
    }
    
    FILE* arquivo = fopen(nome_arquivo, "wb");
    if (arquivo == NULL) {
        printf("\nERRO: Não foi possível abrir o arquivo '%s' para salvar!\n", nome_arquivo);
        return;
    }
    
    printf("\n--- SALVANDO SEQUÊNCIA NO GRIMÓRIO ---\n");
    printf("Arquivo: %s\n", nome_arquivo);
    
    int contador = 0;
    No* atual = p->topo;
    
    while (atual != NULL) {
        size_t escritos = fwrite(&atual->dado, sizeof(Feitico), 1, arquivo);
        if (escritos != 1) {
            printf("Erro ao salvar o feitiço '%s'!\n", atual->dado.nome);
        } else {
            contador++;
        }
        atual = atual->prox;
    }
    
    fclose(arquivo);
    
    printf("%d feitiços salvos com sucesso no grimório!\n", contador);
    printf("Sua sabedoria está arquivada para o futuro.\n");
}

// ============================================================
// FUNÇÃO CARREGAR_PILHA_DE_ARQUIVO - IMPLEMENTE AQUI
// ============================================================
void carregar_pilha_de_arquivo(Pilha* p, const char* nome_arquivo) {
    // Abre o arquivo em modo de leitura binária
    FILE* arquivo = fopen(nome_arquivo, "rb");
    if (arquivo == NULL) {
        printf("\nNenhum grimório encontrado, iniciando com uma pilha vazia.\n");
        return;
    }
    
    printf("\n--- CARREGANDO SABEDORIA DO GRIMÓRIO ---\n");
    printf("Arquivo: %s\n", nome_arquivo);
    
    Feitico temp;
    int contador = 0;
    
    // Lê cada feitiço do arquivo
    while (fread(&temp, sizeof(Feitico), 1, arquivo) == 1) {
        push_feitico(p, temp);
        contador++;
        printf("Feitiço carregado: %s (Custo: %d mana)\n", temp.nome, temp.custo_mana);
    }
    
    // Fecha o arquivo
    fclose(arquivo);
    
    printf("%d feitiços carregados do grimório.\n", contador);
    
    // CRUCIAL: Inverte a pilha para restaurar a ordem original
    if (contador > 0) {
        printf("Restaurando ordem original dos feitiços...\n");
        inverter_pilha(p);
        printf("Ordem restaurada com sucesso!\n");
    }
}
// ============================================================

void liberar_pilha(Pilha* p) {
    int contador = 0;
    
    while (!vazia(p)) {
        No* removido = p->topo;
        p->topo = removido->prox;
        free(removido);
        contador++;
    }
    
    printf("\n%d feitiços removidos da pilha.\n", contador);
    printf("Memória da pilha liberada com sucesso!\n");
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
    printf("  2 - Lançar próximo feitiço (pop)\n");
    printf("  3 - Mostrar pilha de comandos\n");
    printf("  4 - Consultar próximo feitiço (top)\n");
    printf("  5 - Inverter ordem dos feitiços\n");
    printf("  6 - Salvar sequência no grimório\n");
    printf("  7 - Verificar status da pilha\n");
    printf("  8 - Finalizar sequência e sair\n");
    printf("========================================\n");
    printf("Escolha uma opção: ");
}

void exibir_detalhes_feitico(Feitico f) {
    printf("\n--- PRÓXIMO FEITIÇO (CONSULTA) ---\n");
    printf("  Nome      : %s\n", f.nome);
    printf("  Custo Mana: %d\n", f.custo_mana);
    printf("  (O feitiço permanece na pilha)\n");
    printf("====================================\n");
}

// ==================== main ====================

int main() {
    Pilha comandos;
    inicializar_pilha(&comandos);
    
    // ============================================================
    // CARREGA A PILHA DO ARQUIVO AO INICIAR O PROGRAMA
    // ============================================================
    carregar_pilha_de_arquivo(&comandos, "grimorio.bin");
    
    int opcao;
    
    printf("\n========================================\n");
    printf("   BEM-VINDO AO SISTEMA DE COMANDOS\n");
    printf("========================================\n");
    printf("Gerencie a pilha de feitiços do Arcanista!\n");
    printf("O último feitiço adicionado será o primeiro\n");
    printf("a ser executado (LIFO - Last In, First Out).\n");
    printf("\nUse o 'Encantamento de Reversão Temporal'\n");
    printf("para inverter a ordem dos feitiços!\n");
    printf("Não se esqueça de salvar sua sabedoria\n");
    printf("no grimório antes de sair!\n");
    
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
                
                printf("\nTotal de feitiços na pilha: %d\n", contar_feiticos(&comandos));
                break;
            }
            case 2: {
                printf("\n--- LANÇANDO PRÓXIMO FEITIÇO ---\n");
                Feitico lancado = pop(&comandos);
                
                if (lancado.custo_mana != -1) {
                    printf("Feitiço '%s' (Custo: %d mana) lançado com sucesso!\n", 
                           lancado.nome, lancado.custo_mana);
                    printf("Restam %d feitiço(s) na pilha.\n", contar_feiticos(&comandos));
                }
                break;
            }
            case 3: {
                mostrar_pilha(&comandos);
                break;
            }
            case 4: {
                printf("\n--- CONSULTANDO PRÓXIMO FEITIÇO ---\n");
                Feitico consultado = top(&comandos);
                
                if (consultado.custo_mana != -1) {
                    exibir_detalhes_feitico(consultado);
                    printf("Total de feitiços na pilha: %d (inalterado)\n", contar_feiticos(&comandos));
                }
                break;
            }
            case 5: {
                inverter_pilha(&comandos);
                printf("\nOrdem dos feitiços invertida com sucesso!\n");
                break;
            }
            case 6: {
                salvar_pilha_em_arquivo(&comandos, "grimorio.bin");
                break;
            }
            case 7: {
                printf("\n--- STATUS DA PILHA ---\n");
                if (vazia(&comandos)) {
                    printf("A pilha de comandos está vazia.\n");
                    printf("Nenhum feitiço aguardando execução.\n");
                } else {
                    printf("A pilha de comandos possui feitiços pendentes.\n");
                    printf("Total de feitiços na pilha: %d\n", contar_feiticos(&comandos));
                }
                break;
            }
            case 8: {
                printf("\nFinalizando sequência de comandos...\n");
                if (!vazia(&comandos)) {
                    printf("A pilha contém %d feitiço(s) aguardando execução.\n", contar_feiticos(&comandos));
                }
                break;
            }
            default: {
                printf("\nOpção inválida! Tente novamente.\n");
            }
        }
    } while (opcao != 8);
    
    // Exibe a pilha final antes de liberar
    mostrar_pilha(&comandos);
    
    // Libera toda a memória
    liberar_pilha(&comandos);
    
    printf("\nPrograma finalizado. Até a próxima aventura!\n");
    printf("Sua sabedoria está salva no grimório!\n");
    
    return 0;
}
