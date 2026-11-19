#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOME 50

typedef struct {
    char nome[MAX_NOME];
    int vida;
    int ataque;
} Unidade;

int main() {
    int n, i;
    Unidade *esquadrao;
    int indice_maior_ataque = 0;
    
    printf("=== MONTAGEM DO ESQUADRAO ===\n");
    printf("Digite o numero de unidades no esquadrao: ");
    scanf("%d", &n);
    
    if (n <= 0) {
        printf("Numero invalido de unidades!\n");
        return 1;
    }
    
    // Alocar dinamicamente o vetor de n unidades
    esquadrao = (Unidade*)malloc(n * sizeof(Unidade));
    
    if (esquadrao == NULL) {
        printf("Erro ao alocar memoria!\n");
        return 1;
    }
    
    // Limpar o buffer do teclado
    while (getchar() != '\n');
    
    // Preencher o vetor com os dados das unidades
    for (i = 0; i < n; i++) {
        printf("\n--- Unidade %d ---\n", i + 1);
        
        printf("Digite o nome: ");
        scanf("%49s", esquadrao[i].nome);
        
        printf("Digite a vida (HP): ");
        scanf("%d", &esquadrao[i].vida);
        
        printf("Digite o ataque (ATK): ");
        scanf("%d", &esquadrao[i].ataque);
    }
    
    // Abrir arquivo para escrita binaria
    FILE *arquivo = fopen("squad.dat", "wb");
    
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo squad.dat!\n");
        free(esquadrao);
        return 1;
    }
    
    // Escrever o vetor inteiro de uma vez no arquivo
    fwrite(esquadrao, sizeof(Unidade), n, arquivo);
    
    // Fechar o arquivo
    fclose(arquivo);
    
    printf("\nEsquadrao salvo em squad.dat com sucesso!\n");
    
    // Encontrar a unidade com maior ataque
    for (i = 1; i < n; i++) {
        if (esquadrao[i].ataque > esquadrao[indice_maior_ataque].ataque) {
            indice_maior_ataque = i;
        }
    }
    
    // Imprimir o nome da unidade com maior ataque
    printf("\n=== UNIDADE COM MAIOR PODER DE ATAQUE ===\n");
    printf("Nome: %s\n", esquadrao[indice_maior_ataque].nome);
    printf("Vida: %d\n", esquadrao[indice_maior_ataque].vida);
    printf("Ataque: %d\n", esquadrao[indice_maior_ataque].ataque);
    
    // Liberar a memoria alocada
    free(esquadrao);
    
    return 0;
}
