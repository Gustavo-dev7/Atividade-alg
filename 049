#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *arquivo;
    
    // Tentar abrir o arquivo level_1_map.dat no modo de leitura
    arquivo = fopen("level_1_map.dat", "r");
    
    // Verificar se o arquivo foi aberto com sucesso
    if (arquivo == NULL) {
        // Mensagem de erro personalizada
        printf("ERRO CRITICO: Nao foi possivel carregar os dados do mapa.\n");
        
        // Mensagem de erro do sistema operacional
        perror("Detalhes do erro");
        
        // Encerrar o programa com status de erro
        exit(1);
    }
    
    // Se o arquivo fosse aberto com sucesso, o programa continuaria aqui
    // Mas como o arquivo nao existe, esta parte nunca sera executada
    
    fclose(arquivo);
    
    return 0;
}
