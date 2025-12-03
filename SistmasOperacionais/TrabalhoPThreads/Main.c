#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define LINHAS        5000
#define COLUNAS       5000
#define SUB_LINHAS    250
#define SUB_COLUNAS   100
#define SEMENTE       1233

int quantidade_sub_matrizes = 0, contador = 0;
int** matriz = NULL;

int qtd_submatrizes(int i, int j, int sub_i, int sub_j) {
    return ((i - sub_i + 1) * (j - sub_j + 1));
}

// ALOCAR ESPA�O PARA MATRIZ
int** alocarMatriz() {
    int i, j;

    // ALOCAR ESPA�O PARA LINHAS
    matriz = calloc(LINHAS, sizeof(int*));
    if (matriz == NULL) {
        printf("Erro ao alocar mem�ria.\n");
        return (NULL);
    }

    // ALOCAR ESPA�O PARA COLUNAS
    for (i = 0; i < LINHAS; i++) {
        matriz[i] = (int*)malloc(COLUNAS * sizeof(int));
        if (matriz[i] == NULL) {
            printf("Erro ao alocar mem�ria.\n");
            return (NULL);
        }
    }

    return matriz;
}

// LIBERAR MEM�RIA ALOCADA
void liberarMatriz() {
    for (int i = 0; i < LINHAS; i++) {
        free(matriz[i]);
    }
    free(matriz);
}

// RETORNAR SE UM N�MERO � OU N�O PRIMO
int ehPrimo(int numero) {
	if (numero <= 1) { return 0; }
	int raiz = sqrt(numero);

	for (int i = 2; i <= raiz; i++) {
		if (numero % i == 0) { return 0; }
	}

	return 1;
}

// FUN��O PRINCIPAL
int main() {

    matriz = alocarMatriz();
    clock_t inicio, fim;
    double tempo_gasto;
    inicio = clock();

    srand(SEMENTE);
    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS; j++) {
            matriz[i][j] = rand() % 32000;
        }
    }

    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS; j++) {
            contador += ehPrimo(matriz[i][j]);
        }
    }
    fim = clock();
    tempo_gasto = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
    
    printf("Tempo de execu��o: %.3f segundos\n", tempo_gasto);
    printf("\nQuantidade de primos: %d\n", contador);

    liberarMatriz(matriz, LINHAS);

    return 0;

}