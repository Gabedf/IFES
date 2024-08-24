#include <stdio.h>

int main() {
    
    /* Declaração de variáveis */
    float arq, speed, time, test;

    /* Entrada de dados */
    printf("Indique o tamanho do arquivo: ");
    scanf("%f", &arq);
    printf("Indique a velocidade de Download: ");
    scanf("%f", &speed);

    /* Processamento de dados */
    time = (arq/speed)/60;

    /* Saída de dados */
    printf("O tempo para Download será de %f minutos." , time);
    scanf("%f", &test);

    return 0;
}