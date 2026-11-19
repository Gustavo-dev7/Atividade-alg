#include <stdio.h>
#include <stdlib.h>

int main() {
    float *ponteiro_altura_salto_duplo = NULL;
    
    printf("Jogador ainda nao possui o Salto Duplo\n");
    
    ponteiro_altura_salto_duplo = (float*) malloc(sizeof(float));
    
    // 4. Verificação
    if (ponteiro_altura_salto_duplo != NULL) {
        *ponteiro_altura_salto_duplo = 15.5;
        
        printf("Pena Dourada coletada! Altura do Salto Duplo: %.2f\n", *ponteiro_altura_salto_duplo);
        
        // Em um jogo real, esta linha seria usada para liberar a memória
        // quando o power-up não fosse mais necessário (ex: fim da fase)
        free(ponteiro_altura_salto_duplo);
    } else {
        printf("Erro ao alocar memoria para o Salto Duplo!\n");
    }
    
    return 0;
}
