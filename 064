#include <stdio.h>

void insertion_sort(int arr[], int n) {
    int i, j, chave;
    
    for (i = 1; i < n; i++) {
        chave = arr[i];
        j = i - 1;
        
        while (j >= 0 && arr[j] > chave) {
            arr[j + 1] = arr[j];
            j--;
        }
        
        arr[j + 1] = chave;
    }
}

int main() {
    int n, i;
    
    // Ler a quantidade de fragmentos
    scanf("%d", &n);
    
    // Criar vetor de poderes
    int fragmentos[n];
    
    // Ler os niveis de poder de cada fragmento
    for (i = 0; i < n; i++) {
        scanf("%d", &fragmentos[i]);
    }
    
    // Ordenar usando Insertion Sort
    insertion_sort(fragmentos, n);
    
    // Exibir os fragmentos ordenados
    for (i = 0; i < n; i++) {
        printf("%d", fragmentos[i]);
        if (i < n - 1) {
            printf(" ");
        }
    }
    printf("\n");
    
    return 0;
}
