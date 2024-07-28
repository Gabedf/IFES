#include <stdio.h>
#include <stdlib.h>

int* uniao(int *x1, int *x2, int n1, int n2, int *n3) {
   
    int here, size = 0;
    int *x3 = malloc((n1+n2) * sizeof(int));
    
    for (int i = 0; i < n1; i++) {
        x3[i] = x1[i];
        size++;
    }

    for (int i = 0; i < n2; i++) {
        here = 0;
        for (int j = 0; j < n2; j++) {
            if (x3[j] == x2[i]) {here = 1;}
        }
        if (!here) {
            x3[size] = x2[i];
            size++;
        }
    }

    *n3 = size;
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

    int *x3 = uniao(x1, x2, n1, n2, &n3);

    for (int i = 0; i < n3; i++) {
        printf("%d ", x3[i]); 
    }

    printf("\n%d", n3);
    return 0;
}