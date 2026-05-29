#include <stdio.h>

void particao(int n, int v[]) {
    int pivo = v[n - 1];
    int i = -1;
    int temp;
    
    for (int j = 0; j < n - 1; j++) {
        if (v[j] < pivo) {
            i++;
            temp = v[i];
            v[i] = v[j];
            v[j] = temp;
        }
    }
    
    // Colocar o pivo na posicao correta
    temp = v[i + 1];
    v[i + 1] = v[n - 1];
    v[n - 1] = temp;
}

int main() {
    int n;
    
    // Ler o numero de unidades mecha
    scanf("%d", &n);
    
    // Criar vetor de pontos de vida
    int v[n];
    
    // Ler os pontos de vida de cada unidade
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }
    
    // Realizar a particao in-place
    particao(n, v);
    
    // Imprimir o vetor reorganizado
    for (int i = 0; i < n; i++) {
        printf("%d", v[i]);
        if (i < n - 1) {
            printf(" ");
        }
    }
    printf("\n");
    
    return 0;
}
