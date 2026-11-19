#include <stdio.h>
#include <stdlib.h>

int main() {
    int quantidade;
    
    printf("Digite a quantidade de inimigos na fase: ");
    scanf("%d", &quantidade);
    
    int *status_inimigos;
    
    status_inimigos = (int*) calloc(quantidade, sizeof(int));
    
    if (status_inimigos == NULL) {
        printf("Erro ao alocar memoria para os inimigos!\n");
        return 1;
    }
    
    printf("\n--- Status inicial (apos calloc) ---\n");
    for (int i = 0; i < quantidade; i++) {
        printf("Inimigo %d: Inativo (%d)\n", i, status_inimigos[i]);
    }
    
    for (int i = 0; i < quantidade; i++) {
        status_inimigos[i] = 1;
    }
    
    printf("\n--- Status apos ativacao ---\n");
    for (int i = 0; i < quantidade; i++) {
        printf("Inimigo %d: Ativo (%d)\n", i, status_inimigos[i]);
    }
    
    free(status_inimigos);
    
    return 0;
}
