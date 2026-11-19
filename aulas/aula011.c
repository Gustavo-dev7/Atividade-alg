#include <stdio.h>

int main() {
    int balas[] = {30, 30};
    int granadas[] = {5, 5};
    int foguetes[] = {2, 2};
    
    int *inventario[3];
    
    inventario[0] = balas;      // aponta para o vetor balas
    inventario[1] = granadas;   // aponta para o vetor granadas
    inventario[2] = foguetes;   // aponta para o vetor foguetes
    
    printf("Inventario Inicial:\n");
    printf("Balas: %d\n", inventario[0][0]);      // ou *inventario[0]
    printf("Granadas: %d\n", inventario[1][0]);   // ou *inventario[1]
    printf("Foguetes: %d\n", inventario[2][0]);   // ou *inventario[2]
    
    for (int i = 0; i < 3; i++) {
        *inventario[i] = *inventario[i] - 1;
        // Ou: *(inventario[i] + 0) -= 1;
    }
    
    printf("\nInventario Apos o Uso:\n");
    printf("Balas: %d\n", *inventario[0]);
    printf("Granadas: %d\n", *inventario[1]);
    printf("Foguetes: %d\n", *inventario[2]);
    
    return 0;
}
