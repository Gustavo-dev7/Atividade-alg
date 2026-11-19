#include <stdio.h>
#include <string.h>

int main() {
    char nome_jogador[100];
    char titulo_conquistado[50];
    
    printf("Digite o nome do heroi: ");
    fgets(nome_jogador, sizeof(nome_jogador), stdin);
    nome_jogador[strcspn(nome_jogador, "\n")] = '\0';  // remove o '\n'
    
    printf("Digite o titulo conquistado: ");
    fgets(titulo_conquistado, sizeof(titulo_conquistado), stdin);
    titulo_conquistado[strcspn(titulo_conquistado, "\n")] = '\0';  // remove o '\n'
    
    strcat(nome_jogador, " ");
    strcat(nome_jogador, titulo_conquistado);
    printf("O heroi agora eh conhecido como: %s\n", nome_jogador);
    
    return 0;
}
