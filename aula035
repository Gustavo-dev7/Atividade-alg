#include <stdio.h>
#include <string.h>

struct ItemColetavel {
    char nome[50];
    int valor_pontos;
};

int main() {
    struct ItemColetavel inventario[3];
    
    printf("--- Coleta de Itens ---\n");
    for (int i = 0; i < 3; i++) {
        printf("\nItem %d:\n", i + 1);
        printf("Nome: ");
        scanf(" %[^\n]", inventario[i].nome);  // lê string com espaços
        printf("Valor em pontos: ");
        scanf("%d", &inventario[i].valor_pontos);
    }
    
    struct ItemColetavel mais_valioso = inventario[0];
    
    for (int i = 1; i < 3; i++) {
        if (inventario[i].valor_pontos > mais_valioso.valor_pontos) {
            mais_valioso = inventario[i];
        }
    }
    
    printf("\nO item mais valioso coletado foi: %s\n", mais_valioso.nome);
    
    return 0;
}
