#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INIMIGOS 3
#define MAX_NOME 50

// Definição da struct para armazenar os dados de um inimigo
typedef struct {
    char nome[MAX_NOME];
    float hp;
    float atk;
} Inimigo;

int main() {
    FILE *arquivo;
    Inimigo inimigos[MAX_INIMIGOS];
    int i, count = 0;
    
    // Abrir o arquivo para leitura
    arquivo = fopen("inimigos.txt", "r");
    
    // Verificar se o arquivo foi aberto corretamente
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo inimigos.txt!\n");
        return 1;
    }
    
    // Ler os dados do arquivo para o vetor de estruturas
    for (i = 0; i < MAX_INIMIGOS; i++) {
        if (fscanf(arquivo, "%s %f %f", inimigos[i].nome, &inimigos[i].hp, &inimigos[i].atk) == 3) {
            count++;
        } else {
            break;
        }
    }
    
    // Fechar o arquivo
    fclose(arquivo);
    
    // Verificar se leu todos os 3 inimigos
    if (count < MAX_INIMIGOS) {
        printf("Aviso: Foram lidos apenas %d inimigos (eram esperados %d)\n", count, MAX_INIMIGOS);
    }
    
    printf("=== INIMIGOS ELITE ===\n");
    
    // Calcular Nível de Ameaça e imprimir os inimigos elite
    for (i = 0; i < count; i++) {
        float nivelAmeaca = inimigos[i].hp + inimigos[i].atk;
        
        if (nivelAmeaca >= 200.0) {
            printf("%s: %.2f\n", inimigos[i].nome, nivelAmeaca);
        }
    }
    
    return 0;
}
