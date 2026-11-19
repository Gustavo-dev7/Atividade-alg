#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOME 50

typedef struct {
    char nome[MAX_NOME];
    int kills;
} Jogador;

void selection_sort_desc(Jogador jogadores[], int n) {
    int i, j, max_idx;
    Jogador temp;
    
    for (i = 0; i < n - 1; i++) {
        max_idx = i;
        
        for (j = i + 1; j < n; j++) {
            if (jogadores[j].kills > jogadores[max_idx].kills) {
                max_idx = j;
            }
        }
        
        if (max_idx != i) {
            temp = jogadores[i];
            jogadores[i] = jogadores[max_idx];
            jogadores[max_idx] = temp;
        }
    }
}

int main() {
    int N, i;
    Jogador *jogadores;
    
    // Ler a quantidade de jogadores
    scanf("%d", &N);
    
    // Alocar dinamicamente o vetor de jogadores
    jogadores = (Jogador*)malloc(N * sizeof(Jogador));
    
    if (jogadores == NULL) {
        printf("Erro ao alocar memoria!\n");
        return 1;
    }
    
    // Ler os dados de cada jogador
    for (i = 0; i < N; i++) {
        scanf("%s %d", jogadores[i].nome, &jogadores[i].kills);
    }
    
    // Ordenar o vetor em ordem decrescente de kills
    selection_sort_desc(jogadores, N);
    
    // Imprimir o leaderboard ordenado
    for (i = 0; i < N; i++) {
        printf("%s %d\n", jogadores[i].nome, jogadores[i].kills);
    }
    
    // Liberar a memoria alocada
    free(jogadores);
    
    return 0;
}
