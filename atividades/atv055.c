#include <stdio.h>
#include <string.h>

#define MAX_NICK 50

typedef struct {
    int id;
    char nickname[MAX_NICK];
    int reputacao;
} Jogador;

// Funcao de busca binaria
// Retorna o indice do jogador no vetor, ou -1 se nao encontrado
int busca_binaria(Jogador jogadores[], int n, int id_busca) {
    int esquerda = 0;
    int direita = n - 1;
    
    while (esquerda <= direita) {
        int meio = (esquerda + direita) / 2;
        
        if (jogadores[meio].id == id_busca) {
            return meio;
        } else if (jogadores[meio].id < id_busca) {
            esquerda = meio + 1;
        } else {
            direita = meio - 1;
        }
    }
    
    return -1;
}

int main() {
    int N, i;
    int opcao;
    int id_busca;
    int indice;
    
    // Ler o numero de jogadores
    scanf("%d", &N);
    
    // Criar vetor de jogadores
    Jogador jogadores[N];
    
    // Ler os dados dos jogadores (IDs ja em ordem crescente)
    for (i = 0; i < N; i++) {
        scanf("%d %s %d", &jogadores[i].id, jogadores[i].nickname, &jogadores[i].reputacao);
    }
    
    // Loop do menu principal
    do {
        scanf("%d", &opcao);
        
        switch (opcao) {
            case 1:
                // Solicitar o ID do jogador
                scanf("%d", &id_busca);
                
                // Buscar o jogador
                indice = busca_binaria(jogadores, N, id_busca);
                
                if (indice != -1) {
                    // Adicionar 100 a reputacao
                    jogadores[indice].reputacao += 100;
                    
                    // Exibir o resultado
                    printf("Nickname: %s, Nova Reputacao: %d\n", 
                           jogadores[indice].nickname, 
                           jogadores[indice].reputacao);
                } else {
                    // Jogador nao encontrado
                    printf("Jogador com ID %d nao encontrado.\n", id_busca);
                }
                break;
                
            case 2:
                // Sair do programa
                break;
                
            default:
                break;
        }
    } while (opcao != 2);
    
    return 0;
}
