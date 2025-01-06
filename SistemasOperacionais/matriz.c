#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define TAM_MATRIZ 1000

int isPrime(int n) {     
    if (n < 2) {return 0;}     
    for (int i = 2; i <= sqrt(n); i++) {         
        if (n % i == 0) { return 0;}
    }
    return 1;
void imprimirMatriz(int **m) {
    for (int i = 0; i < TAM_MATRIZ; i++) {
        for (int j = 0; j < TAM_MATRIZ; j++) {
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }
}
void matriz(int **m) {
    *m = malloc(TAM_MATRIZ * sizeof(int *));  
    for (int i = 0; i < TAM_MATRIZ; i++) {   
        (*m)[i] = malloc(TAM_MATRIZ * sizeof(int)); 
        for (int j = 0; j < TAM_MATRIZ; j++) {     
            (*m)[i][j] = rand() % 31999;  
        }
    }
}
void liberarMatriz(int **m) {
    for (int i = 0; i < TAM_MATRIZ; i++) {
        free(m[i]);  
    }
    free(m);  
}
int serialPrimo(int **m) {
    int total = 0
    for (int i = 0; i < TAM_MATRIZ; i++) {
        for (int j = 0; j < TAM_MATRIZ; j++) {
            if (isPrime(m[i][j])) {total++;}
        }
    }
    return total;
}

int main() {
    srand(time(NULL)); 
    int **m; 
    
    matriz(&m);
    
    printf("Matriz gerada:\n");
    imprimirMatriz(&m);
    int total = serialPrimo(&m);
    
    printf("Quantidade de números primos: %d", total);
    liberarMatriz(&m);
    
    return 0;
}