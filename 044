#include <stdio.h>
#include <stdlib.h>

// Definição da struct Conquista
typedef struct {
    int id;
    int pontos;
} Conquista;

int main() {
    FILE *arquivo;
    int N, i;
    int total_pontos = 0;
    
    // Abrir o arquivo no modo de leitura e escrita ("r+")
    // Este modo permite ler e escrever sem apagar o conteúdo existente
    arquivo = fopen("player_log.txt", "r+");
    
    // Verificar se o arquivo foi aberto corretamente
    if (arquivo == NULL) {
        printf("Erro: Nao foi possivel abrir o arquivo player_log.txt!\n");
        printf("Certifique-se de que o arquivo existe no diretorio atual.\n");
        return 1;
    }
    
    // Ler o número N (quantidade de conquistas)
    if (fscanf(arquivo, "%d", &N) != 1) {
        printf("Erro: Arquivo player_log.txt vazio ou com formato invalido!\n");
        fclose(arquivo);
        return 1;
    }
    
    printf("=== PROCESSAMENTO DE LOG DO JOGADOR ===\n");
    printf("Total de conquistas registradas: %d\n\n", N);
    
    // Validar se N é um número positivo
    if (N <= 0) {
        printf("Nenhuma conquista para processar.\n");
        printf("Total de pontos de experiencia: 0\n");
    } else {
        // Alocar memória para o vetor de conquistas
        Conquista *conquistas = (Conquista*)malloc(N * sizeof(Conquista));
        
        if (conquistas == NULL) {
            printf("Erro: Falha na alocacao de memoria!\n");
            fclose(arquivo);
            return 1;
        }
        
        // Ler cada uma das N conquistas
        printf("Conquistas processadas:\n");
        for (i = 0; i < N; i++) {
            if (fscanf(arquivo, "%d %d", &conquistas[i].id, &conquistas[i].pontos) != 2) {
                printf("Erro: Formato invalido na linha %d do arquivo!\n", i + 2);
                free(conquistas);
                fclose(arquivo);
                return 1;
            }
            
            total_pontos += conquistas[i].pontos;
            printf("  Conquista %d: ID %d -> +%d XP\n", 
                   i + 1, conquistas[i].id, conquistas[i].pontos);
        }
        
        // Exibir o total de pontos de experiência
        printf("\n--- TOTAL DA SESSAO ---\n");
        printf("Total de pontos de experiencia ganhos: %d\n", total_pontos);
        
        // Liberar a memória alocada
        free(conquistas);
    }
    
    // Mover o ponteiro do arquivo para o final para anexar a mensagem
    // Isso é necessário porque após a leitura, o ponteiro está no final do arquivo
    fseek(arquivo, 0, SEEK_END);
    
    // Escrever a mensagem de conclusão da sessão
    fprintf(arquivo, "\n--- SESSION CONCLUDED ---");
    
    // Fechar o arquivo
    fclose(arquivo);
    
    printf("\nArquivo player_log.txt atualizado com sucesso!\n");
    printf("Mensagem '--- SESSION CONCLUDED ---' adicionada ao final.\n");
    
    return 0;
}
