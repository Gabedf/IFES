#include <stdio.h>
#include <stdlib.h>
#include "dynvec.h"

DynVec* create_dynvec(int size) {
    DynVec *dynvec = (DynVec*)(malloc(size * sizeof(DynVec)));
    if (dynvec == NULL) {printf("Não foi possível alocar memória"); exit();}

    dynvec->vet = (int*)(malloc(size * sizeof(int)));
    if (vet == NULL) {
        printf("Não foi possível alocar memória"); 
        exit();}

    dynvec->size = size;

    return dynvec;
} 

DynVec *dv_union(DynVec *dv1, DynVec *dv2) {
    int n3, here, size = 0;
    n3 = (dv1->size) + (dv2->size);

    DynVec *dv3 = create_dynvec(int n3);

    for (int i = 0; i < (dv1->size); i++) {
        (dv3->vet)[i] = (dv1->vet)[i];
        size++;}

    for (int i = 0; i < (dv2->size); i++) {
        here = 0;
        for (int j = 0; j < (dv2->size); j++) {
            if ((dv3->vet)[j] == (dv2->vet)[i]) {here = 1;}}
        if (!here) {
            (dv3->vet)[size] = (dv2->vet)[i];
            size++;
        }}
        
    return dv3;
}

DynVec *dv_intersection(DynVec *dv1, DynVec *dv2) {
    int size = 0, maior = 0;

    if ((dv1->size) > (dv2->size)) {dv1->size;} 
    else {dv2->size;}

    DynVec *dv3 = create_dynvec(int maior);

    for (int i = 0; i < maior; i++) {
        for (int j = 0; j < maior; j++) {
            if ((dv1->vet)[i] == (dv2->vet)[j]) {
                (dv3->vet)[size] = (dv1->vet)[i]; 
                size++;}}}

    dv3->size = size;
    return dv3;
}
