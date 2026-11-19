#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOME 50

typedef struct {
    char nome[MAX_NOME];
    int nivel;
    float vida;
    float mana;
} Personagem;

int main() {
    int opcao;
    Personagem personagem;
    FILE *arquivo;
    
    do {
        printf("\n=== SISTEMA DE SAVE GAME ===\n");
        printf("1 - Criar Novo Personagem\n");
        printf("2 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        
        switch (opcao) {
            case 1:
                printf("\n--- Criacao de Personagem ---\n");
                
                printf("Digite o nome: ");
                scanf("%49s", personagem.nome);
                
                printf("Digite o nivel: ");
                scanf("%d", &personagem.nivel);
                
                printf("Digite a vida: ");
                scanf("%f", &personagem.vida);
                
                printf("Digite a mana: ");
                scanf("%f", &personagem.mana);
                
                arquivo = fopen("savegame.sav", "ab");
                if (arquivo == NULL) {
                    printf("Erro ao abrir o arquivo savegame.sav!\n");
                    return 1;
                }
                
                fwrite(&personagem, sizeof(Personagem), 1, arquivo);
                
                fclose(arquivo);
                
                printf("\nPersonagem '%s' salvo com sucesso!\n", personagem.nome);
                break;
                
            case 2:
                printf("\nEncerrando sistema de save game.\n");
                break;
                
            default:
                printf("\nOpcao invalida! Tente novamente.\n");
                break;
        }
    } while (opcao != 2);
    
    return 0;
}
