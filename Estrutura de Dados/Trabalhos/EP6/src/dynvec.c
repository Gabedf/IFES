#include <stdio.h>
#include <stdlib.h>
#include "dynvec.h"

DynVec* create_dynvec(int size) {
    DynVec *dynvec = (DynVec*)(malloc(size * sizeof(DynVec)));
    if (dynvec == NULL) {printf("Não foi possível alocar memória"); exit(1);}

    dynvec->vet = (int*)(malloc(size * sizeof(int)));
    if (dynvec->vet == NULL) {
        printf("Não foi possível alocar memória"); 
        exit(1);}

    dynvec->size = size;

    return dynvec;
} 

DynVec *dv_intersection(DynVec *dv1, DynVec *dv2) {
    int n3, size = 0;
    n3 = (dv1->size) + (dv2->size);
    DynVec *dv3 = create_dynvec(n3);

    for (int i = 0; i < n3; i++) 
        {
        int here = 0, here3 = 0;
        for (int j = 0; j < n3; j++) {
            if (dv1->vet[i] == dv2->vet[j]) {here = 1; break;}}

        if (here) {
            for (int k = 0; k < (size+1); k++) {
                if (dv3->vet[k] == dv1->vet[i]) {here3 = 1;}}}
        
        if (here && (here3 == 0)) {dv3->vet[size] = dv1->vet[i]; size++;}
        }
        
    dv3->size = size;
    dv3->vet = (int*)(realloc(dv3->vet, size * sizeof(int)));
    return dv3;
}

DynVec *dv_union(DynVec *dv1, DynVec *dv2) {
    int size = 0, here;
    int sum = dv1->size + dv2->size;
    DynVec *dv3 = create_dynvec(sum);

    for (int i = 0; i < dv1->size; i++) {dv3->vet[size++] = dv1->vet[i];}

    for (int i = 0; i < dv2->size; i++) {
        here = 0;
        for (int j = 0; j < dv3->size; j++) {
            if (dv2->vet[i] == dv3->vet[j]) {here = 1;}}
        if (!here) {
            dv3->vet[size++] = dv2->vet[i];}}
            
    dv3->size = size;
    dv3->vet = (int*)(realloc(dv3->vet, size * sizeof(int)));
    return dv3;
}