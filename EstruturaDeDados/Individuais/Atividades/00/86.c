#include <stdio.h>
#include <stdlib.h>

float** alloc(int row, int col) {
    float **vet = (float **)(malloc(row * sizeof(float*)));
    float *vet = (float *)(malloc(row * sizeof(float)));

    if ((*vet == NULL) || (vet == NULL)) {
        printf("Memory allocation failed!\n");
        return 1;}
    
    return vet;
}

int main() {
    int row, col; 
    float **vet = alloc(row, col);

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < row; j++) {
            if (i >= j) {vet[i][j] = 1;}
            else {vet[i][j] = 0;}
        }}
    
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < row; j++) {
            printf("%f ", vet[i][j]);
        }
    printf("\n");}

    return 0;
}