#include <stdio.h>
#include <stdlib.h>

int* alloc(int n) {
    int *vet = (int *)(malloc(n * sizeof(int)));

    if (vet == NULL) {
        printf("Memory allocation failed!\n");
        return 1;}
        
    return vet;
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int *vet = alloc(n);
    for (int i = 0; i < n; i++) {
        printf("Type a value: ");
        scanf("%d", &vet[i]);
    } 

    printf("\nThe vector is: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", vet[i]);
    }
    free(vet);

    return 0;
}