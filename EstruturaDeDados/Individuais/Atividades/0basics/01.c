#include <stdio.h>

int main() {
    float C;
    int F;

    /* Recebe informação do usuário */
    printf("Digite a temperatura em Farenheits");
    scanf("%d", &F);

    /* Calcula a temperatura */
    C = 5 * (F-32)/9;

    /* Saída de dados */
    printf("");
    printf("A temperatura é %f graus Celcius\n", C);

    return 0;
}