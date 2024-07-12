#include <stdio.h>

int main() {
    int a;
    printf("Type the value of the variable: ");
    scanf("%d", &a);
    
    if (a%2 == 0) {
        printf("O valor é par.");
    }
    else {
        printf("O valor é ímpar.");
    }
    
    return 0;
}