#include <stdio.h>

// Funcao recursiva para calcular o dano total do Ataque em Cascata
int calcular_dano(int nivel) {
    // Caso base: nivel 1 retorna 1
    if (nivel == 1) {
        return 1;
    }
    // Passo recursivo: nivel atual + soma dos niveis anteriores
    else {
        return nivel + calcular_dano(nivel - 1);
    }
}

int main() {
    int nivel;
    
    // Ler o nivel do mago
    scanf("%d", &nivel);
    
    // Calcular o dano total
    int dano_total = calcular_dano(nivel);
    
    // Imprimir o resultado
    printf("%d\n", dano_total);
    
    return 0;
}
