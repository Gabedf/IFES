#include <stdio.h>

int main() {
    int n, v;
    
    printf("How many times do you want to multiply the value by 3?\nN times: ");
    scanf("%d", &n);

    for (int i; i < n; i++) {
        printf("Type a value: ");
        scanf("%d", &v);
        v = v*3;
        printf("The value multiplied by 3 is %d.\n", v);    
    }

    return 0;
}