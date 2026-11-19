#include <stdio.h>
#include <stdlib.h>

int main() {
    int n_inimigos;
    
    int *ponteiro_onda;
    
    printf("Digite a quantidade de inimigos da onda: ");
    scanf("%d", &n_inimigos);
    
    ponteiro_onda = (int*) malloc(n_inimigos * sizeof(int));
    
    if (ponteiro_onda == NULL) {
        printf("Erro ao alocar memoria para a onda de inimigos!\n");
        return 1;
    }
    
    printf("Digite os IDs dos %d inimigos:\n", n_inimigos);
    for (int i = 0; i < n_inimigos; i++) {
        printf("Inimigo %d: ", i + 1);
        scanf("%d", &ponteiro_onda[i]);  // ou ponteiro_onda + i
    }
    
    printf("Onda de inimigos criada com sucesso! IDs: ");
    for (int i = 0; i < n_inimigos; i++) {
        printf("%d ", ponteiro_onda[i]);
    }
    printf("\n");
    
    free(ponteiro_onda);
    
    return 0;
}
