#include <stdio.h>
#include <string.h>

#define MAX_NOME 50

typedef struct {
    char nome[MAX_NOME];
    int hp;
} Monstro;

int main() {
    int N, i;
    int indice_menor_hp;
    
    // Ler a quantidade de monstros
    scanf("%d", &N);
    
    // Criar vetor de monstros
    Monstro horda[N];
    
    // Ler os dados de cada monstro
    for (i = 0; i < N; i++) {
        scanf("%s %d", horda[i].nome, &horda[i].hp);
    }
    
    // Encontrar o monstro com o menor HP
    indice_menor_hp = 0;
    for (i = 1; i < N; i++) {
        if (horda[i].hp < horda[indice_menor_hp].hp) {
            indice_menor_hp = i;
        }
    }
    
    // Imprimir o alvo prioritario
    printf("Alvo prioritario: %s (%d HP)\n", 
           horda[indice_menor_hp].nome, 
           horda[indice_menor_hp].hp);
    
    return 0;
}
