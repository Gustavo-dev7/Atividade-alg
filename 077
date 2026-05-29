#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    int pontuacao;
} Jogador;

// Funcao para trocar dois jogadores
void trocar(Jogador *a, Jogador *b) {
    Jogador temp = *a;
    *a = *b;
    *b = temp;
}

// Funcao de particao de Lomuto (pivo como ultimo elemento) para ordem decrescente
int particao(Jogador jogadores[], int baixo, int alto) {
    int pivo = jogadores[alto].pontuacao;
    int i = baixo - 1;
    
    for (int j = baixo; j < alto; j++) {
        if (jogadores[j].pontuacao >= pivo) {  // Maior ou igual para ordem decrescente
            i++;
            trocar(&jogadores[i], &jogadores[j]);
        }
    }
    
    // Colocar o pivo na posicao correta
    trocar(&jogadores[i + 1], &jogadores[alto]);
    
    return i + 1;
}

// Funcao recursiva do Quick Sort
void quick_sort(Jogador jogadores[], int baixo, int alto) {
    if (baixo < alto) {
        int pi = particao(jogadores, baixo, alto);
        
        // Ordenar as duas metades
        quick_sort(jogadores, baixo, pi - 1);
        quick_sort(jogadores, pi + 1, alto);
    }
}

int main() {
    int n;
    
    // Ler a quantidade de jogadores
    scanf("%d", &n);
    
    // Criar vetor de jogadores
    Jogador jogadores[n];
    
    // Ler os dados de cada jogador
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &jogadores[i].id, &jogadores[i].pontuacao);
    }
    
    // Ordenar usando Quick Sort em ordem decrescente de pontuacao
    quick_sort(jogadores, 0, n - 1);
    
    // Imprimir a lista ordenada
    for (int i = 0; i < n; i++) {
        printf("%d %d\n", jogadores[i].id, jogadores[i].pontuacao);
    }
    
    return 0;
}
