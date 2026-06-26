// ==================== heroi/heroi.h ====================
#ifndef HEROI_H
#define HEROI_H

typedef struct heroi Heroi;

Heroi* criar_vetor(int quantidade);
void ler_herois(Heroi *herois, int quantidade);
void imprimir_herois(Heroi *herois, int quantidade);

#endif

// ==================== heroi/heroi.c ====================
#include "heroi.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_NOME 50

struct heroi {
    char nome[TAM_NOME];
    int hp;
    int ataque;
};

Heroi* criar_vetor(int quantidade) {
    Heroi *herois = (Heroi*)malloc(quantidade * sizeof(Heroi));
    if (herois == NULL) {
        printf("Erro ao alocar memória!\n");
        exit(1);
    }
    return herois;
}

void ler_herois(Heroi *herois, int quantidade) {
    for (int i = 0; i < quantidade; i++) {
        printf("\n--- Herói %d ---\n", i + 1);
        
        printf("Nome: ");
        getchar();
        fgets(herois[i].nome, TAM_NOME, stdin);
        size_t len = strlen(herois[i].nome);
        if (len > 0 && herois[i].nome[len - 1] == '\n') {
            herois[i].nome[len - 1] = '\0';
        }
        
        printf("Pontos de Vida (HP): ");
        scanf("%d", &herois[i].hp);
        
        printf("Poder de Ataque: ");
        scanf("%d", &herois[i].ataque);
    }
}

void imprimir_herois(Heroi *herois, int quantidade) {
    printf("\n=== ROSTER DA EQUIPE ===\n");
    for (int i = 0; i < quantidade; i++) {
        printf("\nHerói %d:\n", i + 1);
        printf("  Nome: %s\n", herois[i].nome);
        printf("  HP: %d\n", herois[i].hp);
        printf("  Ataque: %d\n", herois[i].ataque);
    }
}

// ==================== main.c ====================
#include <stdio.h>
#include <stdlib.h>
#include "heroi/heroi.h"

int main() {
    int quantidade;
    
    printf("=== MONTAGEM DA EQUIPE ===\n");
    printf("Quantos heróis farão parte da equipe? ");
    scanf("%d", &quantidade);
    
    if (quantidade <= 0) {
        printf("Quantidade inválida!\n");
        return 1;
    }
    
    Heroi *equipe = criar_vetor(quantidade);
    
    printf("\n--- Preencha os dados dos heróis ---");
    ler_herois(equipe, quantidade);
    
    imprimir_herois(equipe, quantidade);
    
    free(equipe);
    
    return 0;
}
