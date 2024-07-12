#include <stdio.h>
#include <stdlib.h>

int* intersection(int *x1, int *x2, int n1, int n2, int *n3) {
    int *x3 = (int *)(malloc((n1+n2) * sizeof(int)));
    int size = 0;

    for (int i = 0; i < (n1+n2); i++) {
        int here = 0, here3 = 0;
        for (int j = 0; j < (n1+n2); j++) {
            if (x1[i] == x2[j]) {
                here = 1;
                break;
        }}
        if (here) {
            for (int k = 0; k < (size+1); k++) {
                if (x3[k] == x1[i]) {here3 = 1;}
            }
        }
        if (here && (here3 == 0)) {x3[size] = x1[i]; size += 1;}
        }

    *n3 = size;
    x3 = (int *)(realloc(x3, size * sizeof(int)));
    return x3; 
    }

int main() {
    int v1[5] = {1, 3, 5, 6, 7};
    int v2[5] = {1, 3, 4, 6, 8};
    int n1 = 5, n2 = 5, n3;

    int *x3 = intersection(v1, v2, n1, n2, &n3);

    printf("\nThe vector is: ");
    for (int i = 0; i < n3; i++) {
        printf("%d ", x3[i]);
    }
    printf("\nThe size of the vector is %d", n3);

    free(x3);
    return 0;
}