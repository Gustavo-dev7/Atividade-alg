#include <stdio.h>

int main() {
    float forca_base, bonus_arma, buff_feitico, dano_total;
    
    // Ler os tres valores de ponto flutuante
    scanf("%f %f %f", &forca_base, &bonus_arma, &buff_feitico);
    
    // Calcular o dano total (soma dos tres valores)
    dano_total = forca_base + bonus_arma + buff_feitico;
    
    // Imprimir o resultado com duas casas decimais
    printf("%.2f\n", dano_total);
    
    return 0;
}
