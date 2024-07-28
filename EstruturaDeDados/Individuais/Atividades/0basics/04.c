#include <stdio.h> 

int main() {

    /* Declaração de variáveis */
    float salary, credit, test;

    /* Entrada de dados */
    printf("Digite seu salário: ");
    scanf("%f", &salary);
    
    /* Processamento de dados */
    credit = salary * 0.3;

    /* Saída de dados */
    printf("O valor máximo possível da prestação será de %f reais.", credit);
    scanf("%f", test);

    return 0;
}   