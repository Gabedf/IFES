#include <stdio.h>

int main() {
    int i = 1, m = 0, v = 0, v2;
    printf("If you want to the program stop, type a value lower then 0.\n\n");

    while (v >= 0) {
        printf("Value: ");
        scanf("%d", &v);
        v2 += v;
        m = v2/i;
        printf("\nThe arithmetic average is: %d.\n", m);
        i++;
    }   

    return 0;
}