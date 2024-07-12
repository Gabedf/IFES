#include <stdio.h>

int main() {

    /* Declaraçãod de variáveis */
    int a, b, c, teste;
    float media;

    /* Entrada de dados */
    printf("Digite seus 3 valores: \n");
    printf("Valor A: ");
    scanf("%d", &a);
    printf("Valor B: ");
    scanf("%d", &b);
    printf("Valor C: ");
    scanf("%d", &c);

    /* Processamento de dados */
    media = (a + b + c)/3;

    /* Saída de dados */
    printf("Sua média final é %f\n", media);
    scanf("%d", &teste);

    return 0;

}