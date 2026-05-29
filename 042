#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int resolucao_x;
    int resolucao_y;
    float volume_som;
} Configuracao;

int main() {
    FILE *arquivo;
    Configuracao config;
    int itens_lidos;
    
    printf("=== SISTEMA DE CARREGAMENTO DE CONFIGURACAO ===\n\n");
    
    // Tentar abrir o arquivo config.txt para leitura
    arquivo = fopen("config.txt", "r");
    
    // Verificar se o arquivo foi aberto com sucesso
    if (arquivo == NULL) {
        printf("Erro: Arquivo config.txt nao encontrado!\n");
        printf("Certifique-se de que o arquivo existe no diretorio atual.\n");
        return 1;
    }
    
    printf("Arquivo config.txt encontrado! Carregando configuracoes...\n\n");
    
    // Ler os três valores do arquivo para a struct
    itens_lidos = fscanf(arquivo, "%d %d %f", &config.resolucao_x, &config.resolucao_y, &config.volume_som);
    
    // Verificar se a leitura foi bem-sucedida
    if (itens_lidos != 3) {
        printf("Erro: Arquivo config.txt com formato invalido!\n");
        printf("O arquivo deve conter: resolucao_x resolucao_y volume_som\n");
        printf("Exemplo: 1920 1080 75.5\n");
        fclose(arquivo);
        return 1;
    }
    
    // Validar os valores lidos
    if (config.resolucao_x <= 0 || config.resolucao_y <= 0) {
        printf("Erro: Resolucao invalida! (%dx%d)\n", config.resolucao_x, config.resolucao_y);
        printf("Os valores de resolucao devem ser positivos.\n");
        fclose(arquivo);
        return 1;
    }
    
    if (config.volume_som < 0.0 || config.volume_som > 100.0) {
        printf("Erro: Volume invalido! (%.1f)\n", config.volume_som);
        printf("O volume deve estar entre 0.0 e 100.0.\n");
        fclose(arquivo);
        return 1;
    }
    
    // Fechar o arquivo
    fclose(arquivo);
    
    // Exibir as configurações carregadas
    printf("Configuracoes carregadas com sucesso!\n");
    printf("Resolucao: %dx%d\n", config.resolucao_x, config.resolucao_y);
    printf("Volume: %.1f\n", config.volume_som);
    
    return 0;
}
