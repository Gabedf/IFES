#include <stdio.h>
#include <string.h>

int main() {
    
    char s1[100], s2[100], resultado[200];
    int lens1, lens2, i = 0;

    printf("Digite a primeira string: ");
    fgets(s1, sizeof(s1), stdin);

    printf("Digite a segunda string: ");
    fgets(s2, sizeof(s2), stdin);    

    lens1 = strlen(s1);
    lens2 = strlen(s2);

    while (s1[i] != '\0' && s2[i] != '\0') {
        resultado[strlen(resultado)] = s1[i];
        resultado[strlen(resultado) + 1] = s2[i];
        i++;
    }

    resultado[strlen(resultado) + 1] = '\0';
    printf("%s", resultado);

    return 0;
}
