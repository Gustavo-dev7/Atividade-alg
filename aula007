#include <stdio.h>

void ler_cenario(int n, int *cenario) {
    printf("Digite os %d blocos (0=vazio, 1=plataforma):\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", cenario + i);
    }
}

int main() {
    int n;
    
    printf("Digite o numero de blocos no cenario: ");
    scanf("%d", &n);
    
    int cenario[n];
    
    ler_cenario(n, cenario);
    
    for (int i = 0; i < n; i++) {
        if (cenario[i] == 1) {
            cenario[i] = 2;
            break; // Interrompe após encontrar o primeiro
        }
    }
    
    printf("Cenario modificado: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", cenario[i]);
    }
    printf("\n");
    
    return 0;
}
