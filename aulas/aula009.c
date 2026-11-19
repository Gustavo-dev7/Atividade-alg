#include <stdio.h>

int main() {
    int moedas_coletadas[] = {10, 50, 20, 5, 100};
    
    int pontuacao_total = 0;
    
    int *ponteiro_moeda;
    
    ponteiro_moeda = moedas_coletadas;
    
    int *fim = moedas_coletadas + 5;  // endereço logo após o último elemento
    
    while (ponteiro_moeda < fim) {
        pontuacao_total = pontuacao_total + *ponteiro_moeda;  // soma o valor atual
        ponteiro_moeda++;  // avança para a próxima moeda
    }
    
    printf("Pontuação total do nível: %d\n", pontuacao_total);
    
    return 0;
}
