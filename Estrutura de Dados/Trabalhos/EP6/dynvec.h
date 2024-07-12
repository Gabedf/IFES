#ifndef MY_DYNVEC
#define MY_DYNVEC

typedef struct {
    int *vet;
    int size;
} DynVec;

// Cria um novo vetor alocando a memória dinamicamente para a estrutura "DynVec"
DynVec* create_dynvec(int size);

// Retorna um vetor com a interseção dos elementos de dv1 e dv2
DynVec *dv_intersection(DynVec *dv1, DynVec *dv2);

// Retorna um vetor com a união dos elementos de dv1 e dv2
DynVec *dv_union(DynVec *dv1, DynVec *dv2)

#endif