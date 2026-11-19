#include <stdio.h>
#include <string.h>

int main() {
    char inventario[5][20];
    char item_necessario[20];
    int encontrado = 0;
    
    printf("Digite os 5 itens do inventario:\n");
    for (int i = 0; i < 5; i++) {
        printf("Item %d: ", i + 1);
        scanf("%s", inventario[i]);
    }
    
    printf("\nDigite o item necessario para abrir a porta: ");
    scanf("%s", item_necessario);
    
    for (int i = 0; i < 5; i++) {
        if (strcmp(inventario[i], item_necessario) == 0) {
            encontrado = 1;
            break;
        }
    }
    
    if (encontrado == 1) {
        printf("Porta aberta!\n");
    } else {
        printf("Voce nao tem o item necessario.\n");
    }
    
    return 0;
}
