#include <stdio.h>

int main() {
    int F;

    printf("Digite a temperatura em Farenheits: ");
    scanf("%d", &F);
    float C = 5 * (F-32)/9;

    printf("\n%d Farenheits são equivalentes a %f Celsius.", F, C);
    return 0;
}