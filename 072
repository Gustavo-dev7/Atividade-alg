#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOME 50

typedef struct {
    int posicao;
    char nome[MAX_NOME];
} Piloto;

void intercala(Piloto pilotos[], int esquerda, int meio, int direita) {
    int i, j, k;
    int n1 = meio - esquerda + 1;
    int n2 = direita - meio;
    
    // Criar vetores temporarios
    Piloto *temp_esquerda = (Piloto*)malloc(n1 * sizeof(Piloto));
    Piloto *temp_direita = (Piloto*)malloc(n2 * sizeof(Piloto));
    
    // Copiar dados para os vetores temporarios
    for (i = 0; i < n1; i++) {
        temp_esquerda[i] = pilotos[esquerda + i];
    }
    for (j = 0; j < n2; j++) {
        temp_direita[j] = pilotos[meio + 1 + j];
    }
    
    // Intercalar os vetores temporarios de volta no vetor original
    i = 0;
    j = 0;
    k = esquerda;
    
    while (i < n1 && j < n2) {
        if (temp_esquerda[i].posicao <= temp_direita[j].posicao) {
            pilotos[k] = temp_esquerda[i];
            i++;
        } else {
            pilotos[k] = temp_direita[j];
            j++;
        }
        k++;
    }
    
    // Copiar os elementos restantes da temp_esquerda (se houver)
    while (i < n1) {
        pilotos[k] = temp_esquerda[i];
        i++;
        k++;
    }
    
    // Copiar os elementos restantes da temp_direita (se houver)
    while (j < n2) {
        pilotos[k] = temp_direita[j];
        j++;
        k++;
    }
    
    // Liberar a memoria alocada
    free(temp_esquerda);
    free(temp_direita);
}

void merge_sort(Piloto pilotos[], int esquerda, int direita) {
    if (esquerda < direita) {
        int meio = (esquerda + direita) / 2;
        
        // Ordenar a primeira e a segunda metade
        merge_sort(pilotos, esquerda, meio);
        merge_sort(pilotos, meio + 1, direita);
        
        // Intercalar as duas metades ordenadas
        intercala(pilotos, esquerda, meio, direita);
    }
}

int main() {
    int N, i;
    
    // Ler o numero total de pilotos
    scanf("%d", &N);
    
    // Criar vetor de pilotos
    Piloto pilotos[N];
    
    // Ler os dados de cada piloto
    for (i = 0; i < N; i++) {
        scanf("%d %s", &pilotos[i].posicao, pilotos[i].nome);
    }
    
    // Ordenar usando Merge Sort baseado na posicao
    merge_sort(pilotos, 0, N - 1);
    
    // Imprimir a lista ordenada
    for (i = 0; i < N; i++) {
        printf("%d %s\n", pilotos[i].posicao, pilotos[i].nome);
    }
    
    return 0;
}
