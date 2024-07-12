#include <stdio.h>

int main() {
    int m;
    
    printf("Digite o tamanho da matriz (m x m): ");
    scanf("%d", &m);

    int matriz[m][m];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            if (i == j) {
                matriz[i][j] = 1; 
            } else {
                matriz[i][j] = 0;  
            }
        }
    }

    printf("Matriz Identidade:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    return 0;
}
