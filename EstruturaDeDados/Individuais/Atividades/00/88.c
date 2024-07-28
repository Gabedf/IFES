#include <stdio.h>
#include <stdlib.h>

int* mix(int *x1, int *x2, int n1, int n2, int *n3) {
    int *x3 = (int *)(malloc((n1+n2) * sizeof(int)));
    int size = 0;

    for (int i = 0; i < (n1); i++) {
        x3[i] = x1[i];
        size += 1;
    }
    
    for (int i = 0; i < (n2); i++) {
        int here = 0;
        for (int j = 0; j < (n2); j++) {
            if (x3[i] == x2[j]) {here = 1;}
        }
        if (here == 0) {
            x3[size] = x2[i]; 
            size += 1;}
    }

    x3 = (int *)(realloc(x3, size * sizeof(int)));
    *n3 = size;
    return x3;
}

int main() {
    int v1[5] = {1, 3, 5, 6, 7};
    int v2[5] = {1, 3, 4, 6, 8};
    int n1 = 5, n2 = 5, n3;

    int *x3 = mix(v1, v2, n1, n2, &n3);

    printf("\nThe vector is: ");
    for (int i = 0; i < n3; i++) {
        printf("%d ", x3[i]);
    }
    printf("\nThe size of the vector is %d", n3);

    free(x3);
    return 0;
}