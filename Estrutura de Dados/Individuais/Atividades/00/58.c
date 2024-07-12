#include <stdio.h>
#include <stdlib.h>

// I did other exercise, but will let this here :)

int main() {
    int *vet;
    int n;

    printf("Type the quantity of values: ");
    scanf("%d", &n);
    vet = (int *)(malloc(n * sizeof(int)));

    for (int i = 0; i < n; i++) {
        printf("Type a value: ");
        scanf("%d", &vet[i]);
    }

    printf("The values of the vet are:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", vet[i]);
    }

    free(vet);

    return 0;

}