#include <stdio.h>

int main() {
    float sales, week = 200;
    
    printf("Type the amount of sales of the week: ");
    scanf("%f", &sales);

    week += (sales*0.09);
    if (sales >= 800) {
        week += 800;
    }

    printf("The salary of the week is: $ %.2f", week);
    return 0;
}