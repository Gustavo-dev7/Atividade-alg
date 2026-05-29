#include <stdio.h>

// Funcao recursiva para calcular o dano bonus do Golpe Ecoante
int calcularDanoEco(int n) {
    // Caso base: 1º golpe nao tem dano bonus
    if (n == 1) {
        return 0;
    }
    // Caso base: 2º golpe tem dano bonus de 1 ponto
    else if (n == 2) {
        return 1;
    }
    // Passo recursivo: soma dos dois golpes anteriores
    else {
        return calcularDanoEco(n - 1) + calcularDanoEco(n - 2);
    }
}

int main() {
    int N;
    
    // Ler o numero do golpe na sequencia
    scanf("%d", &N);
    
    // Calcular o dano bonus do golpe
    int dano = calcularDanoEco(N);
    
    // Imprimir o resultado
    printf("%d\n", dano);
    
    return 0;
}
