#include <stdio.h>
#include <stdlib.h>

#define MAX_EVENTO 500

int main() {
    int opcao;
    char evento[MAX_EVENTO];
    FILE *arquivo;
    
    printf("=== SISTEMA DE LOG DE EVENTOS ===\n");
    printf("Bem-vindo ao sistema de registro!\n\n");
    
    do {
        printf("--- MENU ---\n");
        printf("1 - Registrar novo evento\n");
        printf("2 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        
        while (getchar() != '\n');
        
        switch (opcao) {
            case 1:
                printf("\nDigite a descricao do evento (sem espacos): ");
                scanf("%s", evento);
                
                arquivo = fopen("game_log.txt", "a");
                
                if (arquivo == NULL) {
                    printf("Erro ao abrir o arquivo game_log.txt!\n");
                    return 1;
                }
                
                fprintf(arquivo, "%s\n", evento);
                fclose(arquivo);
                
                printf("Evento registrado com sucesso!\n\n");
                break;
                
            case 2:
                printf("\nEncerrando o sistema de log. Ate mais!\n");
                break;
                
            default:
                printf("\nOpcao invalida! Tente novamente.\n\n");
                break;
        }
        
    } while (opcao != 2);
    
    return 0;
}
