#include <stdio.h>

int main() {
    int mapa_fase1[5][8] = {
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {1, 1, 0, 0, 2, 0, 1, 1},
        {0, 0, 1, 1, 0, 1, 0, 0},
        {1, 1, 1, 1, 2, 2, 1, 1}
    };
    
    printf("Buscando espinhos no mapa...\n\n");
    
    for (int i = 0; i < 5; i++) {          // percorre as linhas
        for (int j = 0; j < 8; j++) {      // percorre as colunas
            if (mapa_fase1[i][j] == 2) {
                // 3. Imprimir Coordenadas
                printf("Espinho encontrado na linha %d, coluna %d\n", i, j);
            }
        }
    }
    
    return 0;
}
