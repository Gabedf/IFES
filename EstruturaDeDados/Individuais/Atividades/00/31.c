#include <stdio.h>

int calculate_sum(int *a, int *b) {
    return *a + *b;
}

int main() {
    int x, y;
    
    printf("Type the value of x: ");
    scanf("%d", &x);
    printf("Type the value of y: ");
    scanf("%d", &y);
    
    int result = calculate_sum(&x, &y);
    
    printf("The sum of %d and %d is: %d\n", x, y, result);
    
    return 0;
}
