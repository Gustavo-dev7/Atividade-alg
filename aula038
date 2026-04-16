#include <stdio.h>

enum EstadoPersonagem {
    PARADO,
    CORRENDO,
    PULANDO
};

int main() {
    enum EstadoPersonagem estado_atual;
    int opcao;
    
    printf("Digite um numero para definir o estado do personagem:\n");
    printf("0 - PARADO\n");
    printf("1 - CORRENDO\n");
    printf("2 - PULANDO\n");
    printf("Opcao: ");
    scanf("%d", &opcao);
    
    estado_atual = opcao;
    
    if (estado_atual == PARADO) {
        printf("O personagem esta parado.\n");
    } else if (estado_atual == CORRENDO) {
        printf("O personagem esta correndo!\n");
    } else if (estado_atual == PULANDO) {
        printf("O personagem esta pulando no ar!\n");
    } else {
        printf("Estado invalido!\n");
    }
    
    return 0;
}
