#include <stdio.h>

void bubble_sort_desc(int arr[], int n) {
    int i, j, temp;
    
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] < arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int N, i;
    
    // Ler a quantidade de jogadores
    scanf("%d", &N);
    
    // Criar vetor de pontuacoes
    int pontuacoes[N];
    
    // Ler as N pontuacoes
    for (i = 0; i < N; i++) {
        scanf("%d", &pontuacoes[i]);
    }
    
    // Ordenar usando Bubble Sort em ordem decrescente
    bubble_sort_desc(pontuacoes, N);
    
    // Imprimir as pontuacoes ordenadas
    for (i = 0; i < N; i++) {
        printf("%d", pontuacoes[i]);
        if (i < N - 1) {
            printf(" ");
        }
    }
    printf("\n");
    
    return 0;
}
