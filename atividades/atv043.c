#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOME 50

// Definição da struct Inimigo com typedef
typedef struct {
    char nome[MAX_NOME];
    int vida;
    int ataque;
} Inimigo;

int main() {
    FILE *arquivo;
    Inimigo inimigo_atual;
    Inimigo inimigo_mais_forte;
    int primeiro_inimigo = 1;
    
    // Tentar abrir o arquivo wave_data.txt para leitura
    arquivo = fopen("wave_data.txt", "r");
    
    // Verificar se o arquivo foi aberto com sucesso
    if (arquivo == NULL) {
        printf("Erro: Nao foi possivel abrir o arquivo wave_data.txt!\n");
        return 1;
    }
    
    // Ler todos os inimigos do arquivo usando fscanf
    while (fscanf(arquivo, "%s %d %d", 
                  inimigo_atual.nome, 
                  &inimigo_atual.vida, 
                  &inimigo_atual.ataque) != EOF) {
        
        // Se for o primeiro inimigo, inicializar a variável do mais forte
        if (primeiro_inimigo) {
            inimigo_mais_forte = inimigo_atual;
            primeiro_inimigo = 0;
        }
        // Caso contrário, comparar o ataque com o maior encontrado até agora
        else if (inimigo_atual.ataque > inimigo_mais_forte.ataque) {
            inimigo_mais_forte = inimigo_atual;
        }
    }
    
    // Fechar o arquivo
    fclose(arquivo);
    
    // Verificar se pelo menos um inimigo foi lido
    if (primeiro_inimigo) {
        printf("Erro: O arquivo wave_data.txt esta vazio ou com formato invalido!\n");
        return 1;
    }
    
    // Imprimir o inimigo com o maior poder de ataque
    printf("Maior Ameaca: %s, Vida: %d, Ataque: %d\n", 
           inimigo_mais_forte.nome, 
           inimigo_mais_forte.vida, 
           inimigo_mais_forte.ataque);
    
    return 0;
}
