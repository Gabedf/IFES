#include <stdio.h>
#include <stdlib.h>

void sum(int *src, int *tgt, int n) {
    
    for (int i = 0; i < n; i++) {
        printf("Enter a value: ");
        scanf("%d", &src[i]);
        if (i > 0) {
            tgt[i] = src[i] + tgt[i-1];
        } else {tgt[i] = src[i];}
    }
}

int main() {
    int *a, *b, n;
    printf("Type the size of the vector: ");
    scanf("%d", &n); 
    a = (int *)(malloc(n * sizeof(int)));
    b = (int *)(malloc(n * sizeof(int)));

    sum(a, b, n);

    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", b[i]);
    }

    free(a);
    free(b);

    return 0;
}