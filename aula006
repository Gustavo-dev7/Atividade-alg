#include <stdio.h>

int main() {
    // 1. Vetor de Plataformas
    int plataformas[] = {10, 20, 5, 15, 30};
    
    // 2. Ponteiro para Plataforma
    int *ponteiro_plataforma;
    
    // 3. Variável de Altura
    int altura_total = 0;
    
    // 4. Loop com Aritmética de Ponteiros
    // Faz o ponteiro apontar para o início do vetor
    ponteiro_plataforma = plataformas;
    
    for(int i = 0; i < 5; i++) {
        // Acessa o valor usando *(plataformas + i)
        altura_total = altura_total + *(plataformas + i);
    }
    
    // 5. Imprima o Resultado
    printf("Altura total do salto: %d metros!\n", altura_total);
    
    return 0;
}
