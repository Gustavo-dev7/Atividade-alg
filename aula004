#include <stdio.h>

void aplicar_powerup_pontuacao_dupla(int *pontuacao) {
    *pontuacao = *pontuacao * 2;  // dobra o valor no endereço de memória
}

int main() {

    int pontuacao_jogador = 1500;

    printf("Pontuacao antes do power-up: %d\n", pontuacao_jogador);

    aplicar_powerup_pontuacao_dupla(&pontuacao_jogador);

    printf("Pontuacao apos o power-up: %d\n", pontuacao_jogador);

    return 0;
}
