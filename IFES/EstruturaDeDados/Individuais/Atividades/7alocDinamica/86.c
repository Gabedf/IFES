#include <stdio.h>
#include <stdlib.h>

int main() {

    int lin, col;
    float **matriz;

    printf("Digite o número de linhas: ");
    scanf("%d", &lin);
    printf("Digite o número de colunas: ");
    scanf("%d", &col);

    matriz = malloc(lin * sizeof(int*));

    for (int i = 0; i < lin; i++) {
        matriz[i] = malloc(col * sizeof(int*));
        for (int j = 0; j < col; j++) {
            printf("Digite o valor: ");
            scanf("%f", &matriz[i][j]);
        } printf("\n");
    }

    for (int i = 0; i < lin; i++) {
        for (int j = 0; j < col; j++) {
            printf("%f ", matriz[i][j]);
        } printf("\n");
    }

    return 0;

}