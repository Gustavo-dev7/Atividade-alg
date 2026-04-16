#include <stdio.h>
#include <stdlib.h>

#define LINHAS 5
#define COLUNAS 10

int main() {
    int *level_map;
    
    level_map = (int*) malloc(LINHAS * COLUNAS * sizeof(int));
    
    if (level_map == NULL) {
        printf("Erro ao alocar memoria para o mapa do nivel!\n");
        return 1;
    }
    
    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS; j++) {
            if (i == LINHAS - 1) {
                // Última linha: chão (valor 1)
                *(level_map + i * COLUNAS + j) = 1;
            } else {
                // Outras linhas: ar (valor 0)
                *(level_map + i * COLUNAS + j) = 0;
            }
        }
    }
    
    printf("Mapa do nivel (%d linhas x %d colunas):\n\n", LINHAS, COLUNAS);
    
    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS; j++) {
            printf("%d ", *(level_map + i * COLUNAS + j));
        }
        printf("\n");
    }
    
    // 5. Liberação de Memória
    free(level_map);
    
    return 0;
}
