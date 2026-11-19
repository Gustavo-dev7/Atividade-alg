#include <stdio.h>

// Funcao recursiva de Divisao e Conquista para encontrar o valor maximo
int encontrar_maximo(int arr[], int inicio, int fim) {
    // Caso base: segmento com apenas um elemento
    if (inicio == fim) {
        return arr[inicio];
    }
    
    // Dividir: encontrar o ponto medio
    int meio = (inicio + fim) / 2;
    
    // Conquistar: encontrar o maximo em cada metade recursivamente
    int max_esquerda = encontrar_maximo(arr, inicio, meio);
    int max_direita = encontrar_maximo(arr, meio + 1, fim);
    
    // Combinar: retornar o maior dos dois
    if (max_esquerda > max_direita) {
        return max_esquerda;
    } else {
        return max_direita;
    }
}

int main() {
    int N, i;
    
    // Ler a quantidade de fragmentos
    scanf("%d", &N);
    
    // Criar vetor de poderes
    int fragmentos[N];
    
    // Ler os niveis de poder de cada fragmento
    for (i = 0; i < N; i++) {
        scanf("%d", &fragmentos[i]);
    }
    
    // Chamar a funcao recursiva para encontrar o valor maximo
    int maximo = encontrar_maximo(fragmentos, 0, N - 1);
    
    // Imprimir o resultado
    printf("%d\n", maximo);
    
    return 0;
}
