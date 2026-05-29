#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Funcao para trocar dois elementos
void trocar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Funcao de particao com pivo aleatorio
int particao(int arr[], int baixo, int alto) {
    // Selecionar um indice aleatorio entre baixo e alto
    int indice_pivo = baixo + rand() % (alto - baixo + 1);
    
    // Mover o pivo aleatorio para o final (para usar a logica de Lomuto)
    trocar(&arr[indice_pivo], &arr[alto]);
    
    int pivo = arr[alto];
    int i = baixo - 1;
    
    for (int j = baixo; j < alto; j++) {
        if (arr[j] <= pivo) {
            i++;
            trocar(&arr[i], &arr[j]);
        }
    }
    
    // Colocar o pivo na posicao correta
    trocar(&arr[i + 1], &arr[alto]);
    
    return i + 1;
}

// Funcao recursiva do Quick Sort com pivo aleatorio
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
    
    // Inicializar o gerador de numeros aleatorios
    srand(time(NULL));
    
    // Ler a quantidade de jogadores
    scanf("%d", &N);
    
    // Criar vetor de pontuacoes
    int pontuacoes[N];
    
    // Ler as pontuacoes de cada jogador
    for (int i = 0; i < N; i++) {
        scanf("%d", &pontuacoes[i]);
    }
    
    // Ordenar usando Quick Sort com pivo aleatorio
    quick_sort(pontuacoes, 0, N - 1);
    
    // Imprimir as pontuacoes ordenadas
    for (int i = 0; i < N; i++) {
        printf("%d", pontuacoes[i]);
        if (i < N - 1) {
            printf(" ");
        }
    }
    printf("\n");
    
    return 0;
}
