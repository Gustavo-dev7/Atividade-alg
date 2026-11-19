#include <stdio.h>
#include <string.h>

#define MAX_NOME 50

typedef struct {
    int id;
    char nome[MAX_NOME];
    int hp;
    int ataque;
} Monstro;

// Funcao de busca binaria recursiva
// Retorna o indice do monstro no vetor, ou -1 se nao encontrado
int busca_binaria_recursiva(Monstro bestiario[], int esquerda, int direita, int id_busca) {
    // Caso base: limite esquerdo ultrapassou o direito (nao encontrado)
    if (esquerda > direita) {
        return -1;
    }
    
    // Calcular o meio do intervalo
    int meio = (esquerda + direita) / 2;
    
    // Caso base: encontrou o monstro
    if (bestiario[meio].id == id_busca) {
        return meio;
    }
    // Passo recursivo: buscar na metade esquerda
    else if (id_busca < bestiario[meio].id) {
        return busca_binaria_recursiva(bestiario, esquerda, meio - 1, id_busca);
    }
    // Passo recursivo: buscar na metade direita
    else {
        return busca_binaria_recursiva(bestiario, meio + 1, direita, id_busca);
    }
}

int main() {
    int N, i;
    int id_busca;
    int indice;
    
    // Ler o numero de monstros a serem catalogados
    scanf("%d", &N);
    
    // Criar vetor de monstros
    Monstro bestiario[N];
    
    // Ler os dados dos monstros (IDs ja em ordem crescente)
    for (i = 0; i < N; i++) {
        scanf("%d %s %d %d", &bestiario[i].id, bestiario[i].nome, 
              &bestiario[i].hp, &bestiario[i].ataque);
    }
    
    // Loop de busca (continua ate o usuario digitar 0)
    while (1) {
        scanf("%d", &id_busca);
        
        // Condicao de parada
        if (id_busca == 0) {
            break;
        }
        
        // Realizar a busca binaria recursiva
        indice = busca_binaria_recursiva(bestiario, 0, N - 1, id_busca);
        
        if (indice != -1) {
            // Monstro encontrado
            printf("Monstro Encontrado: %s (ID: %d) - HP: %d, Ataque: %d\n", 
                   bestiario[indice].nome, bestiario[indice].id, 
                   bestiario[indice].hp, bestiario[indice].ataque);
        } else {
            // Monstro nao encontrado
            printf("Monstro com ID %d nao encontrado.\n", id_busca);
        }
    }
    
    return 0;
}
