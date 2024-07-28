#include <stdio.h>

int square(int x) {
    return x*x;
}

int main() {
    int a;
    printf("Type a value to mutiply by himself: ");
    scanf("%d", &a);

    a = square(a);
    printf("The value is %d.", a);
    return 0;
}