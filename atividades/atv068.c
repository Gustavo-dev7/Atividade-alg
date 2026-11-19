#include <stdio.h>

typedef struct {
    int id;
    int pontuacao;
} Jogador;

void bubble_sort_desc(Jogador jogadores[], int n) {
    int i, j;
    Jogador temp;
    
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (jogadores[j].pontuacao < jogadores[j + 1].pontuacao) {
                temp = jogadores[j];
                jogadores[j] = jogadores[j + 1];
                jogadores[j + 1] = temp;
            }
        }
    }
}

int main() {
    int N, i;
    
    // Ler a quantidade de jogadores
    scanf("%d", &N);
    
    // Criar vetor de jogadores
    Jogador jogadores[N];
    
    // Ler os dados de cada jogador
    for (i = 0; i < N; i++) {
        scanf("%d %d", &jogadores[i].id, &jogadores[i].pontuacao);
    }
    
    // Ordenar usando Bubble Sort em ordem decrescente de pontuacao
    bubble_sort_desc(jogadores, N);
    
    // Imprimir a lista ordenada
    for (i = 0; i < N; i++) {
        printf("%d %d\n", jogadores[i].id, jogadores[i].pontuacao);
    }
    
    return 0;
}
