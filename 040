#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOME 100

// Definição da struct para armazenar os dados de um jogador
typedef struct {
    char nome[MAX_NOME];
    int pontuacao;
} Jogador;

int main() {
    int n, i;
    Jogador *jogadores;
    int indiceMaior = 0;
    
    // Ler o número de jogadores
    printf("Digite a quantidade de jogadores: ");
    scanf("%d", &n);
    
    // Limpar o buffer do teclado
    while (getchar() != '\n');
    
    // Alocar memória para o vetor de jogadores
    jogadores = (Jogador*)malloc(n * sizeof(Jogador));
    
    if (jogadores == NULL) {
        printf("Erro ao alocar memória!\n");
        return 1;
    }
    
    // Ler os dados dos n jogadores
    for (i = 0; i < n; i++) {
        printf("\n--- Jogador %d ---\n", i + 1);
        
        printf("Digite o nome: ");
        fgets(jogadores[i].nome, MAX_NOME, stdin);
        
        // Remover o caractere de nova linha do final do nome
        size_t len = strlen(jogadores[i].nome);
        if (len > 0 && jogadores[i].nome[len - 1] == '\n') {
            jogadores[i].nome[len - 1] = '\0';
        }
        
        printf("Digite a pontuação: ");
        scanf("%d", &jogadores[i].pontuacao);
        
        // Limpar o buffer do teclado
        while (getchar() != '\n');
    }
    
    // Encontrar o jogador com a maior pontuação
    for (i = 1; i < n; i++) {
        if (jogadores[i].pontuacao > jogadores[indiceMaior].pontuacao) {
            indiceMaior = i;
        }
    }
    
    // Abrir o arquivo highscore.txt em modo de escrita
    FILE *arquivo = fopen("highscore.txt", "w");
    
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo highscore.txt!\n");
        free(jogadores);
        return 1;
    }
    
    // Escrever o recordista no arquivo usando fprintf
    fprintf(arquivo, "Nome: %s, Pontuacao: %d\n", 
            jogadores[indiceMaior].nome, 
            jogadores[indiceMaior].pontuacao);
    
    // Fechar o arquivo
    fclose(arquivo);
    
    // Exibir o resultado na tela
    printf("\n=== RECORDISTA ===\n");
    printf("Jogador: %s\n", jogadores[indiceMaior].nome);
    printf("Pontuação: %d\n", jogadores[indiceMaior].pontuacao);
    printf("Recorde salvo em highscore.txt!\n");
    
    // Liberar a memória alocada
    free(jogadores);
    
    return 0;
}
