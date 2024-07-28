#include <stdio.h>
#include <stdlib.h>

// Nothing from exercise, just testing a random matrix :D

int main() {
    int **p, k, j;

    printf("Enter the number of lines: ");
    scanf("%d", &k);
    p = (int **)malloc(k *sizeof(int *));

    printf("Enter the number of colunms: ");
    scanf("%d", &j);

    for (int i = 0; i < k; i++) {
        p[i] = (int *)(malloc(j * sizeof(int)));
        for (int a = 0; a < j; a++) {
            printf("Enter a value: ");
            scanf("%d", &p[i][a]);
        }
    }

    for (int i = 0; i < k; i++) {
        for (int a = 0; a < j; a++) {
            printf("%d  ", p[i][a]);
        }
        printf("\n");
    }

    return 0;

}   