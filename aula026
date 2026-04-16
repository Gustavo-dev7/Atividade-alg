#include <stdio.h>
#include <stdlib.h>

int main() {
    int *mochila;
    
    mochila = (int*) malloc(3 * sizeof(int));
    
    if (mochila == NULL) {
        printf("Erro ao alocar memoria para a mochila!\n");
        return 1;
    }
    
    printf("Digite os 3 primeiros itens encontrados:\n");
    for (int i = 0; i < 3; i++) {
        printf("Item %d: ", i + 1);
        scanf("%d", &mochila[i]);
    }
    
    printf("\nItens atualmente na mochila: ");
    for (int i = 0; i < 3; i++) {
        printf("%d ", mochila[i]);
    }
    printf("\n");
    
    mochila = (int*) realloc(mochila, 6 * sizeof(int));
    
    // Verifica se a realocação foi bem-sucedida
    if (mochila == NULL) {
        printf("Erro ao expandir a mochila!\n");
        return 1;
    }
    
    printf("\nMochila expandida! Agora cabe 6 itens.\n");
    
    printf("\nDigite os 3 novos itens encontrados:\n");
    for (int i = 3; i < 6; i++) {
        printf("Item %d: ", i + 1);
        scanf("%d", &mochila[i]);
    }
    
    printf("\nMochila completa com %d itens: ", 6);
    for (int i = 0; i < 6; i++) {
        printf("%d ", mochila[i]);
    }
    printf("\n");
    
    // 7. Limpar Memória
    free(mochila);
    
    return 0;
}
