#include <stdio.h>
#include <stdlib.h>

struct Moeda {
    int posicao_x;
    int posicao_y;
    int valor;
};

int main() {
    int quantidade;
    struct Moeda *moedas;
    int total_pontos = 0;
    
    printf("Digite a quantidade de moedas no nivel: ");
    scanf("%d", &quantidade);
    
    moedas = (struct Moeda*) malloc(quantidade * sizeof(struct Moeda));
    
    // Verifica se a alocação foi bem-sucedida
    if (moedas == NULL) {
        printf("Erro ao alocar memoria para as moedas!\n");
        return 1;
    }
    
    printf("\n--- Cadastro das Moedas ---\n");
    for (int i = 0; i < quantidade; i++) {
        printf("\nMoeda %d:\n", i + 1);
        printf("Posicao X: ");
        scanf("%d", &moedas[i].posicao_x);
        printf("Posicao Y: ");
        scanf("%d", &moedas[i].posicao_y);
        printf("Valor: ");
        scanf("%d", &moedas[i].valor);
    }
    
    for (int i = 0; i < quantidade; i++) {
        total_pontos = total_pontos + moedas[i].valor;
    }
    
    printf("\nPontuacao maxima do nivel: %d\n", total_pontos);
    
    free(moedas);
    
    return 0;
}
