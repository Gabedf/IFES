#include <stdio.h>
#include <stdlib.h>

int* interseccao(int *x1, int *x2, int n1, int n2, int *n3) {
    int maior = 0;

    if (n1 > n2) {
        maior = n1;
    } else {maior = n2;}

    int *x3 = malloc((maior) * sizeof(int));
    for (int i = 0; i < maior; i++) {
        for (int j = 0; j < maior; j++) {
            if (x1[i] == x2[j]) {
                x3[i] = x1[i];
                (*n3)++;}}}

    return x3;
}

int main() {
    int n1, n2, n3;

    printf("Defina o tamanho do vetor 1: ");
    scanf("%d", &n1);
    printf("Defina o tamanho do vetor 2: ");
    scanf("%d", &n2);

    int x1[n1], x2[n2];
    for (int i = 0; i < n1; i++) {
        printf("Defina o valor do vetor 1: ");
        scanf("%d",  &x1[i]);
    }
    for (int i = 0; i < n2; i++) {
        printf("Defina o valor do vetor 2: ");
        scanf("%d",  &x2[i]);
    }

    int *uniao = interseccao(x1, x2, n1, n2, &n3);

    for (int i = 0; i < n3; i++) {
        printf("%d ", uniao[i]);
    }
    printf(" ");
    printf("Tamanho de x3: %d", n3);

    return 0;
}