#include <stdio.h>

void selection_sort(int arr[], int n) {
    int i, j, min_idx, temp;
    
    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        
        if (min_idx != i) {
            temp = arr[i];
            arr[i] = arr[min_idx];
            arr[min_idx] = temp;
        }
    }
}

int main() {
    int N, i;
    
    // Ler a quantidade de jogadores
    scanf("%d", &N);
    
    // Criar vetor de pontuacoes
    int scores[N];
    
    // Ler as N pontuacoes
    for (i = 0; i < N; i++) {
        scanf("%d", &scores[i]);
    }
    
    // Ordenar o vetor usando Selection Sort
    selection_sort(scores, N);
    
    // Exibir as pontuacoes ordenadas
    for (i = 0; i < N; i++) {
        printf("%d", scores[i]);
        if (i < N - 1) {
            printf(" ");
        }
    }
    printf("\n");
    
    return 0;
}
