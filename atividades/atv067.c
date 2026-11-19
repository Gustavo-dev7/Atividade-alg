#include <stdio.h>

void bubble_sort_optimized_desc(int arr[], int n) {
    int i, j, temp;
    int trocou;
    
    for (i = 0; i < n - 1; i++) {
        trocou = 0;
        
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] < arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                trocou = 1;
            }
        }
        
        // Se nenhuma troca foi realizada, o vetor ja esta ordenado
        if (trocou == 0) {
            break;
        }
    }
}

int main() {
    int n, i;
    
    // Ler a quantidade de jogadores
    scanf("%d", &n);
    
    // Criar vetor de pontuacoes
    int pontuacoes[n];
    
    // Ler as n pontuacoes
    for (i = 0; i < n; i++) {
        scanf("%d", &pontuacoes[i]);
    }
    
    // Ordenar usando Bubble Sort otimizado em ordem decrescente
    bubble_sort_optimized_desc(pontuacoes, n);
    
    // Imprimir as pontuacoes ordenadas
    for (i = 0; i < n; i++) {
        printf("%d", pontuacoes[i]);
        if (i < n - 1) {
            printf(" ");
        }
    }
    printf("\n");
    
    return 0;
}
