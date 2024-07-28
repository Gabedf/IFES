#include <stdio.h>

int main() {
    char c;
    int n;
    
    printf("Digite o caractere a ser procurado (c): ");
    scanf(" %c", &c); 
    
    printf("Digite o tamanho do vetor (n): ");
    scanf("%d", &n);

    char vetor[n];

    printf("Digite os caracteres do vetor (separados por espaço ou enter):\n");
    for (int i = 0; i < n; i++) {
        scanf(" %c", &vetor[i]); 
    }

    printf("O caractere '%c' foi encontrado nos seguintes índices:\n", c);
    for (int i = 0; i < n; i++) {
        if (vetor[i] == c) {
            printf("%d", i);
        }
    }
    printf("\n");

    return 0;
}
