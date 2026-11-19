#include <stdio.h>

int main() {
    int placar[5] = {120, 125, 130, 142, 150};
    int novo_tempo;
    int i, j;
    
    // Ler o novo tempo do jogador
    scanf("%d", &novo_tempo);
    
    // Verificar se o novo tempo e melhor que algum tempo do placar
    // (mais rapido = menor numero)
    for (i = 0; i < 5; i++) {
        if (novo_tempo < placar[i]) {
            // Deslocar os tempos maiores para a direita
            for (j = 4; j > i; j--) {
                placar[j] = placar[j - 1];
            }
            // Inserir o novo tempo na posicao correta
            placar[i] = novo_tempo;
            break;
        }
    }
    
    // Imprimir o placar atualizado
    for (i = 0; i < 5; i++) {
        printf("%d", placar[i]);
        if (i < 4) {
            printf(" ");
        }
    }
    printf("\n");
    
    return 0;
}
