#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    int nivel_ameaca;
} Nave;

void merge(Nave naves[], int esquerda, int meio, int direita) {
    int i, j, k;
    int n1 = meio - esquerda + 1;
    int n2 = direita - meio;
    
    // Criar vetores temporarios
    Nave *temp_esquerda = (Nave*)malloc(n1 * sizeof(Nave));
    Nave *temp_direita = (Nave*)malloc(n2 * sizeof(Nave));
    
    // Copiar dados para os vetores temporarios
    for (i = 0; i < n1; i++) {
        temp_esquerda[i] = naves[esquerda + i];
    }
    for (j = 0; j < n2; j++) {
        temp_direita[j] = naves[meio + 1 + j];
    }
    
    // Intercalar os vetores temporarios de volta no vetor original
    i = 0;
    j = 0;
    k = esquerda;
    
    while (i < n1 && j < n2) {
        if (temp_esquerda[i].nivel_ameaca <= temp_direita[j].nivel_ameaca) {
            naves[k] = temp_esquerda[i];
            i++;
        } else {
            naves[k] = temp_direita[j];
            j++;
        }
        k++;
    }
    
    // Copiar os elementos restantes da temp_esquerda (se houver)
    while (i < n1) {
        naves[k] = temp_esquerda[i];
        i++;
        k++;
    }
    
    // Copiar os elementos restantes da temp_direita (se houver)
    while (j < n2) {
        naves[k] = temp_direita[j];
        j++;
        k++;
    }
    
    // Liberar a memoria alocada
    free(temp_esquerda);
    free(temp_direita);
}

void merge_sort(Nave naves[], int esquerda, int direita) {
    if (esquerda < direita) {
        int meio = (esquerda + direita) / 2;
        
        // Ordenar a primeira e a segunda metade
        merge_sort(naves, esquerda, meio);
        merge_sort(naves, meio + 1, direita);
        
        // Intercalar as duas metades ordenadas
        merge(naves, esquerda, meio, direita);
    }
}

int main() {
    int N, i;
    
    // Ler a quantidade de naves inimigas
    scanf("%d", &N);
    
    // Criar vetor de naves
    Nave naves[N];
    
    // Ler os dados de cada nave
    for (i = 0; i < N; i++) {
        scanf("%d %d", &naves[i].id, &naves[i].nivel_ameaca);
    }
    
    // Ordenar usando Merge Sort baseado no nivel de ameaca
    merge_sort(naves, 0, N - 1);
    
    // Imprimir os IDs das naves ordenadas
    for (i = 0; i < N; i++) {
        printf("%d", naves[i].id);
        if (i < N - 1) {
            printf(" ");
        }
    }
    printf("\n");
    
    return 0;
}
