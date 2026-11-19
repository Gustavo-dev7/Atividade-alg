#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOME 50
#define NUM_CAMPEOES 3

typedef struct {
    char nome[MAX_NOME];
    int vida;
    int ataque;
} Campeao;

int main() {
    FILE *arquivo;
    Campeao esquadrao[NUM_CAMPEOES];
    int i;
    int indice_tanque = 0;
    
    // Abrir o arquivo binario para leitura
    arquivo = fopen("squad.dat", "rb");
    
    if (arquivo == NULL) {
        printf("Erro: Nao foi possivel abrir o arquivo squad.dat!\n");
        printf("Certifique-se de que o arquivo existe no diretorio atual.\n");
        return 1;
    }
    
    // Ler os 3 campeoes do arquivo em uma unica operacao
    fread(esquadrao, sizeof(Campeao), NUM_CAMPEOES, arquivo);
    
    // Fechar o arquivo
    fclose(arquivo);
    
    // Encontrar o campeao com maior vida
    for (i = 1; i < NUM_CAMPEOES; i++) {
        if (esquadrao[i].vida > esquadrao[indice_tanque].vida) {
            indice_tanque = i;
        }
    }
    
    // Imprimir o nome do tanque do esquadrao
    printf("%s: Tanque do esquadrao.\n", esquadrao[indice_tanque].nome);
    
    return 0;
}

/* ============================================================
   PROGRAMA AUXILIAR PARA CRIAR O ARQUIVO squad.dat
   Execute este programa primeiro para gerar o arquivo de teste
   ============================================================ */

/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOME 50

typedef struct {
    char nome[MAX_NOME];
    int vida;
    int ataque;
} Campeao;

int main() {
    FILE *arquivo;
    Campeao esquadrao[3];
    
    // Preencher os dados dos campeoes
    strcpy(esquadrao[0].nome, "Garen");
    esquadrao[0].vida = 620;
    esquadrao[0].ataque = 69;
    
    strcpy(esquadrao[1].nome, "Lux");
    esquadrao[1].vida = 530;
    esquadrao[1].ataque = 55;
    
    strcpy(esquadrao[2].nome, "Ashe");
    esquadrao[2].vida = 590;
    esquadrao[2].ataque = 61;
    
    // Abrir arquivo para escrita binaria
    arquivo = fopen("squad.dat", "wb");
    
    if (arquivo == NULL) {
        printf("Erro ao criar o arquivo squad.dat!\n");
        return 1;
    }
    
    // Escrever os 3 campeoes no arquivo
    fwrite(esquadrao, sizeof(Campeao), 3, arquivo);
    
    fclose(arquivo);
    
    printf("Arquivo squad.dat criado com sucesso!\n");
    printf("Campeoes salvos: Garen, Lux, Ashe\n");
    
    return 0;
}
*/
