#include <stdio.h>

typedef struct {
    int pontos;
    float pos_x;
    float pos_y;
} Coletavel;

int main() {
    Coletavel gema_rara;
    
    printf("Digite o valor em pontos da gema rara: ");
    scanf("%d", &gema_rara.pontos);
    
    printf("Digite a posicao X da gema rara: ");
    scanf("%f", &gema_rara.pos_x);
    
    printf("Digite a posicao Y da gema rara: ");
    scanf("%f", &gema_rara.pos_y);
    
    printf("Coletavel criado! Valor: %d pontos. Posicao: (X=%.1f, Y=%.1f)\n",
           gema_rara.pontos, gema_rara.pos_x, gema_rara.pos_y);
    
    return 0;
}
