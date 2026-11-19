#include <stdio.h>

int main() {
    int n, m, i, j, k;
    
    // Ler os inimigos do Portal Alfa
    scanf("%d", &n);
    int alfa[n];
    for (i = 0; i < n; i++) {
        scanf("%d", &alfa[i]);
    }
    
    // Ler os inimigos do Portal Beta
    scanf("%d", &m);
    int beta[m];
    for (i = 0; i < m; i++) {
        scanf("%d", &beta[i]);
    }
    
    // Criar vetor para a lista intercalada
    int total = n + m;
    int merge[total];
    
    // Intercalar os dois vetores ordenados
    i = 0;  // indice para alfa
    j = 0;  // indice para beta
    k = 0;  // indice para merge
    
    while (i < n && j < m) {
        if (alfa[i] <= beta[j]) {
            merge[k] = alfa[i];
            i++;
        } else {
            merge[k] = beta[j];
            j++;
        }
        k++;
    }
    
    // Copiar os elementos restantes do vetor alfa (se houver)
    while (i < n) {
        merge[k] = alfa[i];
        i++;
        k++;
    }
    
    // Copiar os elementos restantes do vetor beta (se houver)
    while (j < m) {
        merge[k] = beta[j];
        j++;
        k++;
    }
    
    // Imprimir a lista intercalada
    for (i = 0; i < total; i++) {
        printf("%d", merge[i]);
        if (i < total - 1) {
            printf(" ");
        }
    }
    printf("\n");
    
    return 0;
}
