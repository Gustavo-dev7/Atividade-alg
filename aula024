#include <stdio.h>
#include <stdlib.h>

int main() {
    int linhas, colunas;
    int **mapa;
    int contagem_tijolos = 0;
    
    printf("Digite o numero de linhas do mapa: ");
    scanf("%d", &linhas);
    printf("Digite o numero de colunas do mapa: ");
    scanf("%d", &colunas);
    
    // Aloca o vetor de ponteiros (linhas)
    mapa = (int**) malloc(linhas * sizeof(int*));
    
    // Verifica se a alocação foi bem-sucedida
    if (mapa == NULL) {
        printf("Erro ao alocar memoria para as linhas do mapa!\n");
        return 1;
    }
    
    // Aloca cada linha individualmente
    for (int i = 0; i < linhas; i++) {
        mapa[i] = (int*) malloc(colunas * sizeof(int));
        if (mapa[i] == NULL) {
            printf("Erro ao alocar memoria para a linha %d!\n", i);
            // Libera as linhas já alocadas antes de sair
            for (int k = 0; k < i; k++) {
                free(mapa[k]);
            }
            free(mapa);
            return 1;
        }
    }
    
    printf("\nDigite os valores do mapa (0=vazio, 1=tijolo, 2=moeda):\n");
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("Posicao [%d][%d]: ", i, j);
            scanf("%d", &mapa[i][j]);
        }
    }
    
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            if (mapa[i][j] == 1) {
                contagem_tijolos++;
            }
        }
    }
    
    printf("\nO mapa possui %d blocos de tijolo.\n", contagem_tijolos);
    
    for (int i = 0; i < linhas; i++) {
        free(mapa[i]);  // libera cada linha
    }
    free(mapa);  // libera o vetor de ponteiros
    
    return 0;
}
