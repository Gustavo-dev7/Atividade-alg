#include <stdio.h>

struct Heroi {
    int saude;
    int pontuacao;
    int posX;
    int posY;
};

int main() {
    struct Heroi meuHeroi;
    meuHeroi.saude = 100;
    meuHeroi.pontuacao = 0;
    meuHeroi.posX = 0;
    meuHeroi.posY = 0;
    
    printf("--- Estado Inicial do Heroi ---\n");
    printf("Saude: %d\n", meuHeroi.saude);
    printf("Pontuacao: %d\n", meuHeroi.pontuacao);
    printf("Posicao: (%d, %d)\n\n", meuHeroi.posX, meuHeroi.posY);
    
    struct Heroi *ptrHeroi;
    ptrHeroi = &meuHeroi;
    
        ptrHeroi->saude = ptrHeroi->saude - 25;
    printf("Heroi sofreu dano! Saude atual: %d\n", ptrHeroi->saude);
    
    ptrHeroi->pontuacao = ptrHeroi->pontuacao + 50;
    printf("Heroi coletou moedas! Pontuacao atual: %d\n", ptrHeroi->pontuacao);
    
    ptrHeroi->posX = ptrHeroi->posX + 10;
    ptrHeroi->posY = ptrHeroi->posY - 5;
    printf("Heroi se moveu! Posicao atual: (%d, %d)\n\n", 
           ptrHeroi->posX, ptrHeroi->posY);
    
    printf("--- Estado Final do Heroi ---\n");
    printf("Saude: %d\n", ptrHeroi->saude);
    printf("Pontuacao: %d\n", ptrHeroi->pontuacao);
    printf("Posicao: (%d, %d)\n", ptrHeroi->posX, ptrHeroi->posY);
    
    return 0;
}
