// ==================== personagem.h ====================
#ifndef PERSONAGEM_H
#define PERSONAGEM_H

typedef struct personagem Personagem;

Personagem* cria_party(int num_membros);
void registra_membros(Personagem* party, int num_membros);
void exibe_relatorio(const Personagem* party, int num_membros);
void libera_party(Personagem* party);

#endif

// ==================== personagem.c ====================
#include "personagem.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_NOME 50

struct personagem {
    char nome[TAM_NOME];
    char classe[TAM_NOME];
    int nivel;
    int hp;
};

Personagem* cria_party(int num_membros) {
    if (num_membros <= 0) {
        printf("Erro: Número de membros inválido!\n");
        return NULL;
    }
    
    Personagem* party = (Personagem*)malloc(num_membros * sizeof(Personagem));
    if (party == NULL) {
        printf("Erro ao alocar memória para a party!\n");
        exit(1);
    }
    return party;
}

void registra_membros(Personagem* party, int num_membros) {
    if (party == NULL) {
        printf("Erro: Party não alocada!\n");
        return;
    }
    
    for (int i = 0; i < num_membros; i++) {
        printf("\n--- Membro %d ---\n", i + 1);
        
        printf("Nome: ");
        getchar();
        fgets(party[i].nome, TAM_NOME, stdin);
        size_t len = strlen(party[i].nome);
        if (len > 0 && party[i].nome[len - 1] == '\n') {
            party[i].nome[len - 1] = '\0';
        }
        
        printf("Classe (Guerreiro/Mago/Arqueiro/etc): ");
        fgets(party[i].classe, TAM_NOME, stdin);
        len = strlen(party[i].classe);
        if (len > 0 && party[i].classe[len - 1] == '\n') {
            party[i].classe[len - 1] = '\0';
        }
        
        printf("Nível: ");
        scanf("%d", &party[i].nivel);
        
        printf("Pontos de Vida (HP): ");
        scanf("%d", &party[i].hp);
    }
}

void exibe_relatorio(const Personagem* party, int num_membros) {
    if (party == NULL) {
        printf("Erro: Party não alocada!\n");
        return;
    }
    
    printf("\n========================================");
    printf("\n   RELATÓRIO DA EQUIPE (PARTY)");
    printf("\n========================================\n");
    
    for (int i = 0; i < num_membros; i++) {
        printf("\n[ Membro %d ]\n", i + 1);
        printf("  Nome    : %s\n", party[i].nome);
        printf("  Classe  : %s\n", party[i].classe);
        printf("  Nível   : %d\n", party[i].nivel);
        printf("  HP      : %d\n", party[i].hp);
    }
    printf("\n========================================\n");
}

void libera_party(Personagem* party) {
    if (party != NULL) {
        free(party);
        printf("Memória da party liberada com sucesso!\n");
    }
}

// ==================== main.c ====================
#include <stdio.h>
#include "personagem.h"

int main() {
    int num_membros;
    
    printf("========================================\n");
    printf("   GERENCIADOR DE EQUIPE - RPG TÁTICO");
    printf("========================================\n");
    
    printf("\nQuantos membros terá sua equipe? ");
    scanf("%d", &num_membros);
    
    if (num_membros <= 0) {
        printf("Número inválido! Encerrando programa.\n");
        return 1;
    }
    
    // Criando a party (alocação dinâmica)
    Personagem* party = cria_party(num_membros);
    if (party == NULL) {
        return 1;
    }
    
    // Registrando os membros
    printf("\n--- Preencha os dados dos membros ---");
    registra_membros(party, num_membros);
    
    // Exibindo o relatório
    exibe_relatorio(party, num_membros);
    
    // Liberando a memória
    libera_party(party);
    
    printf("\nPrograma finalizado com sucesso!\n");
    
    return 0;
}
