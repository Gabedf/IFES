#include <stdio.h>

void switch_values(int *a, int *b) {
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}

int main() {
    int a, b;
    printf("Type the value of a: ");
    scanf("%d", &a);
    printf("Type the value of b: ");
    scanf("%d", &b);

    // Before swap the values
    printf("The value of a is %d and b is %d.\n\n", a, b);

    switch_values(&a, &b);

    printf("Now, the value of a is %d and b is %d.", a, b);

    return 0;
}