#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    int x;
    int y;
} Unidade;

int main() {
    int n, i, j;
    float raio;
    int contagem = 0;
    Unidade *unidades;
    
    // Ler o numero de unidades inimigas
    scanf("%d", &n);
    
    // Alocar dinamicamente o vetor de unidades
    unidades = (Unidade*)malloc(n * sizeof(Unidade));
    
    if (unidades == NULL) {
        printf("Erro ao alocar memoria!\n");
        return 1;
    }
    
    // Ler as coordenadas de cada unidade
    for (i = 0; i < n; i++) {
        scanf("%d %d", &unidades[i].x, &unidades[i].y);
    }
    
    // Ler o raio de explosao
    scanf("%f", &raio);
    
    // Comparar cada par de unidades
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            // Calcular a distancia entre as unidades i e j
            int dx = unidades[j].x - unidades[i].x;
            int dy = unidades[j].y - unidades[i].y;
            float distancia = sqrt(dx * dx + dy * dy);
            
            // Verificar se estao dentro do raio de explosao
            if (distancia <= raio) {
                contagem++;
            }
        }
    }
    
    // Imprimir a contagem total de duplas proximas
    printf("%d\n", contagem);
    
    // Liberar a memoria alocada
    free(unidades);
    
    return 0;
}
