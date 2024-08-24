#include <stdio.h>

int main() {

    int m;
    printf("Digite o tamanho da matriz: ");
    scanf("%d", &m);

    float matriz[m][m], valor, maior = 0;
    for (int i = 0; i < m; i++) { 
        for (int j = 0; j < m; j++) {
            printf("Digite um valor: ");
            scanf("%f", &valor);
            matriz[i][j] = valor;
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            if (matriz[i][j] > maior) {
                maior = matriz[i][j];
            }
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            matriz[i][j] = matriz[i][j]/maior;
        }
    }

    printf("Matriz Identidade:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            printf("%2.f    ", matriz[i][j]);
        }
        printf("\n");
    }

    return 0;
}