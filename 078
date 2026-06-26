#include <stdio.h>

// ============ combate.h (Interface) ============
int calcular_ataque_total(int ataque_base, int bonus_arma);
int aplicar_dano(int vida_atual, int dano_sofrido);

// ============ combate.c (Implementação) ============
int calcular_ataque_total(int ataque_base, int bonus_arma) {
    return ataque_base + bonus_arma;
}

int aplicar_dano(int vida_atual, int dano_sofrido) {
    int resultado = vida_atual - dano_sofrido;
    if (resultado < 0) {
        return 0;
    }
    return resultado;
}

// ============ main.c (Programa Principal) ============
int main() {
    int ataque_base, bonus_arma, vida_inimigo;
    
    printf("=== SIMULADOR DE COMBATE RPG ===\n\n");
    
    printf("Digite o ataque base do herói: ");
    scanf("%d", &ataque_base);
    
    printf("Digite o bônus da espada: ");
    scanf("%d", &bonus_arma);
    
    printf("Digite a vida inicial do inimigo: ");
    scanf("%d", &vida_inimigo);
    
    int dano_total = calcular_ataque_total(ataque_base, bonus_arma);
    int vida_restante = aplicar_dano(vida_inimigo, dano_total);
    
    printf("\n--- RESULTADO DO COMBATE ---\n");
    printf("Poder de ataque total: %d\n", dano_total);
    printf("Vida restante do inimigo: %d\n", vida_restante);
    
    if (vida_restante == 0) {
        printf("Inimigo derrotado!\n");
    } else {
        printf("Inimigo ainda está de pé!\n");
    }
    
    return 0;
}
