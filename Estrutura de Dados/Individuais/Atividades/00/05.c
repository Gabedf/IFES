#include <stdio.h>

int main() {
    int a, b, c;
    printf("Digite o valor do coeficiente a: ");
    scanf("%d", &a);
    printf("Digite o valor do coeficiente b: ");
    scanf("%d", &b);
    printf("Digite o valor do coeficiente c: ");
    scanf("%d", &c);
    
    int delta = (b*b) - 4*a*c;
    printf("O valor de delta será %d", delta);

    return 0;
}