#include <stdio.h>

int main() {
    int x, y;

    printf("Digite o valor de x: ");
    scanf("%d", &x);
    printf("Digite o valor de y: ");
    scanf("%d", &y);

    printf("Antes da troca: x = %d, y = %d\n", x, y);

    x = x + y;
    y = x - y;
    x = x - y;

    printf("Depois da troca: x = %d, y = %d\n", x, y);

    return 0;
}
