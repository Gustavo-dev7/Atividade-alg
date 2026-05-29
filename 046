#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOME 50

typedef struct {
    char nome[MAX_NOME];
    int nivel;
    int highScore;
} PlayerProfile;

int main() {
    FILE *arquivo;
    PlayerProfile perfil;
    int perfis_carregados = 0;
    
    // Abrir o arquivo binário para leitura
    arquivo = fopen("profiles.dat", "rb");
    
    if (arquivo == NULL) {
        printf("Erro: Nao foi possivel abrir o arquivo profiles.dat!\n");
        printf("Certifique-se de que o arquivo existe no diretorio atual.\n");
        return 1;
    }
    
    printf("=== CARREGANDO PERFIS DE JOGADORES ===\n\n");
    
    // Ler perfis do arquivo até o final
    while (fread(&perfil, sizeof(PlayerProfile), 1, arquivo) == 1) {
        perfis_carregados++;
        
        // Determinar o rank baseado no highScore
        char *rank;
        if (perfil.highScore > 10000) {
            rank = "Mestre do Jogo";
        } else if (perfil.highScore > 5000) {
            rank = "Veterano";
        } else {
            rank = "Aspirante";
        }
        
        // Imprimir as informações do perfil
        printf("Perfil %d:\n", perfis_carregados);
        printf("  Nome: %s\n", perfil.nome);
        printf("  Nivel: %d\n", perfil.nivel);
        printf("  High Score: %d\n", perfil.highScore);
        printf("  Rank: %s\n\n", rank);
    }
    
    // Fechar o arquivo
    fclose(arquivo);
    
    if (perfis_carregados == 0) {
        printf("Nenhum perfil encontrado no arquivo.\n");
    } else {
        printf("Total de perfis carregados: %d\n", perfis_carregados);
    }
    
    return 0;
}

/* ============================================================
   PROGRAMA AUXILIAR PARA CRIAR O ARQUIVO profiles.dat
   Execute este programa primeiro para gerar o arquivo de teste
   ============================================================ */

/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOME 50

typedef struct {
    char nome[MAX_NOME];
    int nivel;
    int highScore;
} PlayerProfile;

int main() {
    FILE *arquivo;
    PlayerProfile perfis[] = {
        {"Guerreiro", 15, 12500},
        {"Mago", 12, 7800},
        {"Arqueiro", 8, 3200},
        {"Paladino", 20, 15000},
        {"Ladino", 5, 1800},
        {"Druida", 10, 5200}
    };
    int num_perfis = sizeof(perfis) / sizeof(perfis[0]);
    int i;
    
    // Abrir arquivo para escrita binária
    arquivo = fopen("profiles.dat", "wb");
    
    if (arquivo == NULL) {
        printf("Erro ao criar o arquivo profiles.dat!\n");
        return 1;
    }
    
    // Escrever cada perfil no arquivo
    for (i = 0; i < num_perfis; i++) {
        fwrite(&perfis[i], sizeof(PlayerProfile), 1, arquivo);
    }
    
    fclose(arquivo);
    
    printf("Arquivo profiles.dat criado com sucesso!\n");
    printf("%d perfis foram salvos.\n", num_perfis);
    
    return 0;
}
*/
