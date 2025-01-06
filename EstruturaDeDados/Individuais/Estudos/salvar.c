// Função para alocar e preencher a matriz com valores aleatórios
void matriz(int ***mat) {
    *mat = malloc(TAM_MATRIZ * sizeof(int *));  // Aloca memória para as linhas
    for (int i = 0; i < TAM_MATRIZ; i++) {
        (*mat)[i] = malloc(TAM_MATRIZ * sizeof(int));  // Aloca memória para cada linha
        for (int j = 0; j < TAM_MATRIZ; j++) {
            (*mat)[i][j] = rand() % 31999;  // Preenche com números aleatórios
        }
    }
}

// Função para imprimir a matriz
void imprimirMatriz(int **mat) {
    for (int i = 0; i < TAM_MATRIZ; i++) {
        for (int j = 0; j < TAM_MATRIZ; j++) {
            printf("%d   ", mat[i][j]);
        }
        printf("\n");
    }
}
