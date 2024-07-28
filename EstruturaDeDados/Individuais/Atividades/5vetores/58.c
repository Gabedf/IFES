#include <stdio.h> 

int main() {

    int v, tam, soma = 0, media;

    printf("Defina o tamanho do vetor: ");
    scanf("%d", &tam);

    int vet[tam];

    for (int i = 0; i < tam; i++) {
        printf("Digite o valor a ser adicionado ao vetor: ");
        scanf("%d", &vet[i]);
    }

    for (int i = 0; i < tam; i++) {
        soma += vet[i];
    }
    media = soma/tam;


    printf("A soma é %d e a média é %d", soma, media);
    return 0;
}       