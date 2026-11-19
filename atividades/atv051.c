#include <stdio.h>
#include <string.h>

#define MAX_TIPO 50

typedef struct {
    char tipo[MAX_TIPO];
    int hp;
} Inimigo;

int main() {
    int n, i;
    
    // Ler o numero de unidades inimigas
    scanf("%d", &n);
    
    // Laço para ler os dados de cada unidade
    for (i = 0; i < n; i++) {
        Inimigo inimigo;
        
        // Ler tipo e HP da unidade
        scanf("%s %d", inimigo.tipo, &inimigo.hp);
        
        // Imprimir o relatorio da unidade
        printf("Inimigo: %s, HP: %d\n", inimigo.tipo, inimigo.hp);
    }
    
    return 0;
}
