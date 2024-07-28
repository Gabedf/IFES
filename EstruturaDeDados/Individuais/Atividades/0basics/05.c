#include <stdio.h>
#include <math.h>

int main() {

    /* Declaração de variáveis */
    int a, b, c, test;
    float delta, x, x2;

    /* Entrada de dados */
    printf("Digite os coeficientes da equação\n");
    printf("Coeficiente a: ");
    scanf("%d", &a);
    printf("Coeficiente b: ");
    scanf("%d", &b);
    printf("Coeficiente c: ");
    scanf("%d", &c);

    /* Processamento de dados */
    delta = b*b - 4*a*c;
    if (delta >= 0) {
        x = (-b + pow(delta, 0.5f)) / (2*a);
        x2 = (-b - pow(delta, 0.5f)) / (2*a);
        printf("O valor de x' é %f\n", x);
        printf("O valor de x'' é %f\n", x2);
    } 
    else {
        printf("Equação não existe.");
    }
    /* Saída de dados */

    scanf("%d", &test);

    return 0;
}