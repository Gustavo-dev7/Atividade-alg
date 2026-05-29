#include <stdio.h>
#include <string.h>

// Definição da struct Personagem
struct Personagem {
    int id;
    char nome[50];
    int forca;
    int agilidade;
    int inteligencia;
};

// Função de busca linear que retorna o índice do personagem encontrado ou -1 se não existir
int buscarPersonagem(struct Personagem personagens[], int total, int idBusca) {
    for (int i = 0; i < total; i++) {
        if (personagens[i].id == idBusca) {
            return i;
        }
    }
    return -1;
}

int main() {
    int totalPersonagens;
    
    // Leitura do número total de personagens
    printf("Digite o numero total de personagens na campanha: ");
    scanf("%d", &totalPersonagens);
    
    // Criação do vetor de structs
    struct Personagem personagens[totalPersonagens];
    
    // Leitura dos dados de cada personagem
    for (int i = 0; i < totalPersonagens; i++) {
        printf("\n--- Personagem %d ---\n", i + 1);
        
        printf("Digite a ID do personagem: ");
        scanf("%d", &personagens[i].id);
        
        printf("Digite o nome do personagem (uma unica palavra): ");
        scanf("%s", personagens[i].nome);
        
        printf("Digite a Forca: ");
        scanf("%d", &personagens[i].forca);
        
        printf("Digite a Agilidade: ");
        scanf("%d", &personagens[i].agilidade);
        
        printf("Digite a Inteligencia: ");
        scanf("%d", &personagens[i].inteligencia);
    }
    
    // Menu interativo
    int opcao;
    int idConsulta;
    
    do {
        printf("\n=== MENU ===\n");
        printf("1 - Consultar Personagem\n");
        printf("2 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        
        switch (opcao) {
            case 1:
                printf("\nDigite a ID do personagem que deseja consultar: ");
                scanf("%d", &idConsulta);
                
                int indice = buscarPersonagem(personagens, totalPersonagens, idConsulta);
                
                if (indice != -1) {
                    float media = (personagens[indice].forca + 
                                   personagens[indice].agilidade + 
                                   personagens[indice].inteligencia) / 3.0;
                    
                    printf("\n=== RESULTADO DA CONSULTA ===\n");
                    printf("Nome do personagem: %s\n", personagens[indice].nome);
                    printf("Media de atributos: %.2f\n", media);
                } else {
                    printf("\nPersonagem com ID %d nao encontrado!\n", idConsulta);
                }
                break;
                
            case 2:
                printf("\nEncerrando o programa. Boa sessao, Mestre!\n");
                break;
                
            default:
                printf("\nOpcao invalida! Tente novamente.\n");
        }
        
    } while (opcao != 2);
    
    return 0;
}
