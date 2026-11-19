#include <stdio.h>
#include <string.h>

#define MAX_NOME 50

typedef struct {
    char nome[MAX_NOME];
    int pontuacao;
} Jogador;

void insertion_sort_desc(Jogador jogadores[], int n) {
    int i, j;
    Jogador chave;
    
    for (i = 1; i < n; i++) {
        chave = jogadores[i];
        j = i - 1;
        
        while (j >= 0 && jogadores[j].pontuacao < chave.pontuacao) {
            jogadores[j + 1] = jogadores[j];
            j--;
        }
        
        jogadores[j + 1] = chave;
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
        scanf("%s %d", jogadores[i].nome, &jogadores[i].pontuacao);
    }
    
    // Ordenar usando Insertion Sort em ordem decrescente de pontuacao
    insertion_sort_desc(jogadores, N);
    
    // Imprimir o ranking final
    for (i = 0; i < N; i++) {
        printf("%d %s\n", jogadores[i].pontuacao, jogadores[i].nome);
    }
    
    return 0;
}
