#include <stdio.h>
#include <stdlib.h>

int main() {
    void *ponteiro_duracao;
    
    ponteiro_duracao = malloc(sizeof(int));
    
    if (ponteiro_duracao == NULL) {
        printf("Erro ao alocar memoria!\n");
        return 1;
    }
    
    // Faz o cast para int* e armazena o valor 10
    *((int*) ponteiro_duracao) = 10;
    
    printf("Power-up 'Super Salto' ativado! Duracao: %d segundos.\n", *((int*) ponteiro_duracao));
    
    // Diminui 3 segundos
    *((int*) ponteiro_duracao) = *((int*) ponteiro_duracao) - 3;
    
    printf("3 segundos se passaram... Duracao restante: %d segundos.\n", *((int*) ponteiro_duracao));
    
    free(ponteiro_duracao);
    
    return 0;
}
