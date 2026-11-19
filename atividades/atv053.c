#include <stdio.h>

int main() {
    int n;
    
    // Ler o nivel de energia inicial do Golem
    scanf("%d", &n);
    
    // Executar o ritual enquanto a energia for maior que 1
    while (n > 1) {
        printf("%d\n", n);
        n = n / 2;  // Reduzir pela metade (divisao inteira)
    }
    
    return 0;
}
