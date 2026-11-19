#include <stdio.h>

// Funcao recursiva para contar cristais com carga positiva
int contar_carregados(int cargas[], int tamanho, int indice) {
    // Caso base: se chegamos ao fim do vetor
    if (indice == tamanho) {
        return 0;
    }
    
    // Contar o cristal atual se for positivo (estritamente maior que 0)
    int atual = (cargas[indice] > 0) ? 1 : 0;
    
    // Passo recursivo: somar o atual com a contagem dos demais
    return atual + contar_carregados(cargas, tamanho, indice + 1);
}

int main() {
    int n, i;
    
    // Ler o numero de cristais
    scanf("%d", &n);
    
    // Criar vetor para armazenar as cargas
    int cargas[n];
    
    // Ler os niveis de carga de cada cristal
    for (i = 0; i < n; i++) {
        scanf("%d", &cargas[i]);
    }
    
    // Chamar a funcao recursiva para contar os cristais carregados
    int total = contar_carregados(cargas, n, 0);
    
    // Imprimir o resultado
    printf("%d\n", total);
    
    return 0;
}
