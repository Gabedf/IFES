#include <stdio.h>

int main() {
    int v = 1, v2 = 0, m, i = 1;

    printf("Type 0 if you want to finish the program.\n");

    while (v != 0) {
        printf("Value: ");
        scanf("%d", &v);
        v2 += v;
        m = v2/i;
        printf("\nThe arithmetic average is: %d.\n", m);
        i++;
    }

    return 0;
}