#include <stdio.h>

// Funcao de particao de Lomuto (pivo como ultimo elemento)
int particao(int arr[], int baixo, int alto) {
    int pivo = arr[alto];
    int i = baixo - 1;
    int temp;
    
    for (int j = baixo; j < alto; j++) {
        if (arr[j] <= pivo) {
            i++;
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    
    // Colocar o pivo na posicao correta
    temp = arr[i + 1];
    arr[i + 1] = arr[alto];
    arr[alto] = temp;
    
    return i + 1;
}

// Funcao recursiva do Quick Sort
void quick_sort(int arr[], int baixo, int alto) {
    if (baixo < alto) {
        int pi = particao(arr, baixo, alto);
        
        // Ordenar as duas metades
        quick_sort(arr, baixo, pi - 1);
        quick_sort(arr, pi + 1, alto);
    }
}

int main() {
    int N;
    
    // Ler a quantidade de jogadores
    scanf("%d", &N);
    
    // Criar vetor de MMRs
    int mmrs[N];
    
    // Ler os MMRs de cada jogador
    for (int i = 0; i < N; i++) {
        scanf("%d", &mmrs[i]);
    }
    
    // Ordenar usando Quick Sort
    quick_sort(mmrs, 0, N - 1);
    
    // Imprimir os MMRs ordenados
    for (int i = 0; i < N; i++) {
        printf("%d", mmrs[i]);
        if (i < N - 1) {
            printf(" ");
        }
    }
    printf("\n");
    
    return 0;
}
