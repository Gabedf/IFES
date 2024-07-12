#include <stdio.h> 
#include <stdlib.h>

int* aloca_vetor(int n) {
    int *vetor = malloc(n * sizeof(int));

    if (vetor == NULL) {
        printf("Erro ao alocar memória para o vetor.\n");
    }

    return vetor;
}

int main() {
    int n;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);

    int *v = aloca_vetor(n);

    for (int i = 0; i < n; i++) {
        printf("Digite o valor do vetor: ");
        scanf("%d", &v[i]);
    }

    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }

    return 0;
}
