#include <stdio.h>
#include <stdlib.h>
#include "dynvec.h"  

int main() {

    int size1 = 7;
    DynVec *dv1 = create_dynvec(size1);
    dv1->vet[0] = 1; dv1->vet[1] = 2; dv1->vet[2] = 3; dv1->vet[3] = 4; dv1->vet[4] = 5; dv1->vet[5] = 7; dv1->vet[6] = 9;

    int size2 = 3;
    DynVec *dv2 = create_dynvec(size2);
    dv2->vet[0] = 3; dv2->vet[1] = 4; dv2->vet[2] = 5;

    printf("Vetor 1: ");
    for (int i = 0; i < (size1); i++) {
        printf("%d ", (dv1->vet)[i]);}
    printf("\n");

    printf("Vetor 2: ");
    for (int i = 0; i < (size2); i++) {
        printf("%d ", (dv2->vet)[i]);}   
    printf("\n");

    // Teste da união dos vetores
    DynVec *unionResult = dv_union(dv1, dv2);
    printf("União dos vetores dv1 e dv2:\n");
    printf("Tamanho: %d\n", unionResult->size);
    printf("Elementos: ");
    for (int i = 0; i < unionResult->size; i++) {
        printf("%d ", unionResult->vet[i]);
    }
    printf("\n\n");

    // Teste da intersecção dos vetores
    DynVec *intersectionResult = dv_intersection(dv1, dv2);
    printf("Interseção dos vetores dv1 e dv2:\n");
    printf("Tamanho: %d\n", intersectionResult->size);
    printf("Elementos: ");
    for (int i = 0; i < intersectionResult->size; i++) {
        printf("%d ", intersectionResult->vet[i]);
    }
    printf("\n");

    // Liberando memória
    free(dv1->vet);
    free(dv1);
    free(dv2->vet);
    free(dv2);
    free(unionResult->vet);
    free(unionResult);
    free(intersectionResult->vet);
    free(intersectionResult);

    return 0;
}
