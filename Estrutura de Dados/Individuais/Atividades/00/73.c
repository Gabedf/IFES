#include <stdio.h>
#include <stdlib.h>

int main() {
    int m;
    printf("Enter the numbers of rows and columns: ");
    scanf("%d", &m);

    int mat[m][m];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            if (i == j) {mat[i][j] = 1;}
            else {mat[i][j] = 0;}
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d  ", mat[i][j]);
        }
        printf("\n");
    }

    return 0;

}