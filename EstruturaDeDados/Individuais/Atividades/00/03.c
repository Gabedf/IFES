#include <stdio.h>

int main() {
    int a, b, c;

    printf("Digite o valor 1: ");
    scanf("%d", &a);
    printf("Digite o valor 2: ");
    scanf("%d", &b);
    printf("Digite o valor 3: ");
    scanf("%d", &c);

    float d = (a + b + c)/3;

    printf("A média dos valores é: %.2f", d);

    return 0;
}