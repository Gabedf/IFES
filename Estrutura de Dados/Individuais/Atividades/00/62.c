#include <stdio.h>
#include <stdlib.h>

int main() {
    char *c, a;
    int n, z, k = 0, *vet;

    printf("Enter the value to be found: ");
    scanf(" %c", &a);
    printf("Enter the size of the vector: ");
    scanf("%d", &n);

    c = (char *)(malloc(n * sizeof(char)));

    for (int i = 0; i < n; i++) {
        printf("\nType a char: ");
        scanf(" %c", &c[i]);

        if (c[i] == a) {
            z += 1;
        }}
    
    vet = (int *)(malloc(z * sizeof(int)));

    for (int i = 0; i < n; i++) {
        if (c[i] == a) {
            vet[k] = i;
            k += 1;
        }
    }

    for (int i = 0; i < n; i++) {
        printf("%c ", c[i]);
    }

    printf("\n");
    for (int i = 0; i < z; i++) {
        printf("%d ", vet[i]);
    }

    free(vet);
    free(c);

    return 0;

}