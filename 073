#include <stdio.h>

void particao(int n, int v[]) {
    int s[n];
    int pivo = v[n - 1];
    int esquerda = 0;
    int direita = n - 1;
    
    // Preencher o vetor secundario
    for (int i = 0; i < n; i++) {
        if (v[i] <= pivo) {
            s[esquerda] = v[i];
            esquerda++;
        } else {
            s[direita] = v[i];
            direita--;
        }
    }
    
    // Copiar de volta para o vetor original
    for (int i = 0; i < n; i++) {
        v[i] = s[i];
    }
}

int main() {
    int N;
    
    // Ler a quantidade de itens
    scanf("%d", &N);
    
    // Criar vetor de niveis de poder
    int v[N];
    
    // Ler os niveis de poder de cada item
    for (int i = 0; i < N; i++) {
        scanf("%d", &v[i]);
    }
    
    // Realizar a particao
    particao(N, v);
    
    // Imprimir o vetor reorganizado
    for (int i = 0; i < N; i++) {
        printf("%d", v[i]);
        if (i < N - 1) {
            printf(" ");
        }
    }
    printf("\n");
    
    return 0;
}
