#include <stdio.h>

int main() {
    /* Tipos de dados */
    float F, C, teste;

    /* Entrada de dados */
    printf("Digite a temperatura em Fahrenheit: ");
    scanf("%f", &F);

    /* Processamento de dados */
    C = ((F - 32) / 9) * 5;

    printf("Sua temperatura em Celcius é de %f graus.\n", C);
    printf("Pressione 'ENTER' pare encerrar o programa: ");
    scanf("%f", &teste);

    return 0;
}